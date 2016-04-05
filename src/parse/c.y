%{

#include <stdio.h>

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
                                        |                        declarator declaration_list compound_statement
                                        | declaration_specifier  declarator                  compound_statement
                                        |                        declarator                  compound_statement
                                        ;

declaration                             : declaration_specifier init_declarator_list ';'
                                        | declaration_specifier                      ';'
                                        ;

declaration_list                        : declaration
                                        | declaration_list declaration
                                        ;

declaration_specifier                   : storage_class_specifier declaration_specifier
                                        | storage_class_specifier
                                        | type_specifier          declaration_specifier
                                        | type_specifier
                                        | type_qualifier          declaration_specifier
                                        | type_qualifier
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
                                        |         direct_declarator
                                        ;

direct_declarator                       : identifier 
                                        | '(' declarator ')'
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
    '{' '}' で閉じられたstatmenet  compound_statement
*/
compound_statement                      : '{' '}'
                                        ;

/*
    式
 */


/*
    定数
 */
constant_expression                     : conditional_expression
                                        ;

conditional_expression                  : logical_or_expression
                                        | logical_or_expression '?' expression ':' conditional_expression
                                        ;

logical_or_expression                   : logical_and_expression
                                        | logical_or_expression OR logical_and_expression
                                        ;

logical_and_expression                  : inclusive_or_expression
                                        | logical_and_expression AND inclusive_or_expression
                                        ;

inclusive_or_expression                 : exclusive_or_expression
                                        | inclusive_or_expression '|' exclusive_or_expression
                                        ;

exclusive_or_expression                 : and_expression
                                        | exclusive_or_expression '^' and_expression
                                        ;

and_expression                          : equality_expression
                                        | and_expression '&' equality_expression
                                        ;

equality_expression                     : relational_expression
                                        | equality_expression EQUAL    relational_expression
                                        | equality_expression NOTEQUAL relational_expression
                                        ;

relational_expression                   : shift_expression
                                        | relational_expression GT shift_expression
                                        | relational_expression LT shift_expression
                                        | relational_expression GE shift_expression
                                        | relational_expression LE shift_expression
                                        ;

shift_expression                        : additive_expression
                                        | shift_expression LSHIFT additive_expression
                                        | shift_expression RSHIFT additive_expression
                                        ;

additive_expression                     : multiplicative_expression
                                        | additive_expression '+' multiplicative_expression
                                        | additive_expression '-' multiplicative_expression
                                        ;

multiplicative_expression               : cast_expression
                                        | multiplicative_expression '*' cast_expression
                                        | multiplicative_expression '/' cast_expression
                                        | multiplicative_expression '%' cast_expression
                                        ;

cast_expression                         : unary_expression
                                        | '(' type_name ')' cast_expression
                                        ;

unary_expression                        : postfix_expression
                                        | PP unary_expression
                                        | MM unary_expression
                                        | unary_operator cast_expression
                                        | SIZEOF unary_expression
                                        | SIZEOF '(' type_name ')' 
                                        ;

unary_operator                          : '&'
                                        | '*'
                                        | '+'
                                        | '-'
                                        | '~'
                                        | '!'
                                        ;

postfix_expression                      : primary_expression
                                        | postfix_expression '[' expression ']'
                                        | postfix_expression '('                            ')'
                                        | postfix_expression '(' assignment_expression_list ')'
                                        | postfix_expression DOT   identifier
                                        | postfix_expression ARROW identifier
                                        | postfix_expression PP
                                        | postfix_expression MM
                                        ;

primary_expression                      : identifier
                                        | constant
                                        | string
                                        | '(' expression ')'
                                        ;

constant                                : integer_constant
                                        | character_constant
                                        | floating_constant
                                        ;

/* 
    列挙型による定数は識別子になるのでここではidentifierとする
    列挙型のテーブルとか作って比較とかはまた別途
emuration_constant                      : 
                                        ;
 */



expression                              : assignment_expression
                                        | expression ',' assignment_expression
                                        ;

assignment_expression_list              : assignment_expression
                                        | assignment_expression_list ',' assignment_expression
                                        ;

assignment_expression                   : conditional_expression
                                        | unary_expression assignment_operator assignment_expression
                                        ;

assignment_operator                     : assignment_operator_keywords
                                        | '='
                                        ;

%%

