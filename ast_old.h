#include "data.h"
#include <stdio.h>
#include <stdlib.h>

/*=======================================================================*/
/*                          SYMLIST DEFINITION                           */
/*=======================================================================*/
typedef struct symlist {
    struct symbol* s;
    struct symlist* next;
} SYM_LIST;
SYM_LIST* addsym(struct symbol*, SYM_LIST*);
void free_symlist(SYM_LIST*);
int compute_size(SYM_LIST*);
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
    struct symlist* sl;
};
struct ast* newmemory_ast(int, struct symbol*, struct ast*, struct symlist*);
/*=======================================================================*/

tData eval(struct ast*);

int yyerror(char*);

void notificaciones(int);