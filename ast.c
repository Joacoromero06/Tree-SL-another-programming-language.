#include "ast.h"
#include "data.h"
#include "defs.h"

struct symbol symtab[NHASH];

/*=======================================================================*/
/*                             AST DEFINITION                            */
/*=======================================================================*/
struct ast *newast(int nodoValue, struct ast *left, struct ast *right, tData data)
{
    struct ast *nuevo = malloc(sizeof(struct ast));
    if (!nuevo)
    {
        notificaciones(8001);
        return NULL;
    }
    nuevo->nodetype = nodoValue;
    nuevo->l = left;
    nuevo->r = right;
    nuevo->d = data;
    return nuevo;
}
int get_nodetype(struct ast *a)
{
    if (!a)
    {
        notificaciones(8000);
        return 0;
    }
    return a->nodetype;
}
int get_widht(struct ast *a)
{
    if (!a)
    {
        printf("error puntero null en get_widht\n");
        return 0;
    }
    int widht = 0;
    while (get_nodetype(a) == LIST_OF_AST)
    {
        widht++;
        a = a->r;
    }
    widht++; // the last ast != LIST_OF_AST
    return widht;
}
/*=======================================================================*/

/*=======================================================================*/
/*                             FLOW DEFINITION                           */
/*=======================================================================*/
struct ast *newflow(int nodetype, struct ast *cond, struct ast *iterable, struct ast *tblock, struct ast *fblock, struct symbol *s)
{
    struct flow *a = malloc(sizeof(struct flow));
    if (!a)
    {
        notificaciones(8002);
        return NULL;
    }
    a->nodetype = nodetype;
    a->cond = cond;
    a->iterable = iterable;
    a->tblock = tblock;
    a->fblock = fblock;
    a->s = s;
    return (struct ast *)a;
}
tData eval_flow(struct flow *a)
{
    struct ast *cond = a->cond;
    struct ast *iterable = a->iterable;
    struct ast *tblock = a->tblock;
    struct ast *fblock = a->fblock;
    struct symbol *s = a->s;

    tData nuevo = NULL;

    switch (get_nodetype((struct ast *)a)) // safe cast
    {
    case IF:
    {
        if (get_bool_value(eval(cond)))
        {
            nuevo = eval(tblock);
        }
        else
        {
            if (fblock != NULL)
            {
                nuevo = eval(fblock);
            }
            // nuevo NULL;
        }
        break;
    }
    case WHILE:
    {
        while (get_bool_value(eval(cond)))
        {
            nuevo = eval(tblock);
        }
        break;
    }
    case FORALL:
    {
        tData collection = copiarData(eval(iterable));
        tData iterator = collection;
        int i = 1;
        while (iterator)
        {
            tData elemento = get_dato(iterator);
            int booleano;
            s->data = copiarData(elemento); // sacar copiar data
            if (cond != NULL)
            {
                booleano = get_bool_value(eval(cond));
            }
            else
            {
                booleano = 1;
            }

            if (booleano != 0)
            {
                nuevo = eval(tblock);
                i++;
            }
            iterator = get_next(iterator);
        }
        freeData(collection);
        break;
    }
    case FORANY:
    {
        tData collection = copiarData(eval(iterable));
        tData iterator = collection;
        int booleano;
        int found = 0;

        while (iterator && found == 0)
        {
            tData elemento = get_dato(iterator);
            int booleano;
            s->data = copiarData(elemento);
            if (cond)
            {
                booleano = get_bool_value(eval(cond));
            }
            else
            {
                booleano = 1;
            }

            if (booleano != 0)
            {
                found = 1;
                nuevo = eval(tblock);
            }
            iterator = get_next(iterator);
        }
        break;
        freeData(collection);
    }
    default:
        break;
    }
    return nuevo;
}
/*=======================================================================*/

