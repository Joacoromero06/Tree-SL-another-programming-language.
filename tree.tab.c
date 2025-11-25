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
    
    int yylex();
    int yyerror(char* s);

#line 83 "tree.tab.c"

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
  YYSYMBOL_T_ADD = 4,                      /* T_ADD  */
  YYSYMBOL_T_KICK = 5,                     /* T_KICK  */
  YYSYMBOL_T_TAKE = 6,                     /* T_TAKE  */
  YYSYMBOL_T_IF = 7,                       /* T_IF  */
  YYSYMBOL_T_ELSE = 8,                     /* T_ELSE  */
  YYSYMBOL_T_ENDIF = 9,                    /* T_ENDIF  */
  YYSYMBOL_T_WHILE = 10,                   /* T_WHILE  */
  YYSYMBOL_T_DO = 11,                      /* T_DO  */
  YYSYMBOL_T_END = 12,                     /* T_END  */
  YYSYMBOL_T_FORALL = 13,                  /* T_FORALL  */
  YYSYMBOL_T_FORANY = 14,                  /* T_FORANY  */
  YYSYMBOL_T_FN = 15,                      /* T_FN  */
  YYSYMBOL_T_ENDFN = 16,                   /* T_ENDFN  */
  YYSYMBOL_NUM_INT = 17,                   /* NUM_INT  */
  YYSYMBOL_ATOM = 18,                      /* ATOM  */
  YYSYMBOL_NUM_DOUBLE = 19,                /* NUM_DOUBLE  */
  YYSYMBOL_T_BOOL = 20,                    /* T_BOOL  */
  YYSYMBOL_ID = 21,                        /* ID  */
  YYSYMBOL_22_ = 22,                       /* '='  */
  YYSYMBOL_T_NOT = 23,                     /* T_NOT  */
  YYSYMBOL_T_AND = 24,                     /* T_AND  */
  YYSYMBOL_T_OR = 25,                      /* T_OR  */
  YYSYMBOL_T_MAYOR = 26,                   /* T_MAYOR  */
  YYSYMBOL_T_MAYOR_IGUAL = 27,             /* T_MAYOR_IGUAL  */
  YYSYMBOL_T_MENOR = 28,                   /* T_MENOR  */
  YYSYMBOL_T_MENOR_IGUAL = 29,             /* T_MENOR_IGUAL  */
  YYSYMBOL_T_IGUAL = 30,                   /* T_IGUAL  */
  YYSYMBOL_T_DISTINTO = 31,                /* T_DISTINTO  */
  YYSYMBOL_T_IN = 32,                      /* T_IN  */
  YYSYMBOL_T_CONTAINS = 33,                /* T_CONTAINS  */
  YYSYMBOL_T_GET = 34,                     /* T_GET  */
  YYSYMBOL_T_UNION = 35,                   /* T_UNION  */
  YYSYMBOL_T_INTER = 36,                   /* T_INTER  */
  YYSYMBOL_T_DIFF = 37,                    /* T_DIFF  */
  YYSYMBOL_T_FROM = 38,                    /* T_FROM  */
  YYSYMBOL_T_CONCAT = 39,                  /* T_CONCAT  */
  YYSYMBOL_T_TO = 40,                      /* T_TO  */
  YYSYMBOL_41_ = 41,                       /* '+'  */
  YYSYMBOL_42_ = 42,                       /* '-'  */
  YYSYMBOL_43_ = 43,                       /* '*'  */
  YYSYMBOL_44_ = 44,                       /* '/'  */
  YYSYMBOL_T_MENOS_UNARIO = 45,            /* T_MENOS_UNARIO  */
  YYSYMBOL_46_ = 46,                       /* '('  */
  YYSYMBOL_47_ = 47,                       /* ')'  */
  YYSYMBOL_48_ = 48,                       /* ':'  */
  YYSYMBOL_49_ = 49,                       /* '|'  */
  YYSYMBOL_50_ = 50,                       /* '['  */
  YYSYMBOL_51_ = 51,                       /* ']'  */
  YYSYMBOL_52_ = 52,                       /* '{'  */
  YYSYMBOL_53_ = 53,                       /* '}'  */
  YYSYMBOL_54_ = 54,                       /* ','  */
  YYSYMBOL_YYACCEPT = 55,                  /* $accept  */
  YYSYMBOL_tree = 56,                      /* tree  */
  YYSYMBOL_stm = 57,                       /* stm  */
  YYSYMBOL_exp = 58,                       /* exp  */
  YYSYMBOL_lit_struct = 59,                /* lit_struct  */
  YYSYMBOL_list_exp = 60,                  /* list_exp  */
  YYSYMBOL_list_id = 61                    /* list_id  */
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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   704

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  7
/* YYNRULES -- Number of rules.  */
#define YYNRULES  54
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  147

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   295


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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      46,    47,    43,    41,    54,    42,     2,    44,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    48,     2,
       2,    22,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    50,     2,    51,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    52,    49,    53,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    45
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int8 yyrline[] =
{
       0,    48,    48,    49,    50,    52,    53,    54,    55,    57,
      58,    59,    60,    63,    64,    65,    66,    67,    69,    70,
      71,    72,    74,    76,    78,    80,    81,    82,    84,    85,
      86,    87,    88,    89,    91,    92,    93,    94,    96,    97,
      98,    99,   100,   101,   103,   104,   105,   108,   109,   110,
     111,   114,   115,   117,   118
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
  "\"end of file\"", "error", "\"invalid token\"", "EOL", "T_ADD",
  "T_KICK", "T_TAKE", "T_IF", "T_ELSE", "T_ENDIF", "T_WHILE", "T_DO",
  "T_END", "T_FORALL", "T_FORANY", "T_FN", "T_ENDFN", "NUM_INT", "ATOM",
  "NUM_DOUBLE", "T_BOOL", "ID", "'='", "T_NOT", "T_AND", "T_OR", "T_MAYOR",
  "T_MAYOR_IGUAL", "T_MENOR", "T_MENOR_IGUAL", "T_IGUAL", "T_DISTINTO",
  "T_IN", "T_CONTAINS", "T_GET", "T_UNION", "T_INTER", "T_DIFF", "T_FROM",
  "T_CONCAT", "T_TO", "'+'", "'-'", "'*'", "'/'", "T_MENOS_UNARIO", "'('",
  "')'", "':'", "'|'", "'['", "']'", "'{'", "'}'", "','", "$accept",
  "tree", "stm", "exp", "lit_struct", "list_exp", "list_id", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-106)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -106,    73,  -106,   231,   231,   231,   -34,   -25,   -22,   -17,
       9,  -106,  -106,  -106,  -106,   -18,   231,   231,   231,   231,
     231,   192,   122,    30,   641,  -106,   557,   578,   599,   231,
     231,    13,    18,    24,   231,   231,   641,   620,  -106,   437,
     411,  -106,   328,    20,  -106,    21,  -106,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   461,   485,
      44,    49,    61,   641,    37,   231,  -106,  -106,   231,  -106,
    -106,   660,   660,    69,    69,    69,    69,    69,    69,    69,
      69,    93,    -1,   -36,    25,   -33,   -33,  -106,  -106,    25,
     -36,   -36,   231,    74,   231,   231,    35,    48,  -106,   -36,
    -106,   260,   231,   359,   385,    61,    50,   231,  -106,   307,
      86,   231,    89,   231,  -106,   172,   285,  -106,   172,   509,
     172,   533,    87,  -106,   104,   106,   109,   113,  -106,  -106,
     172,  -106,   172,   119,   121,  -106,  -106
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     1,     0,     0,     0,     0,     0,     0,     0,
       0,    13,    14,    15,    16,    45,     0,     0,     0,     0,
       0,     0,     0,     0,     5,    17,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    27,     0,    23,     0,
       0,    47,    51,     0,    49,     0,     3,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    44,     0,     0,    22,    24,     0,    48,
      50,    25,    26,    28,    30,    29,    31,    33,    32,    38,
      42,    39,    40,    41,    37,    18,    19,    20,    21,    34,
      35,    36,     0,     0,     0,     0,    53,     0,    46,    43,
      52,     0,     0,     0,     0,     0,     0,     0,     6,     0,
       0,     0,     0,     0,    54,     0,     0,     8,     0,     0,
       0,     0,     0,     7,     0,     0,     0,     0,     4,    11,
       0,    12,     0,     0,     0,     9,    10
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -106,  -106,  -105,    -3,  -106,   -13,    23
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,    23,    24,    25,    43,   107
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      26,    27,    28,    60,    34,    61,    62,    63,    64,    45,
      63,    64,    29,    36,    37,    38,    39,    40,    42,    42,
     132,    30,    74,   134,    31,   136,    68,    69,    35,    32,
      33,    73,    42,    46,    70,   143,    59,   144,    60,    71,
      61,    62,    63,    64,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   110,    61,    62,    63,    64,
      72,    79,   109,     2,    80,    42,   104,     3,     4,     5,
       6,   105,   106,     7,   108,   112,     8,     9,    10,   115,
      11,    12,    13,    14,    15,   116,    16,   128,   125,   111,
     130,   113,   114,   138,    57,    58,    59,    17,    60,   119,
      61,    62,    63,    64,   126,    18,   139,   140,   129,    19,
     131,   141,    20,    21,   142,    22,     3,     4,     5,    58,
      59,   145,    60,   146,    61,    62,    63,    64,   124,    11,
      12,    13,    14,    15,     0,    16,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    17,     0,     0,     0,
       0,     0,     0,     0,    18,     0,     0,     0,    19,     0,
       0,    20,    21,     0,    22,    44,     3,     4,     5,     6,
       0,     0,     7,     0,     0,     8,     9,     0,     0,    11,
      12,    13,    14,    15,     0,    16,     3,     4,     5,     0,
       0,     0,     0,     0,     0,     0,    17,     0,     0,    11,
      12,    13,    14,    15,    18,    16,     0,     0,    19,     0,
       0,    20,    21,     0,    22,     0,    17,     0,     0,     0,
       0,     0,     0,     0,    18,     3,     4,     5,    19,     0,
       0,    20,    21,    41,    22,     0,     0,     0,    11,    12,
      13,    14,    15,     0,    16,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    17,     0,     0,   117,   118,
       0,     0,     0,    18,     0,     0,     0,    19,     0,     0,
      20,    21,     0,    22,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,   133,    57,    58,    59,     0,    60,
       0,    61,    62,    63,    64,     0,     0,     0,     0,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,   127,
      57,    58,    59,     0,    60,     0,    61,    62,    63,    64,
       0,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,     0,    57,    58,    59,     0,    60,     0,    61,    62,
      63,    64,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,     0,    57,    58,    59,     0,    60,     0,    61,
      62,    63,    64,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    78,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,     0,    57,    58,    59,     0,    60,     0,
      61,    62,    63,    64,     0,     0,   120,     0,   121,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,     0,
      57,    58,    59,     0,    60,     0,    61,    62,    63,    64,
       0,     0,   122,     0,   123,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,     0,    57,    58,    59,     0,
      60,     0,    61,    62,    63,    64,     0,     0,     0,     0,
      77,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,     0,    57,    58,    59,     0,    60,     0,    61,    62,
      63,    64,     0,     0,    76,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,     0,    57,    58,    59,     0,
      60,     0,    61,    62,    63,    64,     0,     0,   102,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,     0,
      57,    58,    59,     0,    60,     0,    61,    62,    63,    64,
       0,     0,   103,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,     0,    57,    58,    59,     0,    60,     0,
      61,    62,    63,    64,     0,     0,   135,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,     0,    57,    58,
      59,     0,    60,     0,    61,    62,    63,    64,     0,     0,
     137,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,     0,    57,    58,    59,     0,    60,    65,    61,    62,
      63,    64,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,     0,    57,    58,    59,    66,    60,     0,    61,
      62,    63,    64,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,     0,    57,    58,    59,    67,    60,     0,
      61,    62,    63,    64,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,     0,    57,    58,    59,    75,    60,
       0,    61,    62,    63,    64,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,     0,    57,    58,    59,     0,
      60,     0,    61,    62,    63,    64,    49,    50,    51,    52,
      53,    54,    55,    56,     0,    57,    58,    59,     0,    60,
       0,    61,    62,    63,    64
};

