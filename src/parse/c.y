%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cytypes.h"
#include "psbuff.h"

extern unsigned int g_line;
extern void yyerror(const char *s);
extern TranslationUnit* tunit;

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
    SourceLocation*  sloc;
    Statement*       stmt;
    Expression*      expr;
    Declaration*     decl;
    TranslationUnit* tunt;
}
%%

translation_unit                        : external_declaration
                                        {
                                            tunit->pushDeclaration($<decl>1);
                                            $<tunt>$ = tunit;
                                            dprintf("Translation Unit1", "%s\n", tunit->toString());
                                        }
                                        | translation_unit external_declaration
                                        {
                                            TranslationUnit* tunit = $<tunt>1;
                                            tunit->pushDeclaration($<decl>2);
                                            $<tunt>$ = tunit;
                                            dprintf("Translation Unit2", "%s\n", tunit->toString());
                                        }
                                        ;

external_declaration                    : function_definition
                                        {
                                            $<decl>$ = $<decl>1;
                                        }
                                        | declaration
                                        {
                                            $<decl>$ = $<decl>1;
                                        }
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
                                            char* funcname;
                                            Declaration* decl = $<decl>3;
                                            funcname = psbuff_realloc($<str>1,  $<str>2);
                                            funcname = psbuff_realloc(funcname, decl->toString());
                                            FunctionDefinition *fdef = new FunctionDefinition(decl->getLine(), funcname, $<stmt>4);
                                            $<decl>$ = fdef;
                                            dprintf("function def1", "%s %s %s\n", $<str>1, $<str>2, decl->toString());
                                        }
                                        |                        declarator declaration_list compound_statement
                                        {
                                            char* funcname;
                                            Declaration* decl = $<decl>2;
                                            funcname = psbuff_realloc($<str>1, decl->toString());
                                            FunctionDefinition* fdef = new FunctionDefinition(decl->getLine(), funcname, $<stmt>3);
                                            $<decl>$ = fdef;
                                            dprintf("function def2", "%s %s\n", $<str>1, decl->toString());
                                        }
                                        | declaration_specifier  declarator                  compound_statement
                                        {
                                            char* funcname;
                                            funcname = psbuff_realloc($<str>1, $<str>2);
                                            FunctionDefinition* fdef = new FunctionDefinition($<stmt>3->getLine(), funcname, $<stmt>3);
                                            $<decl>$ = fdef;
                                            dprintf("function def3", "%s %s\n", $<str>1, $<str>2);
                                        }
                                        |                        declarator                  compound_statement
                                        {
                                            // このLineだけdeclaratorを文字列で扱っている都合上断念。。。
                                            FunctionDefinition* fdef = new FunctionDefinition(g_line, $<str>1, $<stmt>2);
                                            $<decl>$ = fdef;
                                            dprintf("function def4", "%s\n", $<str>1);
                                        }
                                        ;

declaration                             : declaration_specifier init_declarator_list ';'
                                        {
                                            char* str;
                                            str = psbuff_realloc($<str>1, $<str>2);
                                            str = psbuff_realloc(str,     $<str>3);

                                            Declaration* decl = new Declaration(g_line, str);
                                            $<decl>$ = decl;
                                            //dprintf("declaration1", "%s\n", decl->toString());
                                            dprintf("declaration1", "%s, %s, %s\n", $<str>1, $<str>2, $<str>3);
                                        }
                                        | declaration_specifier                      ';'
                                        {
                                            char* str;
                                            str = psbuff_realloc($<str>1, $<str>2);

                                            Declaration* decl = new Declaration(g_line, str);
                                            $<decl>$ = decl;
                                            dprintf("declaration2", "%s\n", decl->toString());
                                        }
                                        ;

declaration_list                        : declaration
                                        {
                                            $<decl>$ = $<decl>1;
                                        }
                                        | declaration_list declaration
                                        {
                                            Declaration* base = $<decl>1;
                                            base->pushSibling($<decl>2);
                                            $<decl>$ = base;
                                        }
                                        ;

