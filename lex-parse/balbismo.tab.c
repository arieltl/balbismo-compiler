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

#include "ast.h"          /* Include AST definitions first */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void yyerror(const char *s);
int yylex();

ASTNode* ast_root;        /* Root of the AST */

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
  YYSYMBOL_EQUAL_EQUAL = 9,                /* EQUAL_EQUAL  */
  YYSYMBOL_NOT_EQUAL = 10,                 /* NOT_EQUAL  */
  YYSYMBOL_GREATER_EQUAL = 11,             /* GREATER_EQUAL  */
  YYSYMBOL_LESS_EQUAL = 12,                /* LESS_EQUAL  */
  YYSYMBOL_GREATER = 13,                   /* GREATER  */
  YYSYMBOL_LESS = 14,                      /* LESS  */
  YYSYMBOL_AND_OP = 15,                    /* AND_OP  */
  YYSYMBOL_OR_OP = 16,                     /* OR_OP  */
  YYSYMBOL_NOT_OP = 17,                    /* NOT_OP  */
  YYSYMBOL_INT_LITERAL = 18,               /* INT_LITERAL  */
  YYSYMBOL_FLOAT_LITERAL = 19,             /* FLOAT_LITERAL  */
  YYSYMBOL_20_ = 20,                       /* '+'  */
  YYSYMBOL_21_ = 21,                       /* '-'  */
  YYSYMBOL_22_ = 22,                       /* '*'  */
  YYSYMBOL_23_ = 23,                       /* '/'  */
  YYSYMBOL_24_ = 24,                       /* '%'  */
  YYSYMBOL_UMINUS = 25,                    /* UMINUS  */
  YYSYMBOL_26_ = 26,                       /* '{'  */
  YYSYMBOL_27_ = 27,                       /* '}'  */
  YYSYMBOL_28_ = 28,                       /* ';'  */
  YYSYMBOL_29_ = 29,                       /* '('  */
  YYSYMBOL_30_ = 30,                       /* ')'  */
  YYSYMBOL_31_ = 31,                       /* '='  */
  YYSYMBOL_YYACCEPT = 32,                  /* $accept  */
  YYSYMBOL_PROGRAM = 33,                   /* PROGRAM  */
  YYSYMBOL_BLOCK = 34,                     /* BLOCK  */
  YYSYMBOL_STATEMENT_LIST = 35,            /* STATEMENT_LIST  */
  YYSYMBOL_STATEMENT = 36,                 /* STATEMENT  */
  YYSYMBOL_matched_stmt = 37,              /* matched_stmt  */
  YYSYMBOL_unmatched_stmt = 38,            /* unmatched_stmt  */
  YYSYMBOL_DECLARATION = 39,               /* DECLARATION  */
  YYSYMBOL_ASSIGNMENT = 40,                /* ASSIGNMENT  */
  YYSYMBOL_PRINT = 41,                     /* PRINT  */
  YYSYMBOL_IF_STATEMENT = 42,              /* IF_STATEMENT  */
  YYSYMBOL_TYPES = 43,                     /* TYPES  */
  YYSYMBOL_RELATIONAL_EXPRESSION = 44,     /* RELATIONAL_EXPRESSION  */
  YYSYMBOL_EXPRESSION = 45,                /* EXPRESSION  */
  YYSYMBOL_TERM = 46,                      /* TERM  */
  YYSYMBOL_FACTOR = 47,                    /* FACTOR  */
  YYSYMBOL_NUMBER = 48                     /* NUMBER  */
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
typedef yytype_int8 yy_state_t;

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
#define YYFINAL  20
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   134

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  17
/* YYNRULES -- Number of rules.  */
#define YYNRULES  45
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  88

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   275


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
       2,     2,     2,     2,     2,     2,     2,    24,     2,     2,
      29,    30,    22,    20,     2,    21,     2,    23,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    28,
       2,    31,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    26,     2,    27,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    25
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    46,    46,    50,    51,    55,    60,    78,    79,    83,
      84,    85,    86,    87,    91,   101,   108,   119,   129,   138,
     149,   150,   154,   156,   162,   168,   174,   180,   186,   195,
     197,   203,   209,   218,   220,   226,   232,   238,   247,   253,
     259,   265,   267,   269,   277,   282
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
  "FLOAT", "PRINTF", "IF", "ELSE", "EQUAL_EQUAL", "NOT_EQUAL",
  "GREATER_EQUAL", "LESS_EQUAL", "GREATER", "LESS", "AND_OP", "OR_OP",
  "NOT_OP", "INT_LITERAL", "FLOAT_LITERAL", "'+'", "'-'", "'*'", "'/'",
  "'%'", "UMINUS", "'{'", "'}'", "';'", "'('", "')'", "'='", "$accept",
  "PROGRAM", "BLOCK", "STATEMENT_LIST", "STATEMENT", "matched_stmt",
  "unmatched_stmt", "DECLARATION", "ASSIGNMENT", "PRINT", "IF_STATEMENT",
  "TYPES", "RELATIONAL_EXPRESSION", "EXPRESSION", "TERM", "FACTOR",
  "NUMBER", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-53)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -21,    12,     4,   -53,   -11,   -53,   -53,   -19,    -1,   -53,
     -53,    37,   -53,   -53,   -53,    -7,     8,     9,   -53,    50,
     -53,     6,     6,     6,   -53,   -53,   -53,   -53,   -53,    29,
     -53,     6,   -53,   -53,     6,     6,     6,   114,    -8,    93,
     -53,   -53,    60,    70,     6,   -53,   -53,   -53,    82,     6,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     6,   -53,    42,   114,   -53,    -8,    -8,    -8,    -8,
      -8,    -8,    93,    93,    93,   -53,   -53,   -53,   -53,   -53,
      53,    52,    36,   -53,     6,    92,    52,    53
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     2,     0,    20,    21,     0,     0,     3,
      13,     0,     5,     7,     8,     0,     0,     0,    12,     0,
       1,     0,     0,     0,     4,     6,     9,    10,    11,    15,
      43,     0,    44,    45,     0,     0,     0,    17,    22,    29,
      33,    41,     0,     0,     0,    40,    38,    39,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    18,     0,    16,    42,    27,    28,    25,    26,
      23,    24,    32,    30,    31,    37,    34,    35,    36,    14,
       7,     0,     0,    19,     0,     0,     0,     0
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -53,   -53,    66,   -53,    -9,   -52,   -53,   -53,   -53,   -53,
     -53,   -53,   -22,    80,    -5,   -28,   -53
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    37,    38,    39,    40,    41
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      42,    43,    25,    45,    20,     1,    46,    47,    55,    30,
      22,    80,    56,    57,    48,     4,     5,     6,     7,     8,
      21,    26,    64,    31,    32,    33,    34,    35,    23,    83,
      75,    76,    77,    78,    87,    36,    27,    28,     1,     9,
       4,     5,     6,     7,     8,     4,     5,     6,     7,     8,
      72,    73,    74,    29,    79,     4,     5,     6,     7,    82,
      44,    81,    85,     1,    24,    84,     3,     0,     1,    49,
      50,    51,    52,    53,    54,     0,     0,     0,     1,    49,
      50,    51,    52,    53,    54,     0,     0,     0,     0,     0,
      62,    49,    50,    51,    52,    53,    54,     0,     0,     0,
      63,    49,    50,    51,    52,    53,    54,     0,    58,     0,
       0,     0,    65,     0,     0,    59,    60,    61,     0,     0,
       0,     0,    86,    49,    50,    51,    52,    53,    54,    66,
      67,    68,    69,    70,    71
};