/*=======================================================================*/
/*                      AST working MEMORY DEFINITION                    */
/*=======================================================================*/
struct ast *newmemory_ast(int nodetype, struct symbol *s, struct ast *a, struct symlist* sl)
{
    struct memory_ast *nvo = malloc(sizeof(struct memory_ast));
    if (!nvo)
    {
        notificaciones(8003);
        return NULL;
    }
    nvo->nodetype = nodetype;
    nvo->s = s;
    nvo->a = a;
    nvo->sl = sl;
    return (struct ast *)nvo;
}
tData eval_memory_ast(struct memory_ast *arbol)
{
    if (!arbol)
    {
        notificaciones(8004);
        return NULL;
    }

    tData nuevo = NULL;
    struct symbol *s = arbol->s;
    struct ast *a = arbol->a;
    struct symlist* sl = arbol->sl;

    switch (get_nodetype((struct ast *)arbol))
    {
    case ASIGNACION:
    {
        nuevo = eval(a);
        s->data = copiarData(nuevo);
        break;
    }
    case VAR_REF:
    {
        nuevo = copiarData(s->data); // sin copiar ?

        if (nuevo == NULL)
        {
            notificaciones(8005);
        }
        break;
    }
    case FN_CALL:
    {
        struct symbol *f = s;
        struct ast *params = a;
        struct symlist *sl = f->args;
        struct ast *body = f->body;

        int nargs = compute_size(sl);
        int widht = get_widht(params);
        if (nargs != widht)
        {
            printf("la cantidad de parametros no coincide con los esperados\n");
            return NULL;
        }

        tData *new_values = malloc(sizeof(tData) * nargs);
        tData *old_values = malloc(sizeof(tData) * nargs);

        if (!new_values || !old_values)
        {
            printf("sin memoria en FN_CALL\n");
            return NULL;
        }

        // Compute new_datas
        struct ast *nav_ast = params;
        for (int i = 0; i < nargs; i++)
        {
            if (get_nodetype(nav_ast) == LIST_OF_AST)
            {
                new_values[i] = eval(nav_ast->l);
                nav_ast = nav_ast->r;
            }
            else
            {
                new_values[i] = eval(nav_ast);
            }
        }

        // Save old_values of the variables
        // Update new_values to the variables
        struct symlist *nav_sl = sl;
        for (int i = 0; i < nargs; i++)
        {
            old_values[i] = nav_sl->s->data;
            nav_sl->s->data = new_values[i];
            if (!nav_sl)
            {
                printf("error en FN_CALL debido a compute_size\n");
                return NULL;
            }
            nav_sl = nav_sl->next;
        }

        // Eval body with variables.data updated
        nuevo = eval(body);

        // Take back old_values to variables.data
        nav_sl = sl;
        for (int i = 0; i < nargs; i++)
        {
            nav_sl->s->data = old_values[i];
            if (!sl)
            {
                printf("error en FN_CALL debido a compute_size\n");
                return NULL;
            }
            nav_sl = nav_sl->next;
        }
        break;
    }
    case ASSIGN_MULTIPLE:
    {
        tData id_data = s->data;
        if(id_data == NULL)
        {
            notificaciones(14000);
            exit(1);
        }
        if(! es_struct(id_data))
        {
            notificaciones(14001);
            exit(1);
        }
        
        int tam = compute_size(sl);
        if( tamanio(id_data) < tam )
        {
            notificaciones(14002);
            exit(1);        
        }
        
        tData elem_i = NULL;
        for(int i = 1; i <= tam; i++)
        {
            elem_i = elemento_pos(id_data, i);
            
            if(!sl)
            {
                printf("error en logica, compute_size");
                return NULL;
            }

            sl->s->data = copiarData(elem_i);
            sl = sl->next;
        }
        break;
    }
    default:
        printf("nodetype desconocido en eval_memory_ast\n"); /*esto nunca va a pasa*/
        break;
    }
    return nuevo;
}
/*=======================================================================*/

/*=======================================================================*/
/*                      AST working STRUCT LITERALS                      */
/*=======================================================================*/
tData eval_list(struct ast *a) // no semantic errors
{
    tData nuevo = createData(LIST);
    if (!a->l)
        return a->d; // lista vacia se va directo
    struct ast *nav = a->l;
    while (get_nodetype(nav) == LIST_OF_AST)
    {
        agregarData(&nuevo, eval(nav->l));
        nav = nav->r;
    }
    agregarData(&nuevo, eval(nav));
    return nuevo;
}
tData eval_set(struct ast *a) // no semantic errors
{
    if (!a->l)
        return a->d; // lista vacia se va directo

    tData nuevo = createData(SET);
    struct ast *nav = a->l;
    while (get_nodetype(nav) == LIST_OF_AST)
    {
        agregarData(&nuevo, eval(nav->l));
        nav = nav->r;
    }
    agregarData(&nuevo, eval(nav));
    return nuevo;
}