declaration_specifier                   : storage_class_specifier declaration_specifier
                                        {
                                            char* str;
                                            str = psbuff_realloc($<str>1, $<str>2);
                                            $<str>$ = str;
                                            dprintf("declaration_spec1", "%s, %s\n", $<str>1,$<str>2);
                                        }
                                        | storage_class_specifier
                                        {
                                            $<str>$ = $<str>1;
                                            dprintf("declaration_spec2", "%s\n", $<str>$);
                                        }
                                        | type_specifier          declaration_specifier
                                        {
                                            char* str;
                                            str = psbuff_realloc($<str>1, $<str>2);
                                            $<str>$ = str;
                                            dprintf("declaration_spec3", "%s\n", $<str>$);
                                        }
                                        | type_specifier
                                        {
                                            $<str>$ = $<str>1;
                                            dprintf("declaration_spec4", "%s\n", $<str>$);
                                        }
                                        | type_qualifier          declaration_specifier
                                        {
                                            char* str;
                                            str = psbuff_realloc($<str>1, $<str>2);
                                            $<str>$ = str;
                                            dprintf("declaration_spec5", "%s\n", $<str>$);
                                        }
                                        | type_qualifier
                                        {
                                            $<str>$ = $<str>1;
                                            dprintf("declaration_spec6", "%s\n", $<str>$);
                                        }
                                        ;

type_specifier                          : type_specifier_keywords
                                        {
                                            $<str>$ = $<str>1;
                                        }
                                        | struct_or_union_specifier
                                        {
                                            $<str>$ = $<str>1;
                                        }
                                        | enum_specifier
                                        {
                                            $<str>$ = $<str>1;
                                        }
/*                                      | typedef_name */
                                        ;

type_qualifier                          : type_qualifier_keywords
                                        {
                                            $<str>$ = $<str>1;
                                        }
                                        ;


/*
    構造体, 共用体定義
 */
struct_or_union_specifier               : struct_or_union identifier '{' struct_declaration_list '}'
                                        {
                                            char* str;
                                            str = psbuff_realloc($<str>1, $<str>2);
                                            str = psbuff_realloc(str,     $<str>3);
                                            str = psbuff_realloc(str,     $<str>4);
                                            str = psbuff_realloc(str,     $<str>5);
                                            $<str>$ = str;
                                        }
                                        | struct_or_union            '{' struct_declaration_list '}'
                                        {
                                            char* str;
                                            str = psbuff_realloc($<str>1, $<str>2);
                                            str = psbuff_realloc(str,     $<str>3);
                                            str = psbuff_realloc(str,     $<str>4);
                                            $<str>$ = str;
                                        }
                                        | struct_or_union identifier
                                        {
                                            char* str;
                                            str = psbuff_realloc($<str>1, $<str>2);
                                            $<str>$ = str;
                                        }
                                        ;

struct_declaration_list                 : struct_declaration
                                        {
                                            $<str>$ = $<str>1;
                                        }
                                        | struct_declaration_list struct_declaration
                                        {
                                            char* str;
                                            str = psbuff_realloc($<str>1, $<str>2);
                                            $<str>$ = str;
                                        }
                                        ;

/* 
    初期化指定子
*/

init_declarator_list                    : init_declarator
                                        {
                                            $<str>$ = $<str>1;
                                        }
                                        | init_declarator_list ',' init_declarator
                                        {
                                            char* str;
                                            str = psbuff_realloc($<str>1, $<str>2);
                                            str = psbuff_realloc(str,     $<str>3);
                                            $<str>$ = str;
                                        }
                                        ;

init_declarator                         : declarator
                                        {
                                            $<str>$ = $<str>1;
                                        }
                                        | declarator '=' initializer
                                        {
                                            char* str;
                                            str = psbuff_realloc($<str>1, $<str>2);
                                            str = psbuff_realloc(str,     $<str>3);
                                            $<str>$ = str;
                                        }
                                        ;

