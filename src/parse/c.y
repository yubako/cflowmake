%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cytypes.h"
#include "psbuff.h"

extern unsigned int g_line;
inline void yyerror(const char *s)
{
    printf("error line = %u %s\n", g_line, s);
}


%}

%token storage_class_specifier type_specifier_keywords type_qualifier_keywords struct_or_union
%token assignment_operator_keywords
%token ENUM IF ELSE SWITCH DO FOR CASE WHILE GOTO CONTINUE BREAK RETURN DEFAULT SIZEOF DOTS DOT
%token GT LT GE LE PP MM ARROW
%token OR AND EQUAL NOTEQUAL
%token LSHIFT RSHIFT 
%token string
%token identifier
%token integer_constant character_constant floating_constant 

%left '*' 

%union {
    char* str;
    Statement*  stmt;
    Expression* expr;
}
%%


translation_unit                        : external_declaration
                                        | translation_unit external_declaration
                                        ;

external_declaration                    : function_definition
                                        | declaration
                                        ;

/* 
    関数定義 ( function_definition )

    declaration_specifier  戻り値型 
    declarator             関数宣言子
    declaration            引数指定子
    compound_statement     関数実体
*/
function_definition                     : declaration_specifier  declarator declaration_list compound_statement
                                        {
                                        }
                                        |                        declarator declaration_list compound_statement
                                        {
                                        }
                                        | declaration_specifier  declarator                  compound_statement
                                        {
                                        }
                                        |                        declarator                  compound_statement
                                        {
                                        }
                                        ;

declaration                             : declaration_specifier init_declarator_list ';'
                                        {
                                        }
                                        | declaration_specifier                      ';'
                                        {
                                        }
                                        ;

declaration_list                        : declaration
                                        | declaration_list declaration
                                        ;

declaration_specifier                   : storage_class_specifier declaration_specifier
                                        {
                                        }
                                        | storage_class_specifier
                                        {
                                        }
                                        | type_specifier          declaration_specifier
                                        {
                                        }
                                        | type_specifier
                                        {
                                        }
                                        | type_qualifier          declaration_specifier
                                        {
                                        }
                                        | type_qualifier
                                        {
                                        }
                                        ;

type_specifier                          : type_specifier_keywords
                                        | struct_or_union_specifier
                                        | enum_specifier
/*                                      | typedef_name */
                                        ;

type_qualifier                          : type_qualifier_keywords
                                        ;


/*
    構造体, 共用体定義
 */
struct_or_union_specifier               : struct_or_union identifier '{' struct_declaration_list '}'
                                        | struct_or_union            '{' struct_declaration_list '}'
                                        | struct_or_union identifier
                                        ;

struct_declaration_list                 : struct_declaration
                                        | struct_declaration_list struct_declaration
                                        ;

/* 
    初期化指定子
*/

init_declarator_list                    : init_declarator
                                        | init_declarator_list ',' init_declarator
                                        ;

init_declarator                         : declarator
                                        | declarator '=' initializer
                                        ;

struct_declaration                      : specifier_qualifier_list struct_declarator_list ';'
                                        ;

specifier_qualifier_list                : type_specifier specifier_qualifier_list
                                        | type_specifier
                                        | type_qualifier specifier_qualifier_list
                                        | type_qualifier
                                        ;

struct_declarator_list                  : struct_declarator
                                        | struct_declarator_list ',' struct_declarator
                                        ;

struct_declarator                       : declarator
                                        | declarator ':' constant_expression
                                        |            ':' constant_expression
                                        ;

/*
    列挙型定義
 */
enum_specifier                          : ENUM identifier '{' enumerator_list '}'
                                        | ENUM            '{' enumerator_list '}'
                                        | ENUM identifier
                                        ;

enumerator_list                         :                     enumerator
                                        | enumerator_list ',' enumerator
                                        ;

enumerator                              : identifier
                                        | identifier '=' constant_expression
                                        ;
/*
    宣言子
*/
declarator                              : pointer direct_declarator
                                        {
                                        }
                                        |         direct_declarator
                                        {
                                        }
                                        ;

