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
    T_ADD = 259,                   /* T_ADD  */
    T_KICK = 260,                  /* T_KICK  */
    T_TAKE = 261,                  /* T_TAKE  */
    T_IF = 262,                    /* T_IF  */
    T_ELSE = 263,                  /* T_ELSE  */
    T_ENDIF = 264,                 /* T_ENDIF  */
    T_WHILE = 265,                 /* T_WHILE  */
    T_DO = 266,                    /* T_DO  */
    T_END = 267,                   /* T_END  */
    T_FORALL = 268,                /* T_FORALL  */
    T_FORANY = 269,                /* T_FORANY  */
    T_FN = 270,                    /* T_FN  */
    T_ENDFN = 271,                 /* T_ENDFN  */
    NUM_INT = 272,                 /* NUM_INT  */
    ATOM = 273,                    /* ATOM  */
    NUM_DOUBLE = 274,              /* NUM_DOUBLE  */
    T_BOOL = 275,                  /* T_BOOL  */
    ID = 276,                      /* ID  */
    T_MAYOR = 277,                 /* T_MAYOR  */
    T_MAYOR_IGUAL = 278,           /* T_MAYOR_IGUAL  */
    T_MENOR = 279,                 /* T_MENOR  */
    T_MENOR_IGUAL = 280,           /* T_MENOR_IGUAL  */
    T_IGUAL = 281,                 /* T_IGUAL  */
    T_DISTINTO = 282,              /* T_DISTINTO  */
    T_IN = 283,                    /* T_IN  */
    T_CONTAINS = 284,              /* T_CONTAINS  */
    T_UNION = 285,                 /* T_UNION  */
    T_INTER = 286,                 /* T_INTER  */
    T_DIFF = 287,                  /* T_DIFF  */
    T_CONCAT = 288,                /* T_CONCAT  */
    T_FROM = 289,                  /* T_FROM  */
    T_TO = 290,                    /* T_TO  */
    T_MENOS_UNARIO = 291           /* T_MENOS_UNARIO  */
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

#line 107 "tree.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_TREE_TAB_H_INCLUDED  */
