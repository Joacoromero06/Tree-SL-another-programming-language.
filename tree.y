%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "defs.h"
    #include "data.h"
    #include "ast.h"  
    
    int yylex();
    int yyerror(char* s);
%}
%union{
    struct ast* a;
    struct symbol* s;
    tData td;
    struct symlist* sl;
}
%token EOL T_FROM T_TO
%token T_IF T_ELSE T_ENDIF T_WHILE T_DO T_END T_FORALL T_FORANY
%token T_FN T_ENDFN 
%token T_MAIN T_ENDMAIN T_PESOS_TREE T_PRINT T_RETURN T_LET T_FLECHA

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

%type <a> exp stm block
%type <a> lit_struct list_exp
%type <sl> list_id

%start tree


%%
tree: 
| T_PESOS_TREE EOL interpreter_tree
| defs main
;

defs:         {  }  
| defs fn_def {  }
; 
main: T_MAIN ':' block T_ENDMAIN { 
    printf(">>> \n");  //mostrarData(eval($3));
    eval($3); printf("\nEjecion finalizada\n"); 
    }
; 

interpreter_tree:
| interpreter_tree exp    EOL { printf(">>> "); mostrarData(eval($2)); printf("\n"); }
| interpreter_tree block  EOL { printf(">>> "); mostrarData(eval($2)); printf("\n"); }
| interpreter_tree fn_def EOL { printf("Funcion Definida.\n"); }  
; 


block:      { $$ = NULL; }
| stm block { $$ = ($2 == NULL)? $1: newast(BLOCK, $1, $2, NULL); }
;

stm: exp ';'  { $$ = $1; }
| T_RETURN exp ';'        { $$ = newast(RETURN, $2, NULL, NULL); }  

| T_IF '(' exp ')' block T_ENDIF                      { $$ = newflow(IF,     $3, NULL, $5 , NULL, NULL); }
| T_IF '(' exp ')' block T_ELSE  block T_ENDIF        { $$ = newflow(IF,     $3, NULL, $5 , $7  , NULL); }

| T_WHILE '(' exp ')' T_DO block T_END                  { $$ = newflow(WHILE,  $3, NULL, $6 , NULL, NULL); }

| T_FORALL '(' ID T_IN exp '|' exp ')' T_DO block T_END { $$ = newflow(FORALL, $7, $5  , $10, NULL, $3  ); }
| T_FORANY '(' ID T_IN exp '|' exp ')' T_DO block T_END { $$ = newflow(FORANY, $7, $5  , $10, NULL, $3  ); }
| T_FORALL '(' ID T_IN exp ')' T_DO block T_END { $$ = newflow(FORALL, NULL, $5  , $8, NULL, $3  ); }
| T_FORANY '(' ID T_IN exp ')' T_DO block T_END { $$ = newflow(FORANY, NULL, $5  , $8, NULL, $3  ); }

| T_LET ID T_FLECHA '(' list_id ')' ';' { $$ = newmemory_ast(ASSIGN_MULTIPLE, $2, NULL, $5); }

| T_PRINT '(' exp ')' ';' { $$ = newast(PRINT, $3, NULL, NULL); }
;

exp: ID '=' exp            { $$ = newmemory_ast(ASIGNACION, $1, $3, NULL  ); }

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

| ID                    { $$ = newmemory_ast(VAR_REF   , $1, NULL, NULL); }
| ID '(' list_exp ')'   { $$ = newmemory_ast(FN_CALL   , $1, $3  , NULL); }
| NUM_INT       { $$ = newast(INT   , NULL, NULL, $1); }   
| ATOM          { $$ = newast(STR   , NULL, NULL, $1); }
| NUM_DOUBLE    { $$ = newast(DOUBLE, NULL, NULL, $1); }
| T_BOOL        { $$ = newast(BOOL  , NULL, NULL, $1); }
| lit_struct    { $$ = $1;}    
;

lit_struct: '[' ']' { $$ = newast(LIST, NULL, NULL, createData(LIST));}
| '[' list_exp ']'  { $$ = newast(LIST, $2,   NULL, createData(LIST));}
| '{' '}'           { $$ = newast(SET,  NULL, NULL, createData(SET)); }
| '{' list_exp'}'   { $$ = newast(SET,  $2,   NULL, createData(SET)); }
;

list_exp: exp       { $$ = $1; }
| exp ',' list_exp  { $$ = newast(LIST_OF_AST, $1, $3, NULL); }
;
list_id: ID         { $$ = addsym($1, NULL); }
| ID ',' list_id    { $$ = addsym($1, $3  ); }
;

fn_def: T_FN ID '(' list_id ')' ':' block T_ENDFN { add_definition($2, $4, $7); }
; 
%%
int main(void){
    yyparse();
    //if(yyin != stdin)  fclose(yyin);
    return 0;
}