direct_declarator                       : identifier 
                                        {
                                        }
                                        | '(' declarator ')'
                                        {
                                        }
                                        | direct_declarator '[' constant_expression']'
                                        | direct_declarator '['                    ']'
                                        | direct_declarator '(' parameter_type_list ')'
                                        | direct_declarator '(' identifier_list     ')'
                                        | direct_declarator '('                     ')'
                                        ;

pointer                                 : '*' type_qualifier_list
                                        | '*' 
                                        | '*' type_qualifier_list pointer
                                        | '*'                     pointer
                                        ;

type_qualifier_list                     :                     type_qualifier
                                        | type_qualifier_list type_qualifier
                                        ;

parameter_type_list                     : parameter_list
                                        | parameter_list ',' DOTS
                                        ;

parameter_list                          :                    parameter_declaration
                                        | parameter_list ',' parameter_declaration
                                        ;

parameter_declaration                   : declaration_specifier declarator
                                        | declaration_specifier abstract_declarator
                                        | declaration_specifier
                                        ;

identifier_list                         : identifier
                                        | identifier_list ',' identifier
                                        ;

initializer                             : assignment_expression
                                        | '{' initializer_list '}'
                                        | '{' initializer_list ',' '}'
                                        ;

initializer_list                        : initializer
                                        | initializer_list ',' initializer
                                        ;

type_name                               : specifier_qualifier_list abstract_declarator
                                        | specifier_qualifier_list
                                        ;

abstract_declarator                     : pointer
                                        | pointer direct_abstract_declarator
                                        |         direct_abstract_declarator
                                        ;

direct_abstract_declarator              : '(' abstract_declarator ')'
                                        | direct_abstract_declarator '[' constant_expression ']'
                                        |                            '[' constant_expression ']'
                                        | direct_abstract_declarator '['                     ']'
                                        |                            '['                     ']'
                                        | direct_abstract_declarator '(' parameter_type_list ')'
                                        |                            '(' parameter_type_list ')'
                                        | direct_abstract_declarator '('                     ')'
                                        |                            '('                     ')'
                                        ;

/*

typedef_nameはidentifierと区別がつかなくなる。
tableを作成して字句として解析したほうがよさげなのでここでは無視

typedef_name                            : identifier
*/


/*
    式
 */
statement                               : labeled_statement
                                        {
                                            $<stmt>$ = $<stmt>1;
                                        }
                                        | expression_statement
                                        {
                                            $<stmt>$ = $<stmt>1;
                                        }
                                        | compound_statement
                                        {
                                            $<stmt>$ = $<stmt>1;
                                        }
                                        | select_statement
                                        {
                                            $<stmt>$ = $<stmt>1;
                                        }
                                        | iteration_statement
                                        {
                                            $<stmt>$ = $<stmt>1;
                                        }
                                        | jump_statement
                                        {
                                            $<stmt>$ = $<stmt>1;
                                        }
                                        ;

labeled_statement                       : identifier ':' statement
                                        | CASE constant_expression ':' statement
                                        | DEFAULT ':' statement
                                        ;

expression_statement                    : expression ';'
                                        {
                                            Expression* expr = $<expr>1;
                                            ExpressionStatement* stmt = new ExpressionStatement(g_line, expr);
                                            $<stmt>$ = stmt;
                                            dprintf("Expression Statement", "%s\n", stmt->toString());
                                        }
                                        |            ';'
                                        {
                                            $<stmt>$ = new NullStatement();
                                        }
                                        ;

select_statement                        : IF '(' expression ')' statement
                                        {
                                            IfStatement* ifstmt = new IfStatement(g_line, $<expr>3);
                                            ifstmt->setTrue($<stmt>5);
                                            dprintf("IfStatement\n", "%s\n", ifstmt->toString());
                                            //printf("IfStatement %s\n", ifstmt->toString());
                                        }
                                        | IF '(' expression ')' statement ELSE statement
                                        {
                                        }
                                        | SWITCH '(' expression ')' statement
                                        {
                                        }
                                        ;