/*=======================================================================*/
/*                      AST working REL LOG EXPRESSION                   */
/*=======================================================================*/
tData eval_log(struct ast *a)
{

    struct ast *left = a->l;
    struct ast *right = a->r;

    tData A = NULL;
    if (left)
    {
        A = eval(left);
    }
    tData B = eval(right);

    switch (get_nodetype(a))
    {

    case AND:
    {
        if (!left || !right)
        {
            notificaciones(9000); // no deberia pasar
            exit(1);
        }

        if (get_bool_value(A) && get_bool_value(B))
        {
            return createBool("true");
        }

        return createBool("false");
    }
    break;

    case OR:
    {
        if (!left || !right)
        {
            notificaciones(9000); // no deberia pasar
            exit(1);
        }

        if (get_bool_value(A) || get_bool_value(B))
        {
            return createBool("true");
        }

        return createBool("false");
    }
    break;

    case NOT:
    {
        tData nuevo = NULL;
        if (!right)
        {
            notificaciones(9000); // no deberia pasar
            exit(1);
        }
        nuevo = (get_bool_value(B)) ? createBool("false") : createBool("true");
        return nuevo;
    }
    break;
    }
    return NULL;
}
tData compute_op_rel(int nodetype, tData eval_left, tData eval_right)
{
    if (!eval_left || !eval_right)
    {
        printf("puntero null en compara_menor");
        return NULL;
    }

    tData nuevo;
    if (get_tipo(eval_left) != get_tipo(eval_right))
    {
        printf("Semantic Error los operadores de lasexpresiones relacionales deben ser del mismo tipo\n");
        nuevo = NULL;
        exit(1);
    }
    switch (nodetype)
    {
    case MAYOR:
    {
        nuevo = compara_mayor(eval_left, eval_right);
        break;
    }

    case MENOR:
    {
        nuevo = compara_menor(eval_left, eval_right);
        break;
    }

    case MAYOR_IGUAL:
    {
        nuevo = compara_mayorigual(eval_left, eval_right);
        break;
    }

    case MENOR_IGUAL:
    {
        nuevo = compara_menorigual(eval_left, eval_right);
        break;
    }

    case IGUAL:
    {
        nuevo = compara_igual(eval_left, eval_right);
        break;
    }

    case DISTINTO:
    {
        nuevo = compara_distinto(eval_left, eval_right);
        break;
    }

    default:
        break;
    }
}

