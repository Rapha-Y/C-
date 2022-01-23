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
	
	// for functions
	AST_Node_Func_Decl *temp_function;

#line 103 "parser.tab.c"

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
#line 35 "parser.y"

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
	
	// for parameters
	Param par;

#line 215 "parser.tab.c"

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
#define YYLAST   291

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  48
/* YYNRULES -- Number of rules.  */
#define YYNRULES  103
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  189

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
       0,   100,   100,   101,   100,   107,   112,   118,   118,   118,
     144,   145,   146,   147,   148,   151,   155,   159,   163,   169,
     170,   175,   183,   183,   185,   193,   201,   209,   210,   213,
     222,   235,   240,   249,   254,   261,   265,   269,   273,   277,
     281,   285,   289,   299,   312,   318,   325,   330,   338,   344,
     350,   366,   372,   379,   383,   387,   391,   401,   411,   415,
     419,   423,   427,   431,   435,   439,   443,   471,   478,   479,
     480,   483,   490,   494,   500,   508,   512,   518,   528,   533,
     541,   546,   552,   557,   563,   563,   570,   571,   570,   595,
     599,   606,   611,   617,   622,   628,   628,   635,   638,   643,
     649,   654,   660,   665
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
  "STRING", "MINUS", "$accept", "program", "$@1", "$@2", "declarations",
  "declaration", "$@3", "$@4", "type", "names", "variable", "pointer",
  "array", "init", "var_init", "array_init", "values", "statements",
  "statement", "if_statement", "else_if", "optional_else", "for_statement",
  "while_statement", "tail", "expression", "constant", "assigment",
  "var_ref", "function_call", "call_params", "call_param",
  "functions_optional", "functions", "function", "$@5", "function_head",
  "$@6", "$@7", "return_type", "parameters_optional", "parameters",
  "parameter", "$@8", "function_tail", "declarations_optional",
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

