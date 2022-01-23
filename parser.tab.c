/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

	#include "semantics.c"
	#include "symtab.c"
	#include "ast.h"
	#include "ast.c"
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	extern FILE *yyin;
	extern FILE *yyout;
	extern int lineno;
	extern int yylex();
	void yyerror();
	
	// for declarations
	void add_to_names(list_t *entry);
	list_t **names;
	int nc = 0;
	
	// for the initializations of arrays
	void add_to_vals(Value val);
	Value *vals;
	int vc = 0;
	
	// for else ifs
	void add_elseif(AST_Node *elsif);
	AST_Node **elsifs;
	int elseif_count = 0;

#line 100 "parser.tab.c"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    CHAR = 258,
    INT = 259,
    FLOAT = 260,
    DOUBLE = 261,
    IF = 262,
    ELSE = 263,
    WHILE = 264,
    FOR = 265,
    CONTINUE = 266,
    BREAK = 267,
    VOID = 268,
    RETURN = 269,
    ADDOP = 270,
    MULOP = 271,
    DIVOP = 272,
    INCR = 273,
    OROP = 274,
    ANDOP = 275,
    NOTOP = 276,
    EQUOP = 277,
    RELOP = 278,
    LPAREN = 279,
    RPAREN = 280,
    LBRACK = 281,
    RBRACK = 282,
    LBRACE = 283,
    RBRACE = 284,
    SEMI = 285,
    DOT = 286,
    COMMA = 287,
    ASSIGN = 288,
    REFER = 289,
    ID = 290,
    ICONST = 291,
    FCONST = 292,
    CCONST = 293,
    STRING = 294,
    MINUS = 295
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 32 "parser.y"

	// different types of values
	Value val;   
	
	// structures
	list_t* symtab_item;
	AST_Node* node;
	
	// for declarations
	int data_type;
	int const_type;
	
	// for arrays
	int array_size;

#line 209 "parser.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */



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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


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
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   315

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  47
/* YYNRULES -- Number of rules.  */
#define YYNRULES  102
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  188

#define YYUNDEFTOK  2
#define YYMAXUTOK   295


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    88,    88,    88,    91,    91,    93,    93,    93,   120,
     121,   122,   123,   124,   127,   131,   135,   139,   145,   146,
     151,   159,   159,   161,   169,   177,   185,   186,   189,   198,
     211,   216,   225,   230,   237,   241,   245,   249,   253,   257,
     261,   262,   272,   285,   291,   298,   303,   311,   317,   323,
     339,   345,   352,   356,   360,   364,   374,   384,   388,   392,
     396,   400,   404,   408,   412,   416,   444,   451,   452,   453,
     456,   463,   467,   473,   475,   475,   475,   477,   477,   480,
     480,   482,   482,   484,   484,   486,   486,   486,   488,   488,
     490,   490,   492,   492,   494,   494,   496,   498,   498,   500,
     500,   502,   502
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CHAR", "INT", "FLOAT", "DOUBLE", "IF",
  "ELSE", "WHILE", "FOR", "CONTINUE", "BREAK", "VOID", "RETURN", "ADDOP",
  "MULOP", "DIVOP", "INCR", "OROP", "ANDOP", "NOTOP", "EQUOP", "RELOP",
  "LPAREN", "RPAREN", "LBRACK", "RBRACK", "LBRACE", "RBRACE", "SEMI",
  "DOT", "COMMA", "ASSIGN", "REFER", "ID", "ICONST", "FCONST", "CCONST",
  "STRING", "MINUS", "$accept", "program", "$@1", "declarations",
  "declaration", "$@2", "$@3", "type", "names", "variable", "pointer",
  "array", "init", "var_init", "array_init", "values", "statements",
  "statement", "if_statement", "else_if", "optional_else", "for_statement",
  "while_statement", "tail", "expression", "constant", "assigment",
  "var_ref", "function_call", "call_params", "call_param",
  "functions_optional", "functions", "function", "$@4", "function_head",
  "$@5", "$@6", "return_type", "parameters_optional", "parameters",
  "parameter", "$@7", "function_tail", "declarations_optional",
  "statements_optional", "return_optional", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295
};
# endif