iteration_statement                     : WHILE '(' expression ')' statement
                                        | DO statement WHILE '(' expression ')' ';'
                                        | FOR '(' expression ';' expression ';' expression ')' statement
                                        | FOR '(' expression ';' expression ';'            ')' statement
                                        | FOR '(' expression ';'            ';' expression ')' statement
                                        | FOR '(' expression ';'            ';'            ')' statement
                                        | FOR '('            ';' expression ';' expression ')' statement
                                        | FOR '('            ';' expression ';'            ')' statement
                                        | FOR '('            ';'            ';' expression ')' statement
                                        | FOR '('            ';'            ';'            ')' statement
                                        ;

jump_statement                          : GOTO identifier ';'
                                        | CONTINUE ';'
                                        | BREAK    ';'
                                        | RETURN expression ';'
                                        | RETURN            ';'
                                        ;

/*
    '{' '}' で閉じられたstatmenet  compound_statement
*/
compound_statement                      : '{' declaration_list statement_list '}'
                                        | '{' declaration_list                '}'
                                        | '{'                  statement_list '}'
                                        | '{'                                 '}'
                                        ;

statement_list                          :                statement
                                        | statement_list statement
                                        ;


/*
    定数
 */
constant_expression                     : conditional_expression
                                        {
                                            $<expr>$ = $<expr>1;
                                            dprintf("Constant Expression",  "%s\n", $<expr>1->toString());
                                        }
                                        ;

conditional_expression                  : logical_or_expression
                                        {
                                            $<expr>$ = $<expr>1;
                                            Expression* expr = $<expr>1;
                                        }
                                        | logical_or_expression '?' expression ':' conditional_expression
                                        {
                                            Expression* expr1 = new Expression(g_line, $<str>2);
                                            Expression* expr2 = new Expression(g_line, $<str>4);
                                            Expression* base = $<expr>1;
                                            base->pushSibling(expr1);
                                            base->pushSibling($<expr>3);
                                            base->pushSibling(expr2);
                                            base->pushSibling($<expr>5);
                                            $<expr>$ = base;
                                        }
                                        ;

logical_or_expression                   : logical_and_expression
                                        {
                                            $<expr>$ = $<expr>1;
                                        }
                                        | logical_or_expression OR logical_and_expression
                                        {
                                            Expression *expr = new Expression(g_line, $<str>2);
                                            Expression *base = $<expr>1;
                                            base->pushSibling(expr);
                                            base->pushSibling($<expr>3);
                                            $<expr>$ = base;
                                        }
                                        ;

logical_and_expression                  : inclusive_or_expression
                                        {
                                            $<expr>$ = $<expr>1;
                                        }
                                        | logical_and_expression AND inclusive_or_expression
                                        {
                                            Expression *expr = new Expression(g_line, $<str>2);
                                            Expression *base = $<expr>1;
                                            base->pushSibling(expr);
                                            base->pushSibling($<expr>3);
                                            $<expr>$ = base;
                                        }
                                        ;

inclusive_or_expression                 : exclusive_or_expression
                                        {
                                            $<expr>$ = $<expr>1;
                                        }
                                        | inclusive_or_expression '|' exclusive_or_expression
                                        {
                                            Expression *expr = new Expression(g_line, $<str>2);
                                            Expression *base = $<expr>1;
                                            base->pushSibling(expr);
                                            base->pushSibling($<expr>3);
                                            $<expr>$ = base;
                                        }
                                        ;

exclusive_or_expression                 : and_expression
                                        {
                                            $<expr>$ = $<expr>1;
                                        }
                                        | exclusive_or_expression '^' and_expression
                                        {
                                            Expression *expr = new Expression(g_line, $<str>2);
                                            Expression *base = $<expr>1;
                                            base->pushSibling(expr);
                                            base->pushSibling($<expr>3);
                                            $<expr>$ = base;
                                        }
                                        ;

and_expression                          : equality_expression
                                        {
                                            $<expr>$ = $<expr>1;
                                        }
                                        | and_expression '&' equality_expression
                                        {
                                            Expression *expr = new Expression(g_line, $<str>2);
                                            Expression *base = $<expr>1;
                                            base->pushSibling(expr);
                                            base->pushSibling($<expr>3);
                                            $<expr>$ = base;
                                        }
                                        ;