static const yytype_int16 yycheck[] =
{
       3,     4,     5,    39,    22,    41,    42,    43,    44,    22,
      43,    44,    46,    16,    17,    18,    19,    20,    21,    22,
     125,    46,    35,   128,    46,   130,    29,    30,    46,    46,
      21,    34,    35,     3,    21,   140,    37,   142,    39,    21,
      41,    42,    43,    44,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    78,    41,    42,    43,    44,
      46,    51,    75,     0,    53,    78,    32,     4,     5,     6,
       7,    32,    21,    10,    47,    11,    13,    14,    15,    54,
      17,    18,    19,    20,    21,    47,    23,    11,    48,   102,
      11,   104,   105,    16,    35,    36,    37,    34,    39,   112,
      41,    42,    43,    44,   117,    42,    12,    11,   121,    46,
     123,    12,    49,    50,    11,    52,     4,     5,     6,    36,
      37,    12,    39,    12,    41,    42,    43,    44,   115,    17,
      18,    19,    20,    21,    -1,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    34,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,    46,    -1,
      -1,    49,    50,    -1,    52,    53,     4,     5,     6,     7,
      -1,    -1,    10,    -1,    -1,    13,    14,    -1,    -1,    17,
      18,    19,    20,    21,    -1,    23,     4,     5,     6,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    34,    -1,    -1,    17,
      18,    19,    20,    21,    42,    23,    -1,    -1,    46,    -1,
      -1,    49,    50,    -1,    52,    -1,    34,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    42,     4,     5,     6,    46,    -1,
      -1,    49,    50,    51,    52,    -1,    -1,    -1,    17,    18,
      19,    20,    21,    -1,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    34,    -1,    -1,     8,     9,
      -1,    -1,    -1,    42,    -1,    -1,    -1,    46,    -1,    -1,
      49,    50,    -1,    52,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,     9,    35,    36,    37,    -1,    39,
      -1,    41,    42,    43,    44,    -1,    -1,    -1,    -1,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    12,
      35,    36,    37,    -1,    39,    -1,    41,    42,    43,    44,
      -1,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    -1,    35,    36,    37,    -1,    39,    -1,    41,    42,
      43,    44,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    -1,    35,    36,    37,    -1,    39,    -1,    41,
      42,    43,    44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    54,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    -1,    35,    36,    37,    -1,    39,    -1,
      41,    42,    43,    44,    -1,    -1,    47,    -1,    49,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    -1,
      35,    36,    37,    -1,    39,    -1,    41,    42,    43,    44,
      -1,    -1,    47,    -1,    49,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    -1,    35,    36,    37,    -1,
      39,    -1,    41,    42,    43,    44,    -1,    -1,    -1,    -1,
      49,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    -1,    35,    36,    37,    -1,    39,    -1,    41,    42,
      43,    44,    -1,    -1,    47,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    -1,    35,    36,    37,    -1,
      39,    -1,    41,    42,    43,    44,    -1,    -1,    47,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    -1,
      35,    36,    37,    -1,    39,    -1,    41,    42,    43,    44,
      -1,    -1,    47,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    -1,    35,    36,    37,    -1,    39,    -1,
      41,    42,    43,    44,    -1,    -1,    47,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    -1,    35,    36,
      37,    -1,    39,    -1,    41,    42,    43,    44,    -1,    -1,
      47,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    -1,    35,    36,    37,    -1,    39,    40,    41,    42,
      43,    44,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    -1,    35,    36,    37,    38,    39,    -1,    41,
      42,    43,    44,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    -1,    35,    36,    37,    38,    39,    -1,
      41,    42,    43,    44,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    -1,    35,    36,    37,    38,    39,
      -1,    41,    42,    43,    44,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    -1,    35,    36,    37,    -1,
      39,    -1,    41,    42,    43,    44,    26,    27,    28,    29,
      30,    31,    32,    33,    -1,    35,    36,    37,    -1,    39,
      -1,    41,    42,    43,    44
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    56,     0,     4,     5,     6,     7,    10,    13,    14,
      15,    17,    18,    19,    20,    21,    23,    34,    42,    46,
      49,    50,    52,    57,    58,    59,    58,    58,    58,    46,
      46,    46,    46,    21,    22,    46,    58,    58,    58,    58,
      58,    51,    58,    60,    53,    60,     3,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    35,    36,    37,
      39,    41,    42,    43,    44,    40,    38,    38,    58,    58,
      21,    21,    46,    58,    60,    38,    47,    49,    54,    51,
      53,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    47,    47,    32,    32,    21,    61,    47,    58,
      60,    58,    11,    58,    58,    54,    47,     8,     9,    58,
      47,    49,    47,    49,    61,    48,    58,    12,    11,    58,
      11,    58,    57,     9,    57,    47,    57,    47,    16,    12,
      11,    12,    11,    57,    57,    12,    12
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    55,    56,    56,    56,    57,    57,    57,    57,    57,
      57,    57,    57,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    59,    59,    59,
      59,    60,    60,    61,    61
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     3,     9,     1,     6,     8,     7,    11,
      11,     9,     9,     1,     1,     1,     1,     1,     3,     3,
       3,     3,     3,     2,     3,     3,     3,     2,     3,     3,
       3,     3,     3,     3,     4,     4,     4,     3,     3,     3,
       3,     3,     3,     4,     3,     1,     4,     2,     3,     2,
       3,     1,     3,     1,     3
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
        yyerror (YY_("syntax error: cannot back up")); \
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
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
                 int yyrule)
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
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
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
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
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
yyparse (void)
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
  case 3: /* tree: tree stm EOL  */