struct_declaration                      : specifier_qualifier_list struct_declarator_list ';'
                                        {
                                            char* str;
                                            str = psbuff_realloc($<str>1, $<str>2);
                                            str = psbuff_realloc(str,     $<str>3);
                                            $<str>$ = str;
                                        }
                                        ;

specifier_qualifier_list                : type_specifier specifier_qualifier_list
                                        {
                                            char* str;
                                            str = psbuff_realloc($<str>1, $<str>2);
                                            $<str>$ = str;
                                        }
                                        | type_specifier
                                        {
                                            $<str>$ = $<str>1;
                                        }
                                        | type_qualifier specifier_qualifier_list
                                        {
                                            char* str;
                                            str = psbuff_realloc($<str>1, $<str>2);
                                            $<str>$ = str;
                                        }
                                        | type_qualifier
                                        {
                                            $<str>$ = $<str>1;
                                        }
                                        ;

struct_declarator_list                  : struct_declarator
                                        {
                                            $<str>$ = $<str>1;
                                        }
                                        | struct_declarator_list ',' struct_declarator
                                        {
                                            char* str;
                                            str = psbuff_realloc($<str>1, $<str>2);
                                            str = psbuff_realloc(str,     $<str>3);
                                            $<str>$ = str;
                                        }
                                        ;

struct_declarator                       : declarator
                                        {
                                            $<str>$ = $<str>1;
                                        }
                                        | declarator ':' constant_expression
                                        {
                                            char* str;
                                            str = psbuff_realloc($<str>1, $<str>2);
                                            str = psbuff_realloc(str,     $<str>3);
                                            $<str>$ = str;
                                        }
                                        |            ':' constant_expression
                                        {
                                            char* str;
                                            str = psbuff_realloc($<str>1, $<str>2);
                                            $<str>$ = str;
                                        }
                                        ;

/*
    列挙型定義
 */
enum_specifier                          : ENUM identifier '{' enumerator_list '}'
                                        {
                                            char* str;
                                            str = psbuff_realloc($<str>1, $<str>2);
                                            str = psbuff_realloc(str,     $<str>3);
                                            str = psbuff_realloc(str,     $<str>4);
                                            str = psbuff_realloc(str,     $<str>5);
                                            $<str>$ = str;
                                        }
                                        | ENUM            '{' enumerator_list '}'
                                        {
                                            char* str;
                                            str = psbuff_realloc($<str>1, $<str>2);
                                            str = psbuff_realloc(str,     $<str>3);
                                            str = psbuff_realloc(str,     $<str>4);
                                            $<str>$ = str;
                                        }
                                        | ENUM identifier
                                        {
                                            char* str;
                                            str = psbuff_realloc($<str>1, $<str>2);
                                            $<str>$ = str;
                                        }
                                        ;

enumerator_list                         :                     enumerator
                                        {
                                            $<str>$ = $<str>1;
                                        }
                                        | enumerator_list ',' enumerator
                                        {
                                            char* str;
                                            str = psbuff_realloc($<str>1, $<str>2);
                                            str = psbuff_realloc(str,     $<str>3);
                                            $<str>$ = str;
                                        }
                                        ;

enumerator                              : identifier
                                        {
                                            $<str>$ = $<str>1;
                                        }
                                        | identifier '=' constant_expression
                                        {
                                            char* str;
                                            str = psbuff_realloc($<str>1, $<str>2);
                                            str = psbuff_realloc(str,     $<str>3);
                                            $<str>$ = str;
                                        }
                                        ;
/*
    宣言子
*/
declarator                              : pointer direct_declarator
                                        {
                                            $<str>$ = psbuff_realloc($<str>1, $<str>2);
                                        }
                                        |         direct_declarator
                                        {
                                            $<str>$ = $<str>1;
                                        }
                                        ;

