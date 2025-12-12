%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "defs.h"
    #include "data.h"
    #include "ast.h"  
    #include "interpret.h"
    #include "env.h"
    
    int yylex();
    int yyerror(Env*, SpEnv*, char*);
%}
%union{
    Ast* a; 
    tData td; 
    char* s;
    Env* ep;
    IdList* l_id;
    Parameter* param;
    ParamList* l_param;
    Argument* arg;
    ArgList* l_arg;
}
%token EOL T_FROM T_TO T_LET
%token T_IF T_ELSE T_ENDIF T_WHILE T_DO T_END T_FORALL T_FORANY
%token T_FUNCTION T_PROCEDURE T_ENDFN T_REF
%token T_MAIN T_ENDMAIN T_PESOS_TREE 
%token T_PRINT T_PRINTLN T_RETURN T_FLECHA T_BREAK T_CONTINUE

%token <td> NUM_INT ATOM NUM_DOUBLE  T_BOOL 
%token <s> ID

%right '='
%left T_OR
%left T_AND 
%right T_NOT
%nonassoc T_MAYOR T_MAYOR_IGUAL T_MENOR T_MENOR_IGUAL T_IGUAL T_DISTINTO T_IN T_CONTAINS
%nonassoc T_GET
%left T_UNION
%left T_INTER
%left T_DIFF
%nonassoc T_TAKE T_KICK
%left T_CONCAT 
%nonassoc T_ADD
%left '+' '-'
%left '*' '/' '%'
%right T_MENOS_UNARIO

%type <a> exp stm body
%type <a> lit_struct list_exp 

%type <l_id> list_id

%type <arg> arg
%type <l_arg> arg_list

%type <param> param
%type <l_param> param_list

%start tree

%parse-param { Env* global_env}
%parse-param { SpEnv* subprogram_env }

%%
tree: {/* programa vacio */}
| defs T_MAIN ':' body T_ENDMAIN   { printf("Ejecucion Finalizada:\n"); exec($4, global_env); printf("\n"); }
| T_PESOS_TREE EOL interpreter_tree  

defs: 
| defs T_PROCEDURE ID '(' param_list ')' ':' body T_END { binding_SP(newSubProgram(PROCEDURE,$3, $5, $8), subprogram_env); printf("procedure defined\n"); }
| defs T_FUNCTION  ID '(' param_list ')' ':' body T_END { binding_SP(newSubProgram(FUNCTION ,$3, $5, $8), subprogram_env); }
;

interpreter_tree: 
| interpreter_tree exp    EOL { printf(">>> "); mostrarData(eval($2, global_env)); printf("\n"); }
| interpreter_tree stm    EOL { printf(">>> "); exec($2, global_env); printf("\n"); }
;

body: { $$ = NULL;  }
| stm body { $$ = ($2 == NULL)? $1: newast(BODY, $1, $2, NULL); }
;

stm: exp ';'         { $$ = newast(EXP_STM, $1, NULL, NULL);   }

| T_LET exp T_FLECHA '(' list_id ')' ';' { $$ = newmemory_ast(MULT_ASSIGN, NULL, $2, $5); }

| T_PRINT exp ';'    { $$ = newast(PRINT  , $2, NULL, NULL); }
| T_PRINTLN exp ';'  { $$ = newast(PRINTLN, $2, NULL, NULL); }

| T_IF '(' exp ')' body T_ENDIF             { $$ = newflow(IF   , $3, $5, NULL, NULL, NULL); }
| T_IF '(' exp ')' body T_ELSE body T_ENDIF { $$ = newflow(IF   , $3, $5, $7  , NULL, NULL); }
| T_WHILE '(' exp ')' T_DO body T_END       { $$ = newflow(WHILE, $3, $6, NULL, NULL, NULL); }

| T_FORALL '(' ID T_IN exp ')' T_DO body T_END            { $$ = newflow(FORALL, NULL, $8 , NULL, $5, $3); }
| T_FORALL '(' ID T_IN exp '|' exp ')' T_DO body T_END    { $$ = newflow(FORALL, $7  , $10, NULL, $5, $3); }
| T_FORANY '(' ID T_IN exp '|' exp ')' T_DO body T_END    { $$ = newflow(FORANY, $7  , $10, NULL, $5, $3); }

| T_RETURN exp ';' { $$ = newast(RETURN_STM  , $2  , NULL, NULL); }
| T_BREAK ';'      { $$ = newast(BREAK_STM   , NULL, NULL, NULL); }
| T_CONTINUE ';'   { $$ = newast(CONTINUE_STM, NULL, NULL, NULL); }

| ID '!' '(' arg_list ')' ';'{ $$ = newFNast(STM_PROCEDURE, $1, $4); printf("procedure called\n"); }
;

exp: ID '=' exp         { $$ = newmemory_ast(ASSIGN, $1, $3, NULL); }