equality_expression                     : relational_expression
                                        {
                                            $<expr>$ = $<expr>1;
                                        }
                                        | equality_expression EQUAL    relational_expression
                                        {
                                            Expression *expr = new Expression(g_line, $<str>2);
                                            Expression *base = $<expr>1;
                                            base->pushSibling(expr);
                                            base->pushSibling($<expr>3);
                                            $<expr>$ = base;
                                        }
                                        | equality_expression NOTEQUAL relational_expression
                                        {
                                            Expression *expr = new Expression(g_line, $<str>2);
                                            Expression *base = $<expr>1;
                                            base->pushSibling(expr);
                                            base->pushSibling($<expr>3);
                                            $<expr>$ = base;
                                        }
                                        ;

relational_expression                   : shift_expression
                                        {
                                            $<expr>$ = $<expr>1;
                                        }
                                        | relational_expression GT shift_expression
                                        {
                                            Expression *expr = new Expression(g_line, $<str>2);
                                            Expression *base = $<expr>1;
                                            base->pushSibling(expr);
                                            base->pushSibling($<expr>3);
                                            $<expr>$ = base;
                                        }
                                        | relational_expression LT shift_expression
                                        {
                                            Expression *expr = new Expression(g_line, $<str>2);
                                            Expression *base = $<expr>1;
                                            base->pushSibling(expr);
                                            base->pushSibling($<expr>3);
                                            $<expr>$ = base;
                                        }
                                        | relational_expression GE shift_expression
                                        {
                                            Expression *expr = new Expression(g_line, $<str>2);
                                            Expression *base = $<expr>1;
                                            base->pushSibling(expr);
                                            base->pushSibling($<expr>3);
                                            $<expr>$ = base;
                                        }
                                        | relational_expression LE shift_expression
                                        {
                                            Expression *expr = new Expression(g_line, $<str>2);
                                            Expression *base = $<expr>1;
                                            base->pushSibling(expr);
                                            base->pushSibling($<expr>3);
                                            $<expr>$ = base;
                                        }
                                        ;

shift_expression                        : additive_expression
                                        {
                                            $<expr>$ = $<expr>1;
                                            Expression* expr = $<expr>1;
                                            dprintf("Shift Expression", "%s\n", expr->toString());
                                        }
                                        | shift_expression LSHIFT additive_expression
                                        {
                                            Expression *expr = new Expression(g_line, $<str>2);
                                            Expression *base = $<expr>1;
                                            base->pushSibling(expr);
                                            base->pushSibling($<expr>3);
                                            $<expr>$ = base;
                                        }
                                        | shift_expression RSHIFT additive_expression
                                        {
                                            Expression *expr = new Expression(g_line, $<str>2);
                                            Expression *base = $<expr>1;
                                            base->pushSibling(expr);
                                            base->pushSibling($<expr>3);
                                            $<expr>$ = base;
                                        }
                                        ;

additive_expression                     : multiplicative_expression
                                        {
                                            $<expr>$ = $<expr>1;
                                            Expression* expr = $<expr>1;
                                            dprintf("Additive Expression", "%s\n", expr->toString());
                                        }
                                        | additive_expression '+' multiplicative_expression
                                        {
                                            Expression *expr = new Expression(g_line, $<str>2);
                                            Expression *base = $<expr>1;
                                            base->pushSibling(expr);
                                            base->pushSibling($<expr>3);
                                            $<expr>$ = base;
                                        }
                                        | additive_expression '-' multiplicative_expression
                                        {
                                            Expression *expr = new Expression(g_line, $<str>2);
                                            Expression *base = $<expr>1;
                                            base->pushSibling(expr);
                                            base->pushSibling($<expr>3);
                                            $<expr>$ = base;
                                        }
                                        ;

