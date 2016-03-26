%{

#include <stdio.h>

%}

%token storage_class_specifier type_specifier_keywords type_qualifier_keywords struct_or_union
%token assignment_operator
%token ENUM IF ELSE SWITCH DO FOR CASE WHILE GOTO CONTINUE BREAK RETURN DEFAULT SIZEOF DOTS
%token GT LT GE LE PP MM ARROW
%token LSHIFT RSHIFT 
%token string
%token typedef_name identifier

%%


translation_unit                        : external_declaration
                                        | translation_unit external_declaration
                                        ;

external_declaration                    : function_definition
                                        ;

/* 
    関数定義 ( function_definition )

    declaration_specifier  戻り値型 
    declarator             関数宣言子
    declaration            引数指定子
    compound_statement     関数実態
*/
function_definition                     : declaration_specifier_list  declarator '(' declaration_list ')' compound_statement
                                        | declaration_specifier_list  declarator '('                  ')' compound_statement
                                        ;

declaration_specifier_list              : declaration_specifier
                                        | declaration_specifier_list declaration_specifier
                                        ;

declaration_specifier                   : storage_class_specifier
                                        | type_specifier 
                                        | type_qualifier
                                        ;

type_qualifier                          : type_qualifier_keywords
                                        ;

/*
    型指定子(voidとか)
*/

type_specifier                          : type_specifier_keywords
                                        ;


/*
    引数とか 型 + 変数名まで( declaration )
*/
declaration_list                        : declaration
                                        | declaration_list ',' declaration
                                        ;

declaration                             : declaration_specifier 
                                        | declaration_specifier init_declarator
                                        ;

/* 
    初期化指定子
*/
init_declarator                         : declarator
                                        ;



/*
    '{' '}' で閉じられたstatmenet  compound_statement
*/
compound_statement                      : '{' '}'



/*
    宣言子
*/
declarator                              : pointer identifier
                                        |         identifier
                                        ;


pointer                                 : '*'
                                        ;

/*
unary_operator                          : '&'
                                        | '*'
                                        | '+'
                                        | '-'
                                        | '~'
                                        | '!'
                                        ;
*/
%%