#line 49 "tree.y"
               { printf("=> "); mostrarData(eval((yyvsp[-1].a)));printf("\n"); }
#line 1325 "tree.tab.c"
    break;

  case 4: /* tree: tree T_FN ID '(' list_id ')' ':' stm T_ENDFN  */
#line 50 "tree.y"
                                               { add_definition((yyvsp[-6].s), (yyvsp[-4].sl), (yyvsp[-1].a)); }
#line 1331 "tree.tab.c"
    break;

  case 5: /* stm: exp  */
#line 52 "tree.y"
            {}
#line 1337 "tree.tab.c"
    break;

  case 6: /* stm: T_IF '(' exp ')' exp T_ENDIF  */
#line 53 "tree.y"
                                                      { (yyval.a) = newflow(IF,     (yyvsp[-3].a), NULL, (yyvsp[-1].a) , NULL, NULL); }
#line 1343 "tree.tab.c"
    break;

  case 7: /* stm: T_IF '(' exp ')' exp T_ELSE exp T_ENDIF  */
#line 54 "tree.y"
                                                      { (yyval.a) = newflow(IF,     (yyvsp[-5].a), NULL, (yyvsp[-3].a) , (yyvsp[-1].a)  , NULL); }
#line 1349 "tree.tab.c"
    break;

  case 8: /* stm: T_WHILE '(' exp ')' T_DO exp T_END  */