#define YYPACT_NINF (-136)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-93)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     128,  -136,  -136,  -136,  -136,  -136,    25,   128,  -136,  -136,
    -136,    66,  -136,    20,     3,    26,    30,    41,    44,  -136,
      45,    21,    27,  -136,    33,    66,  -136,  -136,  -136,  -136,
      64,    82,    67,    53,    84,  -136,  -136,  -136,  -136,   102,
     102,     8,  -136,  -136,    68,    95,  -136,    92,    72,   142,
     103,  -136,  -136,   114,  -136,  -136,   102,  -136,   -27,    69,
      20,   100,   -27,   107,   102,   102,    65,  -136,  -136,  -136,
     195,  -136,  -136,  -136,   206,   113,  -136,  -136,  -136,   250,
     119,   115,   121,   177,   102,   116,   250,  -136,   133,  -136,
    -136,  -136,  -136,  -136,  -136,   217,  -136,   102,   102,   102,
     102,   102,   102,   102,   134,   134,   102,  -136,   102,  -136,
    -136,   186,   164,   -27,  -136,    43,  -136,  -136,   259,   268,
     136,    88,    66,   157,  -136,   152,   250,  -136,  -136,   170,
    -136,  -136,    -6,  -136,    23,    10,   173,  -136,   151,  -136,
     161,   128,  -136,   -27,  -136,   171,  -136,    12,  -136,   189,
     128,  -136,   200,   184,  -136,   102,   203,   199,   128,    66,
     214,   211,   228,   102,   134,    66,   224,  -136,   134,   239,
    -136,   102,   212,   221,  -136,   134,   168,  -136,   227,   225,
    -136,   128,  -136,  -136,  -136,  -136,    21,  -136,  -136
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    11,    10,    12,    13,    14,     0,     2,     6,     7,
       1,     0,     5,     0,     0,     0,     0,     0,     0,    23,
       0,     0,    19,    72,     0,     3,    34,    35,    36,    37,
       0,     0,     0,    19,     8,    17,    18,    27,    28,     0,
       0,     0,    39,    40,     0,    19,    73,     0,    77,     0,
      21,    22,    20,     0,    33,    38,     0,    41,     0,    21,
       0,     0,     0,     0,     0,     0,    19,    68,    69,    70,
       0,    65,    64,    67,     0,     0,    43,    42,    76,    79,
       0,    75,    68,     0,     0,     0,    71,    29,     0,    15,
      16,     9,    66,    57,    60,     0,    56,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    74,     0,    26,
      25,     0,    84,     0,    63,    53,    54,    55,    58,    59,
      61,    62,     0,    49,    51,     0,    78,    24,     4,    84,
      83,    86,     0,    32,     0,     0,    49,    45,     0,    82,
       0,     0,    30,     0,    52,     0,    48,     0,    44,     0,
      99,    85,    89,     0,    31,     0,     0,     0,    98,   101,
      90,     0,     0,     0,     0,   100,   103,    87,     0,     0,
      50,     0,     0,    95,    47,     0,     0,    97,     0,    91,
      94,     0,    46,   102,    88,    95,     0,    93,    96
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -136,  -136,  -136,  -136,    99,    -4,  -136,  -136,  -135,  -136,
     -13,   108,   230,   208,  -136,  -136,  -136,  -115,   -20,  -136,
    -136,   135,  -136,  -136,   -83,   -36,   -44,   236,   -10,    -9,
    -136,  -136,  -136,  -136,   149,  -136,  -136,  -136,  -136,  -136,
    -136,  -136,   101,  -136,  -136,  -136,  -136,  -136
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     6,    11,    53,     7,     8,    13,    61,     9,    34,
      23,    24,    50,    36,    37,    38,   132,    25,    26,    27,
     136,   137,    28,    29,   146,    70,    71,    30,    72,    73,
      80,    81,   128,   129,   130,   131,   140,   141,   173,   153,
     178,   179,   180,   181,   151,   159,   166,   172
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      35,    31,    32,    12,    74,    54,   152,   134,    46,    67,
      68,    69,    79,    83,    87,    31,    32,   145,    92,   156,
      86,   123,   124,   142,    19,    10,   143,    39,    94,    95,
      14,    31,    15,    16,    17,    18,    19,    19,   122,    19,
     122,    20,    21,    45,   165,    47,   186,    89,   111,    51,
      40,    48,   144,    49,    41,    33,    45,    21,    22,    98,
      99,   115,   116,   117,   118,   119,   120,   121,    52,   133,
     125,    42,   126,    14,    43,    15,    16,    17,    18,    49,
      44,   170,    19,    96,    20,   174,    58,    62,    19,    48,
      63,    49,   182,    64,    55,    84,    65,    57,    76,   154,
      21,    22,    88,    97,    98,    99,    21,    66,    67,    68,
      69,    78,    31,    32,    54,    56,    60,    62,    19,   162,
      63,    49,    77,    64,    31,    32,    65,   169,    85,    84,
      91,     1,     2,     3,     4,   176,    21,    66,    67,    68,
      69,     5,    93,   106,   107,    54,   112,   108,   109,    31,
      32,    97,    98,    99,    12,    31,    32,    62,    19,   103,
      63,   113,   122,    64,   -81,   135,    65,    97,    98,    99,
     -80,   100,   101,   188,   102,   103,    21,    66,    82,    68,
      69,   147,   138,    97,    98,    99,   149,   100,   101,   150,
     102,   103,    97,    98,    99,   155,   100,   101,   183,   102,
     103,    97,    98,    99,   110,   100,   101,   157,   102,   103,
      97,    98,    99,   127,   100,   101,    19,   102,   103,   161,
     104,    97,    98,    99,   164,   100,   101,   163,   102,   103,
      51,   105,    97,    98,    99,   167,   100,   101,   171,   102,
     103,   177,   114,    97,    98,    99,   -92,   100,   101,   158,
     102,   103,   184,   168,    97,    98,    99,   185,   100,   101,
     160,   102,   103,    59,   175,    97,    98,    99,    90,   100,
     101,   148,   102,   103,    97,    98,    99,    75,   139,   101,
       0,   102,   103,    97,    98,    99,   187,     0,     0,     0,
     102,   103
};