/*=======================================================================*/
/*                      AST working STRUCT EXPRESSIONS                   */
/*=======================================================================*/
tData evalOpList(struct ast *a)
{
    struct ast *left = a->l;
    struct ast *right = a->r;

    tData nuevo = NULL;

    tData aux_result = eval(left);
    tData list_result = eval(right);

    if (!aux_result || !list_result)
    {
        notificaciones(9000); // no deberia pasar
        exit(1);
    }

    switch (get_nodetype(a))
    {
    case KICK:
    {
        if (get_tipo(aux_result) == INT && get_tipo(list_result) == LIST)
        {
            nuevo = (list_result);
            int posicion = get_value(aux_result); // eval(left)

            if (posicion > tamanio(list_result))
            {
                notificaciones(10000);
                mostrarData(list_result);
                printf(" es demesiada pequeña para eliminiar su elem en posicion: %d\n", posicion);
                exit(1);
            }
            else
            {
                eliminar_pos(&nuevo, posicion);
            }
        }
        else
        {
            // mostrar linea de error
            if (get_tipo(aux_result) != INT)
            {
                notificaciones(301);
                mostrarData(aux_result);
                exit(1);
            }
            if (get_tipo(list_result) != LIST)
            {
                notificaciones(10002);
                mostrarData(list_result);
                exit(1);
            }
        }
        break;
    }
    case ADD:
    {
        if (aux_result != NULL && get_tipo(list_result) == LIST)
        {
            nuevo = list_result;
            agregarData(&nuevo, aux_result);
        }
        else
        {
            // mostrar linea de error
            if (get_tipo(aux_result) != INT)
            {
                notificaciones(301);
                mostrarData(aux_result);
                exit(1);
            }
            if (get_tipo(list_result) != LIST)
            {
                notificaciones(10002);
                exit(1);
            }
        }
        break;
    }
    case TAKE:
    {
        if (get_tipo(aux_result) == INT && get_tipo(list_result) == LIST)
        {
            int posicion = get_value(aux_result);
            if (posicion > tamanio(list_result))
            {
                notificaciones(10000);
                mostrarData(list_result);
                exit(1);
            }
            else
            {
                nuevo = elemento_pos(list_result, posicion);
            }
        }
        else
        {
            // mostrar linea de error
            if (get_tipo(aux_result) != INT)
            {
                notificaciones(10001);
                mostrarData(aux_result);
                exit(1);
            }
            if (get_tipo(list_result) != LIST)
            {
                notificaciones(10002);
                mostrarData(list_result);
                exit(1);
            }
        }
        break;
    }
    case CONCAT:
    {
        if (get_tipo(aux_result) == LIST && get_tipo(list_result) == LIST)
        {
            nuevo = concat_list(aux_result, list_result);
        }
        else
        {
            notificaciones(10003);
            exit(1);
        }
        break;
    }
    default:
        printf("\nError papu 2."); /* no entra nunca creo */
        break;
    }
    return nuevo;
}
tData evalOpSet(struct ast *a)
{
    struct ast *left = a->l;
    struct ast *right = a->r;

    tData nuevo = NULL;

    tData conj_1 = eval(left);
    tData conj_2 = eval(right);

    if (!conj_1 || !conj_2)
    {
        notificaciones(9000);
        exit(1);
    }
    if (get_tipo(conj_1) != SET || get_tipo(conj_2) != SET)
    {
        printf("Operacion valida solo para conjuntos\n");
        return NULL;
    }

    switch (get_nodetype(a))
    {
    case UNION:
        nuevo = Union(conj_1, conj_2);
        break;
    case DIFF:
        nuevo = Diferencia(conj_1, conj_2);
        break;
    case INTER:
        nuevo = Interseccion(conj_1, conj_2);
        break;
    case CONTAINS:
        if (contenido(conj_1, conj_2))
        {
            nuevo = createBool("true");
        }
        else
        {
            nuevo = createBool("false");
        }
        break;
    default:
        printf("Operacion no encontrada papu.\n"); /*no entra realmente */
        break;
    }
    return nuevo;
}

/*=======================================================================*/
/*                      AST working BUILT-IN-FUNCTIONS                   */
/*=======================================================================*/
tData eval_built_in_function(struct ast* a)
{
    struct ast* left  = a->l;
    struct ast* right = a->r;

    tData nuevo = NULL;
    switch (get_nodetype(a))
    {
        case PRINT:
        {
            if(left != NULL)
            {
                mostrarData(eval(left));printf("\n");
            }
            break;
        
        }
        case RETURN:
        {
            if(left != NULL)
            {
                printf("output: "); mostrarData(eval(left));printf("\n");
            }
            break;
        }
        default:
        {
            printf("error nodetype desconocido eval_built_in_function\n");
            break;
        }
    }
         
    return nuevo;
}

