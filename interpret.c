#include "interpret.h"
#include <string.h>
#include "ast.h"
#include "data.h"
#include "defs.h"
SpEnv* SUBPROGRAM_ENV = NULL;


/*==================================================================*/
/*                              EVAL                                */
/*==================================================================*/
tData eval_list(Ast *a, Env *e)
{
    tData nuevo = createData(LIST);
    if (!a->l)
        return createData(LIST); // lista vacia se va directo
    Ast *nav = a->l;
    while (get_nodetype(nav) == LIST_OF_AST)
    {
        agregarData(&nuevo, eval(nav->l, e));
        nav = nav->r;
    }
    agregarData(&nuevo, eval(nav, e));
    return nuevo;
}
tData eval_set(Ast *a, Env *e)
{
    if (!a->l)
        return createData(SET); // lista vacia se va directo

    tData nuevo = createData(SET);
    Ast *nav = a->l;
    while (get_nodetype(nav) == LIST_OF_AST)
    {
        agregarData(&nuevo, eval(nav->l, e));
        nav = nav->r;
    }
    agregarData(&nuevo, eval(nav, e));
    return nuevo;
}

tData evalOpList(Ast *a, Env *e)
{
    Ast *left = a->l;
    Ast *right = a->r;

    tData nuevo = NULL;

    tData aux_result = eval(left, e);
    tData list_result = eval(right, e);

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
            nuevo = copiarData(list_result);
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
                nuevo = copiarData(elemento_pos(list_result, posicion));
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
    freeData(aux_result);
    freeData(list_result);

    return nuevo;
}
tData evalOpSet(Ast *a, Env *e)
{
    Ast *left = a->l;
    Ast *right = a->r;

    tData nuevo = NULL;

    tData conj_1 = eval(left, e);
    tData conj_2 = eval(right, e);

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

    freeData(conj_1);
    freeData(conj_2);

    return nuevo;
}

tData eval_log(Ast *a, Env *e)
{

    if (!a)
    {
        debugEval("Ast null en eval_log");
        exit(1);
    }
    if (!a->l || !a->r)
    {
        notificaciones(9000); // no deberia pasar
        exit(1);
    }

    tData A = eval(a->l, e);
    tData B = eval(a->r, e);

    tData nuevo = NULL;

    switch (get_nodetype(a))
    {

    case AND:
    {
        if (get_bool_value(A) && get_bool_value(B))
        {
            nuevo = createBool("true");
        }

        nuevo = createBool("false");
        break;
    }

    case OR:
    {
        if (get_bool_value(A) || get_bool_value(B))
        {
            nuevo = createBool("true");
        }

        nuevo = createBool("false");
        break;
    }

    case NOT:
    {
        nuevo = (get_bool_value(B)) ? createBool("false") : createBool("true");
        break;
    }
    }

    freeData(A);
    freeData(B);

    return nuevo;
}
tData eval_rel(Ast *a, Env *e)
{
    if (!a)
    {
        debugEval("Ast null en compute_op_rel");
        return NULL;
    }
    int nodetype = a->nodetype;

    tData eval_left = eval(a->l, e);
    tData eval_right = eval(a->r, e);

    if (!eval_left || !eval_right)
    {
        printf("puntero null en compara_menor");
        return NULL;
    }

    tData nuevo = NULL;
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

    freeData(eval_left);
    freeData(eval_right);
    return nuevo;
}