direct_declarator                       : identifier 
                                        {
                                            $<str>$ = $<str>1;
                                        }
                                        | '(' declarator ')'
                                        {
                                            char* str;
                                            str = psbuff_realloc($<str>1, $<str>2);
                                            str = psbuff_realloc(str,     $<str>3);
                                            $<str>$ = str;
                                        }
                                        | direct_declarator '[' constant_expression']'
                                        {
                                            char* str;
                                            str = psbuff_realloc($<str>1, $<str>2);
                                            str = psbuff_realloc(str,     $<str>3);
                                            str = psbuff_realloc(str,     $<str>4);
                                            $<str>$ = str;
                                        }
                                        | direct_declarator '['                    ']'
                                        {
                                            char* str;
                                            str = psbuff_realloc($<str>1, $<str>2);
                                            str = psbuff_realloc(str,     $<str>3);
                                            $<str>$ = str;
                                        }
                                        | direct_declarator '(' parameter_type_list ')'
                                        {
                                            char* str;
                                            str = psbuff_realloc($<str>1, $<str>2);
                                            str = psbuff_realloc(str,     $<str>3);
                                            str = psbuff_realloc(str,     $<str>4);
                                            $<str>$ = str;
                                        }
                                        | direct_declarator '(' identifier_list     ')'
                                        {
                                            char* str;
                                            str = psbuff_realloc($<str>1, $<str>2);
                                            str = psbuff_realloc(str,     $<str>3);
                                            str = psbuff_realloc(str,     $<str>4);
                                            $<str>$ = str;
                                        }
                                        | direct_declarator '('                     ')'
                                        {
                                            char* str;
                                            str = psbuff_realloc($<str>1, $<str>2);
                                            str = psbuff_realloc(str,     $<str>3);
                                            $<str>$ = str;
                                        }
                                        ;

pointer                                 : '*' type_qualifier_list
                                        {
                                            char* str;
                                            str = psbuff_realloc($<str>1, $<str>2);
                                            $<str>$ = str;
                                        }
                                        | '*' 
                                        {
                                            $<str>$ = $<str>1;
                                        }
                                        | '*' type_qualifier_list pointer
                                        {
                                            char* str;
                                            str = psbuff_realloc($<str>1, $<str>2);
                                            str = psbuff_realloc(str,     $<str>3);
                                            $<str>$ = str;
                                        }
                                        | '*'                     pointer
                                        {
                                            char* str;
                                            str = psbuff_realloc($<str>1, $<str>2);
                                            $<str>$ = str;
                                        }
                                        ;

type_qualifier_list                     :                     type_qualifier
                                        {
                                            $<str>$ = $<str>1;
                                            dprintf("type_qualifier", "%s\n", $<str>$);
                                        }
                                        | type_qualifier_list type_qualifier
                                        {
                                            char* str;
                                            str = psbuff_realloc($<str>1, $<str>2);
                                            $<str>$ = str;
                                            dprintf("type_qualifier", "%s\n", $<str>$);
                                        }
                                        ;

parameter_type_list                     : parameter_list
                                        {
                                            $<str>$ = $<str>1;
                                        }
                                        | parameter_list ',' DOTS
                                        {
                                            char* str;
                                            str = psbuff_realloc($<str>1, $<str>2);
                                            str = psbuff_realloc(str,     $<str>3);
                                            $<str>$ = str;
                                        }
                                        ;

parameter_list                          :                    parameter_declaration
                                        {
                                            $<str>$ = $<str>1;
                                        }
                                        | parameter_list ',' parameter_declaration
                                        {
                                            char* str;
                                            str = psbuff_realloc($<str>1, $<str>2);
                                            str = psbuff_realloc(str,     $<str>3);
                                            $<str>$ = str;
                                        }
                                        ;

parameter_declaration                   : declaration_specifier declarator
                                        {
                                            char* str;
                                            str = psbuff_realloc($<str>1, $<str>2);
                                            $<str>$ = str;
                                        }
                                        | declaration_specifier abstract_declarator
                                        {
                                            char* str;
                                            str = psbuff_realloc($<str>1, $<str>2);
                                            $<str>$ = str;
                                        }
                                        | declaration_specifier
                                        {
                                            $<str>$ = $<str>1;
                                        }
                                        ;

