/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_TREE_TAB_H_INCLUDED
# define YY_YY_TREE_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    EOL = 258,                     /* EOL  */
    T_FROM = 259,                  /* T_FROM  */
    T_TO = 260,                    /* T_TO  */
    T_IF = 261,                    /* T_IF  */
    T_ELSE = 262,                  /* T_ELSE  */
    T_ENDIF = 263,                 /* T_ENDIF  */
    T_WHILE = 264,                 /* T_WHILE  */
    T_DO = 265,                    /* T_DO  */
    T_END = 266,                   /* T_END  */
    T_FORALL = 267,                /* T_FORALL  */
    T_FORANY = 268,                /* T_FORANY  */
    T_FN = 269,                    /* T_FN  */
    T_ENDFN = 270,                 /* T_ENDFN  */
    T_MAIN = 271,                  /* T_MAIN  */
    T_ENDMAIN = 272,               /* T_ENDMAIN  */
    T_PESOS_TREE = 273,            /* T_PESOS_TREE  */
    T_PRINT = 274,                 /* T_PRINT  */
    T_RETURN = 275,                /* T_RETURN  */
    T_LET = 276,                   /* T_LET  */
    T_FLECHA = 277,                /* T_FLECHA  */
    NUM_INT = 278,                 /* NUM_INT  */
    ATOM = 279,                    /* ATOM  */
    NUM_DOUBLE = 280,              /* NUM_DOUBLE  */
    T_BOOL = 281,                  /* T_BOOL  */
    ID = 282,                      /* ID  */
    T_OR = 283,                    /* T_OR  */
    T_AND = 284,                   /* T_AND  */
    T_NOT = 285,                   /* T_NOT  */
    T_MAYOR = 286,                 /* T_MAYOR  */
    T_MAYOR_IGUAL = 287,           /* T_MAYOR_IGUAL  */
    T_MENOR = 288,                 /* T_MENOR  */
    T_MENOR_IGUAL = 289,           /* T_MENOR_IGUAL  */
    T_IGUAL = 290,                 /* T_IGUAL  */
    T_DISTINTO = 291,              /* T_DISTINTO  */
    T_IN = 292,                    /* T_IN  */
    T_CONTAINS = 293,              /* T_CONTAINS  */
    T_GET = 294,                   /* T_GET  */
    T_UNION = 295,                 /* T_UNION  */
    T_INTER = 296,                 /* T_INTER  */
    T_DIFF = 297,                  /* T_DIFF  */
    T_TAKE = 298,                  /* T_TAKE  */
    T_KICK = 299,                  /* T_KICK  */
    T_CONCAT = 300,                /* T_CONCAT  */
    T_ADD = 301,                   /* T_ADD  */
    T_MENOS_UNARIO = 302           /* T_MENOS_UNARIO  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 12 "tree.y"

    struct ast* a;
    struct symbol* s;
    tData td;
    struct symlist* sl;

#line 118 "tree.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_TREE_TAB_H_INCLUDED  */
