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
    storage_class_specifier = 258,
    type_specifier_keywords = 259,
    type_qualifier_keywords = 260,
    struct_or_union = 261,
    assignment_operator_keywords = 262,
    ENUM = 263,
    IF = 264,
    ELSE = 265,
    SWITCH = 266,
    DO = 267,
    FOR = 268,
    CASE = 269,
    WHILE = 270,
    GOTO = 271,
    CONTINUE = 272,
    BREAK = 273,
    RETURN = 274,
    DEFAULT = 275,
    SIZEOF = 276,
    DOTS = 277,
    DOT = 278,
    GT = 279,
    LT = 280,
    GE = 281,
    LE = 282,
    PP = 283,
    MM = 284,
    ARROW = 285,
    OR = 286,
    AND = 287,
    EQUAL = 288,
    NOTEQUAL = 289,
    LSHIFT = 290,
    RSHIFT = 291,
    string = 292,
    identifier = 293,
    integer_constant = 294,
    character_constant = 295,
    floating_constant = 296
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 27 "c.y" /* yacc.c:1909  */

    char* str;
    SourceLocation*  sloc;
    Statement*       stmt;
    Expression*      expr;
    Declaration*     decl;
    TranslationUnit* tunt;

#line 105 ".yaccwork/cy.hpp" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_YACCWORK_CY_HPP_INCLUDED  */