#line 55 "tree.y"
                                                      { (yyval.a) = newflow(WHILE,  (yyvsp[-4].a), NULL, (yyvsp[-1].a) , NULL, NULL); }
#line 1355 "tree.tab.c"
    break;

  case 9: /* stm: T_FORALL '(' ID T_IN exp '|' exp ')' T_DO stm T_END  */
#line 57 "tree.y"
                                                      { (yyval.a) = newflow(FORALL, (yyvsp[-4].a), (yyvsp[-6].a)  , (yyvsp[-1].a), NULL, (yyvsp[-8].s)  ); }
#line 1361 "tree.tab.c"
    break;

  case 10: /* stm: T_FORANY '(' ID T_IN exp '|' exp ')' T_DO stm T_END  */
#line 58 "tree.y"
                                                      { (yyval.a) = newflow(FORANY, (yyvsp[-4].a), (yyvsp[-6].a)  , (yyvsp[-1].a), NULL, (yyvsp[-8].s)  ); }
#line 1367 "tree.tab.c"
    break;

  case 11: /* stm: T_FORALL '(' ID T_IN exp ')' T_DO stm T_END  */
#line 59 "tree.y"
                                              { (yyval.a) = newflow(FORALL, NULL, (yyvsp[-4].a)  , (yyvsp[-1].a), NULL, (yyvsp[-6].s)  ); }
