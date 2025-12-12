#ifndef INTERPRETER_H
#define INTERPRETER_H
#include "data.h"
#include "ast.h"
#include "env.h"
/*==================================================================*/
/*                              EVAL                                */
/*==================================================================*/
tData eval(Ast*, Env*);

tData eval_list(Ast*, Env*);
tData eval_set(Ast*, Env*);

tData evalOpList(Ast*, Env*);
tData evalOpSet(Ast*, Env*);

tData eval_rel(Ast*, Env*);
tData eval_log(Ast*, Env*);

tData eval_fn(char*, ArgList*, Env*);
/*==================================================================*/


/*==================================================================*/
/*                      EXECUTION RESULT                            */
/*==================================================================*/
typedef enum {NORMAL=0, RETURN, BREAK, CONTINUE} ExecResult_Tipo;
typedef struct{
    ExecResult_Tipo type;
    tData return_value;
} ExecResult;

ExecResult new_ER(ExecResult_Tipo, tData);
ExecResult_Tipo ResultType(ExecResult);
tData ReturnValue(ExecResult);
/*==================================================================*/

/*==================================================================*/
/*                              EXEC                                */
/*==================================================================*/
ExecResult exec(Ast*, Env*);
ExecResult exec_flow(AstFlow*, Env*);
ExecResult exec_procedure(char*, ArgList*, Env*);
/*==================================================================*/

void notificaciones(int);
void debugExec(char*);
void debugEval(char*);

#endif