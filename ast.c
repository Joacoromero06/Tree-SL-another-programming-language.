#include "ast.h"
#include "data.h"
#include "defs.h"

struct symbol symtab[NHASH];

int get_nodetype(struct ast *a)
{
    if (!a)
    {
        yyerror("Error en get_nodettype() puntero nulo");
        return 0;
    }
    return a->nodetype;
}

struct ast *newast(int nodoValue, struct ast *left, struct ast *right, tData data)
{
    struct ast *nuevo = malloc(sizeof(struct ast));
    if (!nuevo)
    {
        yyerror("sin memoria en newast");
        return NULL;
    }
    nuevo->nodetype = nodoValue;
    nuevo->l = left;
    nuevo->r = right;
    nuevo->d = data;
    return nuevo;
}
struct ast *newflow(int nodetype, struct ast *cond, struct ast *iterable, struct ast *tblock, struct ast *fblock, struct symbol *s)
{
    struct flow *a = malloc(sizeof(struct flow));
    if (!a)
    {
        printf("error malloc newflow\n");
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
struct ast *newmemory_ast(int nodetype, struct symbol *s, struct ast *a)
{
    struct memory_ast *nvo = malloc(sizeof(struct memory_ast));
    if (!nvo)
    {
        printf("sin memoria en newmemory_ast\n");
        return NULL;
    }
    nvo->nodetype = nodetype;
    nvo->s = s;
    nvo->a = a;
    return (struct ast *)nvo;
}

tData eval_list(struct ast *a) // no semantic errors
{
    // a = newast(LIST, list_exp, NULL, createData(LIST));
    // listt_exp = newast(LIST_OF_AST, $1, $3, NULL);

    if (!a->l)
        return a->d; // lista vacia se va directo
    tData *list_to_load = &(a->d);
    struct ast *nav = a->l;

    while (get_nodetype(nav) == LIST_OF_AST)
    {
        agregarData(list_to_load, eval(nav->l));
        nav = nav->r;
    }
    agregarData(list_to_load, eval(nav));
    return (*list_to_load);
}
tData eval_set(struct ast *a)  // no semantic errors
{
    if (!a->l)
    {
        return a->d; // lista vacia se va directo
    }
    tData *set_to_load = &(a->d);
    struct ast *nav = a->l;
    while (get_nodetype(nav) == LIST_OF_AST)
    {
        agregarData(set_to_load, eval(nav->l));
        nav = nav->r;
    }
    agregarData(set_to_load, eval(nav));
    return (*set_to_load);
}

tData evalOpList(struct ast *a)
{
    struct ast *left = a->l;
    struct ast *right = a->r;

    tData nuevo = NULL;

    tData aux_result = eval(left);
    tData list_result = eval(right);

    switch (get_nodetype(a))
    {
    case KICK:
    {
        if (get_tipo(aux_result) == INT && get_tipo(list_result) == LIST)
        {
            nuevo = (list_result);
            int posicion = get_value(aux_result); // eval(left)
            if ( posicion > tamanio(nuevo) )
            {
                printf("Error semantico."); mostrarData(list_result); printf(" es demesiada pequeña para eliminiar su elem en posicion: %d\n", posicion);
            }
            else
            {
                eliminar_pos(&nuevo, posicion);
            }
        }
        else
        {
            // mostrar linea de error
            if ( get_tipo(aux_result) != INT  )
            {
                printf("Error semantico. "); mostrarData(aux_result); printf(" debe ser entero");
            }
            if ( get_tipo(list_result) != LIST )
            {
                printf("Error semantico. "); mostrarData(list_result); printf(" debe ser lista");
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
            if ( get_tipo(aux_result) != INT  )
            {
                printf("Error semantico. "); mostrarData(aux_result); printf(" debe ser entero");
            }
            if ( get_tipo(list_result) != LIST )
            {
                printf("Error semantico. "); mostrarData(list_result); printf(" debe ser lista");
            }
        }
        break;
    }
    case TAKE:
    {
        if (get_tipo(aux_result) == INT && get_tipo(list_result) == LIST)
        {
            int posicion = get_value(aux_result);
            if ( posicion > tamanio(nuevo) )
            {
                printf("Error semantico."); mostrarData(list_result); printf(" es demesiada pequeña para obtener su elem en posicion: %d\n", posicion);
            }
            else
            {
                nuevo = elemento_pos(list_result, posicion);
            }
        }
        else
        {
            // mostrar linea de error
            if ( get_tipo(aux_result) != INT  )
            {
                printf("Error semantico."); mostrarData(aux_result); printf(" debe ser entero");
            }
            if ( get_tipo(list_result) != LIST )
            {
                printf("Error semantico."); mostrarData(list_result); printf(" debe ser lista");
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
            printf("Erorr semantico solo se puede concatenar dos listas\n");
        }
        break;
    }
    default:
        printf("\nError papu 2.");
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
        printf("Operacion no encontrada papu.\n");
        break;
    }
    return nuevo;
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
    }
    case FORALL:
    {
        tData data_iterable = copiarData(eval(iterable));
        int tam = tamanio(data_iterable);
        for (int i = 1; i < tam; i++) // forall ( x in [1,2] | x ) do 2 + 2 end // chequear i
        {
            tData elem_i = elemento_pos(data_iterable, i); // añadir que funcione para SET
            s->data = copiarData(elem_i);

            if ( get_bool_value(eval( cond )) )
            {
                nuevo = eval(tblock);
            }
        }
    }
    default:
        break;
    }
    return nuevo;
}

tData eval_memory_ast(struct memory_ast * arbol)
{
    if (!arbol)
    {
        printf("puntero nulo en eval_memory_ast\n");
        return NULL;
    }

    tData nuevo = NULL;
    struct ast* a    = arbol->a;
    struct symbol* s = arbol->s;

    switch (get_nodetype( (struct ast*) arbol ))
    {
    case ASIGNACION:
        nuevo = eval(a);
        s->data = copiarData(nuevo);
        break;
    case VAR_REF:
        nuevo = copiarData(s->data); // sin copiar ?
        if (nuevo == NULL)
        {
            printf("Error referencia a variable no inicializada");
        }
        break;
    default:
        printf("nodetype desconocido en eval_memory_ast\n");
        break;
    }
    return nuevo;
}

tData eval(struct ast *a)
{
    if (!a)
    {
        printf("error puntero null en eval\n");
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
    {
        tData eval_r, eval_l; // printf(" MUERE AQUI 3 ");
        eval_r = eval(right);
        eval_l = eval(left);
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
            default:
                break;
            }
        }
        else
            printf("Error semantico: Solo operaciones entre numeros.");
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
        }
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
    {
        nuevo = eval_memory_ast((struct memory_ast *)a);
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

int yyerror(char *s)
{
    fprintf(stderr, "Error de sintaxis: %s", s);
}