tData eval(struct ast *a)
{
    if (!a)
    {
        printf("error puntero null en eval\n\n\n");
        return NULL;
    }
    struct ast *right = a->r;
    struct ast *left = a->l;
    tData nuevo;

    switch (get_nodetype(a))
    {
    case INT:
    case STR:
    case DOUBLE: /*newast(INT, NULL, NULL, $1)*/
    case BOOL:
    {
        if (!a->d)
        {
            printf("ERROR: Literal sin dato\n");
            exit(1);
        }
        nuevo = a->d; // copiar? free?
        break;
    }

    case LIST:
    {
        nuevo = eval_list(a);
        break;
    }
    case SET:
    {
        nuevo = eval_set(a);
        break;
    }

    case '+':
    case '-':
    case '*':
    case '/':
    case '%':
    {
        tData eval_r, eval_l; // printf(" MUERE AQUI 3 ");
        eval_r = eval(right);
        eval_l = eval(left);
        
        if (!eval_l || !eval_r)
        {
            printf("Run-Time Error\n");
            nuevo = NULL;
            exit(1);
        }
        if (get_tipo(eval_r) != BOOL && get_tipo(eval_r) != STR && get_tipo(eval_r) != LIST && get_tipo(eval_r) != SET && get_tipo(eval_l) != BOOL && get_tipo(eval_l) != STR && get_tipo(eval_l) != SET && get_tipo(eval_l) != LIST)
        {
            switch (get_nodetype(a))
            {
            case '+':
                nuevo = sumaData(eval_l, eval_r);
                break;
            case '-':
                nuevo = restaData(eval_l, eval_r);
                break;
            case '*':
                nuevo = prodData(eval_l, eval_r);
                break;
            case '/':
                nuevo = cocData(eval_l, eval_r);
                break;
            case '%':
                nuevo = modData(eval_l, eval_r);
                break;
            default:
                break;
            }
        }
        else
        {
            printf("Error semantico: Solo operaciones entre numeros.");
            exit(1);
        }
        break;
    }

    case MENOS_UNARIO:
    {
        tData eval_left = eval(left);
        if (!eval_left)
        {
            printf("Run-Time Error\n");
            exit(1);
        }
        nuevo = negar_data(eval_left);
        break;
    }

    case MODULO:
    {
        tData eval_left = eval(left);
        if (!eval_left)
        {
            printf("Eun-Time Error\n");
            exit(1);
        }
        nuevo = modulo_data(eval_left);
        break;
    }

    case MAYOR:
    case MENOR:
    case MAYOR_IGUAL:
    case MENOR_IGUAL:
    case IGUAL:
    case DISTINTO:
    {
        tData eval_left = eval(left);
        tData eval_right = eval(right);
        if (!eval_left || !eval_right)
        {
            printf("Run-Time Error \n");
            nuevo = NULL;
            exit(1);
        }
        nuevo = compute_op_rel(get_nodetype(a), eval_left, eval_right);

        break;
    }

    case KICK:
    case ADD:
    case CONCAT:
    case TAKE:
    {
        nuevo = evalOpList(a);
        break;
    }

    case UNION:
    case INTER:
    case DIFF:
    case CONTAINS:
    {
        nuevo = evalOpSet(a);
        break;
    }

    case IN:
    {
        tData aux1 = eval(left);
        tData aux2 = eval(right);
        if (aux1 == NULL)
        {
            printf("puntero null en exp IN exp\n");
            nuevo = NULL;
            break;
        }
        if (get_tipo(aux2) == SET || get_tipo(aux2) == LIST)
        {
            if (pertenece_completing(aux1, aux2))
            {
                nuevo = createBool("true");
            }
            else
            {
                nuevo = createBool("false");
            }
        }
        else
        {
            printf("Error Semantic, IN solo funciona para listas o conjuntos\n");
            nuevo = NULL;
            exit(1);
        }
        break;
    }
    case AND:
    case OR:
    case NOT:
    {
        nuevo = eval_log(a);
        break;
    }

    case IF:
    case WHILE:
    case FORALL:
    case FORANY:
    {
        nuevo = eval_flow((struct flow *)a);
        break;
    }

    case ASIGNACION:
    case VAR_REF:
    case FN_CALL:
    case ASSIGN_MULTIPLE:
    {
        nuevo = eval_memory_ast((struct memory_ast *)a);
        break;
    }

    case GET:
    {
        tData pos_data = eval(left);
        tData conj_aux = eval(right);

        if (get_tipo(pos_data) != INT || get_tipo(conj_aux) != SET)
        {
            if (get_tipo(pos_data) != INT)
            {
                notificaciones(301);
                mostrarData(pos_data);
                exit(1);
            }
            if (get_tipo(conj_aux) != SET)
            {
                notificaciones(11000);
                mostrarData(conj_aux);
                exit(1);
            }
        }

        int pos = get_value(pos_data);

        if (pos > tamanio(conj_aux))
        {
            mostrarData(conj_aux);
            printf(" es demesiada pequeña para eliminiar su elem en posicion: %d\n", pos);
            exit(1);
        }

        nuevo = elemento_pos(conj_aux, pos);

        break;
    }

    case BLOCK:
    {
        /*while (get_nodetype(a) == BLOCK)
        {
            nuevo = eval(a->l);
            a = a->r;
        }
        nuevo = eval(a);*/
        eval(left);
        nuevo = eval(right);
        break;
    }
    case PRINT: case RETURN:
    {
        nuevo = eval_built_in_function(a);
        break;
    }
    default:
    {
        printf("Error papu.");
        break;
    }
    }
    // printf("nuevo: ");mostrarData(nuevo);printf("\n");
    return nuevo;
}