multiplicative_expression               : cast_expression
                                        {
                                            $<expr>$ = $<expr>1;

                                            Expression* expr = $<expr>1;
                                            dprintf("Multiplicativ Expression", "%s\n", expr->toString());
                                        }
                                        | multiplicative_expression '*' cast_expression
                                        {
                                            Expression *expr = new Expression(g_line, $<str>2);
                                            Expression *base = $<expr>1;
                                            base->pushSibling(expr);
                                            base->pushSibling($<expr>3);
                                            $<expr>$ = base;
                                        }
                                        | multiplicative_expression '/' cast_expression
                                        {
                                            Expression *expr = new Expression(g_line, $<str>2);
                                            Expression *base = $<expr>1;
                                            base->pushSibling(expr);
                                            base->pushSibling($<expr>3);
                                            $<expr>$ = base;
                                        }
                                        | multiplicative_expression '%' cast_expression
                                        {
                                            Expression *expr = new Expression(g_line, $<str>2);
                                            Expression *base = $<expr>1;
                                            base->pushSibling(expr);
                                            base->pushSibling($<expr>3);
                                            $<expr>$ = base;
                                        }
                                        ;

cast_expression                         : unary_expression
                                        {
                                            $<expr>$ = $<expr>1;
                                        }
                                        | '(' type_name ')' cast_expression
                                        {
                                            size_t len = strlen($<str>2);
                                            char*  str = (char*)malloc(len + 3);

                                            sprintf(str, "(%s)", $<str>2);
                                            Expression *expr = new Expression(g_line, str);
                                            $<expr>$ = expr;
                                        }
                                        ;

unary_expression                        : postfix_expression
                                        {
                                            $<expr>$ = $<expr>1;
                                        }
                                        | PP unary_expression
                                        {
                                            Expression* expr = new Expression(g_line, $<str>1);
                                            expr->pushSibling($<expr>2);
                                            $<expr>$ = expr;
                                        }
                                        | MM unary_expression
                                        {
                                            Expression* expr = new Expression(g_line, $<str>1);
                                            expr->pushSibling($<expr>2);
                                            $<expr>$ = expr;
                                        }
                                        | unary_operator cast_expression
                                        {
                                            Expression* expr = new Expression(g_line, $<str>1);
                                            expr->pushSibling($<expr>2);
                                            $<expr>$ = expr;
                                        }
                                        | SIZEOF unary_expression
                                        {
                                            Expression* expr = new Expression(g_line, $<str>1);
                                            expr->pushSibling($<expr>2);
                                            $<expr>$ = expr;
                                        }
                                        | SIZEOF '(' type_name ')' 
                                        {
                                            size_t len = strlen($<str>3);
                                            char*  str = (char*)malloc(len + 32);
                                            sprintf(str, "(%s)", $<str>3);
                                            Expression* expr1 = new Expression(g_line, "sizeof");
                                            Expression* expr2 = new Expression(g_line, str);
                                            expr1->pushSibling(expr2);
                                            $<expr>$ = expr1;
                                        }
                                        ;

unary_operator                          : '&'
                                        {
                                            $<str>$ = $<str>1;
                                        }
                                        | '*'
                                        {
                                            $<str>$ = $<str>1;
                                        }
                                        | '+'
                                        {
                                            $<str>$ = $<str>1;
                                        }
                                        | '-'
                                        {
                                            $<str>$ = $<str>1;
                                        }
                                        | '~'
                                        {
                                            $<str>$ = $<str>1;
                                        }
                                        | '!'
                                        {
                                            $<str>$ = $<str>1;
                                        }
                                        ;