static const yytype_int16 yycheck[] =
{
      13,    11,    11,     7,    40,    25,   141,   122,    21,    36,
      37,    38,    48,    49,    58,    25,    25,     7,    62,     7,
      56,   104,   105,    29,    16,     0,    32,    24,    64,    65,
       7,    41,     9,    10,    11,    12,    16,    16,    28,    16,
      28,    18,    34,    35,   159,    18,   181,    60,    84,    16,
      24,    24,    29,    26,    24,    35,    35,    34,    35,    16,
      17,    97,    98,    99,   100,   101,   102,   103,    35,   113,
     106,    30,   108,     7,    30,     9,    10,    11,    12,    26,
      35,   164,    16,    18,    18,   168,    33,    15,    16,    24,
      18,    26,   175,    21,    30,    26,    24,    30,    30,   143,
      34,    35,    33,    15,    16,    17,    34,    35,    36,    37,
      38,    39,   122,   122,   134,    33,    32,    15,    16,   155,
      18,    26,    30,    21,   134,   134,    24,   163,    14,    26,
      30,     3,     4,     5,     6,   171,    34,    35,    36,    37,
      38,    13,    35,    30,    25,   165,    30,    32,    27,   159,
     159,    15,    16,    17,   158,   165,   165,    15,    16,    23,
      18,    28,    28,    21,     0,     8,    24,    15,    16,    17,
       0,    19,    20,   186,    22,    23,    34,    35,    36,    37,
      38,     8,    30,    15,    16,    17,    35,    19,    20,    28,
      22,    23,    15,    16,    17,    24,    19,    20,    30,    22,
      23,    15,    16,    17,    27,    19,    20,    18,    22,    23,
      15,    16,    17,    27,    19,    20,    16,    22,    23,    35,
      25,    15,    16,    17,    25,    19,    20,    24,    22,    23,
      16,    25,    15,    16,    17,    24,    19,    20,    14,    22,
      23,    29,    25,    15,    16,    17,    25,    19,    20,   150,
      22,    23,    25,    25,    15,    16,    17,    32,    19,    20,
     152,    22,    23,    33,    25,    15,    16,    17,    60,    19,
      20,   136,    22,    23,    15,    16,    17,    41,   129,    20,
      -1,    22,    23,    15,    16,    17,   185,    -1,    -1,    -1,
      22,    23
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,    13,    42,    45,    46,    49,
       0,    43,    46,    47,     7,     9,    10,    11,    12,    16,
      18,    34,    35,    51,    52,    58,    59,    60,    63,    64,
      68,    69,    70,    35,    50,    51,    54,    55,    56,    24,
      24,    24,    30,    30,    35,    35,    51,    18,    24,    26,
      53,    16,    35,    44,    59,    30,    33,    30,    33,    53,
      32,    48,    15,    18,    21,    24,    35,    36,    37,    38,
      66,    67,    69,    70,    66,    68,    30,    30,    39,    66,
      71,    72,    36,    66,    26,    14,    66,    67,    33,    51,
      54,    30,    67,    35,    66,    66,    18,    15,    16,    17,
      19,    20,    22,    23,    25,    25,    30,    25,    32,    27,
      27,    66,    30,    28,    25,    66,    66,    66,    66,    66,
      66,    66,    28,    65,    65,    66,    66,    27,    73,    74,
      75,    76,    57,    67,    58,     8,    61,    62,    30,    75,
      77,    78,    29,    32,    29,     7,    65,     8,    62,    35,
      28,    85,    49,    80,    67,    24,     7,    18,    45,    86,
      52,    35,    66,    24,    25,    58,    87,    24,    25,    66,
      65,    14,    88,    79,    65,    25,    66,    29,    81,    82,
      83,    84,    65,    30,    25,    32,    49,    83,    51
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    41,    43,    44,    42,    45,    45,    47,    48,    46,
      49,    49,    49,    49,    49,    50,    50,    50,    50,    51,
      51,    51,    52,    52,    53,    53,    53,    54,    54,    55,
      56,    57,    57,    58,    58,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    60,    60,    61,    61,    62,    62,
      63,    64,    65,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    67,    67,
      67,    68,    69,    69,    70,    71,    71,    71,    72,    72,
      73,    73,    74,    74,    76,    75,    78,    79,    77,    80,
      80,    81,    81,    82,    82,    84,    83,    85,    86,    86,
      87,    87,    88,    88
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     0,     7,     2,     1,     0,     0,     5,
       1,     1,     1,     1,     1,     3,     3,     1,     1,     1,
       2,     2,     2,     1,     4,     3,     3,     1,     1,     3,
       6,     3,     1,     2,     1,     1,     1,     1,     2,     2,
       2,     2,     3,     3,     7,     6,     7,     6,     2,     0,
      10,     5,     3,     3,     3,     3,     2,     2,     3,     3,
       2,     3,     3,     3,     1,     1,     2,     1,     1,     1,
       1,     3,     1,     2,     4,     1,     1,     0,     3,     1,
       1,     0,     2,     1,     0,     3,     0,     0,     7,     1,
       2,     1,     0,     3,     1,     0,     3,     5,     1,     0,
       1,     0,     3,     0
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
#line 100 "parser.y"
                     { ast_traversal((yyvsp[0].node)); }
#line 1548 "parser.tab.c"
    break;

  case 3:
#line 101 "parser.y"
                     { ast_traversal((yyvsp[0].node)); }
#line 1554 "parser.tab.c"
    break;

  case 4:
#line 102 "parser.y"
                                       { ast_traversal((yyvsp[0].node)); }
#line 1560 "parser.tab.c"
    break;

  case 5:
#line 108 "parser.y"
        {
		AST_Node_Declarations *temp = (AST_Node_Declarations*) (yyvsp[-1].node);
		(yyval.node) = new_declarations_node(temp->declarations, temp->declaration_count, (yyvsp[0].node));
	}
#line 1569 "parser.tab.c"
    break;

  case 6:
#line 113 "parser.y"
        {
		(yyval.node) = new_declarations_node(NULL, 0, (yyvsp[0].node));
	}
#line 1577 "parser.tab.c"
    break;

  case 7:
#line 118 "parser.y"
                  { declare = 1; }
#line 1583 "parser.tab.c"
    break;

  case 8:
#line 118 "parser.y"
                                         { declare = 0; }
#line 1589 "parser.tab.c"
    break;

  case 9:
#line 119 "parser.y"
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
	}
