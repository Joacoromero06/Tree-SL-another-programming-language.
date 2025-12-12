#ifndef ENVH
#define ENVH
#include "defs.h"
#include "data.h"
#include <stdlib.h>
#include <string.h>
#include "ast.h"

#define NHASH 79
#define SUBPROGRAM_TYPE(value) ((value)->tipo)
#define SBENV_FUN(sb) ((sb)->f) 
typedef enum
{
    UNDEF = -1,
    FALSE = 0,
    TRUE = 1
} boolean;

/*=======================================================================*/
/*                              SYMLIST                                  */
/*=======================================================================*/

typedef struct sym_list
{
    char* key;
    tData value;

    struct sym_list* next;
} SymList;

boolean pertence_SL(char*, SymList*);
tData localiza_SL(char*, SymList*);
void inserta_SL(char*, tData, SymList**);
void suprime_SL(char*, SymList**);

SymList* new_SL(char*, tData, SymList*);
void delete_SL(SymList*);
/*=======================================================================*/


/*=======================================================================*/
/*                             HASH MAP                                  */
/*=======================================================================*/
typedef SymList** HashMap ;

boolean pertenece_HM(char *, HashMap);
tData localiza_HM(char *, HashMap);
void inserta_HM(char *, tData, HashMap);
void suprime_HM(char*, HashMap);

HashMap new_HM();
void delete_HM(HashMap);
/*=======================================================================*/

/*=======================================================================*/
/*                                 ENV                                   */
/*=======================================================================*/
typedef struct env
{
    HashMap map;
    struct env* parent;
} Env;

void binding(char*, tData, Env*);
boolean is_binded(char*, Env*);
tData reference(char*, Env*);

Env* newEnv(Env*);
Env* MAIN_ENV();
void deleteEnv(Env*);
/*=======================================================================*/



/*=======================================================================*/
/*                             ARGUMENT                                  */
/*=======================================================================*/
typedef enum {xREFERENCIA, xVALOR} ParameterType;
typedef struct {
    ParameterType tipo;
    union{
        struct{
            Ast* a;
            tData data;
        };
        char* name;
    };
} Argument;
Argument* newValueArg(Ast*);
Argument* newRefArg(char*);
void deleteArgument(Argument*);
/*=======================================================================*/
/*                         ARGUMENT LIST                                 */
/*=======================================================================*/
typedef struct arg_list{
    Argument* arg;
    struct arg_list* sig;
}ArgList;
ArgList* newArgList(Argument*, ArgList*);
void deleteArgList(ArgList*);
/*=======================================================================*/



/*=======================================================================*/
/*                            PARAMETER                                  */
/*=======================================================================*/
typedef struct {
    ParameterType tipo;
    union {
        struct { 
            boolean defaul;
            Ast* a;
            tData data;
            char* name_val;     
        };
        char* name_ref;     

    };
} Parameter;  
Parameter* newValueParam(boolean, Ast*, char*);
Parameter* newRefParam(char*);
void deleteParam(Parameter*); 
/*=======================================================================*/
/*                          PARAMETER LIST                               */
/*=======================================================================*/
typedef struct param_list{
    Parameter* param;
    struct param_list* sig;
} ParamList;
ParamList* newParamList(Parameter*, ParamList*);
void deleteParamList(ParamList*);
/*=======================================================================*/

/*=======================================================================*/
/*                              FUNCTION                                 */
/*=======================================================================*/
typedef enum { PROCEDURE, FUNCTION } SpType;
typedef struct{
    SpType tipo;
    char* name;
    ParamList* params;
    Ast* body;
} SubProgram;

void deleteSubProgram(SubProgram*);
SubProgram* newSubProgram(SpType, char*, ParamList*, Ast*);
/*=======================================================================*/
/*                            FUNCTION ENV                               */
/*=======================================================================*/
typedef struct sp_env{
    SubProgram* f;
    struct sp_env* sig;
} SpEnv;

SpEnv* newSpEnv(SubProgram*, SpEnv*);
void binding_SP(SubProgram*, SpEnv*);
SubProgram* reference_SP(char*, SpEnv*);
boolean is_binded_SP(char*, SpEnv*);
/*=======================================================================*/

/*=======================================================================*/
/*                       SUBPROGRAM AST DEFINITION                       */
/*=======================================================================*/
typedef struct{
    int nodetype;
    char* name;
    ArgList* args;
} AstSubprogram;
Ast* newFNast(int, char*, ArgList*);
/*=======================================================================*/
void envError(char*);
#endif