postfix_expression                      : primary_expression
                                        {
                                            $<expr>$ = $<expr>1;
                                        }
                                        | postfix_expression '[' expression ']'
                                        {
                                            Expression* expr1 = new Expression(g_line, "[");
                                            Expression* expr2 = new Expression(g_line, "]");
                                            Expression* base  = $<expr>1;
                                            base->pushSibling(expr1);
                                            base->pushSibling($<expr>3);
                                            base->pushSibling(expr2);
                                            $<expr>$ = base;
                                        }
                                        | postfix_expression '('                            ')'
                                        {
                                            Expression* expr1 = new Expression(g_line, "(");
                                            Expression* expr2 = new Expression(g_line, ")");
                                            Expression* base  = $<expr>1;
                                            base->pushSibling(expr1);
                                            base->pushSibling(expr2);
                                            $<expr>$ = base;
                                        }
                                        | postfix_expression '(' assignment_expression_list ')'
                                        {
                                            Expression* expr1 = new Expression(g_line, "(");
                                            Expression* expr2 = new Expression(g_line, ")");
                                            Expression* base  = $<expr>1;
                                            base->pushSibling(expr1);
                                            base->pushSibling($<expr>3);
                                            base->pushSibling(expr2);
                                            $<expr>$ = base;
                                        }
                                        | postfix_expression DOT   identifier
                                        {
                                            Expression* expr1 = new Expression(g_line, $<str>2);
                                            Expression* expr2 = new Expression(g_line, $<str>3);
                                            Expression* base = $<expr>1;
                                            base->pushSibling(expr1);
                                            base->pushSibling(expr2);
                                            $<expr>$ = base;
                                        }
                                        | postfix_expression ARROW identifier
                                        {
                                            Expression* expr1 = new Expression(g_line, $<str>2);
                                            Expression* expr2 = new Expression(g_line, $<str>3);
                                            Expression* base = $<expr>1;
                                            base->pushSibling(expr1);
                                            base->pushSibling(expr2);
                                            $<expr>$ = base;
                                        }
                                        | postfix_expression PP
                                        {
                                            Expression* expr = new Expression(g_line, $<str>2);
                                            Expression* base = $<expr>1;
                                            base->pushSibling(expr);
                                            $<expr>$ = base;
                                        }
                                        | postfix_expression MM
                                        {
                                            Expression* expr = new Expression(g_line, $<str>2);
                                            Expression* base = $<expr>1;
                                            base->pushSibling(expr);
                                            $<expr>$ = base;
                                        }
                                        ;

primary_expression                      : identifier
                                        {
                                            Expression *expr = new Expression(g_line, $<str>1);
                                            $<expr>$ = expr;
                                        }
                                        | constant
                                        {
                                            Expression *expr = new Expression(g_line, $<str>1);
                                            $<expr>$ = expr;
                                        }
                                        | string
                                        {
                                            Expression* expr = new Expression(g_line, $<str>1);
                                            $<expr>$ = expr;
                                        }
                                        | '(' expression ')'
                                        {
                                            Expression* base = new Expression(g_line, "(");
                                            Expression* expr = new Expression(g_line, ")");
                                            base->pushSibling($<expr>2);
                                            base->pushSibling(expr);
                                            $<expr>$ = base;
                                        }
                                        ;

constant                                : integer_constant
                                        {
                                            $<str>$ = $<str>1;
                                        }
                                        | character_constant
                                        {
                                            $<str>$ = $<str>1;
                                        }
                                        | floating_constant
                                        {
                                            $<str>$ = $<str>1;
                                        }
                                        ;

/* 
    列挙型による定数は識別子になるのでここではidentifierとする
    列挙型のテーブルとか作って比較とかはまた別途
emuration_constant                      : 
                                        ;
 */



expression                              : assignment_expression
                                        {
                                            $<expr>$ = $<expr>1; 
                                        }
                                        | expression ',' assignment_expression
                                        {
                                            Expression* expr = new Expression(g_line, $<str>3);
                                            Expression* base = $<expr>1;
                                            base->pushSibling(expr);
                                            $<expr>$ = base;
                                        }
                                        ;

assignment_expression_list              : assignment_expression
                                        {
                                            $<expr>$ = $<expr>1;
                                        }
                                        | assignment_expression_list ',' assignment_expression
                                        {
                                            Expression* base = $<expr>1;
                                            base->pushSibling($<expr>3);
                                            $<expr>$ = base;
                                        }
                                        ;

assignment_expression                   : conditional_expression
                                        {
                                            $<expr>$ = $<expr>1;
                                        }
                                        | unary_expression assignment_operator assignment_expression
                                        {
                                            /* operatorを考慮しだすと複雑になるのでexpressionに含める */
                                            Expression* expr = new Expression(g_line, $<str>2);
                                            Expression* base = $<expr>1;
                                            base->pushSibling(expr);
                                            base->pushSibling($<expr>3);
                                            $<expr>$ = base;
                                        }
                                        ;

assignment_operator                     : assignment_operator_keywords
                                        {
                                            $<str>$ = $<str>1;
                                        }
                                        | '='
                                        {
                                            $<str>$ = $<str>1;
                                        }
                                        ;

%%

