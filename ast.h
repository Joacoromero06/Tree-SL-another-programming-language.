#include "data.h"
#include <stdio.h>
#include <stdlib.h>

struct ast{
    int nodetype;
    struct ast* l;
    struct ast* r;
    tData d;
};
struct ast* newast(int, struct ast*, struct ast*, tData);
int get_nodetype(struct ast*);

struct flow{
    int nodetype;
    struct ast* cond;
    struct ast* iterable;
    struct ast* tblock;
    struct ast* fblock;
    struct symbol* s;
};
struct ast* newflow(int, struct ast*, struct ast*, struct ast*, struct ast*, struct symbol*);

struct memory_ast{
    int nodetype;
    struct symbol* s;
    struct ast* a; // value | body | params actuales
};
struct ast* newmemory_ast(int, struct symbol*, struct ast*);

struct symbol{
    char* name;
    tData data;
    //struct symlist* args;
    //struct ast* body;
};
struct symbol* lookup(char* sym);
#define NHASH 9997
    

tData eval(struct ast*);


int yyerror(char*);

void notificaciones(int);