identifier_list                         : identifier
                                        {
                                            $<str>$ = $<str>1;
                                        }
                                        | identifier_list ',' identifier
                                        {
                                            char* str;
                                            str = psbuff_realloc($<str>1, $<str>2);
                                            str = psbuff_realloc(str,     $<str>3);
                                            $<str>$ = str;
                                        }
                                        ;

initializer                             : assignment_expression
                                        {
                                            /* 初期化子は文字列扱いにする。 */
                                            Expression* expr = $<expr>1;
                                            $<str>$ = (char*)expr->toString();
                                        }
                                        | '{' initializer_list '}'
                                        {
                                            char* str;
                                            str = psbuff_realloc($<str>1, $<str>2);
                                            str = psbuff_realloc(str,     $<str>3);
                                            $<str>$ = str;
                                        }
                                        | '{' initializer_list ',' '}'
                                        {
                                            char* str;
                                            str = psbuff_realloc($<str>1, $<str>2);
                                            str = psbuff_realloc(str,     $<str>3);
                                            str = psbuff_realloc(str,     $<str>4);
                                            $<str>$ = str;
                                        }
                                        ;

initializer_list                        : initializer
                                        {
                                            $<str>$ = $<str>1;
                                        }
                                        | initializer_list ',' initializer
                                        {
                                            char* str;
                                            str = psbuff_realloc($<str>1, $<str>2);
                                            str = psbuff_realloc(str,     $<str>3);
                                            $<str>$ = str;
                                        }
                                        ;

type_name                               : specifier_qualifier_list abstract_declarator
                                        {
                                            char* str;
                                            str = psbuff_realloc($<str>1, $<str>2);
                                            $<str>$ = str;
                                        }
                                        | specifier_qualifier_list
                                        {
                                            $<str>$ = $<str>1;
                                        }
                                        ;

abstract_declarator                     : pointer
                                        {
                                            $<str>$ = $<str>1;
                                        }
                                        | pointer direct_abstract_declarator
                                        {
                                            char* str;
                                            str = psbuff_realloc($<str>1, $<str>2);
                                            $<str>$ = str;
                                        }
                                        |         direct_abstract_declarator
                                        {
                                            $<str>$ = $<str>1;
                                        }
                                        ;

