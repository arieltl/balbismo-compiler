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
#line 2 "balbismo.y"

#include "ast.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void yyerror(const char *s);
int yylex();

ASTNode* ast_root;

#line 83 "balbismo.tab.c"

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

#include "balbismo.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDENTIFIER = 3,                 /* IDENTIFIER  */
  YYSYMBOL_INT = 4,                        /* INT  */
  YYSYMBOL_FLOAT = 5,                      /* FLOAT  */
  YYSYMBOL_PRINTF = 6,                     /* PRINTF  */
  YYSYMBOL_IF = 7,                         /* IF  */
  YYSYMBOL_ELSE = 8,                       /* ELSE  */
  YYSYMBOL_WHILE = 9,                      /* WHILE  */
  YYSYMBOL_RETURN = 10,                    /* RETURN  */
  YYSYMBOL_EQUAL_EQUAL = 11,               /* EQUAL_EQUAL  */
  YYSYMBOL_NOT_EQUAL = 12,                 /* NOT_EQUAL  */
  YYSYMBOL_GREATER_EQUAL = 13,             /* GREATER_EQUAL  */
  YYSYMBOL_LESS_EQUAL = 14,                /* LESS_EQUAL  */
  YYSYMBOL_GREATER = 15,                   /* GREATER  */
  YYSYMBOL_LESS = 16,                      /* LESS  */
  YYSYMBOL_AND_OP = 17,                    /* AND_OP  */
  YYSYMBOL_OR_OP = 18,                     /* OR_OP  */
  YYSYMBOL_NOT_OP = 19,                    /* NOT_OP  */
  YYSYMBOL_INT_LITERAL = 20,               /* INT_LITERAL  */
  YYSYMBOL_FLOAT_LITERAL = 21,             /* FLOAT_LITERAL  */
  YYSYMBOL_UMINUS = 22,                    /* UMINUS  */
  YYSYMBOL_23_ = 23,                       /* '*'  */
  YYSYMBOL_24_ = 24,                       /* '/'  */
  YYSYMBOL_25_ = 25,                       /* '%'  */
  YYSYMBOL_26_ = 26,                       /* '+'  */
  YYSYMBOL_27_ = 27,                       /* '-'  */
  YYSYMBOL_28_ = 28,                       /* '<'  */
  YYSYMBOL_29_ = 29,                       /* '>'  */
  YYSYMBOL_30_ = 30,                       /* '('  */
  YYSYMBOL_31_ = 31,                       /* ')'  */
  YYSYMBOL_32_ = 32,                       /* ','  */
  YYSYMBOL_33_ = 33,                       /* '['  */
  YYSYMBOL_34_ = 34,                       /* ']'  */
  YYSYMBOL_35_ = 35,                       /* '{'  */
  YYSYMBOL_36_ = 36,                       /* '}'  */
  YYSYMBOL_37_ = 37,                       /* ';'  */
  YYSYMBOL_38_ = 38,                       /* '='  */
  YYSYMBOL_YYACCEPT = 39,                  /* $accept  */
  YYSYMBOL_PROGRAM = 40,                   /* PROGRAM  */
  YYSYMBOL_FUNCTION_LIST = 41,             /* FUNCTION_LIST  */
  YYSYMBOL_FUNCTION_DECLARATION = 42,      /* FUNCTION_DECLARATION  */
  YYSYMBOL_PARAMETER_LIST = 43,            /* PARAMETER_LIST  */
  YYSYMBOL_PARAMETER = 44,                 /* PARAMETER  */
  YYSYMBOL_PARAMETER_TYPE = 45,            /* PARAMETER_TYPE  */
  YYSYMBOL_TYPE = 46,                      /* TYPE  */
  YYSYMBOL_ARRAY_TYPE = 47,                /* ARRAY_TYPE  */
  YYSYMBOL_VARIABLE_TYPE = 48,             /* VARIABLE_TYPE  */
  YYSYMBOL_BLOCK = 49,                     /* BLOCK  */
  YYSYMBOL_STATEMENT_LIST = 50,            /* STATEMENT_LIST  */
  YYSYMBOL_STATEMENT = 51,                 /* STATEMENT  */
  YYSYMBOL_DECLARATION = 52,               /* DECLARATION  */
  YYSYMBOL_ASSIGNMENT = 53,                /* ASSIGNMENT  */
  YYSYMBOL_PRINT = 54,                     /* PRINT  */
  YYSYMBOL_RETURN_STATEMENT = 55,          /* RETURN_STATEMENT  */
  YYSYMBOL_FUNCTION_CALL_STATEMENT = 56,   /* FUNCTION_CALL_STATEMENT  */
  YYSYMBOL_FUNCTION_CALL = 57,             /* FUNCTION_CALL  */
  YYSYMBOL_ARGUMENT_LIST = 58,             /* ARGUMENT_LIST  */
  YYSYMBOL_IF_STATEMENT = 59,              /* IF_STATEMENT  */
  YYSYMBOL_ELSE_CLAUSE = 60,               /* ELSE_CLAUSE  */
  YYSYMBOL_WHILE_STATEMENT = 61,           /* WHILE_STATEMENT  */
  YYSYMBOL_PRIMITIVE_TYPES = 62,           /* PRIMITIVE_TYPES  */
  YYSYMBOL_EXPRESSION = 63,                /* EXPRESSION  */
  YYSYMBOL_LOGICAL_OR = 64,                /* LOGICAL_OR  */
  YYSYMBOL_LOGICAL_AND = 65,               /* LOGICAL_AND  */
  YYSYMBOL_EQUALITY = 66,                  /* EQUALITY  */
  YYSYMBOL_RELATIONAL = 67,                /* RELATIONAL  */
  YYSYMBOL_ADDITIVE = 68,                  /* ADDITIVE  */
  YYSYMBOL_MULTIPLICATIVE = 69,            /* MULTIPLICATIVE  */
  YYSYMBOL_UNARY = 70,                     /* UNARY  */
  YYSYMBOL_PRIMARY = 71,                   /* PRIMARY  */
  YYSYMBOL_NUMBER = 72                     /* NUMBER  */
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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   115

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  76
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  136

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   277


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
       2,     2,     2,     2,     2,     2,     2,    25,     2,     2,
      30,    31,    23,    26,    32,    27,     2,    24,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    37,
      28,    38,    29,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    33,     2,    34,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    35,     2,    36,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    51,    51,    55,    68,    74,    86,    98,   105,   111,
     121,   122,   126,   133,   144,   148,   159,   163,   176,   182,
     183,   184,   185,   186,   187,   188,   189,   193,   200,   211,
     218,   230,   239,   243,   252,   259,   269,   281,   288,   294,
     301,   312,   316,   323,   333,   334,   338,   342,   347,   352,
     357,   362,   367,   372,   377,   382,   387,   392,   397,   402,
     407,   412,   417,   422,   427,   432,   437,   442,   447,   452,
     457,   461,   467,   469,   471,   476,   480
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
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFIER", "INT",
  "FLOAT", "PRINTF", "IF", "ELSE", "WHILE", "RETURN", "EQUAL_EQUAL",
  "NOT_EQUAL", "GREATER_EQUAL", "LESS_EQUAL", "GREATER", "LESS", "AND_OP",
  "OR_OP", "NOT_OP", "INT_LITERAL", "FLOAT_LITERAL", "UMINUS", "'*'",
  "'/'", "'%'", "'+'", "'-'", "'<'", "'>'", "'('", "')'", "','", "'['",
  "']'", "'{'", "'}'", "';'", "'='", "$accept", "PROGRAM", "FUNCTION_LIST",
  "FUNCTION_DECLARATION", "PARAMETER_LIST", "PARAMETER", "PARAMETER_TYPE",
  "TYPE", "ARRAY_TYPE", "VARIABLE_TYPE", "BLOCK", "STATEMENT_LIST",
  "STATEMENT", "DECLARATION", "ASSIGNMENT", "PRINT", "RETURN_STATEMENT",
  "FUNCTION_CALL_STATEMENT", "FUNCTION_CALL", "ARGUMENT_LIST",
  "IF_STATEMENT", "ELSE_CLAUSE", "WHILE_STATEMENT", "PRIMITIVE_TYPES",
  "EXPRESSION", "LOGICAL_OR", "LOGICAL_AND", "EQUALITY", "RELATIONAL",
  "ADDITIVE", "MULTIPLICATIVE", "UNARY", "PRIMARY", "NUMBER", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-45)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -45,     8,    24,   -45,   -45,   -45,   -45,    27,   -45,    23,
      24,    13,   -45,    32,   -45,   -45,    47,     3,    24,   -45,
       7,   -45,   -45,   -45,   -45,    11,    19,    51,    57,    58,
       6,   -45,    86,   -45,   -45,    53,    55,    56,   -45,    59,
     -45,   -45,   -45,    61,    45,    45,    45,    45,    45,    45,
       4,    45,   -45,   -45,    45,    45,    45,   -45,   -45,    60,
      73,    78,    39,    54,    33,    -1,   -45,   -45,   -45,    62,
     -45,   -45,   -45,   -45,    45,    31,   -45,    64,   -45,    68,
      70,    71,    45,   -45,   -45,   -45,    72,   -45,    45,    45,
      45,    45,    45,    45,    45,    45,    45,    45,    45,    45,
      45,    45,    74,   -45,    45,    66,   -45,     3,     3,    75,
     -45,    78,    39,    54,    54,    33,    33,    33,    33,    -1,
      -1,   -45,   -45,   -45,   -45,   -45,   -45,    45,    97,   -45,
     -45,   -45,     5,   -45,   -45,   -45
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     2,     1,    44,    45,     3,     0,    12,     0,
       8,     0,     7,     0,    10,    11,    12,     0,     0,     9,
       0,    18,     5,     6,    13,     0,     0,     0,     0,     0,
       0,    16,     0,    26,    17,     0,     0,     0,    24,     0,
      34,    22,    23,    14,    38,     0,     0,     0,     0,     0,
      70,     0,    75,    76,     0,     0,     0,    32,    74,     0,
      46,    48,    50,    53,    58,    61,    65,    69,    72,    27,
      19,    20,    21,    25,     0,     0,    37,     0,    29,     0,
       0,     0,     0,    68,    66,    67,     0,    33,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    35,     0,     0,    31,     0,     0,     0,
      73,    47,    49,    51,    52,    56,    57,    54,    55,    59,
      60,    62,    63,    64,    28,    15,    36,     0,    39,    43,
      71,    30,     0,    40,    41,    42
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -45,   -45,   -45,   -45,   -45,    88,   -45,   108,   -45,   -45,
     -25,   -45,   -45,   -45,   -45,   -45,   -45,   -45,    87,   -45,
     -21,   -45,   -45,    17,   -43,   -45,    25,    26,   -17,   -16,
     -11,   -44,   -45,   -45
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,     6,    11,    12,    13,    14,    15,    32,
      22,    25,    34,    35,    36,    37,    38,    39,    58,    75,
      41,   133,    42,    16,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      33,    76,    77,    78,    79,    80,    81,    83,     3,    50,
      84,    85,    28,    86,    26,     4,     5,    27,    28,     8,
      29,    30,    98,    99,   100,    51,    52,    53,     4,     5,
       9,   102,    54,    55,    44,    19,    56,    82,    21,   109,
      21,    24,    43,    57,    17,    18,    21,    31,    50,    44,
      90,    91,    45,    10,   121,   122,   123,    46,   124,    96,
      97,   126,   103,   104,    51,    52,    53,    92,    93,    94,
      95,    54,    55,   113,   114,    56,   115,   116,   117,   118,
      20,    47,   128,   129,   131,   119,   120,    48,    49,    69,
      70,    88,    71,    72,    74,    89,    73,    87,   105,   106,
     101,   107,   108,   110,   127,   132,    23,   134,   125,   130,
       7,   135,    40,   111,     0,   112
};