tData eval_memoryast(AstMemory *ast, Env *e)
{
    if (!ast)
    {
        printf("error puntero null en eval\n\n\n");
        return NULL;
    }
    char *name = ast->name;
    Ast *a = ast->a;

    tData nuevo = NULL;

    switch (get_nodetype((Ast *)ast))
    {
    case REFERENCE:
    {
        if (is_binded(name, e))
        {
            nuevo = copiarData(reference(name, e));
        }
        else
        {
            notificaciones(8005);
            exit(1);
        }
        break;
    }
    case ASSIGN:
    {
        tData rhs = eval(a, e);
        nuevo = copiarData(rhs);
        binding(name, rhs, e);

        break;
    }
    default:
    {
        debugEval("puntero null en eval_memoryast()");
        break;
    }
    }
    // free(name);
    return nuevo;
}
static void compute_argXvalue(ArgList *args, Env *e)
{
    while (args != NULL)
    {
        if (args->arg && args->arg->tipo == xVALOR)
        {
            args->arg->data = eval(args->arg->a, e);
        }
        args = args->sig;
    }
}
static void make_bindings(ParamList *params, ArgList *args, Env *old_e, Env *new_e)
{
    Argument *arg_i;
    Parameter *param_i;
    while (params && args)
    {
        arg_i = args->arg;
        param_i = params->param;
        if (param_i->tipo == xREFERENCIA && arg_i->tipo == xREFERENCIA)
        {
            binding(strdup(param_i->name_ref), reference(arg_i->name, old_e), new_e);
            tData x_old = reference(arg_i->name, old_e);
            tData x_new = reference(param_i->name_ref, new_e);
        }
        else if (param_i->tipo == xVALOR && arg_i->tipo == xVALOR)
            binding(strdup(param_i->name_val), copiarData(arg_i->data), new_e);
        else if (param_i->tipo == xVALOR)
        {
            notificaciones(18);
            exit(1);
        }
        else
        {
            notificaciones(19);
            exit(1);
        }
        params = params->sig;
        args = args->sig;
    }
    if (args!=NULL)
    {
        notificaciones(20); exit(1);
    }
    while (params!=NULL)
    {
        param_i = params->param;
        if(param_i->tipo == xVALOR && param_i->defaul)
            binding(param_i->name_val, param_i->data, new_e);
        else 
            notificaciones(21); exit(1);
        params= params->sig;
    }
    
}
tData eval_fn(char *name, ArgList *args, Env *e)
{
    if (!is_binded_SP(name, SUBPROGRAM_ENV))
    {
        notificaciones(15);
        free(name);
        deleteArgList(args);
        exit(1);
    }
    
    SubProgram *f = reference_SP(name, SUBPROGRAM_ENV);
    compute_argXvalue(args, e);

    Env *new_e = newEnv(e);
    make_bindings(f->params, args, e, new_e);
    
    ExecResult r = exec(f->body, new_e);
    
    if (ReturnValue(r) == NULL)
    {
        notificaciones(16);
        deleteArgList(args);
        deleteEnv(new_e);
        exit(1);
    }
    
    //deleteArgList(args);
    deleteEnv(new_e);
    return ReturnValue(r);
}

