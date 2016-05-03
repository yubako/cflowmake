/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

#ifndef YY_YY_YACCWORK_CY_HPP_INCLUDED
# define YY_YY_YACCWORK_CY_HPP_INCLUDED
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
    storage_class_specifier_keywords = 258,
    type_specifier_keywords = 259,
    type_qualifier_keywords = 260,
    struct_or_union = 261,
    assignment_operator_keywords = 262,
    typedef_name = 263,
    ENUM = 264,
    IF = 265,
    ELSE = 266,
    SWITCH = 267,
    DO = 268,
    FOR = 269,
    CASE = 270,
    WHILE = 271,
    GOTO = 272,
    CONTINUE = 273,
    BREAK = 274,
    RETURN = 275,
    DEFAULT = 276,
    SIZEOF = 277,
    DOTS = 278,
    DOT = 279,
    GT = 280,
    LT = 281,
    GE = 282,
    LE = 283,
    PP = 284,
    MM = 285,
    ARROW = 286,
    OR = 287,
    AND = 288,
    EQUAL = 289,
    NOTEQUAL = 290,
    LSHIFT = 291,
    RSHIFT = 292,
    string = 293,
    identifier = 294,
    integer_constant = 295,
    character_constant = 296,
    floating_constant = 297
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 28 "c.y" /* yacc.c:1909  */

    char* str;
    SourceLocation*  sloc;
    Statement*       stmt;
    Expression*      expr;
    Declaration*     decl;
    TranslationUnit* tunt;

#line 106 ".yaccwork/cy.hpp" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_YACCWORK_CY_HPP_INCLUDED  */
