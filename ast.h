#include "data.h"
#include <stdio.h>
#include <stdlib.h>


/*=======================================================================*/
/*                             AST DEFINITION                            */
/*=======================================================================*/
struct ast{
    int nodetype;
    struct ast* l;
    struct ast* r;
    tData d;
};
struct ast* newast(int, struct ast*, struct ast*, tData);
int get_nodetype(struct ast*);
int get_widht(struct ast*);
/*=======================================================================*/

/*=======================================================================*/
/*                             FLOW DEFINITION                           */
/*=======================================================================*/
struct flow{
    int nodetype;
    struct ast* cond;
    struct ast* iterable;
    struct ast* tblock;
    struct ast* fblock;
    struct symbol* s;
};
struct ast* newflow(int, struct ast*, struct ast*, struct ast*, struct ast*, struct symbol*);
/*=======================================================================*/


/*=======================================================================*/
/*                          SYMLIST DEFINITION                           */
/*=======================================================================*/
struct symlist {
    struct symbol* s;
    struct symlist* next;
};
struct symlist* addsym(struct symbol*, struct symlist*);
void free_symlist(struct symlist*);
int compute_size(struct symlist*);
/*=======================================================================*/

/*=======================================================================*/
/*                          SYMBOL DEFINITION                            */
/*=======================================================================*/
struct symbol{
    char* name;
    tData data;
    struct symlist* args;
    struct ast* body;
};
struct symbol* lookup(char* sym);
void add_definition(struct symbol*, struct symlist*, struct ast*);
#define NHASH 9997
/*=======================================================================*/

/*=======================================================================*/
/*                      AST working MEMORY DEFINITION                    */
/*=======================================================================*/
struct memory_ast{
    int nodetype;
    struct symbol* s;
    struct ast* a; // value | body | params actuales
};
struct ast* newmemory_ast(int, struct symbol*, struct ast*);
/*=======================================================================*/

tData eval(struct ast*);

int yyerror(char*);

void notificaciones(int);