/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "tree.y"

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

#line 85 "tree.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "tree.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_EOL = 3,                        /* EOL  */
  YYSYMBOL_T_FROM = 4,                     /* T_FROM  */
  YYSYMBOL_T_TO = 5,                       /* T_TO  */
  YYSYMBOL_T_LET = 6,                      /* T_LET  */
  YYSYMBOL_T_IF = 7,                       /* T_IF  */
  YYSYMBOL_T_ELSE = 8,                     /* T_ELSE  */
  YYSYMBOL_T_ENDIF = 9,                    /* T_ENDIF  */
  YYSYMBOL_T_WHILE = 10,                   /* T_WHILE  */
  YYSYMBOL_T_DO = 11,                      /* T_DO  */
  YYSYMBOL_T_END = 12,                     /* T_END  */
  YYSYMBOL_T_FORALL = 13,                  /* T_FORALL  */
  YYSYMBOL_T_FORANY = 14,                  /* T_FORANY  */
  YYSYMBOL_T_FUNCTION = 15,                /* T_FUNCTION  */
  YYSYMBOL_T_PROCEDURE = 16,               /* T_PROCEDURE  */
  YYSYMBOL_T_ENDFN = 17,                   /* T_ENDFN  */
  YYSYMBOL_T_REF = 18,                     /* T_REF  */
  YYSYMBOL_T_MAIN = 19,                    /* T_MAIN  */
  YYSYMBOL_T_ENDMAIN = 20,                 /* T_ENDMAIN  */
  YYSYMBOL_T_PESOS_TREE = 21,              /* T_PESOS_TREE  */
  YYSYMBOL_T_PRINT = 22,                   /* T_PRINT  */
  YYSYMBOL_T_PRINTLN = 23,                 /* T_PRINTLN  */
  YYSYMBOL_T_RETURN = 24,                  /* T_RETURN  */
  YYSYMBOL_T_FLECHA = 25,                  /* T_FLECHA  */
  YYSYMBOL_T_BREAK = 26,                   /* T_BREAK  */
  YYSYMBOL_T_CONTINUE = 27,                /* T_CONTINUE  */
  YYSYMBOL_NUM_INT = 28,                   /* NUM_INT  */
  YYSYMBOL_ATOM = 29,                      /* ATOM  */
  YYSYMBOL_NUM_DOUBLE = 30,                /* NUM_DOUBLE  */
  YYSYMBOL_T_BOOL = 31,                    /* T_BOOL  */
  YYSYMBOL_ID = 32,                        /* ID  */
  YYSYMBOL_33_ = 33,                       /* '='  */
  YYSYMBOL_T_OR = 34,                      /* T_OR  */
  YYSYMBOL_T_AND = 35,                     /* T_AND  */
  YYSYMBOL_T_NOT = 36,                     /* T_NOT  */
  YYSYMBOL_T_MAYOR = 37,                   /* T_MAYOR  */
  YYSYMBOL_T_MAYOR_IGUAL = 38,             /* T_MAYOR_IGUAL  */
  YYSYMBOL_T_MENOR = 39,                   /* T_MENOR  */
  YYSYMBOL_T_MENOR_IGUAL = 40,             /* T_MENOR_IGUAL  */
  YYSYMBOL_T_IGUAL = 41,                   /* T_IGUAL  */
  YYSYMBOL_T_DISTINTO = 42,                /* T_DISTINTO  */
  YYSYMBOL_T_IN = 43,                      /* T_IN  */
  YYSYMBOL_T_CONTAINS = 44,                /* T_CONTAINS  */
  YYSYMBOL_T_GET = 45,                     /* T_GET  */
  YYSYMBOL_T_UNION = 46,                   /* T_UNION  */
  YYSYMBOL_T_INTER = 47,                   /* T_INTER  */
  YYSYMBOL_T_DIFF = 48,                    /* T_DIFF  */
  YYSYMBOL_T_TAKE = 49,                    /* T_TAKE  */
  YYSYMBOL_T_KICK = 50,                    /* T_KICK  */
  YYSYMBOL_T_CONCAT = 51,                  /* T_CONCAT  */
  YYSYMBOL_T_ADD = 52,                     /* T_ADD  */
  YYSYMBOL_53_ = 53,                       /* '+'  */
  YYSYMBOL_54_ = 54,                       /* '-'  */
  YYSYMBOL_55_ = 55,                       /* '*'  */
  YYSYMBOL_56_ = 56,                       /* '/'  */
  YYSYMBOL_57_ = 57,                       /* '%'  */
  YYSYMBOL_T_MENOS_UNARIO = 58,            /* T_MENOS_UNARIO  */
  YYSYMBOL_59_ = 59,                       /* ':'  */
  YYSYMBOL_60_ = 60,                       /* '('  */
  YYSYMBOL_61_ = 61,                       /* ')'  */
  YYSYMBOL_62_ = 62,                       /* ';'  */
  YYSYMBOL_63_ = 63,                       /* '|'  */
  YYSYMBOL_64_ = 64,                       /* '!'  */
  YYSYMBOL_65_ = 65,                       /* '['  */
  YYSYMBOL_66_ = 66,                       /* ']'  */
  YYSYMBOL_67_ = 67,                       /* '{'  */
  YYSYMBOL_68_ = 68,                       /* '}'  */
  YYSYMBOL_69_ = 69,                       /* ','  */
  YYSYMBOL_70_ = 70,                       /* '&'  */
  YYSYMBOL_YYACCEPT = 71,                  /* $accept  */
  YYSYMBOL_tree = 72,                      /* tree  */
  YYSYMBOL_defs = 73,                      /* defs  */
  YYSYMBOL_interpreter_tree = 74,          /* interpreter_tree  */
  YYSYMBOL_body = 75,                      /* body  */
  YYSYMBOL_stm = 76,                       /* stm  */
  YYSYMBOL_exp = 77,                       /* exp  */
  YYSYMBOL_lit_struct = 78,                /* lit_struct  */
  YYSYMBOL_list_exp = 79,                  /* list_exp  */
  YYSYMBOL_list_id = 80,                   /* list_id  */
  YYSYMBOL_arg_list = 81,                  /* arg_list  */
  YYSYMBOL_arg = 82,                       /* arg  */
  YYSYMBOL_param_list = 83,                /* param_list  */
  YYSYMBOL_param = 84                      /* param  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   909

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  71
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  14
/* YYNRULES -- Number of rules.  */
#define YYNRULES  80
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  206

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   307


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    64,     2,     2,     2,    57,    70,     2,
      60,    61,    55,    53,    69,    54,     2,    56,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    59,    62,
       2,    33,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    65,     2,    66,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    67,    63,    68,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    58
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    67,    67,    68,    69,    71,    72,    73,    76,    77,
      78,    81,    82,    85,    87,    89,    90,    92,    93,    94,
      96,    97,    98,   100,   101,   102,   104,   107,   109,   110,
     111,   113,   114,   115,   116,   117,   118,   119,   120,   122,
     124,   125,   126,   127,   128,   130,   132,   134,   135,   136,
     137,   138,   140,   141,   142,   144,   145,   146,   147,   148,
     149,   150,   153,   154,   155,   156,   159,   160,   162,   163,
     166,   167,   168,   170,   171,   174,   175,   176,   178,   179,
     180
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "EOL", "T_FROM",
  "T_TO", "T_LET", "T_IF", "T_ELSE", "T_ENDIF", "T_WHILE", "T_DO", "T_END",
  "T_FORALL", "T_FORANY", "T_FUNCTION", "T_PROCEDURE", "T_ENDFN", "T_REF",
  "T_MAIN", "T_ENDMAIN", "T_PESOS_TREE", "T_PRINT", "T_PRINTLN",
  "T_RETURN", "T_FLECHA", "T_BREAK", "T_CONTINUE", "NUM_INT", "ATOM",
  "NUM_DOUBLE", "T_BOOL", "ID", "'='", "T_OR", "T_AND", "T_NOT", "T_MAYOR",
  "T_MAYOR_IGUAL", "T_MENOR", "T_MENOR_IGUAL", "T_IGUAL", "T_DISTINTO",
  "T_IN", "T_CONTAINS", "T_GET", "T_UNION", "T_INTER", "T_DIFF", "T_TAKE",
  "T_KICK", "T_CONCAT", "T_ADD", "'+'", "'-'", "'*'", "'/'", "'%'",
  "T_MENOS_UNARIO", "':'", "'('", "')'", "';'", "'|'", "'!'", "'['", "']'",
  "'{'", "'}'", "','", "'&'", "$accept", "tree", "defs",
  "interpreter_tree", "body", "stm", "exp", "lit_struct", "list_exp",
  "list_id", "arg_list", "arg", "param_list", "param", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-114)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-3)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       8,    15,    32,    22,  -114,  -114,    10,    21,   -12,   128,
      -6,    -4,   128,   392,     2,     3,     5,    25,   392,   392,
     392,    28,    30,  -114,  -114,  -114,  -114,   -30,   392,   392,
     392,   392,   392,   392,   392,   392,   352,   311,    61,   162,
    -114,    -1,    -1,    69,   128,   558,   -27,   450,   392,   392,
      67,    73,   584,   610,   636,  -114,  -114,   392,   299,    55,
     831,   188,   216,   242,   269,  -114,   662,   504,  -114,   426,
      50,  -114,    56,  -114,  -114,   392,   392,   392,   392,   392,
     392,   392,   392,   392,   392,   392,   392,   392,   392,   392,
     392,   392,   392,   392,  -114,    86,    93,    68,    59,    71,
    -114,  -114,    70,   687,   712,    90,    94,  -114,  -114,  -114,
     787,   107,   787,    84,    77,   299,   392,   392,   392,   392,
    -114,  -114,   392,  -114,  -114,   810,   831,   852,   852,   852,
     852,   852,   852,   852,   852,    40,    66,    47,   -41,   -11,
     -11,  -114,  -114,  -114,  -114,   392,    89,    -1,   104,   117,
     128,   155,   392,   392,  -114,  -114,   299,   106,     4,    47,
      47,   -41,  -114,   787,   128,  -114,   128,    99,   108,    27,
     128,   474,   531,  -114,   109,   158,   160,   117,   114,   128,
    -114,   167,   170,   392,   392,  -114,  -114,  -114,  -114,  -114,
     174,  -114,   128,   737,   762,  -114,   172,   175,   176,  -114,
     128,   128,   173,   177,  -114,  -114
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       5,     0,     0,     0,     8,     1,     0,     0,     0,     4,
       0,     0,    11,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    55,    56,    57,    58,    60,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      59,    75,    75,     0,    11,     0,    60,     0,     0,     0,
       0,     0,     0,     0,     0,    24,    25,     0,    70,     0,
      30,     0,     0,     0,     0,    54,     0,     0,    62,    66,
       0,    64,     0,    10,     9,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    13,     0,    79,     0,    76,     0,
       3,    12,     0,     0,     0,     0,     0,    15,    16,    23,
      27,     0,    73,     0,    71,    70,     0,     0,     0,     0,
      52,    53,     0,    63,    65,    29,    28,    31,    33,    32,
      34,    36,    35,    37,    38,    40,    41,    42,    45,    47,
      48,    49,    50,    51,    78,     0,     0,    75,     0,     0,
      11,     0,     0,     0,    74,    61,    70,     0,    39,    44,
      43,    46,    67,    80,    11,    77,    11,    68,     0,     0,
      11,     0,     0,    72,     0,     0,     0,     0,     0,    11,
      17,     0,     0,     0,     0,    26,     7,     6,    69,    14,
       0,    19,    11,     0,     0,    18,     0,     0,     0,    20,
      11,    11,     0,     0,    21,    22
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -114,  -114,  -114,  -114,   -39,   181,    -9,  -114,   -36,    17,
    -113,  -114,   -35,  -114
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,     9,    43,    44,    45,    40,    70,   168,
     113,   114,    97,    98
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      39,    72,   157,    57,    47,   101,    57,    99,    -2,    52,
      53,    54,    89,    90,    91,    92,    93,    95,     4,    60,
      61,    62,    63,    64,    65,    66,    67,    69,    69,     1,
      58,    96,     5,    58,    59,   179,   180,     6,     7,   103,
     104,     8,    10,   173,    91,    92,    93,    12,   110,   112,
      85,    86,    87,    11,    41,    88,    42,    89,    90,    91,
      92,    93,    48,    49,    73,    50,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,    51,   162,    86,    87,   100,
      55,    88,    56,    89,    90,    91,    92,    93,    88,   105,
      89,    90,    91,    92,    93,   106,   112,   158,   159,   160,
     161,   169,   165,    69,    87,   115,   123,    88,   144,    89,
      90,    91,    92,    93,   124,   175,   145,   176,   147,   146,
     149,   181,   148,   152,    13,    14,   163,   153,    15,   154,
     190,    16,    17,   171,   172,   155,   156,   112,   164,   167,
      18,    19,    20,   196,    21,    22,    23,    24,    25,    26,
      27,   202,   203,   166,    28,    74,   170,   174,   177,   178,
     186,   185,   187,    29,   193,   194,   189,    30,    31,   191,
      32,   192,    33,   195,   199,   204,   200,   201,    34,   205,
      38,    35,   116,    36,   188,    37,    75,    76,     0,    77,
      78,    79,    80,    81,    82,    83,    84,     0,    85,    86,
      87,     0,     0,    88,     0,    89,    90,    91,    92,    93,
     117,     0,    75,    76,    94,    77,    78,    79,    80,    81,
      82,    83,    84,     0,    85,    86,    87,     0,     0,    88,
       0,    89,    90,    91,    92,    93,   118,     0,     0,     0,
      75,    76,     0,    77,    78,    79,    80,    81,    82,    83,
      84,     0,    85,    86,    87,     0,     0,    88,     0,    89,
      90,    91,    92,    93,   119,     0,    75,    76,     0,    77,
      78,    79,    80,    81,    82,    83,    84,     0,    85,    86,
      87,     0,     0,    88,     0,    89,    90,    91,    92,    93,
       0,     0,     0,    75,    76,     0,    77,    78,    79,    80,
      81,    82,    83,    84,     0,    85,    86,    87,     0,     0,
      88,     0,    89,    90,    91,    92,    93,    23,    24,    25,
      26,    46,     0,     0,     0,    28,     0,     0,     0,    23,
      24,    25,    26,    46,    29,     0,     0,    28,    30,    31,
       0,    32,     0,    33,     0,     0,    29,     0,     0,    34,
      30,    31,    35,    32,    36,    33,    37,     0,     0,   111,
       0,    34,     0,     0,    35,     0,    36,     0,    37,    71,
      23,    24,    25,    26,    46,     0,     0,     0,    28,     0,
       0,     0,     0,     0,     0,     0,     0,    29,     0,     0,
       0,    30,    31,     0,    32,     0,    33,     0,     0,     0,
       0,     0,    34,     0,     0,    35,     0,    36,    68,    37,
      23,    24,    25,    26,    46,     0,     0,     0,    28,     0,
       0,     0,     0,     0,     0,     0,     0,    29,     0,     0,
       0,    30,    31,     0,    32,     0,    33,     0,     0,     0,
       0,     0,    34,     0,     0,    35,     0,    36,     0,    37,
      75,    76,     0,    77,    78,    79,    80,    81,    82,    83,
      84,     0,    85,    86,    87,   102,     0,    88,     0,    89,
      90,    91,    92,    93,    75,    76,     0,    77,    78,    79,
      80,    81,    82,    83,    84,   122,    85,    86,    87,     0,
       0,    88,     0,    89,    90,    91,    92,    93,    75,    76,
       0,    77,    78,    79,    80,    81,    82,    83,    84,     0,
      85,    86,    87,     0,     0,    88,     0,    89,    90,    91,
      92,    93,     0,     0,     0,   182,     0,   183,    75,    76,
       0,    77,    78,    79,    80,    81,    82,    83,    84,     0,
      85,    86,    87,     0,     0,    88,     0,    89,    90,    91,
      92,    93,     0,     0,     0,    75,    76,   121,    77,    78,
      79,    80,    81,    82,    83,    84,     0,    85,    86,    87,
       0,     0,    88,     0,    89,    90,    91,    92,    93,     0,
       0,     0,    75,    76,   184,    77,    78,    79,    80,    81,
      82,    83,    84,     0,    85,    86,    87,     0,     0,    88,
       0,    89,    90,    91,    92,    93,     0,     0,    75,    76,
      94,    77,    78,    79,    80,    81,    82,    83,    84,     0,
      85,    86,    87,     0,     0,    88,     0,    89,    90,    91,
      92,    93,     0,     0,    75,    76,   107,    77,    78,    79,
      80,    81,    82,    83,    84,     0,    85,    86,    87,     0,
       0,    88,     0,    89,    90,    91,    92,    93,     0,     0,
      75,    76,   108,    77,    78,    79,    80,    81,    82,    83,
      84,     0,    85,    86,    87,     0,     0,    88,     0,    89,
      90,    91,    92,    93,     0,     0,    75,    76,   109,    77,
      78,    79,    80,    81,    82,    83,    84,     0,    85,    86,
      87,     0,     0,    88,     0,    89,    90,    91,    92,    93,
       0,    75,    76,   120,    77,    78,    79,    80,    81,    82,
      83,    84,     0,    85,    86,    87,     0,     0,    88,     0,
      89,    90,    91,    92,    93,     0,    75,    76,   150,    77,
      78,    79,    80,    81,    82,    83,    84,     0,    85,    86,
      87,     0,     0,    88,     0,    89,    90,    91,    92,    93,
       0,    75,    76,   151,    77,    78,    79,    80,    81,    82,
      83,    84,     0,    85,    86,    87,     0,     0,    88,     0,
      89,    90,    91,    92,    93,     0,    75,    76,   197,    77,
      78,    79,    80,    81,    82,    83,    84,     0,    85,    86,
      87,     0,     0,    88,     0,    89,    90,    91,    92,    93,
       0,    75,    76,   198,    77,    78,    79,    80,    81,    82,
      83,    84,     0,    85,    86,    87,     0,     0,    88,     0,
      89,    90,    91,    92,    93,    76,     0,    77,    78,    79,
      80,    81,    82,    83,    84,     0,    85,    86,    87,     0,
       0,    88,     0,    89,    90,    91,    92,    93,    77,    78,
      79,    80,    81,    82,    83,    84,     0,    85,    86,    87,
       0,     0,    88,     0,    89,    90,    91,    92,    93,    -3,
      -3,    -3,    -3,    -3,    -3,    -3,    -3,     0,    85,    86,
      87,     0,     0,    88,     0,    89,    90,    91,    92,    93
};