tData eval(Ast *a, Env *e)
{
    if (!a)
    {
        printf("error puntero null en eval\n\n\n");
        return NULL;
    }
    Ast *right = a->r;
    Ast *left = a->l;
    tData nuevo = NULL;
    
    switch (get_nodetype(a))
    {
    case REFERENCE:
    case ASSIGN:
    {
        nuevo = eval_memoryast((AstMemory *)a, e);
        break;
    }

    case INT:
    case STR:
    case DOUBLE: /*newAst(INT, NULL, NULL, $1)*/
    case BOOL:
    {
        if (!a->d)
        {
            printf("ERROR: Literal sin dato\n");
            exit(1);
        }
        nuevo = copiarData(a->d); // copiar? free?
        break;
    }

    case LIST:
    {
        nuevo = eval_list(a, e);
        break;
    }
    case SET:
    {
        nuevo = eval_set(a, e);
        break;
    }

    case '+':
    case '-':
    case '*':
    case '/':
    case '%':
    {
        tData eval_r, eval_l; // printf(" MUERE AQUI 3 ");
        eval_r = eval(right, e);
        eval_l = eval(left, e);

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
        // freeData(eval_l);
        // freeData(eval_r);
        break;
    }

    case MENOS_UNARIO:
    {
        tData eval_left = eval(left, e);
        if (!eval_left)
        {
            printf("Run-Time Error\n");
            exit(1);
        }
        nuevo = negar_data(eval_left);
        freeData(eval_left);
        break;
    }

    case MODULO:
    {
        tData eval_left = eval(left, e);
        if (!eval_left)
        {
            printf("Eun-Time Error\n");
            exit(1);
        }
        nuevo = modulo_data(eval_left);

        freeData(eval_left);

        break;
    }

    case MAYOR:
    case MENOR:
    case MAYOR_IGUAL:
    case MENOR_IGUAL:
    case IGUAL:
    case DISTINTO:
    {
        nuevo = eval_rel(a, e);
        break;
    }

    case KICK:
    case ADD:
    case CONCAT:
    case TAKE:
    {
        nuevo = evalOpList(a, e);
        break;
    }

    case UNION:
    case INTER:
    case DIFF:
    case CONTAINS:
    {
        nuevo = evalOpSet(a, e);
        break;
    }

    case IN:
    {
        tData aux1 = eval(left, e);
        tData aux2 = eval(right, e);
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

        freeData(aux1);
        freeData(aux2);

        break;
    }

    case AND:
    case OR:
    case NOT:
    {
        nuevo = eval_log(a, e);
        break;
    }

    case GET:
    {
        tData pos_data = eval(left, e);
        tData conj_aux = eval(right, e);

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

        freeData(pos_data);
        freeData(conj_aux);

        break;
    }

    case EXP_FUNCTION:
        nuevo = eval_fn(((AstSubprogram *)a)->name, ((AstSubprogram *)a)->args, e);
        break;
    default:
    {
        printf("Error papu.");
        break;
    }
    }
    return nuevo;
}
/*==================================================================*/

/*==================================================================*/
/*                      EXECUTION RESULT                            */
/*==================================================================*/
ExecResult new_ER(ExecResult_Tipo tipo, tData return_value)
{
    return (ExecResult){tipo, return_value};
}
ExecResult_Tipo ResultType(ExecResult result)
{
    return result.type;
}
tData ReturnValue(ExecResult result)
{
    if (ResultType(result) != RETURN)
    {
        debugExec("ResultType no es RETURN en ReturnValue()\n");
        return NULL;
    }
    return result.return_value;
}
/*==================================================================*/