#line 1373 "tree.tab.c"
    break;

  case 12: /* stm: T_FORANY '(' ID T_IN exp ')' T_DO stm T_END  */
#line 60 "tree.y"
                                              { (yyval.a) = newflow(FORANY, NULL, (yyvsp[-4].a)  , (yyvsp[-1].a), NULL, (yyvsp[-6].s)  ); }
#line 1379 "tree.tab.c"
    break;

  case 13: /* exp: NUM_INT  */
#line 63 "tree.y"
                { (yyval.a) = newast(INT   , NULL, NULL, (yyvsp[0].td)); }
#line 1385 "tree.tab.c"
    break;

  case 14: /* exp: ATOM  */
#line 64 "tree.y"
                { (yyval.a) = newast(STR   , NULL, NULL, (yyvsp[0].td)); }
#line 1391 "tree.tab.c"
    break;

  case 15: /* exp: NUM_DOUBLE  */
#line 65 "tree.y"
                { (yyval.a) = newast(DOUBLE, NULL, NULL, (yyvsp[0].td)); }
#line 1397 "tree.tab.c"
    break;

  case 16: /* exp: T_BOOL  */
#line 66 "tree.y"
                { (yyval.a) = newast(BOOL  , NULL, NULL, (yyvsp[0].td)); }
