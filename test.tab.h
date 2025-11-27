/* 由 SeuYacc 生成的 LR(1) 解析器头文件 */

#ifndef TEST_TAB_H_INCLUDED
# define TEST_TAB_H_INCLUDED
/* 调试跟踪设置 */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* 令牌类型定义 */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEOF = 0,                     /* "文件结束" */
    CHAR = 257,
    INTEGER_LITERAL = 258,
    INT = 259,
    IDENTIFIER = 260,
    SEMICOLON = 261,
    STRING_LITERAL = 262,
    VOID = 263,
    RETURN = 264,
    MAIN = 265,
    PRINTF = 266,
    LBRACE = 267,
    RBRACE = 268,
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* 令牌定义宏 */
#define YYEOF 0
#define CHAR 257
#define INTEGER_LITERAL 258
#define INT 259
#define IDENTIFIER 260
#define SEMICOLON 261
#define STRING_LITERAL 262
#define VOID 263
#define RETURN 264
#define MAIN 265
#define PRINTF 266
#define LBRACE 267
#define RBRACE 268

/* 值类型定义 */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
    int ival;
    char* sval;
    struct ASTNode* node;
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


/* 外部变量声明 */
extern YYSTYPE yylval;


/* 解析函数声明 */
int yyparse(void);


#endif /* !TEST_TAB_H_INCLUDED */
