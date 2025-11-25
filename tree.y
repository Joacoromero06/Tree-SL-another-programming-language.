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
}
%token EOL T_ADD T_KICK T_TAKE
%token T_IF T_ELSE T_ENDIF T_WHILE T_DO T_END T_FORALL T_FORANY

%token <td> NUM_INT ATOM NUM_DOUBLE  T_BOOL
%token <s> ID

%right '='
%left T_MAYOR T_MAYOR_IGUAL T_MENOR T_MENOR_IGUAL T_IGUAL T_DISTINTO T_IN T_CONTAINS
%left T_UNION
%left T_INTER
%left T_DIFF
%left T_CONCAT
%left T_FROM T_TO
%left '+' '-'
%left '*' '/'
%right T_MENOS_UNARIO

%type <a> exp stm 
%type <a> lit_struct list_exp
%start tree


%%
tree: 
| tree stm EOL { printf("=> "); mostrarData(eval($2));printf("\n"); }
; 
stm: exp    {}
| T_IF '(' exp ')' exp T_ENDIF                        { $$ = newflow(IF,     $3, NULL, $5 , NULL, NULL); }
| T_IF '(' exp ')' exp T_ELSE exp T_ENDIF             { $$ = newflow(IF,     $3, NULL, $5 , $7  , NULL); }
| T_WHILE '(' exp ')' T_DO exp T_END                  { $$ = newflow(WHILE,  $3, NULL, $6 , NULL, NULL); }

| T_FORALL '(' ID T_IN exp '|' exp ')' T_DO stm T_END { $$ = newflow(FORALL, $7, $5  , $10, NULL, $3  ); }
| T_FORANY '(' ID T_IN exp '|' exp ')' T_DO stm T_END { $$ = newflow(FORANY, $7, $5  , $10, NULL, $3  ); }
| T_FORALL '(' ID T_IN exp ')' T_DO stm T_END { $$ = newflow(FORALL, NULL, $5  , $8, NULL, $3  ); }
| T_FORANY '(' ID T_IN exp ')' T_DO stm T_END { $$ = newflow(FORANY, NULL, $5  , $8, NULL, $3  ); }
;

exp: NUM_INT    { $$ = newast(INT   , NULL, NULL, $1); }   
| ATOM          { $$ = newast(STR   , NULL, NULL, $1); }
| NUM_DOUBLE    { $$ = newast(DOUBLE, NULL, NULL, $1); }
| T_BOOL        { $$ = newast(BOOL  , NULL, NULL, $1); }
| lit_struct    { $$ = $1;}    

| exp '+' exp   { $$ = newast('+',$1,$3,NULL); }
| exp '-' exp   { $$ = newast('-',$1,$3,NULL); }
| exp '*' exp   { $$ = newast('*',$1,$3,NULL); }
| exp '/' exp   { $$ = newast('/',$1,$3,NULL); }

| '(' exp ')'   { $$ = $2;}

| '-' exp %prec T_MENOS_UNARIO { $$ = newast(MENOS_UNARIO, $2, NULL, NULL); }

| '|' exp '|'   { $$ = newast(MODULO, $2, NULL, NULL); }

| exp T_MAYOR exp       { $$ = newast(MAYOR      , $1, $3, NULL); }
| exp T_MENOR exp       { $$ = newast(MENOR      , $1, $3, NULL); }
| exp T_MAYOR_IGUAL exp { $$ = newast(MAYOR_IGUAL, $1, $3, NULL); }
| exp T_MENOR_IGUAL exp { $$ = newast(MENOR_IGUAL, $1, $3, NULL); }
| exp T_DISTINTO exp    { $$ = newast(DISTINTO   , $1, $3, NULL); }
| exp T_IGUAL exp       { $$ = newast(IGUAL      , $1, $3, NULL); }

| T_ADD exp T_TO exp    { $$ = newast(ADD,   $2 , $4, NULL); }
| T_KICK exp T_FROM exp { $$ = newast(KICK,  $2 , $4, NULL); }
| T_TAKE exp T_FROM exp { $$ = newast(TAKE,  $2 , $4, NULL); }
| exp T_CONCAT exp      { $$ = newast(CONCAT,$1 , $3, NULL); }

| exp T_IN exp       { $$ = newast(IN,       $1, $3, NULL); }
| exp T_UNION exp    { $$ = newast(UNION,    $1, $3, NULL); }
| exp T_INTER exp    { $$ = newast(INTER,    $1, $3, NULL); }
| exp T_DIFF exp     { $$ = newast(DIFF,     $1, $3, NULL); }
| exp T_CONTAINS exp { $$ = newast(CONTAINS, $1, $3, NULL); }

| ID '=' exp        { $$ = newmemory_ast(ASIGNACION, $1, $3  );}
| ID                { $$ = newmemory_ast(VAR_REF   , $1, NULL);}
;

lit_struct: '[' ']' { $$ = newast(LIST, NULL, NULL, createData(LIST));}
| '[' list_exp ']'  { $$ = newast(LIST, $2,   NULL, createData(LIST));}
| '{' '}'           { $$ = newast(SET,  NULL, NULL, createData(SET)); }
| '{' list_exp'}'   { $$ = newast(SET,  $2,   NULL, createData(SET)); }
;

list_exp: exp       { $$ = $1; }
| exp ',' list_exp  { $$ = newast(LIST_OF_AST, $1, $3, NULL); }
;

%%
int main(void){
    yyparse();
    //if(yyin != stdin)  fclose(yyin);
    return 0;
}