#line 1403 "tree.tab.c"
    break;

  case 17: /* exp: lit_struct  */
#line 67 "tree.y"
                { (yyval.a) = (yyvsp[0].a);}
#line 1409 "tree.tab.c"
    break;

  case 18: /* exp: exp '+' exp  */
#line 69 "tree.y"
                { (yyval.a) = newast('+',(yyvsp[-2].a),(yyvsp[0].a),NULL); }
#line 1415 "tree.tab.c"
    break;

  case 19: /* exp: exp '-' exp  */
#line 70 "tree.y"
                { (yyval.a) = newast('-',(yyvsp[-2].a),(yyvsp[0].a),NULL); }
#line 1421 "tree.tab.c"
    break;

  case 20: /* exp: exp '*' exp  */
#line 71 "tree.y"
                { (yyval.a) = newast('*',(yyvsp[-2].a),(yyvsp[0].a),NULL); }
#line 1427 "tree.tab.c"
    break;

  case 21: /* exp: exp '/' exp  */
#line 72 "tree.y"
                { (yyval.a) = newast('/',(yyvsp[-2].a),(yyvsp[0].a),NULL); }
#line 1433 "tree.tab.c"
    break;

  case 22: /* exp: '(' exp ')'  */
#line 74 "tree.y"
                { (yyval.a) = (yyvsp[-1].a);}
#line 1439 "tree.tab.c"
    break;

  case 23: /* exp: '-' exp  */
#line 76 "tree.y"
                               { (yyval.a) = newast(MENOS_UNARIO, (yyvsp[0].a), NULL, NULL); }
#line 1445 "tree.tab.c"
    break;

  case 24: /* exp: '|' exp '|'  */
#line 78 "tree.y"
                { (yyval.a) = newast(MODULO, (yyvsp[-1].a), NULL, NULL); }