direct_abstract_declarator              : '(' abstract_declarator ')'
                                        {
                                            char* str;
                                            str = psbuff_realloc($<str>1, $<str>2);
                                            str = psbuff_realloc(str,     $<str>3);
                                            $<str>$ = str;
                                        }
                                        | direct_abstract_declarator '[' constant_expression ']'
                                        {
                                            char* str;
                                            str = psbuff_realloc($<str>1, $<str>2);
                                            str = psbuff_realloc(str,     $<str>3);
                                            str = psbuff_realloc(str,     $<str>4);
                                            $<str>$ = str;
                                        }
                                        |                            '[' constant_expression ']'
                                        {
                                            char* str;
                                            str = psbuff_realloc($<str>1, $<str>2);
                                            str = psbuff_realloc(str,     $<str>3);
                                            $<str>$ = str;
                                        }
                                        | direct_abstract_declarator '['                     ']'
                                        {
                                            char* str;
                                            str = psbuff_realloc($<str>1, $<str>2);
                                            str = psbuff_realloc(str,     $<str>3);
                                            $<str>$ = str;
                                        }
                                        |                            '['                     ']'
                                        {
                                            char* str;
                                            str = psbuff_realloc($<str>1, $<str>2);
                                            $<str>$ = str;
                                        }
                                        | direct_abstract_declarator '(' parameter_type_list ')'
                                        {
                                            char* str;
                                            str = psbuff_realloc($<str>1, $<str>2);
                                            str = psbuff_realloc(str,     $<str>3);
                                            str = psbuff_realloc(str,     $<str>4);
                                            $<str>$ = str;
                                        }
                                        |                            '(' parameter_type_list ')'
                                        {
                                            char* str;
                                            str = psbuff_realloc($<str>1, $<str>2);
                                            str = psbuff_realloc(str,     $<str>3);
                                            $<str>$ = str;
                                        }
                                        | direct_abstract_declarator '('                     ')'
                                        {
                                            $<str>$ = psbuff_realloc($<str>1, "()");
                                        }
                                        |                            '('                     ')'
                                        {
                                            char* str;
                                            str = psbuff_realloc($<str>1, $<str>2);
                                            $<str>$ = str;
                                        }
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
                                        {
                                            LabeledStatement* lstmt = new LabeledStatement(g_line, $<str>1, $<stmt>3);
                                            $<stmt>$ = lstmt;
                                            dprintf("LabeledStatement", "%s--\n", lstmt->toString()); 
                                        }
                                        | CASE constant_expression ':' statement
                                        {
                                            CaseStatement* cstmt = new CaseStatement(g_line, $<expr>2, $<stmt>4);
                                            $<stmt>$ = cstmt;
                                            dprintf("LabeledStatement Case", "%s\n", cstmt->toString());
                                        }
                                        | DEFAULT ':' statement
                                        {
                                            DefaultStatement* dstmt = new DefaultStatement(g_line, $<stmt>3);
                                            $<stmt>$ = dstmt;
                                            dprintf("LabeledStatement Default", "%s\n", dstmt->toString());
                                        }
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
                                            IfStatement* ifstmt = new IfStatement($<expr>3->getLine(), $<expr>3);
                                            ifstmt->setTrue($<stmt>5);
                                            $<stmt>$ = ifstmt;
                                            dprintf("IfStatement", "%s\n", ifstmt->toString());
                                        }
                                        | IF '(' expression ')' statement ELSE statement
                                        {
                                            IfStatement* ifstmt = new IfStatement($<expr>3->getLine(), $<expr>3);
                                            ifstmt->setTrue($<stmt>5);
                                            ifstmt->setElse($<stmt>7); $<stmt>$ = ifstmt;
                                            dprintf("IfStatement", "%s\n", ifstmt->toString());
                                        }
                                        | SWITCH '(' expression ')' statement
                                        {
                                            SwtStatement* swt = new SwtStatement($<expr>3->getLine(), $<expr>3, $<stmt>5);
                                            $<stmt>$ = swt;
                                            dprintf("SwitchStatement", "%s\n", swt->toString());
                                        }
                                        ;