| exp T_AND exp         { $$ = newast(AND        , $1, $3, NULL); }
| exp T_OR exp          { $$ = newast(OR         , $1, $3, NULL); }
| T_NOT exp             { $$ = newast(NOT      , NULL, $2, NULL); }

| exp T_MAYOR exp       { $$ = newast(MAYOR      , $1, $3, NULL); }
| exp T_MENOR exp       { $$ = newast(MENOR      , $1, $3, NULL); }
| exp T_MAYOR_IGUAL exp { $$ = newast(MAYOR_IGUAL, $1, $3, NULL); }
| exp T_MENOR_IGUAL exp { $$ = newast(MENOR_IGUAL, $1, $3, NULL); }
| exp T_DISTINTO exp    { $$ = newast(DISTINTO   , $1, $3, NULL); }
| exp T_IGUAL exp       { $$ = newast(IGUAL      , $1, $3, NULL); }
| exp T_IN exp          { $$ = newast(IN,       $1, $3, NULL); }
| exp T_CONTAINS exp    { $$ = newast(CONTAINS, $1, $3, NULL); }

| T_GET exp T_FROM exp %prec T_GET { $$ = newast(GET,      $2, $4, NULL); }

| exp T_UNION exp      { $$ = newast(UNION,    $1, $3, NULL); }
| exp T_INTER exp      { $$ = newast(INTER,    $1, $3, NULL); }
| exp T_DIFF exp       { $$ = newast(DIFF,     $1, $3, NULL); }
| T_KICK exp T_FROM exp %prec T_KICK { $$ = newast(KICK,  $2 , $4, NULL); }
| T_TAKE exp T_FROM exp %prec T_TAKE { $$ = newast(TAKE,  $2 , $4, NULL); }

| exp T_CONCAT exp      { $$ = newast(CONCAT,$1 , $3, NULL); }

| T_ADD exp T_TO exp   %prec T_ADD { $$ = newast(ADD,   $2 , $4, NULL); }

| exp '+' exp   { $$ = newast('+',$1,$3,NULL); }
| exp '-' exp   { $$ = newast('-',$1,$3,NULL); }
| exp '*' exp   { $$ = newast('*',$1,$3,NULL); }
| exp '/' exp   { $$ = newast('/',$1,$3,NULL); }
| exp '%' exp   { $$ = newast('%',$1,$3,NULL); }

| '(' exp ')'   { $$ = $2;}
| '|' exp '|'   { $$ = newast(MODULO, $2, NULL, NULL); }
| '-' exp %prec T_MENOS_UNARIO { $$ = newast(MENOS_UNARIO, $2, NULL, NULL); }
 
| NUM_INT       { $$ = newast(INT   , NULL, NULL, $1); }   
| ATOM          { $$ = newast(STR   , NULL, NULL, $1); }
| NUM_DOUBLE    { $$ = newast(DOUBLE, NULL, NULL, $1); }
| T_BOOL        { $$ = newast(BOOL  , NULL, NULL, $1); }
| lit_struct    { $$ = $1;}  
| ID            { $$ = newmemory_ast(REFERENCE, $1, NULL, NULL); }
| ID '(' arg_list ')' { $$ = newFNast(EXP_FUNCTION, $1, $3); }
;

lit_struct: '[' ']' { $$ = newast(LIST, NULL, NULL, createData(LIST));}
| '[' list_exp ']'  { $$ = newast(LIST, $2,   NULL, createData(LIST));}
| '{' '}'           { $$ = newast(SET,  NULL, NULL, createData(SET)); }
| '{' list_exp'}'   { $$ = newast(SET,  $2,   NULL, createData(SET)); }
;

list_exp: exp       { $$ = $1; }
| exp ',' list_exp  { $$ = newast(LIST_OF_AST, $1, $3, NULL); }
; 
list_id: ID      { $$ = newIdList($1, NULL); }
| ID ',' list_id { $$ = newIdList($1, $3  ); }
;

arg_list:           { $$ = NULL; }
| arg               { $$ = newArgList($1, NULL); }
| arg ',' arg_list  { $$ = newArgList($1, $3  ); }
;
arg: exp { $$ = newValueArg($1); } 
| '&' ID { $$ = newRefArg($2);   }
;

param_list:            { $$ = NULL; } 
| param                { $$ = newParamList($1, NULL); }
| param ',' param_list { $$ = newParamList($1, $3  ); }
;
param: T_REF ID { $$ = newRefParam($2);                }
| ID            { $$ = newValueParam(FALSE, NULL, $1); }
| ID '=' exp    { $$ = newValueParam(TRUE, $3, $1);    }
;
%%
extern SpEnv* SUBPROGRAM_ENV;
int main(void){     
    SUBPROGRAM_ENV = newSpEnv(NULL, NULL);
    yyparse(MAIN_ENV(), SUBPROGRAM_ENV);
    //if(yyin != stdin)  fclose(yyin);
    return 0;
}