#line 1451 "tree.tab.c"
    break;

  case 25: /* exp: exp T_AND exp  */
#line 80 "tree.y"
                        { (yyval.a) = newast(AND        , (yyvsp[-2].a), (yyvsp[0].a), NULL); }
#line 1457 "tree.tab.c"
    break;

  case 26: /* exp: exp T_OR exp  */
#line 81 "tree.y"
                        { (yyval.a) = newast(OR         , (yyvsp[-2].a), (yyvsp[0].a), NULL); }
#line 1463 "tree.tab.c"
    break;

  case 27: /* exp: T_NOT exp  */
#line 82 "tree.y"
                        { (yyval.a) = newast(NOT      , NULL, (yyvsp[0].a), NULL); }
#line 1469 "tree.tab.c"
    break;

  case 28: /* exp: exp T_MAYOR exp  */
#line 84 "tree.y"
                        { (yyval.a) = newast(MAYOR      , (yyvsp[-2].a), (yyvsp[0].a), NULL); }
#line 1475 "tree.tab.c"
    break;

  case 29: /* exp: exp T_MENOR exp  */
#line 85 "tree.y"
                        { (yyval.a) = newast(MENOR      , (yyvsp[-2].a), (yyvsp[0].a), NULL); }
#line 1481 "tree.tab.c"
    break;

  case 30: /* exp: exp T_MAYOR_IGUAL exp  */
#line 86 "tree.y"
                        { (yyval.a) = newast(MAYOR_IGUAL, (yyvsp[-2].a), (yyvsp[0].a), NULL); }
#line 1487 "tree.tab.c"
    break;

  case 31: /* exp: exp T_MENOR_IGUAL exp  */
#line 87 "tree.y"
                        { (yyval.a) = newast(MENOR_IGUAL, (yyvsp[-2].a), (yyvsp[0].a), NULL); }
#line 1493 "tree.tab.c"
    break;

  case 32: /* exp: exp T_DISTINTO exp  */
#line 88 "tree.y"
                        { (yyval.a) = newast(DISTINTO   , (yyvsp[-2].a), (yyvsp[0].a), NULL); }
#line 1499 "tree.tab.c"
    break;

  case 33: /* exp: exp T_IGUAL exp  */
#line 89 "tree.y"
                        { (yyval.a) = newast(IGUAL      , (yyvsp[-2].a), (yyvsp[0].a), NULL); }
#line 1505 "tree.tab.c"
    break;

  case 34: /* exp: T_ADD exp T_TO exp  */
#line 91 "tree.y"
                        { (yyval.a) = newast(ADD,   (yyvsp[-2].a) , (yyvsp[0].a), NULL); }
#line 1511 "tree.tab.c"
    break;

  case 35: /* exp: T_KICK exp T_FROM exp  */
#line 92 "tree.y"
                        { (yyval.a) = newast(KICK,  (yyvsp[-2].a) , (yyvsp[0].a), NULL); }
#line 1517 "tree.tab.c"
    break;

  case 36: /* exp: T_TAKE exp T_FROM exp  */
#line 93 "tree.y"
                        { (yyval.a) = newast(TAKE,  (yyvsp[-2].a) , (yyvsp[0].a), NULL); }
#line 1523 "tree.tab.c"
    break;

  case 37: /* exp: exp T_CONCAT exp  */
#line 94 "tree.y"
                        { (yyval.a) = newast(CONCAT,(yyvsp[-2].a) , (yyvsp[0].a), NULL); }
#line 1529 "tree.tab.c"
    break;

  case 38: /* exp: exp T_IN exp  */
#line 96 "tree.y"
                     { (yyval.a) = newast(IN,       (yyvsp[-2].a), (yyvsp[0].a), NULL); }
#line 1535 "tree.tab.c"
    break;

  case 39: /* exp: exp T_UNION exp  */
#line 97 "tree.y"
                     { (yyval.a) = newast(UNION,    (yyvsp[-2].a), (yyvsp[0].a), NULL); }
#line 1541 "tree.tab.c"
    break;

  case 40: /* exp: exp T_INTER exp  */
