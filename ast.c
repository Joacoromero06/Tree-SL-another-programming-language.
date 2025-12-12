#include "ast.h"
#include "defs.h"
#include "data.h"
#include "env.h"
void notificaciones(int);
/*=======================================================================*/
/*                             AST DEFINITION                            */
/*=======================================================================*/
Ast *newast(int nodoValue, Ast *left, Ast *right, tData data)
{
    Ast *nuevo = malloc(sizeof(Ast));
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
int get_nodetype(Ast *a)
{
    if (!a)
    {
        notificaciones(8000);
        return 0;
    }
    return a->nodetype;
}
void set_nodetype(Ast **p_a, int nodetype)
{
    if (!p_a)
    {
        astError("puntero/referencia null en set_nodetype");
        return;
    }
    (*p_a)->nodetype = nodetype;
    printf("setee el nodetype correctamente %d", (*p_a)->nodetype);
}
int get_widht(Ast *a)
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
    widht++; // the lAst Ast != LIST_OF_Ast
    return widht;
}
void walk(Ast **p_a)
{
    if (!p_a)
    {
        astError("referencia null en walk()");
        return;
    }
    (*p_a) = (*p_a)->r;
}
/*=======================================================================*/

/*=======================================================================*/
/*                             FLOW DEFINITION                           */
/*=======================================================================*/
Ast *newflow(int nodetype, Ast *cond, Ast *tbody, Ast *fbody, Ast *iterable, char *iterator)
{
    AstFlow *a = malloc(sizeof(AstFlow));
    if (!a)
    {
        notificaciones(8002);
        return NULL;
    }
    a->nodetype = nodetype;
    a->cond = cond;
    a->iterable = iterable;
    a->tbody = tbody;
    a->fbody = fbody;
    a->iterator = iterator;
    return (Ast *)a;
}
/*=======================================================================*/
/*                         MEMORY AST DEFINITION                         */
/*=======================================================================*/
IdList *newIdList(char *name, IdList *sig)
{
    IdList *new = malloc(sizeof(IdList));
    if (!new)
    {
        astError("sin memoria en neIdList()");
        exit(1);
    }
    new->name = name;
    new->sig = sig;
    return new;
}
void deleteIdList(IdList *l)
{
    IdList *temp;
    while (l != NULL)
    {
        temp = l;
        l = l->sig;
        free(temp->name);
        free(temp);
    }
}
Ast *newmemory_ast(int nodetype, char *name, Ast *a, IdList *list_id)
{
    AstMemory *new = malloc(sizeof(AstMemory));
    if (!new)
    {
        astError("sin memoria en newmemory_ast");
        return NULL;
    }
    new->nodetype = nodetype;
    new->name = name;
    new->a = a;
    new->list_id = list_id;
    return (Ast *)new;
}
void avanzo_IdList(IdList **pp)
{
    if (!pp)
    {
        astError("puntero null en avanzo_IdList");
        exit(1);
    }
    if (!(*pp))
    {
        astError("intento de avanzo de null");
        return;
    }
    *pp = (*pp)->sig;
}
/*=======================================================================*/
/*=======================================================================*/
/*                     SUBPROGRAM AST DEFINITION                         */
/*=======================================================================*/
Ast *newFNast(int nodetype, char *name, ArgList *args)
{
    AstSubprogram *new = malloc(sizeof(AstSubprogram));
    if (!new)
    {
        astError("sin memoria en newFNast()");
        exit(1);
    }
    new->nodetype = nodetype;
    new->name = name;
    new->args = args;
    return (Ast *)new;
}
/*=======================================================================*/

void freetree(Ast *a)
{
}

void astError(char *error)
{
    printf("Error en Ast: %s\n\n", error);
}