/*=======================================================================*/
/*                          SYMBOL DEFINITION                            */
/*=======================================================================*/
unsigned int symhash(char *sym)
{
    unsigned int hash = 0;
    int c;
    while (c = *sym)
    {
        hash = (hash * 9) ^ c;
        sym++;
    }
    return hash;
}
struct symbol *lookup(char *sym)
{
    struct symbol *sp = &symtab[symhash(sym) % NHASH]; // sp: symbol pointer
    struct symbol s = *sp;
    int count = 1;

    while (count <= NHASH)
    {
        if (!s.name) // celda vacia
        {
            s.name = strdup(sym);
            s.data = NULL;
            // agregar para args y body
            return sp;
        }
        else if (!strcmp(s.name, sym)) // 0 son iguales
        {
            return sp;
        }
        else
        {
            sp++;
            if (sp >= symtab + NHASH)
                sp = symtab; // aritmetica modular
            count++;
        }
    }
    printf("Overflow tabla de simbolos \n");
    return NULL;
}
void add_definition(struct symbol *s, struct symlist *sl, struct ast *body)
{
    if (s->args)
    {
        free_symlist(s->args);
    }
    if (s->body)
    {
        // treefree(s->body);
    }
    s->args = sl;
    s->body = body;
}
/*=======================================================================*/

/*=======================================================================*/
/*                          SYMLIST DEFINITION                           */
/*=======================================================================*/
struct symlist *addsym(struct symbol *s, struct symlist *sl)
{
    struct symlist *lista = malloc(sizeof(struct symlist));
    if (!lista)
    {
        printf("error en addsym sin memoria\n");
        return NULL;
    }
    lista->s = s;
    lista->next = sl;
    return lista;
}
void free_symlist(struct symlist *sl)
{
    if (!sl)
    {
        return;
    }
    struct symlist *next = sl->next;
    free(sl);
    free_symlist(next);
    /*struct symlist* next;
    while (sl)
    {
        next = sl->next;
        free(sl);
        sl = next;
    }
    */
}
int compute_size(struct symlist *sl)
{
    if (!sl)
    {
        printf("posible error puntero null en compute_size\n");
        return 0;
    }
    int size = 0;
    while (sl)
    {
        size++;
        sl = sl->next;
    }
    return size;
}
/*=======================================================================*/

int yyerror(char *s)
{
    fprintf(stderr, "Error de sintaxis: %s", s);
}

void notificaciones(int caso)
{
    switch (caso)
    {
    /*Errores de memoria*/
    case 8000:
        printf("\nError 8000: Puntero nulo en get_nodetype().\n");
        break;
    case 8001:
        printf("\nError 8001: Sin memoria en newast. \n");
        break;
    case 8002:
        printf("\nError 8002: Sin memoria para estructura de control.");
        break;
    case 8003:
        printf("\nError 80003: Sin en estructura newmemory.\n");
        break;
    case 8004:
        printf("\nError 8004: Puntero nulo.\n");
        break;
    case 8005:
        printf("\nError 8005: Referencia a variable no inicializada.\n");
        break;
    /*Error *e ejecucion*/
    case 9000:
        printf("\nError 9000: Error de ejecucion. Revise la entrada de datos.\n");
        break;
    /*Error operaciones entre listas*/
    case 10000:
        printf("\nError 300: La posicion es mayor al tamanio de la lista.\n");
        break;
    case 10001:
        printf("\nError 301: El primer elemento debe ser un tipo INT.\n");
        break;
    case 10002:
        printf("\nError 302: El segundo elemento debe ser tipo LIST.\n");
        break;
    case 10003:
        printf("\nError 303: Solo se pueden concatenar LIST.\n");
        break;
    /*Error operaciones entre conjuntos*/
    case 11000:
        printf("\nError 400 El segundo elemento debe ser tipo SET.\n");
        break;
        /*Error operaciones relacionales*/

    case 14000:
        printf("Error 500: Variable no inicializada en assignacion multiple. \n");
        break;
    case 14001:
        printf("Error solo se puede desempaquetar listas o conjuntos.\n");
        break;
    case 14002:
        printf("Error no se puede desempaquetar tanto elementos como necesita.\n");
        break;
    default:
        printf("error en notificaciones no conido %d", caso);
        break;
    }
}