#line 1617 "parser.tab.c"
    break;

  case 10:
#line 144 "parser.y"
                        { (yyval.data_type) = INT_TYPE;   }
#line 1623 "parser.tab.c"
    break;

  case 11:
#line 145 "parser.y"
                        { (yyval.data_type) = CHAR_TYPE;  }
#line 1629 "parser.tab.c"
    break;

  case 12:
#line 146 "parser.y"
                        { (yyval.data_type) = REAL_TYPE;  }
#line 1635 "parser.tab.c"
    break;

  case 13:
#line 147 "parser.y"
                        { (yyval.data_type) = REAL_TYPE;  }
#line 1641 "parser.tab.c"
    break;

  case 14:
#line 148 "parser.y"
                        { (yyval.data_type) = VOID_TYPE;  }
#line 1647 "parser.tab.c"
    break;

  case 15:
#line 152 "parser.y"
        {
		add_to_names((yyvsp[0].symtab_item));
	}
#line 1655 "parser.tab.c"
    break;

  case 16:
#line 156 "parser.y"
        {
		add_to_names((yyvsp[0].symtab_item));
	}
#line 1663 "parser.tab.c"
    break;

  case 17:
#line 160 "parser.y"
        {
		add_to_names((yyvsp[0].symtab_item));
	}
#line 1671 "parser.tab.c"
    break;

  case 18:
#line 164 "parser.y"
        { 
		add_to_names((yyvsp[0].symtab_item));
	}
#line 1679 "parser.tab.c"
    break;

  case 19:
#line 169 "parser.y"
             { (yyval.symtab_item) = (yyvsp[0].symtab_item); }
#line 1685 "parser.tab.c"
    break;

  case 20:
#line 171 "parser.y"
        {
		(yyvsp[0].symtab_item)->st_type = POINTER_TYPE;
		(yyval.symtab_item) = (yyvsp[0].symtab_item);
	}
#line 1694 "parser.tab.c"
    break;

  case 21:
#line 176 "parser.y"
        {
		(yyvsp[-1].symtab_item)->st_type = ARRAY_TYPE;
		(yyvsp[-1].symtab_item)->array_size = (yyvsp[0].array_size);
		(yyval.symtab_item) = (yyvsp[-1].symtab_item);
	}
#line 1704 "parser.tab.c"
    break;

  case 24:
#line 186 "parser.y"
        { 
	    // if declaration then error!
		if(declare == 1){
			fprintf(stderr, "Array declaration at %d contains expression!\n", lineno);
			exit(1);
		}
	}
#line 1716 "parser.tab.c"
    break;

  case 25:
#line 194 "parser.y"
        {
		// if declaration then error!
		if(declare == 1){
			fprintf(stderr, "Array declaration at %d contains expression!\n", lineno);
			exit(1);
		}
	}
#line 1728 "parser.tab.c"
    break;

  case 26:
#line 202 "parser.y"
        {
		// set array_size for declaration purposes
		(yyval.array_size) = (yyvsp[-1].val).ival;
	}