static const yytype_int16 yycheck[] =
{
      25,    44,    45,    46,    47,    48,    49,    51,     0,     3,
      54,    55,     7,    56,     3,     4,     5,     6,     7,     2,
       9,    10,    23,    24,    25,    19,    20,    21,     4,     5,
       3,    74,    26,    27,    30,     3,    30,    33,    35,    82,
      35,    34,    25,    37,    31,    32,    35,    36,     3,    30,
      11,    12,    33,    30,    98,    99,   100,    38,   101,    26,
      27,   104,    31,    32,    19,    20,    21,    13,    14,    15,
      16,    26,    27,    90,    91,    30,    92,    93,    94,    95,
      33,    30,   107,   108,   127,    96,    97,    30,    30,     3,
      37,    18,    37,    37,    33,    17,    37,    37,    34,    31,
      38,    31,    31,    31,    38,     8,    18,   132,    34,    34,
       2,   132,    25,    88,    -1,    89
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    40,    41,     0,     4,     5,    42,    46,    62,     3,
      30,    43,    44,    45,    46,    47,    62,    31,    32,     3,
      33,    35,    49,    44,    34,    50,     3,     6,     7,     9,
      10,    36,    48,    49,    51,    52,    53,    54,    55,    56,
      57,    59,    61,    62,    30,    33,    38,    30,    30,    30,
       3,    19,    20,    21,    26,    27,    30,    37,    57,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,     3,
      37,    37,    37,    37,    33,    58,    63,    63,    63,    63,
      63,    63,    33,    70,    70,    70,    63,    37,    18,    17,
      11,    12,    13,    14,    15,    16,    26,    27,    23,    24,
      25,    38,    63,    31,    32,    34,    31,    31,    31,    63,
      31,    65,    66,    67,    67,    68,    68,    68,    68,    69,
      69,    70,    70,    70,    63,    34,    63,    38,    49,    49,
      34,    63,     8,    60,    49,    59
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    39,    40,    41,    41,    42,    43,    43,    43,    44,
      45,    45,    46,    47,    48,    48,    49,    50,    50,    51,
      51,    51,    51,    51,    51,    51,    51,    52,    52,    53,
      53,    54,    55,    55,    56,    57,    58,    58,    58,    59,
      59,    60,    60,    61,    62,    62,    63,    64,    64,    65,
      65,    66,    66,    66,    67,    67,    67,    67,    67,    68,
      68,    68,    69,    69,    69,    69,    70,    70,    70,    70,
      71,    71,    71,    71,    71,    72,    72
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     6,     3,     1,     0,     2,
       1,     1,     1,     3,     1,     4,     3,     2,     0,     2,
       2,     2,     1,     1,     1,     2,     1,     2,     4,     3,
       6,     4,     2,     3,     1,     4,     3,     1,     0,     5,
       6,     2,     2,     5,     1,     1,     1,     3,     1,     3,
       1,     3,     3,     1,     3,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     3,     1,     2,     2,     2,     1,
       1,     4,     1,     3,     1,     1,     1
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
  case 2: /* PROGRAM: FUNCTION_LIST  */
#line 51 "balbismo.y"
                               { ast_root = (yyvsp[0].ast); }
#line 1229 "balbismo.tab.c"
    break;

  case 3: /* FUNCTION_LIST: FUNCTION_LIST FUNCTION_DECLARATION  */
#line 56 "balbismo.y"
        {
            ASTNode** new_children = realloc((yyvsp[-1].ast)->children, sizeof(ASTNode*) * ((yyvsp[-1].ast)->num_children + 1));
            if (new_children == NULL) {
                yyerror("Memory allocation failed for FUNCTION_LIST.");
                exit(1);
            }
            new_children[(yyvsp[-1].ast)->num_children] = (yyvsp[0].ast);
            (yyvsp[-1].ast)->children = new_children;
            (yyvsp[-1].ast)->num_children += 1;
            (yyval.ast) = (yyvsp[-1].ast);
        }
#line 1245 "balbismo.tab.c"
    break;

  case 4: /* FUNCTION_LIST: %empty  */
#line 68 "balbismo.y"
        {
            (yyval.ast) = create_node(NODE_FUNCTION_LIST, NULL, 0, NULL);
        }
#line 1253 "balbismo.tab.c"
    break;

  case 5: /* FUNCTION_DECLARATION: TYPE IDENTIFIER '(' PARAMETER_LIST ')' BLOCK  */
#line 75 "balbismo.y"
        {
            ASTNode* return_type_node = (yyvsp[-5].ast);
            ASTNode* function_name_node = create_node(NODE_IDENTIFIER, (yyvsp[-4].str), 0, NULL);
            ASTNode* parameter_list_node = (yyvsp[-2].ast);
            ASTNode* block_node = (yyvsp[0].ast);
            ASTNode* children_array[] = { return_type_node, function_name_node, parameter_list_node, block_node };
            (yyval.ast) = create_node(NODE_FUNCTION_DECLARATION, NULL, 4, children_array);
        }
#line 1266 "balbismo.tab.c"
    break;

  case 6: /* PARAMETER_LIST: PARAMETER_LIST ',' PARAMETER  */
#line 87 "balbismo.y"
        {
            ASTNode** new_children = realloc((yyvsp[-2].ast)->children, sizeof(ASTNode*) * ((yyvsp[-2].ast)->num_children + 1));
            if (new_children == NULL) {
                yyerror("Memory allocation failed for PARAMETER_LIST.");
                exit(1);
            }
            new_children[(yyvsp[-2].ast)->num_children] = (yyvsp[0].ast);
            (yyvsp[-2].ast)->children = new_children;
            (yyvsp[-2].ast)->num_children += 1;
            (yyval.ast) = (yyvsp[-2].ast);
        }
#line 1282 "balbismo.tab.c"
    break;

  case 7: /* PARAMETER_LIST: PARAMETER  */
#line 99 "balbismo.y"
        {
            ASTNode** children_array = malloc(sizeof(ASTNode*));
            children_array[0] = (yyvsp[0].ast);
            (yyval.ast) = create_node(NODE_PARAMETER_LIST, NULL, 1, children_array);
        }
#line 1292 "balbismo.tab.c"
    break;

  case 8: /* PARAMETER_LIST: %empty  */
#line 105 "balbismo.y"
        {
            (yyval.ast) = create_node(NODE_PARAMETER_LIST, NULL, 0, NULL);
        }
#line 1300 "balbismo.tab.c"
    break;

  case 9: /* PARAMETER: PARAMETER_TYPE IDENTIFIER  */
#line 112 "balbismo.y"
        {
            ASTNode* type_node = (yyvsp[-1].ast);
            ASTNode* id_node = create_node(NODE_IDENTIFIER, (yyvsp[0].str), 0, NULL);
            ASTNode* children_array[] = { type_node, id_node };
            (yyval.ast) = create_node(NODE_DECLARATION, NULL, 2, children_array);
        }
#line 1311 "balbismo.tab.c"
    break;

  case 12: /* TYPE: PRIMITIVE_TYPES  */
#line 127 "balbismo.y"
        {
            (yyval.ast) = create_node(NODE_TYPE, (yyvsp[0].str), 0, NULL);
        }
#line 1319 "balbismo.tab.c"
    break;

  case 13: /* ARRAY_TYPE: PRIMITIVE_TYPES '[' ']'  */
#line 134 "balbismo.y"
        {
            ASTNode* type_node = create_node(NODE_TYPE, (yyvsp[-2].str), 0, NULL);
            ASTNode* array_specifier = create_node(NODE_ARRAY_SPECIFIER, NULL, 0, NULL);
            ASTNode* children_array[] = { type_node, array_specifier };
            (yyval.ast) = create_node(NODE_ARRAY_TYPE, NULL, 2, children_array);
        }
#line 1330 "balbismo.tab.c"
    break;

  case 14: /* VARIABLE_TYPE: PRIMITIVE_TYPES  */
#line 145 "balbismo.y"
        {
            (yyval.ast) = create_node(NODE_TYPE, (yyvsp[0].str), 0, NULL);
        }
#line 1338 "balbismo.tab.c"
    break;

  case 15: /* VARIABLE_TYPE: PRIMITIVE_TYPES '[' EXPRESSION ']'  */
#line 149 "balbismo.y"
        {
            ASTNode* type_node = create_node(NODE_TYPE, (yyvsp[-3].str), 0, NULL);
            ASTNode* size_node = (yyvsp[-1].ast);
            ASTNode* array_specifier = create_node(NODE_ARRAY_SPECIFIER, NULL, 1, &size_node);
            ASTNode* children_array[] = { type_node, array_specifier };
            (yyval.ast) = create_node(NODE_ARRAY_TYPE, NULL, 2, children_array);
        }
#line 1350 "balbismo.tab.c"
    break;

  case 16: /* BLOCK: '{' STATEMENT_LIST '}'  */
#line 159 "balbismo.y"
                             { (yyval.ast) = create_node(NODE_BLOCK, NULL, (yyvsp[-1].ast)->num_children, (yyvsp[-1].ast)->children); }
#line 1356 "balbismo.tab.c"
    break;

  case 17: /* STATEMENT_LIST: STATEMENT_LIST STATEMENT  */
#line 164 "balbismo.y"
        {
            ASTNode** new_children = realloc((yyvsp[-1].ast)->children, sizeof(ASTNode*) * ((yyvsp[-1].ast)->num_children + 1));
            if (new_children == NULL) {
                yyerror("Memory allocation failed for STATEMENT_LIST.");
                exit(1);
            }
            new_children[(yyvsp[-1].ast)->num_children] = (yyvsp[0].ast);
            (yyvsp[-1].ast)->children = new_children;
            (yyvsp[-1].ast)->num_children += 1;
            (yyval.ast) = (yyvsp[-1].ast);
        }
#line 1372 "balbismo.tab.c"
    break;

  case 18: /* STATEMENT_LIST: %empty  */
#line 176 "balbismo.y"
        {
            (yyval.ast) = create_node(NODE_STATEMENT_LIST, NULL, 0, NULL);
        }
#line 1380 "balbismo.tab.c"
    break;

  case 19: /* STATEMENT: DECLARATION ';'  */
#line 182 "balbismo.y"
                               { (yyval.ast) = (yyvsp[-1].ast); }
#line 1386 "balbismo.tab.c"
    break;

  case 20: /* STATEMENT: ASSIGNMENT ';'  */
#line 183 "balbismo.y"
                               { (yyval.ast) = (yyvsp[-1].ast); }
#line 1392 "balbismo.tab.c"
    break;

  case 21: /* STATEMENT: PRINT ';'  */
#line 184 "balbismo.y"
                               { (yyval.ast) = (yyvsp[-1].ast); }
#line 1398 "balbismo.tab.c"
    break;

  case 22: /* STATEMENT: IF_STATEMENT  */
#line 185 "balbismo.y"
                               { (yyval.ast) = (yyvsp[0].ast); }
#line 1404 "balbismo.tab.c"
    break;

  case 23: /* STATEMENT: WHILE_STATEMENT  */
#line 186 "balbismo.y"
                               { (yyval.ast) = (yyvsp[0].ast); }
#line 1410 "balbismo.tab.c"
    break;

  case 24: /* STATEMENT: RETURN_STATEMENT  */
#line 187 "balbismo.y"
                               { (yyval.ast) = (yyvsp[0].ast); }
#line 1416 "balbismo.tab.c"
    break;

  case 25: /* STATEMENT: FUNCTION_CALL_STATEMENT ';'  */
#line 188 "balbismo.y"
                                  { (yyval.ast) = (yyvsp[-1].ast); }
#line 1422 "balbismo.tab.c"
    break;

  case 26: /* STATEMENT: BLOCK  */
#line 189 "balbismo.y"
                               { (yyval.ast) = (yyvsp[0].ast); }
#line 1428 "balbismo.tab.c"
    break;

  case 27: /* DECLARATION: VARIABLE_TYPE IDENTIFIER  */
#line 194 "balbismo.y"
        {
            ASTNode* type_node = (yyvsp[-1].ast);
            ASTNode* id_node = create_node(NODE_IDENTIFIER, (yyvsp[0].str), 0, NULL);
            ASTNode* children_array[] = { type_node, id_node };
            (yyval.ast) = create_node(NODE_DECLARATION, NULL, 2, children_array);
        }
#line 1439 "balbismo.tab.c"
    break;

  case 28: /* DECLARATION: VARIABLE_TYPE IDENTIFIER '=' EXPRESSION  */
#line 201 "balbismo.y"
        {
            ASTNode* type_node = (yyvsp[-3].ast);
            ASTNode* id_node = create_node(NODE_IDENTIFIER, (yyvsp[-2].str), 0, NULL);
            ASTNode* expr_node = (yyvsp[0].ast);
            ASTNode* children_array[] = { type_node, id_node, expr_node };
            (yyval.ast) = create_node(NODE_DECLARATION, NULL, 3, children_array);
        }
#line 1451 "balbismo.tab.c"
    break;

  case 29: /* ASSIGNMENT: IDENTIFIER '=' EXPRESSION  */
#line 212 "balbismo.y"
        {
            ASTNode* id_node = create_node(NODE_IDENTIFIER, (yyvsp[-2].str), 0, NULL);
            ASTNode* expr_node = (yyvsp[0].ast);
            ASTNode* children_array[] = { id_node, expr_node };
            (yyval.ast) = create_node(NODE_ASSIGNMENT, NULL, 2, children_array);
        }
#line 1462 "balbismo.tab.c"
    break;

  case 30: /* ASSIGNMENT: IDENTIFIER '[' EXPRESSION ']' '=' EXPRESSION  */
#line 219 "balbismo.y"
        {
            ASTNode* index_node = (yyvsp[-3].ast);
            ASTNode* lhs_children[] = { index_node };
            ASTNode* indexed_id_node = create_node(NODE_INDEXED_IDENTIFIER, (yyvsp[-5].str), 1, lhs_children);
            ASTNode* expr_node = (yyvsp[0].ast);
            ASTNode* children_array[] = { indexed_id_node, expr_node };
            (yyval.ast) = create_node(NODE_ASSIGNMENT, NULL, 2, children_array);
        }
#line 1475 "balbismo.tab.c"
    break;

  case 31: /* PRINT: PRINTF '(' EXPRESSION ')'  */
#line 231 "balbismo.y"
        {
            ASTNode* expr_node = (yyvsp[-1].ast);
            ASTNode* children_array[] = { expr_node };
            (yyval.ast) = create_node(NODE_PRINT, NULL, 1, children_array);
        }
#line 1485 "balbismo.tab.c"
    break;

  case 32: /* RETURN_STATEMENT: RETURN ';'  */
#line 240 "balbismo.y"
        {
            (yyval.ast) = create_node(NODE_RETURN_STATEMENT, NULL, 0, NULL);
        }
#line 1493 "balbismo.tab.c"
    break;

  case 33: /* RETURN_STATEMENT: RETURN EXPRESSION ';'  */
#line 244 "balbismo.y"
        {
            ASTNode* expr_node = (yyvsp[-1].ast);
            ASTNode* children_array[] = { expr_node };
            (yyval.ast) = create_node(NODE_RETURN_STATEMENT, NULL, 1, children_array);
        }
#line 1503 "balbismo.tab.c"
    break;

  case 34: /* FUNCTION_CALL_STATEMENT: FUNCTION_CALL  */
#line 253 "balbismo.y"
        {
            (yyval.ast) = (yyvsp[0].ast);
        }
#line 1511 "balbismo.tab.c"
    break;

  case 35: /* FUNCTION_CALL: IDENTIFIER '(' ARGUMENT_LIST ')'  */
#line 260 "balbismo.y"
        {
            ASTNode* function_name_node = create_node(NODE_IDENTIFIER, (yyvsp[-3].str), 0, NULL);
            ASTNode* argument_list_node = (yyvsp[-1].ast);
            ASTNode* children_array[] = { function_name_node, argument_list_node };
            (yyval.ast) = create_node(NODE_FUNCTION_CALL, NULL, 2, children_array);
        }
#line 1522 "balbismo.tab.c"
    break;

  case 36: /* ARGUMENT_LIST: ARGUMENT_LIST ',' EXPRESSION  */
#line 270 "balbismo.y"
        {
            ASTNode** new_children = realloc((yyvsp[-2].ast)->children, sizeof(ASTNode*) * ((yyvsp[-2].ast)->num_children + 1));
            if (new_children == NULL) {
                yyerror("Memory allocation failed for ARGUMENT_LIST.");
                exit(1);
            }
            new_children[(yyvsp[-2].ast)->num_children] = (yyvsp[0].ast);
            (yyvsp[-2].ast)->children = new_children;
            (yyvsp[-2].ast)->num_children += 1;
            (yyval.ast) = (yyvsp[-2].ast);
        }
#line 1538 "balbismo.tab.c"
    break;

  case 37: /* ARGUMENT_LIST: EXPRESSION  */
#line 282 "balbismo.y"
        {
            ASTNode** children_array = malloc(sizeof(ASTNode*));
            children_array[0] = (yyvsp[0].ast);
            (yyval.ast) = create_node(NODE_ARGUMENT_LIST, NULL, 1, children_array);
        }
#line 1548 "balbismo.tab.c"
    break;

  case 38: /* ARGUMENT_LIST: %empty  */
#line 288 "balbismo.y"
        {
            (yyval.ast) = create_node(NODE_ARGUMENT_LIST, NULL, 0, NULL);
        }
#line 1556 "balbismo.tab.c"
    break;

  case 39: /* IF_STATEMENT: IF '(' EXPRESSION ')' BLOCK  */
#line 295 "balbismo.y"
        {
            ASTNode* condition = (yyvsp[-2].ast);
            ASTNode* if_block = (yyvsp[0].ast);
            ASTNode* children_array[] = { condition, if_block };
            (yyval.ast) = create_node(NODE_IF_STATEMENT, NULL, 2, children_array);
        }
#line 1567 "balbismo.tab.c"
    break;

  case 40: /* IF_STATEMENT: IF '(' EXPRESSION ')' BLOCK ELSE_CLAUSE  */
#line 302 "balbismo.y"
        {
            ASTNode* condition = (yyvsp[-3].ast);
            ASTNode* if_block = (yyvsp[-1].ast);
            ASTNode* else_clause = (yyvsp[0].ast);
            ASTNode* children_array[] = { condition, if_block, else_clause };
            (yyval.ast) = create_node(NODE_IF_STATEMENT, NULL, 3, children_array);
        }
#line 1579 "balbismo.tab.c"
    break;

  case 41: /* ELSE_CLAUSE: ELSE BLOCK  */
#line 313 "balbismo.y"
        {
            (yyval.ast) = (yyvsp[0].ast);
        }
#line 1587 "balbismo.tab.c"
    break;

  case 42: /* ELSE_CLAUSE: ELSE IF_STATEMENT  */
#line 317 "balbismo.y"
        {
            (yyval.ast) = (yyvsp[0].ast);
        }
#line 1595 "balbismo.tab.c"
    break;

  case 43: /* WHILE_STATEMENT: WHILE '(' EXPRESSION ')' BLOCK  */
#line 324 "balbismo.y"
        {
            ASTNode* condition = (yyvsp[-2].ast);
            ASTNode* body = (yyvsp[0].ast);
            ASTNode* children_array[] = { condition, body };
            (yyval.ast) = create_node(NODE_WHILE_STATEMENT, NULL, 2, children_array);
        }
#line 1606 "balbismo.tab.c"
    break;

  case 44: /* PRIMITIVE_TYPES: INT  */
#line 333 "balbismo.y"
               { (yyval.str) = strdup("int"); }
#line 1612 "balbismo.tab.c"
    break;

  case 45: /* PRIMITIVE_TYPES: FLOAT  */
#line 334 "balbismo.y"
               { (yyval.str) = strdup("float"); }
#line 1618 "balbismo.tab.c"
    break;

  case 46: /* EXPRESSION: LOGICAL_OR  */
#line 338 "balbismo.y"
                           { (yyval.ast) = (yyvsp[0].ast); }
#line 1624 "balbismo.tab.c"
    break;

  case 47: /* LOGICAL_OR: LOGICAL_OR OR_OP LOGICAL_AND  */
#line 343 "balbismo.y"
        {
            ASTNode* children_array[] = { (yyvsp[-2].ast), (yyvsp[0].ast) };
            (yyval.ast) = create_node(NODE_BOOL_BIN_OP, "||", 2, children_array);
        }
#line 1633 "balbismo.tab.c"
    break;

  case 48: /* LOGICAL_OR: LOGICAL_AND  */
#line 348 "balbismo.y"
        { (yyval.ast) = (yyvsp[0].ast); }
#line 1639 "balbismo.tab.c"
    break;

  case 49: /* LOGICAL_AND: LOGICAL_AND AND_OP EQUALITY  */
#line 353 "balbismo.y"
        {
            ASTNode* children_array[] = { (yyvsp[-2].ast), (yyvsp[0].ast) };
            (yyval.ast) = create_node(NODE_BOOL_BIN_OP, "&&", 2, children_array);
        }
#line 1648 "balbismo.tab.c"
    break;

  case 50: /* LOGICAL_AND: EQUALITY  */
#line 358 "balbismo.y"
        { (yyval.ast) = (yyvsp[0].ast); }
#line 1654 "balbismo.tab.c"
    break;

  case 51: /* EQUALITY: EQUALITY EQUAL_EQUAL RELATIONAL  */
#line 363 "balbismo.y"
        {
            ASTNode* children_array[] = { (yyvsp[-2].ast), (yyvsp[0].ast) };
            (yyval.ast) = create_node(NODE_REL_OP, "==", 2, children_array);
        }
#line 1663 "balbismo.tab.c"
    break;

  case 52: /* EQUALITY: EQUALITY NOT_EQUAL RELATIONAL  */
#line 368 "balbismo.y"
        {
            ASTNode* children_array[] = { (yyvsp[-2].ast), (yyvsp[0].ast) };
            (yyval.ast) = create_node(NODE_REL_OP, "!=", 2, children_array);
        }
#line 1672 "balbismo.tab.c"
    break;

  case 53: /* EQUALITY: RELATIONAL  */
#line 373 "balbismo.y"
        { (yyval.ast) = (yyvsp[0].ast); }
#line 1678 "balbismo.tab.c"
    break;

  case 54: /* RELATIONAL: RELATIONAL GREATER ADDITIVE  */
#line 378 "balbismo.y"
        {
            ASTNode* children_array[] = { (yyvsp[-2].ast), (yyvsp[0].ast) };
            (yyval.ast) = create_node(NODE_REL_OP, ">", 2, children_array);
        }
#line 1687 "balbismo.tab.c"
    break;

  case 55: /* RELATIONAL: RELATIONAL LESS ADDITIVE  */
#line 383 "balbismo.y"
        {
            ASTNode* children_array[] = { (yyvsp[-2].ast), (yyvsp[0].ast) };
            (yyval.ast) = create_node(NODE_REL_OP, "<", 2, children_array);
        }
#line 1696 "balbismo.tab.c"
    break;

  case 56: /* RELATIONAL: RELATIONAL GREATER_EQUAL ADDITIVE  */
#line 388 "balbismo.y"
        {
            ASTNode* children_array[] = { (yyvsp[-2].ast), (yyvsp[0].ast) };
            (yyval.ast) = create_node(NODE_REL_OP, ">=", 2, children_array);
        }
#line 1705 "balbismo.tab.c"
    break;

  case 57: /* RELATIONAL: RELATIONAL LESS_EQUAL ADDITIVE  */
#line 393 "balbismo.y"
        {
            ASTNode* children_array[] = { (yyvsp[-2].ast), (yyvsp[0].ast) };
            (yyval.ast) = create_node(NODE_REL_OP, "<=", 2, children_array);
        }
#line 1714 "balbismo.tab.c"
    break;

  case 58: /* RELATIONAL: ADDITIVE  */
#line 398 "balbismo.y"
        { (yyval.ast) = (yyvsp[0].ast); }
#line 1720 "balbismo.tab.c"
    break;

  case 59: /* ADDITIVE: ADDITIVE '+' MULTIPLICATIVE  */
#line 403 "balbismo.y"
        {
            ASTNode* children_array[] = { (yyvsp[-2].ast), (yyvsp[0].ast) };
            (yyval.ast) = create_node(NODE_BIN_OP, "+", 2, children_array);
        }
#line 1729 "balbismo.tab.c"
    break;

  case 60: /* ADDITIVE: ADDITIVE '-' MULTIPLICATIVE  */
#line 408 "balbismo.y"
        {
            ASTNode* children_array[] = { (yyvsp[-2].ast), (yyvsp[0].ast) };
            (yyval.ast) = create_node(NODE_BIN_OP, "-", 2, children_array);
        }
#line 1738 "balbismo.tab.c"
    break;

  case 61: /* ADDITIVE: MULTIPLICATIVE  */
#line 413 "balbismo.y"
        { (yyval.ast) = (yyvsp[0].ast); }
#line 1744 "balbismo.tab.c"
    break;

  case 62: /* MULTIPLICATIVE: MULTIPLICATIVE '*' UNARY  */
#line 418 "balbismo.y"
        {
            ASTNode* children_array[] = { (yyvsp[-2].ast), (yyvsp[0].ast) };
            (yyval.ast) = create_node(NODE_BIN_OP, "*", 2, children_array);
        }
#line 1753 "balbismo.tab.c"
    break;

  case 63: /* MULTIPLICATIVE: MULTIPLICATIVE '/' UNARY  */
#line 423 "balbismo.y"
        {
            ASTNode* children_array[] = { (yyvsp[-2].ast), (yyvsp[0].ast) };
            (yyval.ast) = create_node(NODE_BIN_OP, "/", 2, children_array);
        }
#line 1762 "balbismo.tab.c"
    break;

  case 64: /* MULTIPLICATIVE: MULTIPLICATIVE '%' UNARY  */
#line 428 "balbismo.y"
        {
            ASTNode* children_array[] = { (yyvsp[-2].ast), (yyvsp[0].ast) };
            (yyval.ast) = create_node(NODE_BIN_OP, "%", 2, children_array);
        }
#line 1771 "balbismo.tab.c"
    break;

  case 65: /* MULTIPLICATIVE: UNARY  */
#line 433 "balbismo.y"
        { (yyval.ast) = (yyvsp[0].ast); }
#line 1777 "balbismo.tab.c"
    break;

  case 66: /* UNARY: '+' UNARY  */
#line 438 "balbismo.y"
        {
            ASTNode* children_array[] = { (yyvsp[0].ast) };
            (yyval.ast) = create_node(NODE_UN_OP, "+", 1, children_array);
        }
#line 1786 "balbismo.tab.c"
    break;

  case 67: /* UNARY: '-' UNARY  */
#line 443 "balbismo.y"
        {
            ASTNode* children_array[] = { (yyvsp[0].ast) };
            (yyval.ast) = create_node(NODE_UN_OP, "-", 1, children_array);
        }
#line 1795 "balbismo.tab.c"
    break;

  case 68: /* UNARY: NOT_OP UNARY  */
#line 448 "balbismo.y"
        {
            ASTNode* children_array[] = { (yyvsp[0].ast) };
            (yyval.ast) = create_node(NODE_BOOL_UN_OP, "!", 1, children_array);
        }
#line 1804 "balbismo.tab.c"
    break;

  case 69: /* UNARY: PRIMARY  */
#line 453 "balbismo.y"
        { (yyval.ast) = (yyvsp[0].ast); }
#line 1810 "balbismo.tab.c"
    break;

  case 70: /* PRIMARY: IDENTIFIER  */
#line 458 "balbismo.y"
        {
            (yyval.ast) = create_node(NODE_IDENTIFIER, (yyvsp[0].str), 0, NULL);
        }
#line 1818 "balbismo.tab.c"
    break;

  case 71: /* PRIMARY: IDENTIFIER '[' EXPRESSION ']'  */
#line 462 "balbismo.y"
        {
            ASTNode* index_node = (yyvsp[-1].ast);
            ASTNode* children_array[] = { index_node };
            (yyval.ast) = create_node(NODE_INDEXED_IDENTIFIER, (yyvsp[-3].str), 1, children_array);
        }
#line 1828 "balbismo.tab.c"
    break;

  case 72: /* PRIMARY: NUMBER  */
#line 468 "balbismo.y"
        { (yyval.ast) = (yyvsp[0].ast); }
#line 1834 "balbismo.tab.c"
    break;

  case 73: /* PRIMARY: '(' EXPRESSION ')'  */
#line 470 "balbismo.y"
        { (yyval.ast) = (yyvsp[-1].ast); }
#line 1840 "balbismo.tab.c"
    break;

  case 74: /* PRIMARY: FUNCTION_CALL  */
#line 472 "balbismo.y"
        { (yyval.ast) = (yyvsp[0].ast); }
#line 1846 "balbismo.tab.c"
    break;

  case 75: /* NUMBER: INT_LITERAL  */
#line 477 "balbismo.y"
        {
            (yyval.ast) = create_node(NODE_INT_LITERAL, (yyvsp[0].str), 0, NULL);
        }
#line 1854 "balbismo.tab.c"
    break;

  case 76: /* NUMBER: FLOAT_LITERAL  */
#line 481 "balbismo.y"
        {
            (yyval.ast) = create_node(NODE_FLOAT_LITERAL, (yyvsp[0].str), 0, NULL);
        }
#line 1862 "balbismo.tab.c"
    break;


#line 1866 "balbismo.tab.c"

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

#line 485 "balbismo.y"

/* C Code Section */
void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main(int argc, char** argv) {
    FILE* yaml_file = NULL;

    if (argc > 2 && strcmp(argv[1], "-o") == 0) {
        yaml_file = fopen(argv[2], "w");
        if (yaml_file == NULL) {
            fprintf(stderr, "Error: Cannot open output file %s\n", argv[2]);
            return 1;
        }
    } else {
        yaml_file = stdout;
    }

    if (yyparse() == 0) {
        if (ast_root == NULL) {
            fprintf(stderr, "Error: AST root is NULL.\n");
        } else {
            printf("\nAbstract Syntax Tree (YAML):\n");
            print_ast_yaml(yaml_file, ast_root, 0);
        }

        if (yaml_file != stdout)
            fclose(yaml_file);

        free_ast(ast_root);
    }

    return 0;
}