static const yytype_int16 yycheck[] =
{
       9,    37,   115,    33,    13,    44,    33,    42,     0,    18,
      19,    20,    53,    54,    55,    56,    57,    18,     3,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    21,
      60,    32,     0,    60,    64,     8,     9,    15,    16,    48,
      49,    19,    32,   156,    55,    56,    57,    59,    57,    58,
      46,    47,    48,    32,    60,    51,    60,    53,    54,    55,
      56,    57,    60,    60,     3,    60,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    60,   122,    47,    48,    20,
      62,    51,    62,    53,    54,    55,    56,    57,    51,    32,
      53,    54,    55,    56,    57,    32,   115,   116,   117,   118,
     119,   150,   147,   122,    48,    60,    66,    51,    32,    53,
      54,    55,    56,    57,    68,   164,    33,   166,    69,    61,
      60,   170,    61,    43,     6,     7,   145,    43,    10,    32,
     179,    13,    14,   152,   153,    61,    69,   156,    59,    32,
      22,    23,    24,   192,    26,    27,    28,    29,    30,    31,
      32,   200,   201,    59,    36,     3,    11,    61,    69,    61,
      12,    62,    12,    45,   183,   184,    62,    49,    50,    12,
      52,    11,    54,     9,    12,    12,    11,    11,    60,    12,
       9,    63,     4,    65,   177,    67,    34,    35,    -1,    37,
      38,    39,    40,    41,    42,    43,    44,    -1,    46,    47,
      48,    -1,    -1,    51,    -1,    53,    54,    55,    56,    57,
       4,    -1,    34,    35,    62,    37,    38,    39,    40,    41,
      42,    43,    44,    -1,    46,    47,    48,    -1,    -1,    51,
      -1,    53,    54,    55,    56,    57,     4,    -1,    -1,    -1,
      34,    35,    -1,    37,    38,    39,    40,    41,    42,    43,
      44,    -1,    46,    47,    48,    -1,    -1,    51,    -1,    53,
      54,    55,    56,    57,     5,    -1,    34,    35,    -1,    37,
      38,    39,    40,    41,    42,    43,    44,    -1,    46,    47,
      48,    -1,    -1,    51,    -1,    53,    54,    55,    56,    57,
      -1,    -1,    -1,    34,    35,    -1,    37,    38,    39,    40,
      41,    42,    43,    44,    -1,    46,    47,    48,    -1,    -1,
      51,    -1,    53,    54,    55,    56,    57,    28,    29,    30,
      31,    32,    -1,    -1,    -1,    36,    -1,    -1,    -1,    28,
      29,    30,    31,    32,    45,    -1,    -1,    36,    49,    50,
      -1,    52,    -1,    54,    -1,    -1,    45,    -1,    -1,    60,
      49,    50,    63,    52,    65,    54,    67,    -1,    -1,    70,
      -1,    60,    -1,    -1,    63,    -1,    65,    -1,    67,    68,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    -1,    -1,
      -1,    49,    50,    -1,    52,    -1,    54,    -1,    -1,    -1,
      -1,    -1,    60,    -1,    -1,    63,    -1,    65,    66,    67,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    -1,    -1,
      -1,    49,    50,    -1,    52,    -1,    54,    -1,    -1,    -1,
      -1,    -1,    60,    -1,    -1,    63,    -1,    65,    -1,    67,
      34,    35,    -1,    37,    38,    39,    40,    41,    42,    43,
      44,    -1,    46,    47,    48,    25,    -1,    51,    -1,    53,
      54,    55,    56,    57,    34,    35,    -1,    37,    38,    39,
      40,    41,    42,    43,    44,    69,    46,    47,    48,    -1,
      -1,    51,    -1,    53,    54,    55,    56,    57,    34,    35,
      -1,    37,    38,    39,    40,    41,    42,    43,    44,    -1,
      46,    47,    48,    -1,    -1,    51,    -1,    53,    54,    55,
      56,    57,    -1,    -1,    -1,    61,    -1,    63,    34,    35,
      -1,    37,    38,    39,    40,    41,    42,    43,    44,    -1,
      46,    47,    48,    -1,    -1,    51,    -1,    53,    54,    55,
      56,    57,    -1,    -1,    -1,    34,    35,    63,    37,    38,
      39,    40,    41,    42,    43,    44,    -1,    46,    47,    48,
      -1,    -1,    51,    -1,    53,    54,    55,    56,    57,    -1,
      -1,    -1,    34,    35,    63,    37,    38,    39,    40,    41,
      42,    43,    44,    -1,    46,    47,    48,    -1,    -1,    51,
      -1,    53,    54,    55,    56,    57,    -1,    -1,    34,    35,
      62,    37,    38,    39,    40,    41,    42,    43,    44,    -1,
      46,    47,    48,    -1,    -1,    51,    -1,    53,    54,    55,
      56,    57,    -1,    -1,    34,    35,    62,    37,    38,    39,
      40,    41,    42,    43,    44,    -1,    46,    47,    48,    -1,
      -1,    51,    -1,    53,    54,    55,    56,    57,    -1,    -1,
      34,    35,    62,    37,    38,    39,    40,    41,    42,    43,
      44,    -1,    46,    47,    48,    -1,    -1,    51,    -1,    53,
      54,    55,    56,    57,    -1,    -1,    34,    35,    62,    37,
      38,    39,    40,    41,    42,    43,    44,    -1,    46,    47,
      48,    -1,    -1,    51,    -1,    53,    54,    55,    56,    57,
      -1,    34,    35,    61,    37,    38,    39,    40,    41,    42,
      43,    44,    -1,    46,    47,    48,    -1,    -1,    51,    -1,
      53,    54,    55,    56,    57,    -1,    34,    35,    61,    37,
      38,    39,    40,    41,    42,    43,    44,    -1,    46,    47,
      48,    -1,    -1,    51,    -1,    53,    54,    55,    56,    57,
      -1,    34,    35,    61,    37,    38,    39,    40,    41,    42,
      43,    44,    -1,    46,    47,    48,    -1,    -1,    51,    -1,
      53,    54,    55,    56,    57,    -1,    34,    35,    61,    37,
      38,    39,    40,    41,    42,    43,    44,    -1,    46,    47,
      48,    -1,    -1,    51,    -1,    53,    54,    55,    56,    57,
      -1,    34,    35,    61,    37,    38,    39,    40,    41,    42,
      43,    44,    -1,    46,    47,    48,    -1,    -1,    51,    -1,
      53,    54,    55,    56,    57,    35,    -1,    37,    38,    39,
      40,    41,    42,    43,    44,    -1,    46,    47,    48,    -1,
      -1,    51,    -1,    53,    54,    55,    56,    57,    37,    38,
      39,    40,    41,    42,    43,    44,    -1,    46,    47,    48,
      -1,    -1,    51,    -1,    53,    54,    55,    56,    57,    37,
      38,    39,    40,    41,    42,    43,    44,    -1,    46,    47,
      48,    -1,    -1,    51,    -1,    53,    54,    55,    56,    57
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    21,    72,    73,     3,     0,    15,    16,    19,    74,
      32,    32,    59,     6,     7,    10,    13,    14,    22,    23,
      24,    26,    27,    28,    29,    30,    31,    32,    36,    45,
      49,    50,    52,    54,    60,    63,    65,    67,    76,    77,
      78,    60,    60,    75,    76,    77,    32,    77,    60,    60,
      60,    60,    77,    77,    77,    62,    62,    33,    60,    64,
      77,    77,    77,    77,    77,    77,    77,    77,    66,    77,
      79,    68,    79,     3,     3,    34,    35,    37,    38,    39,
      40,    41,    42,    43,    44,    46,    47,    48,    51,    53,
      54,    55,    56,    57,    62,    18,    32,    83,    84,    83,
      20,    75,    25,    77,    77,    32,    32,    62,    62,    62,
      77,    70,    77,    81,    82,    60,     4,     4,     4,     5,
      61,    63,    69,    66,    68,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    32,    33,    61,    69,    61,    60,
      61,    61,    43,    43,    32,    61,    69,    81,    77,    77,
      77,    77,    79,    77,    59,    83,    59,    32,    80,    75,
      11,    77,    77,    81,    61,    75,    75,    69,    61,     8,
       9,    75,    61,    63,    63,    62,    12,    12,    80,    62,
      75,    12,    11,    77,    77,     9,    75,    61,    61,    12,
      11,    11,    75,    75,    12,    12
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    71,    72,    72,    72,    73,    73,    73,    74,    74,
      74,    75,    75,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    78,    78,    78,    78,    79,    79,    80,    80,
      81,    81,    81,    82,    82,    83,    83,    83,    84,    84,
      84
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     5,     3,     0,     9,     9,     0,     3,
       3,     0,     2,     2,     7,     3,     3,     6,     8,     7,
       9,    11,    11,     3,     2,     2,     6,     3,     3,     3,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     4,
       3,     3,     3,     4,     4,     3,     4,     3,     3,     3,
       3,     3,     3,     3,     2,     1,     1,     1,     1,     1,
       1,     4,     2,     3,     2,     3,     1,     3,     1,     3,
       0,     1,     3,     1,     2,     0,     1,     3,     2,     1,
       3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (global_env, subprogram_env, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, global_env, subprogram_env); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, Env* global_env, SpEnv* subprogram_env)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (global_env);
  YY_USE (subprogram_env);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, Env* global_env, SpEnv* subprogram_env)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep, global_env, subprogram_env);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule, Env* global_env, SpEnv* subprogram_env)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)], global_env, subprogram_env);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, global_env, subprogram_env); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, Env* global_env, SpEnv* subprogram_env)
{
  YY_USE (yyvaluep);
  YY_USE (global_env);
  YY_USE (subprogram_env);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (Env* global_env, SpEnv* subprogram_env)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* tree: %empty  */
#line 67 "tree.y"
      {/* programa vacio */}
#line 1428 "tree.tab.c"
    break;

  case 3: /* tree: defs T_MAIN ':' body T_ENDMAIN  */
#line 68 "tree.y"
                                   { printf("Ejecucion Finalizada:\n"); exec((yyvsp[-1].a), global_env); printf("\n"); }
#line 1434 "tree.tab.c"
    break;

  case 6: /* defs: defs T_PROCEDURE ID '(' param_list ')' ':' body T_END  */
#line 72 "tree.y"
                                                        { binding_SP(newSubProgram(PROCEDURE,(yyvsp[-6].s), (yyvsp[-4].l_param), (yyvsp[-1].a)), subprogram_env); printf("procedure defined\n"); }
#line 1440 "tree.tab.c"
    break;

  case 7: /* defs: defs T_FUNCTION ID '(' param_list ')' ':' body T_END  */
#line 73 "tree.y"
                                                        { binding_SP(newSubProgram(FUNCTION ,(yyvsp[-6].s), (yyvsp[-4].l_param), (yyvsp[-1].a)), subprogram_env); }
#line 1446 "tree.tab.c"
    break;

  case 9: /* interpreter_tree: interpreter_tree exp EOL  */
#line 77 "tree.y"
                              { printf(">>> "); mostrarData(eval((yyvsp[-1].a), global_env)); printf("\n"); }
#line 1452 "tree.tab.c"
    break;

  case 10: /* interpreter_tree: interpreter_tree stm EOL  */
#line 78 "tree.y"
                              { printf(">>> "); exec((yyvsp[-1].a), global_env); printf("\n"); }
#line 1458 "tree.tab.c"
    break;

  case 11: /* body: %empty  */
#line 81 "tree.y"
      { (yyval.a) = NULL;  }
#line 1464 "tree.tab.c"
    break;

  case 12: /* body: stm body  */
#line 82 "tree.y"
           { (yyval.a) = ((yyvsp[0].a) == NULL)? (yyvsp[-1].a): newast(BODY, (yyvsp[-1].a), (yyvsp[0].a), NULL); }
#line 1470 "tree.tab.c"
    break;

  case 13: /* stm: exp ';'  */
#line 85 "tree.y"
                     { (yyval.a) = newast(EXP_STM, (yyvsp[-1].a), NULL, NULL);   }
#line 1476 "tree.tab.c"
    break;

  case 14: /* stm: T_LET exp T_FLECHA '(' list_id ')' ';'  */
#line 87 "tree.y"
                                         { (yyval.a) = newmemory_ast(MULT_ASSIGN, NULL, (yyvsp[-5].a), (yyvsp[-2].l_id)); }
#line 1482 "tree.tab.c"
    break;

  case 15: /* stm: T_PRINT exp ';'  */
#line 89 "tree.y"
                     { (yyval.a) = newast(PRINT  , (yyvsp[-1].a), NULL, NULL); }
#line 1488 "tree.tab.c"
    break;

  case 16: /* stm: T_PRINTLN exp ';'  */
#line 90 "tree.y"
                     { (yyval.a) = newast(PRINTLN, (yyvsp[-1].a), NULL, NULL); }
#line 1494 "tree.tab.c"
    break;

  case 17: /* stm: T_IF '(' exp ')' body T_ENDIF  */
#line 92 "tree.y"
                                            { (yyval.a) = newflow(IF   , (yyvsp[-3].a), (yyvsp[-1].a), NULL, NULL, NULL); }
#line 1500 "tree.tab.c"
    break;

  case 18: /* stm: T_IF '(' exp ')' body T_ELSE body T_ENDIF  */
#line 93 "tree.y"
                                            { (yyval.a) = newflow(IF   , (yyvsp[-5].a), (yyvsp[-3].a), (yyvsp[-1].a)  , NULL, NULL); }
#line 1506 "tree.tab.c"
    break;

  case 19: /* stm: T_WHILE '(' exp ')' T_DO body T_END  */
#line 94 "tree.y"
                                            { (yyval.a) = newflow(WHILE, (yyvsp[-4].a), (yyvsp[-1].a), NULL, NULL, NULL); }
#line 1512 "tree.tab.c"
    break;

  case 20: /* stm: T_FORALL '(' ID T_IN exp ')' T_DO body T_END  */
#line 96 "tree.y"
                                                          { (yyval.a) = newflow(FORALL, NULL, (yyvsp[-1].a) , NULL, (yyvsp[-4].a), (yyvsp[-6].s)); }
#line 1518 "tree.tab.c"
    break;

  case 21: /* stm: T_FORALL '(' ID T_IN exp '|' exp ')' T_DO body T_END  */
#line 97 "tree.y"
                                                          { (yyval.a) = newflow(FORALL, (yyvsp[-4].a)  , (yyvsp[-1].a), NULL, (yyvsp[-6].a), (yyvsp[-8].s)); }
#line 1524 "tree.tab.c"
    break;

  case 22: /* stm: T_FORANY '(' ID T_IN exp '|' exp ')' T_DO body T_END  */
#line 98 "tree.y"
                                                          { (yyval.a) = newflow(FORANY, (yyvsp[-4].a)  , (yyvsp[-1].a), NULL, (yyvsp[-6].a), (yyvsp[-8].s)); }
#line 1530 "tree.tab.c"
    break;

  case 23: /* stm: T_RETURN exp ';'  */
#line 100 "tree.y"
                   { (yyval.a) = newast(RETURN_STM  , (yyvsp[-1].a)  , NULL, NULL); }
#line 1536 "tree.tab.c"
    break;

  case 24: /* stm: T_BREAK ';'  */
#line 101 "tree.y"
                   { (yyval.a) = newast(BREAK_STM   , NULL, NULL, NULL); }
#line 1542 "tree.tab.c"
    break;

  case 25: /* stm: T_CONTINUE ';'  */
#line 102 "tree.y"
                   { (yyval.a) = newast(CONTINUE_STM, NULL, NULL, NULL); }
#line 1548 "tree.tab.c"
    break;

  case 26: /* stm: ID '!' '(' arg_list ')' ';'  */
#line 104 "tree.y"
                             { (yyval.a) = newFNast(STM_PROCEDURE, (yyvsp[-5].s), (yyvsp[-2].l_arg)); printf("procedure called\n"); }
#line 1554 "tree.tab.c"
    break;

  case 27: /* exp: ID '=' exp  */
#line 107 "tree.y"
                        { (yyval.a) = newmemory_ast(ASSIGN, (yyvsp[-2].s), (yyvsp[0].a), NULL); }
#line 1560 "tree.tab.c"
    break;

  case 28: /* exp: exp T_AND exp  */
#line 109 "tree.y"
                        { (yyval.a) = newast(AND        , (yyvsp[-2].a), (yyvsp[0].a), NULL); }
#line 1566 "tree.tab.c"
    break;

  case 29: /* exp: exp T_OR exp  */
#line 110 "tree.y"
                        { (yyval.a) = newast(OR         , (yyvsp[-2].a), (yyvsp[0].a), NULL); }
#line 1572 "tree.tab.c"
    break;

  case 30: /* exp: T_NOT exp  */
#line 111 "tree.y"
                        { (yyval.a) = newast(NOT      , NULL, (yyvsp[0].a), NULL); }
#line 1578 "tree.tab.c"
    break;

  case 31: /* exp: exp T_MAYOR exp  */
#line 113 "tree.y"
                        { (yyval.a) = newast(MAYOR      , (yyvsp[-2].a), (yyvsp[0].a), NULL); }
#line 1584 "tree.tab.c"
    break;

  case 32: /* exp: exp T_MENOR exp  */
#line 114 "tree.y"
                        { (yyval.a) = newast(MENOR      , (yyvsp[-2].a), (yyvsp[0].a), NULL); }
#line 1590 "tree.tab.c"
    break;

  case 33: /* exp: exp T_MAYOR_IGUAL exp  */
#line 115 "tree.y"
                        { (yyval.a) = newast(MAYOR_IGUAL, (yyvsp[-2].a), (yyvsp[0].a), NULL); }
#line 1596 "tree.tab.c"
    break;

  case 34: /* exp: exp T_MENOR_IGUAL exp  */
#line 116 "tree.y"
                        { (yyval.a) = newast(MENOR_IGUAL, (yyvsp[-2].a), (yyvsp[0].a), NULL); }
#line 1602 "tree.tab.c"
    break;

  case 35: /* exp: exp T_DISTINTO exp  */
#line 117 "tree.y"
                        { (yyval.a) = newast(DISTINTO   , (yyvsp[-2].a), (yyvsp[0].a), NULL); }
#line 1608 "tree.tab.c"
    break;

  case 36: /* exp: exp T_IGUAL exp  */
#line 118 "tree.y"
                        { (yyval.a) = newast(IGUAL      , (yyvsp[-2].a), (yyvsp[0].a), NULL); }
#line 1614 "tree.tab.c"
    break;

  case 37: /* exp: exp T_IN exp  */
#line 119 "tree.y"
                        { (yyval.a) = newast(IN,       (yyvsp[-2].a), (yyvsp[0].a), NULL); }
#line 1620 "tree.tab.c"
    break;

  case 38: /* exp: exp T_CONTAINS exp  */
#line 120 "tree.y"
                        { (yyval.a) = newast(CONTAINS, (yyvsp[-2].a), (yyvsp[0].a), NULL); }
#line 1626 "tree.tab.c"
    break;

  case 39: /* exp: T_GET exp T_FROM exp  */
#line 122 "tree.y"
                                   { (yyval.a) = newast(GET,      (yyvsp[-2].a), (yyvsp[0].a), NULL); }
#line 1632 "tree.tab.c"
    break;

  case 40: /* exp: exp T_UNION exp  */
#line 124 "tree.y"
                       { (yyval.a) = newast(UNION,    (yyvsp[-2].a), (yyvsp[0].a), NULL); }
#line 1638 "tree.tab.c"
    break;

  case 41: /* exp: exp T_INTER exp  */
#line 125 "tree.y"
                       { (yyval.a) = newast(INTER,    (yyvsp[-2].a), (yyvsp[0].a), NULL); }
#line 1644 "tree.tab.c"
    break;

  case 42: /* exp: exp T_DIFF exp  */
#line 126 "tree.y"
                       { (yyval.a) = newast(DIFF,     (yyvsp[-2].a), (yyvsp[0].a), NULL); }
#line 1650 "tree.tab.c"
    break;

  case 43: /* exp: T_KICK exp T_FROM exp  */
#line 127 "tree.y"
                                     { (yyval.a) = newast(KICK,  (yyvsp[-2].a) , (yyvsp[0].a), NULL); }
#line 1656 "tree.tab.c"
    break;

  case 44: /* exp: T_TAKE exp T_FROM exp  */
#line 128 "tree.y"
                                     { (yyval.a) = newast(TAKE,  (yyvsp[-2].a) , (yyvsp[0].a), NULL); }
#line 1662 "tree.tab.c"
    break;

  case 45: /* exp: exp T_CONCAT exp  */
#line 130 "tree.y"
                        { (yyval.a) = newast(CONCAT,(yyvsp[-2].a) , (yyvsp[0].a), NULL); }
#line 1668 "tree.tab.c"
    break;

  case 46: /* exp: T_ADD exp T_TO exp  */
#line 132 "tree.y"
                                   { (yyval.a) = newast(ADD,   (yyvsp[-2].a) , (yyvsp[0].a), NULL); }
#line 1674 "tree.tab.c"
    break;

  case 47: /* exp: exp '+' exp  */
#line 134 "tree.y"
                { (yyval.a) = newast('+',(yyvsp[-2].a),(yyvsp[0].a),NULL); }
#line 1680 "tree.tab.c"
    break;

  case 48: /* exp: exp '-' exp  */
#line 135 "tree.y"
                { (yyval.a) = newast('-',(yyvsp[-2].a),(yyvsp[0].a),NULL); }
#line 1686 "tree.tab.c"
    break;

  case 49: /* exp: exp '*' exp  */
#line 136 "tree.y"
                { (yyval.a) = newast('*',(yyvsp[-2].a),(yyvsp[0].a),NULL); }
#line 1692 "tree.tab.c"
    break;

  case 50: /* exp: exp '/' exp  */
#line 137 "tree.y"
                { (yyval.a) = newast('/',(yyvsp[-2].a),(yyvsp[0].a),NULL); }
#line 1698 "tree.tab.c"
    break;

  case 51: /* exp: exp '%' exp  */
#line 138 "tree.y"
                { (yyval.a) = newast('%',(yyvsp[-2].a),(yyvsp[0].a),NULL); }
#line 1704 "tree.tab.c"
    break;

  case 52: /* exp: '(' exp ')'  */
#line 140 "tree.y"
                { (yyval.a) = (yyvsp[-1].a);}
#line 1710 "tree.tab.c"
    break;

  case 53: /* exp: '|' exp '|'  */
#line 141 "tree.y"
                { (yyval.a) = newast(MODULO, (yyvsp[-1].a), NULL, NULL); }
#line 1716 "tree.tab.c"
    break;

  case 54: /* exp: '-' exp  */
#line 142 "tree.y"
                               { (yyval.a) = newast(MENOS_UNARIO, (yyvsp[0].a), NULL, NULL); }
#line 1722 "tree.tab.c"
    break;

  case 55: /* exp: NUM_INT  */
#line 144 "tree.y"
                { (yyval.a) = newast(INT   , NULL, NULL, (yyvsp[0].td)); }
#line 1728 "tree.tab.c"
    break;

  case 56: /* exp: ATOM  */
#line 145 "tree.y"
                { (yyval.a) = newast(STR   , NULL, NULL, (yyvsp[0].td)); }
#line 1734 "tree.tab.c"
    break;

  case 57: /* exp: NUM_DOUBLE  */
#line 146 "tree.y"
                { (yyval.a) = newast(DOUBLE, NULL, NULL, (yyvsp[0].td)); }
#line 1740 "tree.tab.c"
    break;

  case 58: /* exp: T_BOOL  */
#line 147 "tree.y"
                { (yyval.a) = newast(BOOL  , NULL, NULL, (yyvsp[0].td)); }
#line 1746 "tree.tab.c"
    break;

  case 59: /* exp: lit_struct  */
#line 148 "tree.y"
                { (yyval.a) = (yyvsp[0].a);}
#line 1752 "tree.tab.c"
    break;

  case 60: /* exp: ID  */
#line 149 "tree.y"
                { (yyval.a) = newmemory_ast(REFERENCE, (yyvsp[0].s), NULL, NULL); }
#line 1758 "tree.tab.c"
    break;

  case 61: /* exp: ID '(' arg_list ')'  */
#line 150 "tree.y"
                      { (yyval.a) = newFNast(EXP_FUNCTION, (yyvsp[-3].s), (yyvsp[-1].l_arg)); }
#line 1764 "tree.tab.c"
    break;

  case 62: /* lit_struct: '[' ']'  */
#line 153 "tree.y"
                    { (yyval.a) = newast(LIST, NULL, NULL, createData(LIST));}
#line 1770 "tree.tab.c"
    break;

  case 63: /* lit_struct: '[' list_exp ']'  */
#line 154 "tree.y"
                    { (yyval.a) = newast(LIST, (yyvsp[-1].a),   NULL, createData(LIST));}
#line 1776 "tree.tab.c"
    break;

  case 64: /* lit_struct: '{' '}'  */
#line 155 "tree.y"
                    { (yyval.a) = newast(SET,  NULL, NULL, createData(SET)); }
#line 1782 "tree.tab.c"
    break;

  case 65: /* lit_struct: '{' list_exp '}'  */
#line 156 "tree.y"
                    { (yyval.a) = newast(SET,  (yyvsp[-1].a),   NULL, createData(SET)); }
#line 1788 "tree.tab.c"
    break;

  case 66: /* list_exp: exp  */
#line 159 "tree.y"
                    { (yyval.a) = (yyvsp[0].a); }
#line 1794 "tree.tab.c"
    break;

  case 67: /* list_exp: exp ',' list_exp  */
#line 160 "tree.y"
                    { (yyval.a) = newast(LIST_OF_AST, (yyvsp[-2].a), (yyvsp[0].a), NULL); }
#line 1800 "tree.tab.c"
    break;

  case 68: /* list_id: ID  */
#line 162 "tree.y"
                 { (yyval.l_id) = newIdList((yyvsp[0].s), NULL); }
#line 1806 "tree.tab.c"
    break;

  case 69: /* list_id: ID ',' list_id  */
#line 163 "tree.y"
                 { (yyval.l_id) = newIdList((yyvsp[-2].s), (yyvsp[0].l_id)  ); }
#line 1812 "tree.tab.c"
    break;

  case 70: /* arg_list: %empty  */
#line 166 "tree.y"
                    { (yyval.l_arg) = NULL; }
#line 1818 "tree.tab.c"
    break;

  case 71: /* arg_list: arg  */
#line 167 "tree.y"
                    { (yyval.l_arg) = newArgList((yyvsp[0].arg), NULL); }
#line 1824 "tree.tab.c"
    break;

  case 72: /* arg_list: arg ',' arg_list  */
#line 168 "tree.y"
                    { (yyval.l_arg) = newArgList((yyvsp[-2].arg), (yyvsp[0].l_arg)  ); }
#line 1830 "tree.tab.c"
    break;

  case 73: /* arg: exp  */
#line 170 "tree.y"
         { (yyval.arg) = newValueArg((yyvsp[0].a)); }
#line 1836 "tree.tab.c"
    break;

  case 74: /* arg: '&' ID  */
#line 171 "tree.y"
         { (yyval.arg) = newRefArg((yyvsp[0].s));   }
#line 1842 "tree.tab.c"
    break;

  case 75: /* param_list: %empty  */
#line 174 "tree.y"
                       { (yyval.l_param) = NULL; }
#line 1848 "tree.tab.c"
    break;

  case 76: /* param_list: param  */
#line 175 "tree.y"
                       { (yyval.l_param) = newParamList((yyvsp[0].param), NULL); }
#line 1854 "tree.tab.c"
    break;

  case 77: /* param_list: param ',' param_list  */
#line 176 "tree.y"
                       { (yyval.l_param) = newParamList((yyvsp[-2].param), (yyvsp[0].l_param)  ); }
#line 1860 "tree.tab.c"
    break;

  case 78: /* param: T_REF ID  */
#line 178 "tree.y"
                { (yyval.param) = newRefParam((yyvsp[0].s));                }
#line 1866 "tree.tab.c"
    break;

  case 79: /* param: ID  */
#line 179 "tree.y"
                { (yyval.param) = newValueParam(FALSE, NULL, (yyvsp[0].s)); }
#line 1872 "tree.tab.c"
    break;

  case 80: /* param: ID '=' exp  */
#line 180 "tree.y"
                { (yyval.param) = newValueParam(TRUE, (yyvsp[0].a), (yyvsp[-2].s));    }
#line 1878 "tree.tab.c"
    break;


#line 1882 "tree.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (global_env, subprogram_env, YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, global_env, subprogram_env);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, global_env, subprogram_env);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (global_env, subprogram_env, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, global_env, subprogram_env);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, global_env, subprogram_env);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 182 "tree.y"

extern SpEnv* SUBPROGRAM_ENV;
int main(void){     
    SUBPROGRAM_ENV = newSpEnv(NULL, NULL);
    yyparse(MAIN_ENV(), SUBPROGRAM_ENV);
    //if(yyin != stdin)  fclose(yyin);
    return 0;
}