static const yytype_int8 yycheck[] =
{
      22,    23,    11,    31,     0,    26,    34,    35,    16,     3,
      29,    63,    20,    21,    36,     3,     4,     5,     6,     7,
      31,    28,    44,    17,    18,    19,    20,    21,    29,    81,
      58,    59,    60,    61,    86,    29,    28,    28,    26,    27,
       3,     4,     5,     6,     7,     3,     4,     5,     6,     7,
      55,    56,    57,     3,    63,     3,     4,     5,     6,     7,
      31,     8,    84,    26,    27,    29,     0,    -1,    26,     9,
      10,    11,    12,    13,    14,    -1,    -1,    -1,    26,     9,
      10,    11,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,
      30,     9,    10,    11,    12,    13,    14,    -1,    -1,    -1,
      30,     9,    10,    11,    12,    13,    14,    -1,    15,    -1,
      -1,    -1,    30,    -1,    -1,    22,    23,    24,    -1,    -1,
      -1,    -1,    30,     9,    10,    11,    12,    13,    14,    49,
      50,    51,    52,    53,    54
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    26,    33,    34,     3,     4,     5,     6,     7,    27,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
       0,    31,    29,    29,    27,    36,    28,    28,    28,     3,
       3,    17,    18,    19,    20,    21,    29,    44,    45,    46,
      47,    48,    44,    44,    31,    47,    47,    47,    44,     9,
      10,    11,    12,    13,    14,    16,    20,    21,    15,    22,
      23,    24,    30,    30,    44,    30,    45,    45,    45,    45,
      45,    45,    46,    46,    46,    47,    47,    47,    47,    36,
      37,     8,     7,    37,    29,    44,    30,    37
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    32,    33,    34,    34,    35,    35,    36,    36,    37,
      37,    37,    37,    37,    38,    39,    39,    40,    41,    42,
      43,    43,    44,    44,    44,    44,    44,    44,    44,    45,
      45,    45,    45,    46,    46,    46,    46,    46,    47,    47,
      47,    47,    47,    47,    48,    48
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     3,     1,     2,     1,     1,     2,
       2,     2,     1,     1,     5,     2,     4,     3,     4,     7,
       1,     1,     1,     3,     3,     3,     3,     3,     3,     1,
       3,     3,     3,     1,     3,     3,     3,     3,     2,     2,
       2,     1,     3,     1,     1,     1
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
  case 2: /* PROGRAM: BLOCK  */
#line 46 "balbismo.y"
                           { ast_root = (yyvsp[0].ast); }
#line 1177 "balbismo.tab.c"
    break;

  case 3: /* BLOCK: '{' '}'  */
#line 50 "balbismo.y"
                           { (yyval.ast) = create_node(NODE_BLOCK, NULL, 0, NULL); }
#line 1183 "balbismo.tab.c"
    break;

  case 4: /* BLOCK: '{' STATEMENT_LIST '}'  */
#line 51 "balbismo.y"
                             { (yyval.ast) = create_node(NODE_BLOCK, NULL, (yyvsp[-1].ast)->num_children, (yyvsp[-1].ast)->children); }
#line 1189 "balbismo.tab.c"
    break;

  case 5: /* STATEMENT_LIST: STATEMENT  */
#line 56 "balbismo.y"
        {
            ASTNode* children_array[] = { (yyvsp[0].ast) };
            (yyval.ast) = create_node(NODE_STATEMENT_LIST, NULL, 1, children_array);
        }
#line 1198 "balbismo.tab.c"
    break;

  case 6: /* STATEMENT_LIST: STATEMENT_LIST STATEMENT  */
#line 61 "balbismo.y"
        {
            ASTNode** new_children = malloc(sizeof(ASTNode*) * ((yyvsp[-1].ast)->num_children + 1));
            if (new_children == NULL) {
                yyerror("Memory allocation failed for STATEMENT_LIST.");
                exit(1);
            }

            memcpy(new_children, (yyvsp[-1].ast)->children, sizeof(ASTNode*) * (yyvsp[-1].ast)->num_children);
            new_children[(yyvsp[-1].ast)->num_children] = (yyvsp[0].ast);

            ASTNode* new_list = create_node(NODE_STATEMENT_LIST, NULL, (yyvsp[-1].ast)->num_children + 1, new_children);
            free((yyvsp[-1].ast)->children);
            (yyval.ast) = new_list;
        }
#line 1217 "balbismo.tab.c"
    break;

  case 7: /* STATEMENT: matched_stmt  */
#line 78 "balbismo.y"
                        { (yyval.ast) = (yyvsp[0].ast); }
#line 1223 "balbismo.tab.c"
    break;

  case 8: /* STATEMENT: unmatched_stmt  */
#line 79 "balbismo.y"
                        { (yyval.ast) = (yyvsp[0].ast); }
#line 1229 "balbismo.tab.c"
    break;

  case 14: /* unmatched_stmt: IF '(' RELATIONAL_EXPRESSION ')' STATEMENT  */
#line 92 "balbismo.y"
        {
            ASTNode* condition = (yyvsp[-2].ast);
            ASTNode* if_block = (yyvsp[0].ast);
            ASTNode* children_array[] = { condition, if_block };
            (yyval.ast) = create_node(NODE_IF_STATEMENT, NULL, 2, children_array);
        }
#line 1240 "balbismo.tab.c"
    break;

  case 15: /* DECLARATION: TYPES IDENTIFIER  */
#line 102 "balbismo.y"
        {
            ASTNode* type_node = create_node(NODE_TYPE, (yyvsp[-1].str), 0, NULL);
            ASTNode* id_node = create_node(NODE_IDENTIFIER, (yyvsp[0].str), 0, NULL);
            ASTNode* children_array[] = { type_node, id_node };
            (yyval.ast) = create_node(NODE_DECLARATION, NULL, 2, children_array);
        }
#line 1251 "balbismo.tab.c"
    break;

  case 16: /* DECLARATION: TYPES IDENTIFIER '=' RELATIONAL_EXPRESSION  */
#line 109 "balbismo.y"
        {
            ASTNode* type_node = create_node(NODE_TYPE, (yyvsp[-3].str), 0, NULL);
            ASTNode* id_node = create_node(NODE_IDENTIFIER, (yyvsp[-2].str), 0, NULL);
            ASTNode* expr_node = (yyvsp[0].ast);
            ASTNode* children_array[] = { type_node, id_node, expr_node };
            (yyval.ast) = create_node(NODE_DECLARATION, NULL, 3, children_array);
        }
#line 1263 "balbismo.tab.c"
    break;

  case 17: /* ASSIGNMENT: IDENTIFIER '=' RELATIONAL_EXPRESSION  */
#line 120 "balbismo.y"
        {
            ASTNode* id_node = create_node(NODE_IDENTIFIER, (yyvsp[-2].str), 0, NULL);
            ASTNode* expr_node = (yyvsp[0].ast);
            ASTNode* children_array[] = { id_node, expr_node };
            (yyval.ast) = create_node(NODE_ASSIGNMENT, NULL, 2, children_array);
        }
#line 1274 "balbismo.tab.c"
    break;

  case 18: /* PRINT: PRINTF '(' RELATIONAL_EXPRESSION ')'  */
#line 130 "balbismo.y"
        {
            ASTNode* expr_node = (yyvsp[-1].ast);
            ASTNode* children_array[] = { expr_node };
            (yyval.ast) = create_node(NODE_PRINT, NULL, 1, children_array);
        }
#line 1284 "balbismo.tab.c"
    break;

  case 19: /* IF_STATEMENT: IF '(' RELATIONAL_EXPRESSION ')' matched_stmt ELSE matched_stmt  */
#line 139 "balbismo.y"
        {
            ASTNode* condition = (yyvsp[-4].ast);
            ASTNode* if_block = (yyvsp[-2].ast);
            ASTNode* else_block = (yyvsp[0].ast);
            ASTNode* children_array[] = { condition, if_block, else_block };
            (yyval.ast) = create_node(NODE_IF_STATEMENT, NULL, 3, children_array);
        }
#line 1296 "balbismo.tab.c"
    break;

  case 20: /* TYPES: INT  */
#line 149 "balbismo.y"
                           { (yyval.str) = (yyvsp[0].str); }
#line 1302 "balbismo.tab.c"
    break;

  case 21: /* TYPES: FLOAT  */
#line 150 "balbismo.y"
                           { (yyval.str) = (yyvsp[0].str); }
#line 1308 "balbismo.tab.c"
    break;

  case 22: /* RELATIONAL_EXPRESSION: EXPRESSION  */
#line 155 "balbismo.y"
        { (yyval.ast) = (yyvsp[0].ast); }
#line 1314 "balbismo.tab.c"
    break;

  case 23: /* RELATIONAL_EXPRESSION: RELATIONAL_EXPRESSION GREATER EXPRESSION  */
#line 157 "balbismo.y"
        {
            ASTNode* children_array[] = { (yyvsp[-2].ast), (yyvsp[0].ast) };
            ASTNode* rel_op_node = create_node(NODE_REL_OP, ">", 2, children_array);
            (yyval.ast) = rel_op_node;
        }
#line 1324 "balbismo.tab.c"
    break;

  case 24: /* RELATIONAL_EXPRESSION: RELATIONAL_EXPRESSION LESS EXPRESSION  */
#line 163 "balbismo.y"
        {
            ASTNode* children_array[] = { (yyvsp[-2].ast), (yyvsp[0].ast) };
            ASTNode* rel_op_node = create_node(NODE_REL_OP, "<", 2, children_array);
            (yyval.ast) = rel_op_node;
        }
#line 1334 "balbismo.tab.c"
    break;

  case 25: /* RELATIONAL_EXPRESSION: RELATIONAL_EXPRESSION GREATER_EQUAL EXPRESSION  */
#line 169 "balbismo.y"
        {
            ASTNode* children_array[] = { (yyvsp[-2].ast), (yyvsp[0].ast) };
            ASTNode* rel_op_node = create_node(NODE_REL_OP, ">=", 2, children_array);
            (yyval.ast) = rel_op_node;
        }
#line 1344 "balbismo.tab.c"
    break;

  case 26: /* RELATIONAL_EXPRESSION: RELATIONAL_EXPRESSION LESS_EQUAL EXPRESSION  */
#line 175 "balbismo.y"
        {
            ASTNode* children_array[] = { (yyvsp[-2].ast), (yyvsp[0].ast) };
            ASTNode* rel_op_node = create_node(NODE_REL_OP, "<=", 2, children_array);
            (yyval.ast) = rel_op_node;
        }
#line 1354 "balbismo.tab.c"
    break;

  case 27: /* RELATIONAL_EXPRESSION: RELATIONAL_EXPRESSION EQUAL_EQUAL EXPRESSION  */
#line 181 "balbismo.y"
        {
            ASTNode* children_array[] = { (yyvsp[-2].ast), (yyvsp[0].ast) };
            ASTNode* rel_op_node = create_node(NODE_REL_OP, "==", 2, children_array);
            (yyval.ast) = rel_op_node;
        }
#line 1364 "balbismo.tab.c"
    break;

  case 28: /* RELATIONAL_EXPRESSION: RELATIONAL_EXPRESSION NOT_EQUAL EXPRESSION  */
#line 187 "balbismo.y"
        {
            ASTNode* children_array[] = { (yyvsp[-2].ast), (yyvsp[0].ast) };
            ASTNode* rel_op_node = create_node(NODE_REL_OP, "!=", 2, children_array);
            (yyval.ast) = rel_op_node;
        }
#line 1374 "balbismo.tab.c"
    break;

  case 29: /* EXPRESSION: TERM  */
#line 196 "balbismo.y"
        { (yyval.ast) = (yyvsp[0].ast); }
#line 1380 "balbismo.tab.c"
    break;

  case 30: /* EXPRESSION: EXPRESSION '+' TERM  */
#line 198 "balbismo.y"
        {
            ASTNode* children_array[] = { (yyvsp[-2].ast), (yyvsp[0].ast) };
            ASTNode* bin_op_node = create_node(NODE_BIN_OP, "+", 2, children_array);
            (yyval.ast) = bin_op_node;
        }
#line 1390 "balbismo.tab.c"
    break;

  case 31: /* EXPRESSION: EXPRESSION '-' TERM  */
#line 204 "balbismo.y"
        {
            ASTNode* children_array[] = { (yyvsp[-2].ast), (yyvsp[0].ast) };
            ASTNode* bin_op_node = create_node(NODE_BIN_OP, "-", 2, children_array);
            (yyval.ast) = bin_op_node;
        }
#line 1400 "balbismo.tab.c"
    break;

  case 32: /* EXPRESSION: EXPRESSION OR_OP TERM  */
#line 210 "balbismo.y"
        {
            ASTNode* children_array[] = { (yyvsp[-2].ast), (yyvsp[0].ast) };
            ASTNode* bool_bin_op_node = create_node(NODE_BOOL_BIN_OP, "||", 2, children_array);
            (yyval.ast) = bool_bin_op_node;
        }
#line 1410 "balbismo.tab.c"
    break;

  case 33: /* TERM: FACTOR  */
#line 219 "balbismo.y"
        { (yyval.ast) = (yyvsp[0].ast); }
#line 1416 "balbismo.tab.c"
    break;

  case 34: /* TERM: TERM '*' FACTOR  */
#line 221 "balbismo.y"
        {
            ASTNode* children_array[] = { (yyvsp[-2].ast), (yyvsp[0].ast) };
            ASTNode* bin_op_node = create_node(NODE_BIN_OP, "*", 2, children_array);
            (yyval.ast) = bin_op_node;
        }
#line 1426 "balbismo.tab.c"
    break;

  case 35: /* TERM: TERM '/' FACTOR  */
#line 227 "balbismo.y"
        {
            ASTNode* children_array[] = { (yyvsp[-2].ast), (yyvsp[0].ast) };
            ASTNode* bin_op_node = create_node(NODE_BIN_OP, "/", 2, children_array);
            (yyval.ast) = bin_op_node;
        }
#line 1436 "balbismo.tab.c"
    break;

  case 36: /* TERM: TERM '%' FACTOR  */
#line 233 "balbismo.y"
        {
            ASTNode* children_array[] = { (yyvsp[-2].ast), (yyvsp[0].ast) };
            ASTNode* bin_op_node = create_node(NODE_BIN_OP, "%", 2, children_array);
            (yyval.ast) = bin_op_node;
        }
#line 1446 "balbismo.tab.c"
    break;

  case 37: /* TERM: TERM AND_OP FACTOR  */
#line 239 "balbismo.y"
        {
            ASTNode* children_array[] = { (yyvsp[-2].ast), (yyvsp[0].ast) };
            ASTNode* bool_bin_op_node = create_node(NODE_BOOL_BIN_OP, "&&", 2, children_array);
            (yyval.ast) = bool_bin_op_node;
        }
#line 1456 "balbismo.tab.c"
    break;

  case 38: /* FACTOR: '+' FACTOR  */
#line 248 "balbismo.y"
        {
            ASTNode* children_array[] = { (yyvsp[0].ast) };
            ASTNode* un_op_node = create_node(NODE_UN_OP, "+", 1, children_array);
            (yyval.ast) = un_op_node;
        }
#line 1466 "balbismo.tab.c"
    break;

  case 39: /* FACTOR: '-' FACTOR  */
#line 254 "balbismo.y"
        {
            ASTNode* children_array[] = { (yyvsp[0].ast) };
            ASTNode* un_op_node = create_node(NODE_UN_OP, "-", 1, children_array);
            (yyval.ast) = un_op_node;
        }
#line 1476 "balbismo.tab.c"
    break;

  case 40: /* FACTOR: NOT_OP FACTOR  */
#line 260 "balbismo.y"
        {
            ASTNode* children_array[] = { (yyvsp[0].ast) };
            ASTNode* bool_un_op_node = create_node(NODE_BOOL_UN_OP, "!", 1, children_array);
            (yyval.ast) = bool_un_op_node;
        }
#line 1486 "balbismo.tab.c"
    break;

  case 41: /* FACTOR: NUMBER  */
#line 266 "balbismo.y"
        { (yyval.ast) = (yyvsp[0].ast); }
#line 1492 "balbismo.tab.c"
    break;

  case 42: /* FACTOR: '(' RELATIONAL_EXPRESSION ')'  */
#line 268 "balbismo.y"
        { (yyval.ast) = (yyvsp[-1].ast); }
#line 1498 "balbismo.tab.c"
    break;

  case 43: /* FACTOR: IDENTIFIER  */
#line 270 "balbismo.y"
        { 
            ASTNode* id_node = create_node(NODE_IDENTIFIER, (yyvsp[0].str), 0, NULL);
            (yyval.ast) = id_node;
        }
#line 1507 "balbismo.tab.c"
    break;

  case 44: /* NUMBER: INT_LITERAL  */
#line 278 "balbismo.y"
        { 
            ASTNode* int_lit_node = create_node(NODE_INT_LITERAL, (yyvsp[0].str), 0, NULL);
            (yyval.ast) = int_lit_node;
        }
#line 1516 "balbismo.tab.c"
    break;

  case 45: /* NUMBER: FLOAT_LITERAL  */
#line 283 "balbismo.y"
        { 
            ASTNode* float_lit_node = create_node(NODE_FLOAT_LITERAL, (yyvsp[0].str), 0, NULL);
            (yyval.ast) = float_lit_node;
        }
#line 1525 "balbismo.tab.c"
    break;


#line 1529 "balbismo.tab.c"

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

#line 289 "balbismo.y"


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

    printf("Parsing started...\n");
    if (yyparse() == 0) {
        printf("Parsing completed successfully.\n");
        printf("\nAbstract Syntax Tree (YAML):\n");

        print_ast_yaml(yaml_file, ast_root, 0);

        if (yaml_file != stdout)
            fclose(yaml_file);

        free_ast(ast_root);
    }

    return 0;
}