/*==================================================================*/
/*                              EXEC                                */
/*==================================================================*/
ExecResult exec_flow(AstFlow *a, Env *e)
{
    /*a->cond;
    a->iterable;
    a->tbody;
    a->fbody;
    a->iterator*/
    tData cond_data = NULL;
    ExecResult r;

    switch (get_nodetype((Ast *)a))
    {
    case IF:
    {
        cond_data = eval(a->cond, e);
        if (get_bool_value(cond_data))
            r = exec(a->tbody, e);
        else if (a->fbody != NULL)
            r = exec(a->fbody, e);
        else
            r = new_ER(NORMAL, NULL);

        freeData(cond_data);
        break;
    }
    case WHILE:
    {
        int c = 0;
        r = new_ER(NORMAL, NULL); // caso while no entra
        cond_data = eval(a->cond, e);

        while (get_bool_value(cond_data))
        {
            freeData(cond_data);
            r = exec(a->tbody, e);

            switch (ResultType(r))
            {
            case RETURN:
                return r;
                break;
            case BREAK:
                return new_ER(NORMAL, NULL);
                break;
            case CONTINUE:
            case NORMAL:
                cond_data = eval(a->cond, e);
                break;
            default:
                debugExec("tipo resultype desconocido en exec_flow");
                break;
            }

            if (++c == MAX_ITER)
            {
                printf("max iter: %d", c);
                notificaciones(10);
                exit(1);
            }
        }
        break;
    }
    case FORALL:
    {
        tData iterable = eval(a->iterable, e);
        if (iterable == NULL)
        {
            debugExec("error interno exec -> eval -> NULL");
            exit(1);
        }
        if (!es_struct(iterable))
        {
            notificaciones(11);
            exit(1);
        }

        tData iterable_cab = iterable, old_data = NULL;
        if (empty_struct(iterable))
        {
            freeData(iterable);
            return new_ER(NORMAL, NULL);
        }

        if (is_binded(a->iterator, e))
            old_data = copiarData(reference(a->iterator, e)); // transfiere OWS

        ExecResult r;
        while (iterable != NULL)
        {
            binding(a->iterator, copiarData(get_dato(iterable)), e); // no modifica iterable
            if (a->cond)
            {
                cond_data = eval(a->cond, e);
                if (get_bool_value(cond_data))
                    r = exec(a->tbody, e);
                else
                    r = new_ER(NORMAL, NULL);
                freeData(cond_data);
            }
            else
                r = exec(a->tbody, e);

            switch (ResultType(r))
            {
            case RETURN:
                iterable = NULL; // salir
                break;
            case BREAK:
            case CONTINUE:
                r = new_ER(NORMAL, NULL);
                iterable = NULL; // salir
                break;
            case NORMAL:
                avanzo_tData(&iterable);
                break;
            default:
                debugExec("result type desconocido en exec_flow");
                break;
            }
        }
        if (old_data != NULL)
            binding(a->iterator, old_data, e); // transfiere OWS
        freeData(iterable_cab);

        break;
    }
    case FORANY:
    {
        tData iterable = eval(a->iterable, e);
        if (!iterable)
        {
            debugExec("error interno exec -> eval -> NULL");
            exit(1);
        }
        if (!es_struct(iterable))
        {
            notificaciones(11);
            exit(1);
        }

        tData iterable_cab = iterable, old_value = NULL;
        if (empty_struct(iterable))
        {
            freeData(iterable);
            return new_ER(NORMAL, NULL);
        }
        if (is_binded(a->iterator, e))
            old_value = copiarData(reference(a->iterator, e));
        ExecResult r;
        boolean any = FALSE;
        while (iterable != NULL)
        {
            binding(a->iterator, copiarData(get_dato(iterable)), e);
            cond_data = eval(a->cond, e);
            if (get_bool_value(cond_data))
            {
                r = exec(a->tbody, e);
                iterable = NULL;
            }
            else
            {
                r = new_ER(NORMAL, NULL);
                avanzo_tData(&iterable);
            }
            freeData(cond_data);
        }
        switch (ResultType(r))
        {
        case RETURN:
            // retorna r {RETURN, tData}
            break;
        case BREAK:
        case CONTINUE:
        case NORMAL:
            r = new_ER(NORMAL, NULL);
            break;
        default:
            debugExec("result type desconocido en forany()");
            break;
        }
        freeData(iterable_cab);
        if (old_value != NULL)
            binding(a->iterator, old_value, e);
        break;
    }
    default:
    {
        debugExec("nodetype desconocido en exec_flow()");
        break;
    }
    }

    return r;
}
ExecResult exec(Ast *a, Env *e)
{
    if (!a)
    {
        debugExec("Ast null en exec()");
        exit(1);
    }

    ExecResult r;
    switch (get_nodetype(a))
    {
    case IF:
    case WHILE:
    case FORALL:
    case FORANY:
    {
        r = exec_flow((AstFlow *)a, e);
        break;
    }

    case EXP_STM:
    {
        freeData(eval(a->l, e));
        r = new_ER(NORMAL, NULL);
        break;
    }
    case BODY:
    {
        while (get_nodetype(a) == BODY)
        {
            r = exec(a->l, e);
            switch (ResultType(r))
            {
            case RETURN:
            case BREAK:
            case CONTINUE:
                return r;
            case NORMAL:
                walk(&a);
                break;
            default:
                debugExec("resultype desconocido en exec body");
                break;
            }
        }
        r = exec(a, e);
        break;
    }

    case RETURN_STM:
    {
        r = new_ER(RETURN, eval(a->l, e));
        break;
    }
    case BREAK_STM:
    {
        r = new_ER(BREAK, NULL);
        break;
    }
    case CONTINUE_STM:
    {
        r = new_ER(CONTINUE, NULL);
        break;
    }

    case PRINT:
    {
        tData v = eval(a->l, e);
        mostrarData(v);
        freeData(v);
        r = new_ER(NORMAL, NULL);
        break;
    }
    case PRINTLN:
    {
        tData v = eval(a->l, e);
        mostrarData(v);
        printf("\n");
        freeData(v);
        r = new_ER(NORMAL, NULL);
        break;
    }
    case MULT_ASSIGN:
    {
        AstMemory *ast = (AstMemory *)a;
        tData iterable = eval(ast->a, e);
        if (!es_struct(iterable))
        {
            notificaciones(13);
            freeData(iterable);
            exit(1);
        }
        if (empty_struct(iterable))
        {
            notificaciones(14);
            freeData(iterable);
            exit(1);
        }

        IdList *list_id = ast->list_id;
        while (list_id != NULL && iterable != NULL)
        {
            binding(strdup(list_id->name), copiarData(get_dato(iterable)), e);
            avanzo_IdList(&list_id);
            avanzo_tData(&iterable);
        }
        if (list_id != NULL) // iterable = NULL
        {
            notificaciones(14);
            freeData(iterable);
            exit(1);
        }
        freeData(iterable);
        r = new_ER(NORMAL, NULL);

        break;
    }
    case STM_PROCEDURE:
        r = exec_procedure( ((AstSubprogram*)a)->name, ((AstSubprogram*)a)->args, e);
        break;
    default:
    {
        debugExec("node type desconocido");
        printf("%d", get_nodetype(a));
        break;
    }
    }
    return r;
}
ExecResult exec_procedure(char* name, ArgList* args, Env* e)
{
    if(!is_binded_SP(name, SUBPROGRAM_ENV))
    {
        notificaciones(15);
        exit(1);
    }
    SubProgram* f = reference_SP(name, SUBPROGRAM_ENV);
    compute_argXvalue(args, e);

    Env* new_e = newEnv(e);
    make_bindings(f->params, args, e, new_e);

    ExecResult r = exec(f->body, new_e);
    if(ReturnValue(r) != NULL)
    {
        notificaciones(17);
        exit(1);
    }
    //deleteEnv(new_e);
    return r;
}
/*==================================================================*/