#line 98 "tree.y"
                     { (yyval.a) = newast(INTER,    (yyvsp[-2].a), (yyvsp[0].a), NULL); }
#line 1547 "tree.tab.c"
    break;

  case 41: /* exp: exp T_DIFF exp  */
#line 99 "tree.y"
                     { (yyval.a) = newast(DIFF,     (yyvsp[-2].a), (yyvsp[0].a), NULL); }
#line 1553 "tree.tab.c"
    break;

  case 42: /* exp: exp T_CONTAINS exp  */
#line 100 "tree.y"
                     { (yyval.a) = newast(CONTAINS, (yyvsp[-2].a), (yyvsp[0].a), NULL); }
#line 1559 "tree.tab.c"
    break;

  case 43: /* exp: T_GET exp T_FROM exp  */
#line 101 "tree.y"
                       { (yyval.a) = newast(GET,      (yyvsp[-2].a), (yyvsp[0].a), NULL); }
#line 1565 "tree.tab.c"
    break;

  case 44: /* exp: ID '=' exp  */
#line 103 "tree.y"
                        { (yyval.a) = newmemory_ast(ASIGNACION, (yyvsp[-2].s), (yyvsp[0].a)  ); }
#line 1571 "tree.tab.c"
    break;

  case 45: /* exp: ID  */
#line 104 "tree.y"
                        { (yyval.a) = newmemory_ast(VAR_REF   , (yyvsp[0].s), NULL); }
#line 1577 "tree.tab.c"
    break;

  case 46: /* exp: ID '(' list_exp ')'  */
#line 105 "tree.y"
                        { (yyval.a) = newmemory_ast(FN_CALL   , (yyvsp[-3].s), (yyvsp[-1].a)  ); }
#line 1583 "tree.tab.c"
    break;

  case 47: /* lit_struct: '[' ']'  */
#line 108 "tree.y"
                    { (yyval.a) = newast(LIST, NULL, NULL, createData(LIST));}
#line 1589 "tree.tab.c"
    break;

  case 48: /* lit_struct: '[' list_exp ']'  */
#line 109 "tree.y"
                    { (yyval.a) = newast(LIST, (yyvsp[-1].a),   NULL, createData(LIST));}
#line 1595 "tree.tab.c"
    break;

  case 49: /* lit_struct: '{' '}'  */
#line 110 "tree.y"
                    { (yyval.a) = newast(SET,  NULL, NULL, createData(SET)); }
#line 1601 "tree.tab.c"
    break;

  case 50: /* lit_struct: '{' list_exp '}'  */
#line 111 "tree.y"
                    { (yyval.a) = newast(SET,  (yyvsp[-1].a),   NULL, createData(SET)); }
#line 1607 "tree.tab.c"
    break;

  case 51: /* list_exp: exp  */
#line 114 "tree.y"
                    { (yyval.a) = (yyvsp[0].a); }
#line 1613 "tree.tab.c"
    break;

  case 52: /* list_exp: exp ',' list_exp  */
#line 115 "tree.y"
                    { (yyval.a) = newast(LIST_OF_AST, (yyvsp[-2].a), (yyvsp[0].a), NULL); }
#line 1619 "tree.tab.c"
    break;

  case 53: /* list_id: ID  */
#line 117 "tree.y"
                    { (yyval.sl) = addsym((yyvsp[0].s), NULL); }
#line 1625 "tree.tab.c"
    break;

  case 54: /* list_id: ID ',' list_id  */
#line 118 "tree.y"
                    { (yyval.sl) = addsym((yyvsp[-2].s), (yyvsp[0].sl)  ); }
#line 1631 "tree.tab.c"
    break;


#line 1635 "tree.tab.c"

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
      yyerror (YY_("syntax error"));
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
                      yytoken, &yylval);
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
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
  yyerror (YY_("memory exhausted"));
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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 119 "tree.y"

int main(void){
    yyparse();
    //if(yyin != stdin)  fclose(yyin);
    return 0;
}