#define YYPACT_NINF (-134)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-92)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     103,  -134,  -134,  -134,  -134,  -134,    10,    49,  -134,  -134,
    -134,    12,    15,    17,    20,    38,  -134,   -23,    -1,    22,
    -134,  -134,     0,   127,  -134,  -134,  -134,  -134,    46,    44,
      57,     7,   164,   164,    -2,  -134,  -134,    62,    19,  -134,
      68,   139,   171,    59,  -134,  -134,    85,  -134,  -134,   164,
    -134,    55,    71,  -134,  -134,  -134,  -134,   -12,    69,   164,
     164,    25,  -134,  -134,  -134,   231,  -134,  -134,  -134,   242,
      75,  -134,  -134,  -134,   149,    87,    78,    94,   213,   164,
      98,   149,   -12,    56,     7,   102,  -134,  -134,  -134,   253,
    -134,   164,   164,   164,   164,   164,   164,   164,   105,   105,
     164,  -134,   164,  -134,  -134,   222,   135,  -134,   113,  -134,
    -134,  -134,  -134,    47,  -134,  -134,   107,   286,   289,   298,
     127,   134,  -134,   195,   149,  -134,  -134,   146,  -134,  -134,
     -12,    84,     1,   141,  -134,   112,  -134,   122,   103,    88,
    -134,  -134,   132,  -134,     2,  -134,   152,   103,  -134,   165,
     148,  -134,   -12,   164,   160,   166,   103,   127,   174,   169,
    -134,   264,   164,   105,   127,   180,  -134,   105,   275,  -134,
     164,   167,   172,  -134,   105,   204,  -134,   178,   181,  -134,
     103,  -134,  -134,  -134,  -134,    -1,  -134,  -134
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    10,     9,    11,    12,    13,     0,     0,     5,     6,
       1,     0,     0,     0,     0,     0,    22,     0,     0,    18,
       4,    71,     0,     2,    33,    34,    35,    36,     0,     0,
       0,     0,     0,     0,     0,    38,    39,     0,    18,    72,
       0,    76,     0,    20,    21,    19,     0,    32,    37,     0,
      40,    18,     7,    16,    17,    26,    27,     0,     0,     0,
       0,    18,    67,    68,    69,     0,    64,    63,    66,     0,
       0,    42,    41,    75,    78,     0,    74,    67,     0,     0,
       0,    70,     0,    20,     0,     0,    65,    56,    59,     0,
      55,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    73,     0,    25,    24,     0,    83,    28,     0,    14,
      15,     8,    62,    52,    53,    54,    57,    58,    60,    61,
       0,    48,    50,     0,    77,    23,     3,    83,    82,    85,
       0,     0,     0,    48,    44,     0,    81,     0,     0,     0,
      31,    51,     0,    47,     0,    43,     0,    98,    84,    88,
       0,    29,     0,     0,     0,     0,    97,   100,    89,     0,
      30,     0,     0,     0,    99,   102,    86,     0,     0,    49,
       0,     0,    94,    46,     0,     0,    96,     0,    90,    93,
       0,    45,   101,    87,    94,     0,    92,    95
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -134,  -134,  -134,    96,    -3,  -134,  -134,  -133,  -134,   -18,
      67,   153,   138,  -134,  -134,  -134,  -113,   -20,  -134,  -134,
     119,  -134,  -134,   -77,   -22,   -51,   197,    -6,    -5,  -134,
    -134,  -134,  -134,   128,  -134,  -134,  -134,  -134,  -134,  -134,
    -134,    76,  -134,  -134,  -134,  -134,  -134
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     6,    46,     7,     8,    31,    85,     9,    52,    21,
      22,    43,    54,    55,    56,   139,    23,    24,    25,   133,
     134,    26,    27,   143,    65,    66,    28,    67,    68,    75,
      76,   126,   127,   128,   129,   137,   138,   172,   150,   177,
     178,   179,   180,   148,   157,   165,   171
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      39,    29,    30,    47,    20,   149,    86,   131,   142,   154,
      10,    69,    37,    53,    16,    16,    44,    29,    30,    74,
      78,   121,   122,    16,    62,    63,    64,    81,    29,   120,
     120,   107,    18,    38,    38,    45,    32,    88,    89,    33,
      40,    34,    51,    90,   164,    42,    41,   185,    42,    41,
      35,    42,     1,     2,     3,     4,    11,   105,    12,    13,
      14,    15,     5,    92,    93,    16,   109,    17,    36,   113,
     114,   115,   116,   117,   118,   119,    48,    49,   123,   140,
     124,    42,    79,    18,    19,    79,   169,    50,    82,   108,
     173,    11,    71,    12,    13,    14,    15,   181,    72,    80,
      16,   160,    17,    84,    87,   100,     1,     2,     3,     4,
     102,    47,   101,   141,    29,    30,     5,   151,    18,    19,
     152,   103,    91,    92,    93,    29,    30,    95,   106,    96,
      97,   161,   111,   120,    11,   -80,    12,    13,    14,    15,
     168,   130,   132,    16,    47,    17,   -79,   146,   175,   144,
     147,    29,    30,    20,    57,    16,   153,    58,    29,    30,
      59,    18,    19,    60,    91,    92,    93,   187,    94,    95,
     155,    96,    97,    18,    61,    62,    63,    64,    73,    57,
      16,    16,    58,   159,   162,    59,    57,    16,    60,    58,
      44,   163,    59,   166,   170,    60,   176,   -91,    18,    61,
      62,    63,    64,   183,    83,    18,    61,    77,    63,    64,
      91,    92,    93,   184,    94,    95,   158,    96,    97,    91,
      92,    93,   110,    94,    95,   135,    96,    97,    91,    92,
      93,    70,    94,    95,   182,    96,    97,    91,    92,    93,
     104,    94,    95,   156,    96,    97,    91,    92,    93,   125,
      94,    95,   145,    96,    97,   136,    98,    91,    92,    93,
     186,    94,    95,     0,    96,    97,     0,    99,    91,    92,
      93,     0,    94,    95,     0,    96,    97,     0,   112,    91,
      92,    93,     0,    94,    95,     0,    96,    97,     0,   167,
      91,    92,    93,     0,    94,    95,     0,    96,    97,     0,
     174,    91,    92,    93,    91,    92,    93,     0,    96,    97,
       0,     0,    97,    91,    92,    93
};