iteration_statement                     : WHILE '(' expression ')' statement
                                        {
                                            WhileStatement* wstmt = new WhileStatement($<expr>3->getLine(), $<expr>3, $<stmt>5);
                                            $<stmt>$ = wstmt;
                                            dprintf("WhileStatement", "%s\n", wstmt->toString());

                                        }
                                        | DO statement WHILE '(' expression ')' ';'
                                        {
                                            DoStatement* dstmt = new DoStatement($<expr>5->getLine(), $<stmt>2, $<expr>5);
                                            $<stmt>$ = dstmt;
                                            dprintf("DoStatement", "%s\n", dstmt->toString());
                                        }
                                        | FOR '(' expression ';' expression ';' expression ')' statement
                                        {
                                            ForStatement *fstmt = new ForStatement(
                                                                    $<expr>3->getLine(), 
                                                                    $<expr>3,
                                                                    $<expr>5,
                                                                    $<expr>7,
                                                                    $<stmt>9);
                                            $<stmt>$ = fstmt;
                                            dprintf("ForStatement1", "%s\n", fstmt->toString());
                                        }
                                        | FOR '(' expression ';' expression ';'            ')' statement
                                        {
                                            ForStatement *fstmt = new ForStatement(
                                                                    $<expr>3->getLine(),
                                                                    $<expr>3,
                                                                    $<expr>5,
                                                                    new NullExpression(),
                                                                    $<stmt>8);
                                            $<stmt>$ = fstmt;
                                            dprintf("ForStatement2", "%s\n", fstmt->toString());
                                        }
                                        | FOR '(' expression ';'            ';' expression ')' statement
                                        {
                                            ForStatement *fstmt = new ForStatement(
                                                                    $<expr>3->getLine(),
                                                                    $<expr>3,
                                                                    new NullExpression(),
                                                                    $<expr>6,
                                                                    $<stmt>8);
                                            $<stmt>$ = fstmt;
                                            dprintf("ForStatement3", "%s\n", fstmt->toString());
                                        }
                                        | FOR '(' expression ';'            ';'            ')' statement
                                        {
                                            ForStatement *fstmt = new ForStatement(
                                                                    $<expr>3->getLine(),
                                                                    $<expr>3,
                                                                    new NullExpression(),
                                                                    new NullExpression(),
                                                                    $<stmt>7);
                                            $<stmt>$ = fstmt;
                                            dprintf("ForStatement4", "%s\n", fstmt->toString());
                                        }
                                        | FOR '('            ';' expression ';' expression ')' statement
                                        {
                                            ForStatement *fstmt = new ForStatement(
                                                                    $<expr>4->getLine(),
                                                                    new NullExpression(),
                                                                    $<expr>4,
                                                                    $<expr>6,
                                                                    $<stmt>8);
                                            $<stmt>$ = fstmt;
                                            dprintf("ForStatement5", "%s\n", fstmt->toString());
                                        }
                                        | FOR '('            ';' expression ';'            ')' statement
                                        {
                                            ForStatement *fstmt = new ForStatement(
                                                                    $<expr>4->getLine(),
                                                                    new NullExpression(),
                                                                    $<expr>4,
                                                                    new NullExpression(),
                                                                    $<stmt>7);
                                            $<stmt>$ = fstmt;
                                            dprintf("ForStatement6", "%s\n", fstmt->toString());
                                        }
                                        | FOR '('            ';'            ';' expression ')' statement
                                        {
                                            ForStatement *fstmt = new ForStatement(
                                                                    $<expr>5->getLine(),
                                                                    new NullExpression(),
                                                                    new NullExpression(),
                                                                    $<expr>5,
                                                                    $<stmt>7);
                                            $<stmt>$ = fstmt;
                                            dprintf("ForStatement7", "%s\n", fstmt->toString());
                                        }
                                        | FOR '('            ';'            ';'            ')' statement
                                        {
                                            ForStatement *fstmt = new ForStatement(
                                                                    g_line, 
                                                                    new NullExpression(),
                                                                    new NullExpression(),
                                                                    new NullExpression(),
                                                                    $<stmt>6);
                                            $<stmt>$ = fstmt;
                                            dprintf("ForStatement8", "%s\n", fstmt->toString());
                                        }
                                        ;

jump_statement                          : GOTO identifier ';'
                                        {
                                            GotoStatement* gtstmt = new GotoStatement(g_line, $<str>2);
                                            $<stmt>$ = gtstmt;
                                            dprintf("GotoStatement", "%s\n", gtstmt->toString());
                                        }
                                        | CONTINUE ';'
                                        {
                                            ContinueStatement* cstmt = new ContinueStatement(g_line);
                                            $<stmt>$ = cstmt;
                                            dprintf("Continue Statement", "%s\n", cstmt->toString());
                                        }
                                        | BREAK    ';'
                                        {
                                            BreakStatement* bstmt = new BreakStatement(g_line);
                                            $<stmt>$ = bstmt;
                                            dprintf("Break Statement", "%s\n", bstmt->toString());
                                        }
                                        | RETURN expression ';'
                                        {
                                            ReturnStatement* rstmt = new ReturnStatement(g_line);
                                            rstmt->setExpression($<expr>2);
                                            $<stmt>$ = rstmt;
                                            dprintf("Return Statement", "%s\n", rstmt->toString());
                                        }
                                        | RETURN            ';'
                                        {
                                            ReturnStatement* rstmt = new ReturnStatement(g_line);
                                            $<stmt>$ = rstmt;
                                            dprintf("Return Statement", "%s\n", rstmt->toString());
                                        }
                                        ;