#line 1737 "parser.tab.c"
    break;

  case 27:
#line 209 "parser.y"
                 { (yyval.symtab_item) = (yyvsp[0].symtab_item); }
#line 1743 "parser.tab.c"
    break;

  case 28:
#line 210 "parser.y"
                     { (yyval.symtab_item) = (yyvsp[0].symtab_item); }
#line 1749 "parser.tab.c"
    break;

  case 29:
#line 214 "parser.y"
{ 
	AST_Node_Const *temp = (AST_Node_Const*) (yyval.symtab_item);
	(yyvsp[-2].symtab_item)->val = temp->val;
	(yyvsp[-2].symtab_item)->st_type = temp->const_type;
	(yyval.symtab_item) = (yyvsp[-2].symtab_item);
}
#line 1760 "parser.tab.c"
    break;

  case 30:
#line 223 "parser.y"
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
#line 1775 "parser.tab.c"
    break;

  case 31:
#line 236 "parser.y"
        {
		AST_Node_Const *temp = (AST_Node_Const*) (yyvsp[0].node);
		add_to_vals(temp->val);
	}
#line 1784 "parser.tab.c"
    break;

  case 32:
#line 241 "parser.y"
        {
		AST_Node_Const *temp = (AST_Node_Const*) (yyvsp[0].node);
		add_to_vals(temp->val);
	}
#line 1793 "parser.tab.c"
    break;

  case 33:
#line 250 "parser.y"
        {
		AST_Node_Statements *temp = (AST_Node_Statements*) (yyvsp[-1].node);
		(yyval.node) = new_statements_node(temp->statements, temp->statement_count, (yyvsp[0].node));
	}
#line 1802 "parser.tab.c"
    break;

  case 34:
#line 255 "parser.y"
        {
		(yyval.node) = new_statements_node(NULL, 0, (yyvsp[0].node));
	}
#line 1810 "parser.tab.c"
    break;

  case 35:
#line 262 "parser.y"
        { 
		(yyval.node) = (yyvsp[0].node); /* just pass information */
	}
#line 1818 "parser.tab.c"
    break;

  case 36:
#line 266 "parser.y"
        { 
		(yyval.node) = (yyvsp[0].node); /* just pass information */
	}
#line 1826 "parser.tab.c"
    break;

  case 37:
#line 270 "parser.y"
        {
		(yyval.node) = (yyvsp[0].node); /* just pass information */
	}
#line 1834 "parser.tab.c"
    break;

  case 38:
#line 274 "parser.y"
        {
		(yyval.node) = (yyvsp[-1].node); /* just pass information */
	}
#line 1842 "parser.tab.c"
    break;

  case 39:
#line 278 "parser.y"
        { 
		(yyval.node) = new_ast_simple_node(0);
	}
#line 1850 "parser.tab.c"
    break;

  case 40:
#line 282 "parser.y"
        { 
		(yyval.node) = new_ast_simple_node(1);
	}
#line 1858 "parser.tab.c"
    break;

  case 41:
#line 286 "parser.y"
        { 
		(yyval.node) = (yyvsp[-1].node); /* just pass information */
	}
#line 1866 "parser.tab.c"
    break;

  case 42:
#line 290 "parser.y"
        {
		/* increment */
		if((yyvsp[-1].val).ival == INC){
			(yyval.node) = new_ast_incr_node((yyvsp[-2].symtab_item), 0, 0);
		}
		else{
			(yyval.node) = new_ast_incr_node((yyvsp[-2].symtab_item), 1, 0);
		}
	}
#line 1880 "parser.tab.c"
    break;

  case 43:
#line 300 "parser.y"
        {
		/* increment */
		if((yyvsp[-2].val).ival == INC){
			(yyval.node) = new_ast_incr_node((yyvsp[-1].symtab_item), 0, 1);
		}
		else{
			(yyval.node) = new_ast_incr_node((yyvsp[-1].symtab_item), 1, 1);
		}
	}
#line 1894 "parser.tab.c"
    break;

  case 44:
#line 313 "parser.y"
        {
		(yyval.node) = new_ast_if_node((yyvsp[-4].node), (yyvsp[-2].node), elsifs, elseif_count, (yyvsp[0].node));
		elseif_count = 0;
		elsifs = NULL;
	}
#line 1904 "parser.tab.c"
    break;

  case 45:
#line 319 "parser.y"
        {
		(yyval.node) = new_ast_if_node((yyvsp[-3].node), (yyvsp[-1].node), NULL, 0, (yyvsp[0].node));
	}
#line 1912 "parser.tab.c"
    break;

  case 46:
#line 326 "parser.y"
        {
		AST_Node *temp = new_ast_elsif_node((yyvsp[-2].node), (yyvsp[0].node));
		add_elseif(temp);
	}
#line 1921 "parser.tab.c"
    break;

  case 47:
#line 331 "parser.y"
        {
		AST_Node *temp = new_ast_elsif_node((yyvsp[-2].node), (yyvsp[0].node));
		add_elseif(temp);
	}
#line 1930 "parser.tab.c"
    break;

  case 48:
#line 339 "parser.y"
        {
		/* else exists */
		(yyval.node) = (yyvsp[0].node);
	}
#line 1939 "parser.tab.c"
    break;

  case 49:
#line 344 "parser.y"
        {
		/* no else */
		(yyval.node) = NULL;
	}
#line 1948 "parser.tab.c"
    break;

  case 50:
#line 351 "parser.y"
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
#line 1966 "parser.tab.c"
    break;

  case 51:
#line 367 "parser.y"
{
	(yyval.node) = new_ast_while_node((yyvsp[-2].node), (yyvsp[0].node));
}
#line 1974 "parser.tab.c"
    break;

  case 52:
#line 373 "parser.y"
{ 
	(yyval.node) = (yyvsp[-1].node); /* just pass information */
}
#line 1982 "parser.tab.c"
    break;

  case 53:
#line 380 "parser.y"
        { 
	    (yyval.node) = new_ast_arithm_node((yyvsp[-1].val).ival, (yyvsp[-2].node), (yyvsp[0].node));
	}
#line 1990 "parser.tab.c"
    break;

  case 54:
#line 384 "parser.y"
        {
	    (yyval.node) = new_ast_arithm_node(MUL, (yyvsp[-2].node), (yyvsp[0].node));
	}
#line 1998 "parser.tab.c"
    break;

  case 55:
#line 388 "parser.y"
        {
		(yyval.node) = new_ast_arithm_node(DIV, (yyvsp[-2].node), (yyvsp[0].node));
	}
#line 2006 "parser.tab.c"
    break;

  case 56:
#line 392 "parser.y"
        {
		/* increment */
		if((yyvsp[0].val).ival == INC){
			(yyval.node) = new_ast_incr_node((yyvsp[-1].symtab_item), 0, 0);
		}
		else{
			(yyval.node) = new_ast_incr_node((yyvsp[-1].symtab_item), 1, 0);
		}	
	}
#line 2020 "parser.tab.c"
    break;

  case 57:
#line 402 "parser.y"
        {
		/* increment */
		if((yyvsp[-1].val).ival == INC){
			(yyval.node) = new_ast_incr_node((yyvsp[0].symtab_item), 0, 1);
		}
		else{
			(yyval.node) = new_ast_incr_node((yyvsp[0].symtab_item), 1, 1);
		}
	}
#line 2034 "parser.tab.c"
    break;

  case 58:
#line 412 "parser.y"
        {
		(yyval.node) = new_ast_bool_node(OR, (yyvsp[-2].node), (yyvsp[0].node));
	}
#line 2042 "parser.tab.c"
    break;

  case 59:
#line 416 "parser.y"
        {
		(yyval.node) = new_ast_bool_node(AND, (yyvsp[-2].node), (yyvsp[0].node));
	}
#line 2050 "parser.tab.c"
    break;

  case 60:
#line 420 "parser.y"
        {
	    (yyval.node) = new_ast_bool_node(NOT, (yyvsp[0].node), NULL);
	}
#line 2058 "parser.tab.c"
    break;

  case 61:
#line 424 "parser.y"
        {
		(yyval.node) = new_ast_equ_node((yyvsp[-1].val).ival, (yyvsp[-2].node), (yyvsp[0].node));
	}
#line 2066 "parser.tab.c"
    break;

  case 62:
#line 428 "parser.y"
        {
		(yyval.node) = new_ast_rel_node((yyvsp[-1].val).ival, (yyvsp[-2].node), (yyvsp[0].node));
	}
#line 2074 "parser.tab.c"
    break;

  case 63:
#line 432 "parser.y"
        {
		(yyval.node) = (yyvsp[-1].node); /* just pass information */
	}
#line 2082 "parser.tab.c"
    break;

  case 64:
#line 436 "parser.y"
        { 
		(yyval.node) = (yyvsp[0].node); /* just pass information */
	}
#line 2090 "parser.tab.c"
    break;

  case 65:
#line 440 "parser.y"
        {
		(yyval.node) = (yyvsp[0].node); /* no sign */
	}
#line 2098 "parser.tab.c"
    break;

  case 66:
#line 444 "parser.y"
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
#line 2130 "parser.tab.c"
    break;

  case 67:
#line 472 "parser.y"
        {
		(yyval.node) = (yyvsp[0].node); /* just pass information */
	}
#line 2138 "parser.tab.c"
    break;

  case 68:
#line 478 "parser.y"
                 { (yyval.node) = new_ast_const_node(INT_TYPE, (yyvsp[0].val));  }
#line 2144 "parser.tab.c"
    break;

  case 69:
#line 479 "parser.y"
                 { (yyval.node) = new_ast_const_node(REAL_TYPE, (yyvsp[0].val)); }
#line 2150 "parser.tab.c"
    break;

  case 70:
#line 480 "parser.y"
                 { (yyval.node) = new_ast_const_node(CHAR_TYPE, (yyvsp[0].val)); }
#line 2156 "parser.tab.c"
    break;

  case 71:
#line 484 "parser.y"
{
	AST_Node_Ref *temp = (AST_Node_Ref*) (yyvsp[-2].node);
	(yyval.node) = new_ast_assign_node(temp->entry, temp->ref, (yyvsp[0].node));
}
#line 2165 "parser.tab.c"
    break;

  case 72:
#line 491 "parser.y"
        {
		(yyval.node) = new_ast_ref_node((yyvsp[0].symtab_item), 0); /* no reference */
	}
#line 2173 "parser.tab.c"
    break;

  case 73:
#line 495 "parser.y"
        {
		(yyval.node) = new_ast_ref_node((yyvsp[0].symtab_item), 1); /* reference */
	}
#line 2181 "parser.tab.c"
    break;

  case 74:
#line 501 "parser.y"
{	
	AST_Node_Call_Params *temp = (AST_Node_Call_Params*) (yyvsp[-1].node);
	(yyval.node) = new_ast_func_call_node((yyvsp[-3].symtab_item), temp->params, temp->num_of_pars);
}
#line 2190 "parser.tab.c"
    break;

  case 75:
#line 509 "parser.y"
        {
		(yyval.node) = (yyvsp[0].node);
	}
#line 2198 "parser.tab.c"
    break;

  case 76:
#line 513 "parser.y"
        {
		AST_Node *temp = new_ast_const_node(STR_TYPE, (yyvsp[0].val));
		(yyval.node) = new_ast_call_params_node(NULL, 0, temp);
	}
#line 2207 "parser.tab.c"
    break;

  case 77:
#line 518 "parser.y"
        {
		AST_Node_Call_Params *temp = malloc (sizeof (AST_Node_Call_Params));
		temp->type = CALL_PARAMS;
		temp->params = NULL;
		temp->num_of_pars = 0;
		(yyval.node) = (AST_Node*)temp;
	}
#line 2219 "parser.tab.c"
    break;

  case 78:
#line 529 "parser.y"
        {
		AST_Node_Call_Params *temp = (AST_Node_Call_Params*) (yyvsp[-2].node);
		(yyval.node) = new_ast_call_params_node(temp->params, temp->num_of_pars, (yyvsp[0].node));
	}
#line 2228 "parser.tab.c"
    break;

  case 79:
#line 534 "parser.y"
        {
		(yyval.node) = new_ast_call_params_node(NULL, 0, (yyvsp[0].node));
	}
#line 2236 "parser.tab.c"
    break;

  case 80:
#line 542 "parser.y"
        {
		(yyval.node) = (yyvsp[0].node);
	}
#line 2244 "parser.tab.c"
    break;

  case 81:
#line 546 "parser.y"
        {
		(yyval.node) = NULL;
	}
#line 2252 "parser.tab.c"
    break;

  case 82:
#line 553 "parser.y"
        {
		AST_Node_Func_Declarations *temp = (AST_Node_Func_Declarations*) (yyvsp[-1].node);
		(yyval.node) = new_func_declarations_node(temp->func_declarations, temp->func_declaration_count, (yyvsp[0].node));
	}
#line 2261 "parser.tab.c"
    break;

  case 83:
#line 558 "parser.y"
        {
		(yyval.node) = new_func_declarations_node(NULL, 0, (yyvsp[0].node));
	}
#line 2269 "parser.tab.c"
    break;

  case 84:
#line 563 "parser.y"
          { incr_scope(); }
#line 2275 "parser.tab.c"
    break;

  case 85:
#line 564 "parser.y"
{ 
	hide_scope();
	(yyval.node) = (AST_Node *) temp_function;
}
#line 2284 "parser.tab.c"
    break;

  case 86:
#line 570 "parser.y"
               { declare = 1; }
#line 2290 "parser.tab.c"
    break;

  case 87:
#line 571 "parser.y"
        { 
		declare = 0;
		
		AST_Node_Ret_Type *temp = (AST_Node_Ret_Type *) (yyvsp[-2].node);
		temp_function = (AST_Node_Func_Decl *) new_ast_func_decl_node(temp->ret_type, temp->pointer, (yyvsp[-1].symtab_item));
		temp_function->entry->st_type = FUNCTION_TYPE;
		temp_function->entry->inf_type = temp->ret_type;
	}
#line 2303 "parser.tab.c"
    break;

  case 88:
#line 580 "parser.y"
        {
		if((yyvsp[-1].node) != NULL){
			AST_Node_Decl_Params *temp = (AST_Node_Decl_Params *) (yyvsp[-1].node);
			
			temp_function->entry->parameters = temp->parameters;
			temp_function->entry->num_of_pars = temp->num_of_pars;
		}
		else{
			temp_function->entry->parameters = NULL;
			temp_function->entry->num_of_pars = 0;
		}		
	}
#line 2320 "parser.tab.c"
    break;

  case 89:
#line 596 "parser.y"
        {
		(yyval.node) = new_ast_ret_type_node((yyvsp[0].data_type), 0);
	}
#line 2328 "parser.tab.c"
    break;

  case 90:
#line 600 "parser.y"
        {
		(yyval.node) = new_ast_ret_type_node((yyvsp[-1].data_type), 1);
	}
#line 2336 "parser.tab.c"
    break;

  case 91:
#line 607 "parser.y"
        {
		(yyval.node) = (yyvsp[0].node);
	}
#line 2344 "parser.tab.c"
    break;

  case 92:
#line 611 "parser.y"
        {
		(yyval.node) = NULL;
	}
#line 2352 "parser.tab.c"
    break;

  case 93:
#line 618 "parser.y"
        {
		AST_Node_Decl_Params *temp = (AST_Node_Decl_Params *) (yyvsp[-2].node);
		(yyval.node) = new_ast_decl_params_node(temp->parameters, temp->num_of_pars, (yyvsp[0].par));
	}
#line 2361 "parser.tab.c"
    break;

  case 94:
#line 623 "parser.y"
        {
		(yyval.node) = new_ast_decl_params_node(NULL, 0, (yyvsp[0].par));
	}
#line 2369 "parser.tab.c"
    break;

  case 95:
#line 628 "parser.y"
            { declare = 1; }
#line 2375 "parser.tab.c"
    break;

  case 96:
#line 629 "parser.y"
{ 
	declare = 0;
	(yyval.par) = def_param((yyvsp[-1].data_type), (yyvsp[0].symtab_item)->st_name, 0);
}
#line 2384 "parser.tab.c"
    break;

  case 98:
#line 639 "parser.y"
        {
		temp_function->declarations = (yyvsp[0].node);
	}
#line 2392 "parser.tab.c"
    break;

  case 99:
#line 643 "parser.y"
        {
		temp_function->declarations = NULL;
	}
#line 2400 "parser.tab.c"
    break;

  case 100:
#line 650 "parser.y"
        {
		temp_function->statements = (yyvsp[0].node);
	}
#line 2408 "parser.tab.c"
    break;

  case 101:
#line 654 "parser.y"
        {
		temp_function->statements = NULL;
	}
#line 2416 "parser.tab.c"
    break;

  case 102:
#line 661 "parser.y"
        {
		temp_function->return_node = new_ast_return_node(temp_function->ret_type, (yyvsp[-1].node));
	}
#line 2424 "parser.tab.c"
    break;

  case 103:
#line 665 "parser.y"
        {
		temp_function->return_node = NULL;
	}
#line 2432 "parser.tab.c"
    break;


#line 2436 "parser.tab.c"

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
#line 670 "parser.y"


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