static const yytype_int16 yycheck[] =
{
      18,     7,     7,    23,     7,   138,    57,   120,     7,     7,
       0,    33,    35,    31,    16,    16,    16,    23,    23,    41,
      42,    98,    99,    16,    36,    37,    38,    49,    34,    28,
      28,    82,    34,    35,    35,    35,    24,    59,    60,    24,
      18,    24,    35,    18,   157,    26,    24,   180,    26,    24,
      30,    26,     3,     4,     5,     6,     7,    79,     9,    10,
      11,    12,    13,    16,    17,    16,    84,    18,    30,    91,
      92,    93,    94,    95,    96,    97,    30,    33,   100,   130,
     102,    26,    26,    34,    35,    26,   163,    30,    33,    33,
     167,     7,    30,     9,    10,    11,    12,   174,    30,    14,
      16,   152,    18,    32,    35,    30,     3,     4,     5,     6,
      32,   131,    25,    29,   120,   120,    13,    29,    34,    35,
      32,    27,    15,    16,    17,   131,   131,    20,    30,    22,
      23,   153,    30,    28,     7,     0,     9,    10,    11,    12,
     162,    28,     8,    16,   164,    18,     0,    35,   170,     8,
      28,   157,   157,   156,    15,    16,    24,    18,   164,   164,
      21,    34,    35,    24,    15,    16,    17,   185,    19,    20,
      18,    22,    23,    34,    35,    36,    37,    38,    39,    15,
      16,    16,    18,    35,    24,    21,    15,    16,    24,    18,
      16,    25,    21,    24,    14,    24,    29,    25,    34,    35,
      36,    37,    38,    25,    51,    34,    35,    36,    37,    38,
      15,    16,    17,    32,    19,    20,   149,    22,    23,    15,
      16,    17,    84,    19,    20,    30,    22,    23,    15,    16,
      17,    34,    19,    20,    30,    22,    23,    15,    16,    17,
      27,    19,    20,   147,    22,    23,    15,    16,    17,    27,
      19,    20,   133,    22,    23,   127,    25,    15,    16,    17,
     184,    19,    20,    -1,    22,    23,    -1,    25,    15,    16,
      17,    -1,    19,    20,    -1,    22,    23,    -1,    25,    15,
      16,    17,    -1,    19,    20,    -1,    22,    23,    -1,    25,
      15,    16,    17,    -1,    19,    20,    -1,    22,    23,    -1,
      25,    15,    16,    17,    15,    16,    17,    -1,    22,    23,
      -1,    -1,    23,    15,    16,    17
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,    13,    42,    44,    45,    48,
       0,     7,     9,    10,    11,    12,    16,    18,    34,    35,
      45,    50,    51,    57,    58,    59,    62,    63,    67,    68,
      69,    46,    24,    24,    24,    30,    30,    35,    35,    50,
      18,    24,    26,    52,    16,    35,    43,    58,    30,    33,
      30,    35,    49,    50,    53,    54,    55,    15,    18,    21,
      24,    35,    36,    37,    38,    65,    66,    68,    69,    65,
      67,    30,    30,    39,    65,    70,    71,    36,    65,    26,
      14,    65,    33,    52,    32,    47,    66,    35,    65,    65,
      18,    15,    16,    17,    19,    20,    22,    23,    25,    25,
      30,    25,    32,    27,    27,    65,    30,    66,    33,    50,
      53,    30,    25,    65,    65,    65,    65,    65,    65,    65,
      28,    64,    64,    65,    65,    27,    72,    73,    74,    75,
      28,    57,     8,    60,    61,    30,    74,    76,    77,    56,
      66,    29,     7,    64,     8,    61,    35,    28,    84,    48,
      79,    29,    32,    24,     7,    18,    44,    85,    51,    35,
      66,    65,    24,    25,    57,    86,    24,    25,    65,    64,
      14,    87,    78,    64,    25,    65,    29,    80,    81,    82,
      83,    64,    30,    25,    32,    48,    82,    50
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    41,    43,    42,    44,    44,    46,    47,    45,    48,
      48,    48,    48,    48,    49,    49,    49,    49,    50,    50,
      50,    51,    51,    52,    52,    52,    53,    53,    54,    55,
      56,    56,    57,    57,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    59,    59,    60,    60,    61,    61,    62,
      63,    64,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    66,    66,    66,
      67,    68,    68,    69,    70,    70,    70,    71,    71,    72,
      72,    73,    73,    75,    74,    77,    78,    76,    79,    79,
      80,    80,    81,    81,    83,    82,    84,    85,    85,    86,
      86,    87,    87
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     6,     2,     1,     0,     0,     5,     1,
       1,     1,     1,     1,     3,     3,     1,     1,     1,     2,
       2,     2,     1,     4,     3,     3,     1,     1,     3,     6,
       3,     1,     2,     1,     1,     1,     1,     2,     2,     2,
       2,     3,     3,     7,     6,     7,     6,     2,     0,    10,
       5,     3,     3,     3,     3,     2,     2,     3,     3,     2,
       3,     3,     3,     1,     1,     2,     1,     1,     1,     1,
       3,     1,     2,     4,     1,     1,     0,     3,     1,     1,
       0,     2,     1,     0,     3,     0,     0,     7,     1,     2,
       1,     0,     3,     1,     0,     3,     5,     1,     0,     1,
       0,     3,     0
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
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

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
  case 2:
#line 88 "parser.y"
                                 { ast_traversal((yyvsp[0].node)); }
#line 1546 "parser.tab.c"
    break;

  case 6:
#line 93 "parser.y"
                  { declare = 1; }
#line 1552 "parser.tab.c"
    break;

  case 7:
#line 93 "parser.y"
                                         { declare = 0; }
#line 1558 "parser.tab.c"
    break;

  case 8:
#line 94 "parser.y"
        {
		int i;
		(yyval.node) = new_ast_decl_node((yyvsp[-4].data_type), names, nc);
		nc = 0;
		
		AST_Node_Decl *temp = (AST_Node_Decl*) (yyval.node);
		
		// declare types of the names
		for(i=0; i < temp->names_count; i++){
			// variable
			if(temp->names[i]->st_type == UNDEF){
				set_type(temp->names[i]->st_name, temp->data_type, UNDEF);
			}
			// pointer
			else if(temp->names[i]->st_type == POINTER_TYPE){
				set_type(temp->names[i]->st_name, POINTER_TYPE, temp->data_type);
			}
			// array
			else if(temp->names[i]->st_type == ARRAY_TYPE){
				set_type(temp->names[i]->st_name, ARRAY_TYPE, temp->data_type);
			}
		}
		ast_traversal((yyval.node)); /* just for testing */
	}
#line 1587 "parser.tab.c"
    break;

  case 9:
#line 120 "parser.y"
                        { (yyval.data_type) = INT_TYPE;   }
#line 1593 "parser.tab.c"
    break;

  case 10:
#line 121 "parser.y"
                        { (yyval.data_type) = CHAR_TYPE;  }
#line 1599 "parser.tab.c"
    break;

  case 11:
#line 122 "parser.y"
                        { (yyval.data_type) = REAL_TYPE;  }
#line 1605 "parser.tab.c"
    break;

  case 12:
#line 123 "parser.y"
                        { (yyval.data_type) = REAL_TYPE;  }
#line 1611 "parser.tab.c"
    break;

  case 13:
#line 124 "parser.y"
                        { (yyval.data_type) = VOID_TYPE;  }
#line 1617 "parser.tab.c"
    break;

  case 14:
#line 128 "parser.y"
        {
		add_to_names((yyvsp[0].symtab_item));
	}
#line 1625 "parser.tab.c"
    break;

  case 15:
#line 132 "parser.y"
        {
		add_to_names((yyvsp[0].symtab_item));
	}
#line 1633 "parser.tab.c"
    break;

  case 16:
#line 136 "parser.y"
        {
		add_to_names((yyvsp[0].symtab_item));
	}
#line 1641 "parser.tab.c"
    break;

  case 17:
#line 140 "parser.y"
        { 
		add_to_names((yyvsp[0].symtab_item));
	}
#line 1649 "parser.tab.c"
    break;

  case 18:
#line 145 "parser.y"
             { (yyval.symtab_item) = (yyvsp[0].symtab_item); }
#line 1655 "parser.tab.c"
    break;

  case 19:
#line 147 "parser.y"
        {
		(yyvsp[0].symtab_item)->st_type = POINTER_TYPE;
		(yyval.symtab_item) = (yyvsp[0].symtab_item);
	}
#line 1664 "parser.tab.c"
    break;

  case 20:
#line 152 "parser.y"
        {
		(yyvsp[-1].symtab_item)->st_type = ARRAY_TYPE;
		(yyvsp[-1].symtab_item)->array_size = (yyvsp[0].array_size);
		(yyval.symtab_item) = (yyvsp[-1].symtab_item);
	}
#line 1674 "parser.tab.c"
    break;

  case 23:
#line 162 "parser.y"
        { 
	    // if declaration then error!
		if(declare == 1){
			fprintf(stderr, "Array declaration at %d contains expression!\n", lineno);
			exit(1);
		}
	}
#line 1686 "parser.tab.c"
    break;

  case 24:
#line 170 "parser.y"
        {
		// if declaration then error!
		if(declare == 1){
			fprintf(stderr, "Array declaration at %d contains expression!\n", lineno);
			exit(1);
		}
	}
#line 1698 "parser.tab.c"
    break;

  case 25:
#line 178 "parser.y"
        {
		// set array_size for declaration purposes
		(yyval.array_size) = (yyvsp[-1].val).ival;
	}
#line 1707 "parser.tab.c"
    break;

  case 26:
#line 185 "parser.y"
                 { (yyval.symtab_item) = (yyvsp[0].symtab_item); }
#line 1713 "parser.tab.c"
    break;

  case 27:
#line 186 "parser.y"
                     { (yyval.symtab_item) = (yyvsp[0].symtab_item); }
#line 1719 "parser.tab.c"
    break;

  case 28:
#line 190 "parser.y"
{ 
	AST_Node_Const *temp = (AST_Node_Const*) (yyval.symtab_item);
	(yyvsp[-2].symtab_item)->val = temp->val;
	(yyvsp[-2].symtab_item)->st_type = temp->const_type;
	(yyval.symtab_item) = (yyvsp[-2].symtab_item);
}
#line 1730 "parser.tab.c"
    break;

  case 29:
#line 199 "parser.y"
{
	if((yyvsp[-5].symtab_item)->array_size != vc){
	    fprintf(stderr, "Array init at %d doesn't contain the right amount of values!\n", lineno);
		exit(1);
	}
	(yyvsp[-5].symtab_item)->vals = vals;
	(yyvsp[-5].symtab_item)->array_size = (yyvsp[-4].array_size);
	(yyval.symtab_item) = (yyvsp[-5].symtab_item);
	vc = 0;
}
#line 1745 "parser.tab.c"
    break;

  case 30:
#line 212 "parser.y"
        {
		AST_Node_Const *temp = (AST_Node_Const*) (yyvsp[0].node);
		add_to_vals(temp->val);
	}
#line 1754 "parser.tab.c"
    break;

  case 31:
#line 217 "parser.y"
        {
		AST_Node_Const *temp = (AST_Node_Const*) (yyvsp[0].node);
		add_to_vals(temp->val);
	}
#line 1763 "parser.tab.c"
    break;

  case 32:
#line 226 "parser.y"
        {
		AST_Node_Statements *temp = (AST_Node_Statements*) (yyvsp[-1].node);
		(yyval.node) = new_statements_node(temp->statements, temp->statement_count, (yyvsp[0].node));
	}
#line 1772 "parser.tab.c"
    break;

  case 33:
#line 231 "parser.y"
        {
		(yyval.node) = new_statements_node(NULL, 0, (yyvsp[0].node));
	}
#line 1780 "parser.tab.c"
    break;

  case 34:
#line 238 "parser.y"
        { 
		(yyval.node) = (yyvsp[0].node); /* just pass information */
	}
#line 1788 "parser.tab.c"
    break;

  case 35:
#line 242 "parser.y"
        { 
		(yyval.node) = (yyvsp[0].node); /* just pass information */
	}
#line 1796 "parser.tab.c"
    break;

  case 36:
#line 246 "parser.y"
        {
		(yyval.node) = (yyvsp[0].node); /* just pass information */
	}
#line 1804 "parser.tab.c"
    break;

  case 37:
#line 250 "parser.y"
        {
		(yyval.node) = (yyvsp[-1].node); /* just pass information */
	}
#line 1812 "parser.tab.c"
    break;

  case 38:
#line 254 "parser.y"
        { 
		(yyval.node) = new_ast_simple_node(0);
	}
#line 1820 "parser.tab.c"
    break;

  case 39:
#line 258 "parser.y"
        { 
		(yyval.node) = new_ast_simple_node(1);
	}
#line 1828 "parser.tab.c"
    break;

  case 40:
#line 261 "parser.y"
                             { (yyval.node) = NULL; /* will do it later ! */ }
#line 1834 "parser.tab.c"
    break;

  case 41:
#line 263 "parser.y"
        {
		/* increment */
		if((yyvsp[-1].val).ival == INC){
			(yyval.node) = new_ast_incr_node((yyvsp[-2].symtab_item), 0, 0);
		}
		else{
			(yyval.node) = new_ast_incr_node((yyvsp[-2].symtab_item), 1, 0);
		}
	}
#line 1848 "parser.tab.c"
    break;

  case 42:
#line 273 "parser.y"
        {
		/* increment */
		if((yyvsp[-2].val).ival == INC){
			(yyval.node) = new_ast_incr_node((yyvsp[-1].symtab_item), 0, 1);
		}
		else{
			(yyval.node) = new_ast_incr_node((yyvsp[-1].symtab_item), 1, 1);
		}
	}
#line 1862 "parser.tab.c"
    break;

  case 43:
#line 286 "parser.y"
        {
		(yyval.node) = new_ast_if_node((yyvsp[-4].node), (yyvsp[-2].node), elsifs, elseif_count, (yyvsp[0].node));
		elseif_count = 0;
		elsifs = NULL;
	}
#line 1872 "parser.tab.c"
    break;

  case 44:
#line 292 "parser.y"
        {
		(yyval.node) = new_ast_if_node((yyvsp[-3].node), (yyvsp[-1].node), NULL, 0, (yyvsp[0].node));
	}
#line 1880 "parser.tab.c"
    break;

  case 45:
#line 299 "parser.y"
        {
		AST_Node *temp = new_ast_elsif_node((yyvsp[-2].node), (yyvsp[0].node));
		add_elseif(temp);
	}
#line 1889 "parser.tab.c"
    break;

  case 46:
#line 304 "parser.y"
        {
		AST_Node *temp = new_ast_elsif_node((yyvsp[-2].node), (yyvsp[0].node));
		add_elseif(temp);
	}
#line 1898 "parser.tab.c"
    break;

  case 47:
#line 312 "parser.y"
        {
		/* else exists */
		(yyval.node) = (yyvsp[0].node);
	}
#line 1907 "parser.tab.c"
    break;

  case 48:
#line 317 "parser.y"
        {
		/* no else */
		(yyval.node) = NULL;
	}
#line 1916 "parser.tab.c"
    break;

  case 49:
#line 324 "parser.y"
{
	/* create increment node*/
	AST_Node *incr_node;
	if((yyvsp[-2].val).ival == INC){ /* increment */
		incr_node = new_ast_incr_node((yyvsp[-3].symtab_item), 0, 0);
	}
	else{
		incr_node = new_ast_incr_node((yyvsp[-3].symtab_item), 1, 0);
	}

	(yyval.node) = new_ast_for_node((yyvsp[-7].node), (yyvsp[-5].node), incr_node, (yyvsp[0].node));
	set_loop_counter((yyval.node));
}
#line 1934 "parser.tab.c"
    break;

  case 50:
#line 340 "parser.y"
{
	(yyval.node) = new_ast_while_node((yyvsp[-2].node), (yyvsp[0].node));
}
#line 1942 "parser.tab.c"
    break;

  case 51:
#line 346 "parser.y"
{ 
	(yyval.node) = (yyvsp[-1].node); /* just pass information */
}
#line 1950 "parser.tab.c"
    break;

  case 52:
#line 353 "parser.y"
        { 
	    (yyval.node) = new_ast_arithm_node((yyvsp[-1].val).ival, (yyvsp[-2].node), (yyvsp[0].node));
	}
#line 1958 "parser.tab.c"
    break;

  case 53:
#line 357 "parser.y"
        {
	    (yyval.node) = new_ast_arithm_node(MUL, (yyvsp[-2].node), (yyvsp[0].node));
	}
#line 1966 "parser.tab.c"
    break;

  case 54:
#line 361 "parser.y"
        {
		(yyval.node) = new_ast_arithm_node(DIV, (yyvsp[-2].node), (yyvsp[0].node));
	}
#line 1974 "parser.tab.c"
    break;

  case 55:
#line 365 "parser.y"
        {
		/* increment */
		if((yyvsp[0].val).ival == INC){
			(yyval.node) = new_ast_incr_node((yyvsp[-1].symtab_item), 0, 0);
		}
		else{
			(yyval.node) = new_ast_incr_node((yyvsp[-1].symtab_item), 1, 0);
		}	
	}
#line 1988 "parser.tab.c"
    break;

  case 56:
#line 375 "parser.y"
        {
		/* increment */
		if((yyvsp[-1].val).ival == INC){
			(yyval.node) = new_ast_incr_node((yyvsp[0].symtab_item), 0, 1);
		}
		else{
			(yyval.node) = new_ast_incr_node((yyvsp[0].symtab_item), 1, 1);
		}
	}
#line 2002 "parser.tab.c"
    break;

  case 57:
#line 385 "parser.y"
        {
		(yyval.node) = new_ast_bool_node(OR, (yyvsp[-2].node), (yyvsp[0].node));
	}
#line 2010 "parser.tab.c"
    break;

  case 58:
#line 389 "parser.y"
        {
		(yyval.node) = new_ast_bool_node(AND, (yyvsp[-2].node), (yyvsp[0].node));
	}
#line 2018 "parser.tab.c"
    break;

  case 59:
#line 393 "parser.y"
        {
	    (yyval.node) = new_ast_bool_node(NOT, (yyvsp[0].node), NULL);
	}
#line 2026 "parser.tab.c"
    break;

  case 60:
#line 397 "parser.y"
        {
		(yyval.node) = new_ast_equ_node((yyvsp[-1].val).ival, (yyvsp[-2].node), (yyvsp[0].node));
	}
#line 2034 "parser.tab.c"
    break;

  case 61:
#line 401 "parser.y"
        {
		(yyval.node) = new_ast_rel_node((yyvsp[-1].val).ival, (yyvsp[-2].node), (yyvsp[0].node));
	}
#line 2042 "parser.tab.c"
    break;

  case 62:
#line 405 "parser.y"
        {
		(yyval.node) = (yyvsp[-1].node); /* just pass information */
	}
#line 2050 "parser.tab.c"
    break;

  case 63:
#line 409 "parser.y"
        { 
		(yyval.node) = (yyvsp[0].node); /* just pass information */
	}
#line 2058 "parser.tab.c"
    break;

  case 64:
#line 413 "parser.y"
        {
		(yyval.node) = (yyvsp[0].node); /* no sign */
	}
#line 2066 "parser.tab.c"
    break;

  case 65:
#line 417 "parser.y"
        {
		/* plus sign error */
		if((yyvsp[-1].val).ival == ADD){
			fprintf(stderr, "Error having plus as a sign!\n");
			exit(1);
		}
		else{
			AST_Node_Const *temp = (AST_Node_Const*) (yyvsp[0].node);
		
			/* inverse value depending on the constant type */
			switch(temp->const_type){
				case INT_TYPE:
					temp->val.ival *= -1;
					break;
				case REAL_TYPE:
					temp->val.fval *= -1;
					break;
				case CHAR_TYPE:
					/* sign before char error */
					fprintf(stderr, "Error having sign before character constant!\n");
					exit(1);
					break;
			}
			
			(yyval.node) = (AST_Node*) temp;
		}
	}
#line 2098 "parser.tab.c"
    break;

  case 66:
#line 445 "parser.y"
        {
		(yyval.node) = NULL; /* will do it later ! */
	}
#line 2106 "parser.tab.c"
    break;

  case 67:
#line 451 "parser.y"
                 { (yyval.node) = new_ast_const_node(INT_TYPE, (yyvsp[0].val));  }
#line 2112 "parser.tab.c"
    break;

  case 68:
#line 452 "parser.y"
                 { (yyval.node) = new_ast_const_node(REAL_TYPE, (yyvsp[0].val)); }
#line 2118 "parser.tab.c"
    break;

  case 69:
#line 453 "parser.y"
                 { (yyval.node) = new_ast_const_node(CHAR_TYPE, (yyvsp[0].val)); }
#line 2124 "parser.tab.c"
    break;

  case 70:
#line 457 "parser.y"
{
	AST_Node_Ref *temp = (AST_Node_Ref*) (yyvsp[-2].node);
	(yyval.node) = new_ast_assign_node(temp->entry, temp->ref, (yyvsp[0].node));
}
#line 2133 "parser.tab.c"
    break;

  case 71:
#line 464 "parser.y"
        {
		(yyval.node) = new_ast_ref_node((yyvsp[0].symtab_item), 0); /* no reference */
	}
#line 2141 "parser.tab.c"
    break;

  case 72:
#line 468 "parser.y"
        {
		(yyval.node) = new_ast_ref_node((yyvsp[0].symtab_item), 1); /* reference */
	}
#line 2149 "parser.tab.c"
    break;

  case 83:
#line 484 "parser.y"
          { incr_scope(); }
#line 2155 "parser.tab.c"
    break;

  case 84:
#line 484 "parser.y"
                                                        { hide_scope(); }
#line 2161 "parser.tab.c"
    break;

  case 85:
#line 486 "parser.y"
               { declare = 1; }
#line 2167 "parser.tab.c"
    break;

  case 86:
#line 486 "parser.y"
                                                      { declare = 0; }
#line 2173 "parser.tab.c"
    break;

  case 94:
#line 494 "parser.y"
            { declare = 1; }
#line 2179 "parser.tab.c"
    break;

  case 95:
#line 494 "parser.y"
                                           { declare = 0; }
#line 2185 "parser.tab.c"
    break;

  case 99:
#line 500 "parser.y"
                                { ast_traversal((yyvsp[0].node)); }
#line 2191 "parser.tab.c"
    break;


#line 2195 "parser.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

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
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
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
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 504 "parser.y"


void yyerror ()
{
  fprintf(stderr, "Syntax error at line %d\n", lineno);
  exit(1);
}

void add_to_names(list_t *entry){
	// first entry
	if(nc == 0){
		nc = 1;
		names = (list_t **) malloc( 1 * sizeof(list_t *));
		names[0] = entry;
	}
	// general case
	else{
		nc++;
		names = (list_t **) realloc(names, nc * sizeof(list_t *));
		names[nc - 1] = entry;		
	}
}

void add_to_vals(Value val){
	// first entry
	if(vc == 0){
		vc = 1;
		vals = (Value *) malloc(1 * sizeof(Value));
		vals[0] = val;
	}
	// general case
	else{
		vc++;
		vals = (Value *) realloc(vals, vc * sizeof(Value));
		vals[vc - 1] = val;
	}
}

void add_elseif(AST_Node *elsif){
	// first entry
	if(elseif_count == 0){
		elseif_count = 1;
		elsifs = (AST_Node **) malloc(1 * sizeof(AST_Node));
		elsifs[0] = elsif;
	}
	// general case
	else{
		elseif_count++;
		elsifs = (AST_Node **) realloc(elsifs, elseif_count * sizeof(AST_Node));
		elsifs[elseif_count - 1] = elsif;
	}
}

int main (int argc, char *argv[]){
	
	// initialize symbol table
	init_hash_table();
	
	// initialize revisit queue
	queue = NULL;
	
	// parsing
	int flag;
	yyin = fopen(argv[1], "r");
	flag = yyparse();
	fclose(yyin);
	
	printf("Parsing finished!\n");
	
	if(queue != NULL){
		printf("Warning: Something has not been checked in the revisit queue!\n");
	}
	
	// symbol table dump
	yyout = fopen("symtab_dump.out", "w");
	symtab_dump(yyout);
	fclose(yyout);
	
	// revisit queue dump
	yyout = fopen("revisit_dump.out", "w");
	revisit_dump(yyout);
	fclose(yyout);
	
	return flag;
}