/*
    '{' '}' で閉じられたstatmenet  compound_statement
*/
compound_statement                      : '{' declaration_list statement_list '}'
                                        {
                                            Statement*         stmt  = $<stmt>3;
                                            CompoundStatement* cstmt = new CompoundStatement(stmt->getLine());
                                            cstmt->pushDeclaration($<decl>2);
                                            cstmt->pushStatement(stmt);
                                            $<stmt>$ = cstmt;
                                            dprintf("Compound Statement1", "\n%s--\n", cstmt->toString());
                                        }
                                        | '{' declaration_list                '}'
                                        {
                                            CompoundStatement* cstmt = new CompoundStatement($<decl>2->getLine());
                                            cstmt->pushDeclaration($<decl>2);
                                            $<stmt>$ = cstmt;
                                            dprintf("Compound Statement2", "\n%s--\n", cstmt->toString());
                                        }
                                        | '{'                  statement_list '}'
                                        {
                                            CompoundStatement* cstmt = new CompoundStatement($<stmt>2->getLine());
                                            cstmt->pushStatement($<stmt>2);
                                            $<stmt>$ = cstmt;
                                            dprintf("Compound Statement3", "\n%s--\n", cstmt->toString());
                                        }
                                        | '{'                                 '}'
                                        {
                                            CompoundStatement* cstmt = new CompoundStatement(g_line);
                                            $<stmt>$ = cstmt;
                                            dprintf("Compound Statement4", "\n%s--\n", cstmt->toString());
                                        }
                                        ;

statement_list                          :                statement
                                        {
                                            $<stmt>$ = $<stmt>1;
                                        }
                                        | statement_list statement
                                        {
                                            Statement* base = $<stmt>1;
                                            Statement* stmt = $<stmt>2;
                                            base->pushSibling(stmt);
                                            $<stmt>$ = base;
                                        }
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
                                            dprintf("postfix expression", "%s\n", base->toString());
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
                                            dprintf("postfix expression", "%s\n", base->toString());
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
                                            dprintf("Expression1", "%s\n", $<expr>1->toString());
                                        }
                                        | expression ',' assignment_expression
                                        {
                                            /* 境界が分かるように "," もExpressionにしておく */
                                            Expression* expr1 = new Expression(g_line, ",");
                                            Expression* expr2 = $<expr>3;
                                            Expression* base = $<expr>1;
                                            base->pushSibling(expr1);
                                            base->pushSibling(expr2);
                                            $<expr>$ = base;
                                            dprintf("Expression2", "%s\n", base->toString());
                                        }
                                        ;

assignment_expression_list              : assignment_expression
                                        {
                                            $<expr>$ = $<expr>1;
                                            dprintf("Assignment Expression List1", "%s\n", $<expr>1->toString());
                                        }
                                        | assignment_expression_list ',' assignment_expression
                                        {
                                            Expression* base = $<expr>1;
                                            base->pushSibling($<expr>3);
                                            $<expr>$ = base;
                                            dprintf("Assignment Expression List2", "%s\n", base->toString());
                                        }
                                        ;

assignment_expression                   : conditional_expression
                                        {
                                            $<expr>$ = $<expr>1;
                                            dprintf("Assignment Expression1", "%s\n", $<expr>1->toString());
                                        }
                                        | unary_expression assignment_operator assignment_expression
                                        {
                                            /* operatorを考慮しだすと複雑になるのでexpressionに含める */
                                            Expression* expr = new Expression(g_line, $<str>2);
                                            Expression* base = $<expr>1;
                                            base->pushSibling(expr);
                                            base->pushSibling($<expr>3);
                                            $<expr>$ = base;
                                            dprintf("Assignment Expression2", "%s\n", base->toString());
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