void notificaciones(int caso)
{
    switch (caso)
    {
    /*Errores de memoria*/
    case 10:
        printf("\nError 10: Max iteraciones alcanzado.\n");
        break;
    case 11:
        printf("\nError 11: Iterable debe ser una estructura.\n");
        break;
    case 12:
        break;
    case 13:
        printf("Error 13: solo se puede desempaquetar listas o conjuntos.\n");
        break;
    case 14:
        printf("Error 14: no se puede desempaquetar tanto elementos como necesita.\n");
        break;
    case 15:
        printf("Error 15: llamada a subprgrama no definido\n");
        break;
    case 16:
        printf("Error 16: funcion debe retornar un valor\n");
        break;
    case 17:
        printf("Error 17: procedimiento no retorna un valor\n");
        break;
    case 18:
        printf("Error 18: el argumento debe ser por valor\n");
        break;
    case 19:
        printf("Error 19: el argumento debe ser por referencia\n");
        break;
        case 20:
        printf("Error 20: Demasiados argumentos para la llamada del subprograma\n");
        break;
        case 21:
        printf("Error 21: Pocos argumentos para la llamada del subprograma\n");
        break;
    case 8000:
        printf("\nError 8000: Puntero nulo en get_nodetype().\n");
        break;
    case 8001:
        printf("\nError 8001: Sin memoria en newAst. \n");
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
    default:
        printf("error en notificaciones no conido %d", caso);
        break;
    }
}

void debugExec(char *error)
{
    fprintf(stderr, "[DEBUG] in function exec(): %s\n", error);
}
void debugEval(char *error)
{
    fprintf(stderr, "[DEBUG] in function eval(): %s \n", error);
}