#ifndef ASTH
#define ASTH

#include "data.h"
#include <stdio.h>
#include <stdlib.h> 

/*=======================================================================*/
/*                             AST DEFINITION                            */
/*=======================================================================*/
typedef struct ast{
    int nodetype;
    struct ast* l;
    struct ast* r;
    tData d;
} Ast;
Ast* newast(int, Ast*, Ast*, tData);
int get_nodetype(Ast*);
void set_nodetype(Ast**, int);
int get_widht(Ast*);
void walk(Ast**);

/*=======================================================================*/

/*=======================================================================*/
/*                             FLOW DEFINITION                           */
/*=======================================================================*/
typedef struct{
    int nodetype;
    Ast* cond;
    Ast* iterable;
    Ast* tbody;
    Ast* fbody;
    char* iterator; 
} AstFlow;
Ast* newflow(int, Ast*, Ast*, Ast*, Ast*, char*);
/*=======================================================================*/

/*=======================================================================*/
/*                         MEMORY AST DEFINITION                         */
/*=======================================================================*/
typedef struct id_list{
    char* name;
    struct id_list* sig;
} IdList;
IdList* newIdList (char*, IdList*);
void deleteIdList (IdList*);
void avanzo_IdList(IdList**);

typedef struct {
    int nodetype;
    char* name;
    Ast* a;
    IdList* list_id;
} AstMemory;
Ast* newmemory_ast(int, char*, Ast*, IdList*);
/*=======================================================================*/



void freetree(Ast*);

void astError(char*);
#endif