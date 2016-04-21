%{

#include "cy.hpp"
#include <string.h>
#include <stdio.h>

unsigned int g_line = 1;

%}

/* %option c++ */
%x cpp_comment c_comment

letters ([a-zA-Z_]+)
digits  ([0-9]+)
digit   ([0-9])
sign    [+-]

%%

#                { BEGIN cpp_comment;               }
"/*"             { BEGIN c_comment;                 }
<c_comment>\n    { g_line++;                        }
<c_comment>"*/"  { BEGIN 0;                         }
"//"             { BEGIN cpp_comment;               }
<cpp_comment>\n  { g_line ++; BEGIN 0;              }
<cpp_comment>.   { /* ignore; */                    }
<c_comment>.     { /* ignore; */                    }
"\n"             { 
                    g_line++ ;  
                 }
[ \t]+           { /* ignore spaces */              }

%{
/*
 * keywords
 */
%}

auto        |
register    |
static      |
extern      |
typedef     { 
                yylval.str = strdup(yytext);
                return storage_class_specifier; 
            }
 
   
function_call_stack_data |
void        |
char        |
short       |
int         |
long        |
float       |
double      |
signed      |
unsigned    |
key_t       |
Dl_info     |
size_t      |
pid_t       |
uint64_t    |
uint32_t    |
uint16_t    {


                /* sys/types.h の一部についても含めておく。typedef定義の対応が面倒... */

                yylval.str = strdup(yytext);
                return type_specifier_keywords; 
            }


const       |
volatile    { 
                yylval.str = strdup(yytext);
                return type_qualifier_keywords; 
            }


struct      |
union       { 
                yylval.str = strdup(yytext);
                return struct_or_union; 
            }

enum        { yylval.str = strdup(yytext); return ENUM;      }
if          { yylval.str = strdup(yytext); return IF;        }
else        { yylval.str = strdup(yytext); return ELSE;      }
switch      { yylval.str = strdup(yytext); return SWITCH;    }
do          { yylval.str = strdup(yytext); return DO;        }
for         { yylval.str = strdup(yytext); return FOR;       }
case        { yylval.str = strdup(yytext); return CASE;      }
while       { yylval.str = strdup(yytext); return WHILE;     }
goto        { yylval.str = strdup(yytext); return GOTO;      }
continue    { yylval.str = strdup(yytext); return CONTINUE;  }
break       { yylval.str = strdup(yytext); return BREAK;     }
return      { yylval.str = strdup(yytext); return RETURN;    }
default     { yylval.str = strdup(yytext); return DEFAULT;   }
sizeof      { yylval.str = strdup(yytext); return SIZEOF;    }
"\.\.\."    { yylval.str = strdup(yytext); return DOTS;      }

"*="        |
"/="        |
"%="        |
"+="        |
"-="        |
"<<="       |
">>="       |
"&="        |
"^="        |
"|="        { yylval.str = strdup(yytext); return assignment_operator_keywords; }
               
"<"         { yylval.str = strdup(yytext); return GT; }
">"         { yylval.str = strdup(yytext); return LT; }
"<="        { yylval.str = strdup(yytext); return GE; }
">="        { yylval.str = strdup(yytext); return LE; }
               
"<<"        { yylval.str = strdup(yytext); return LSHIFT; }
">>"        { yylval.str = strdup(yytext); return RSHIFT; }

"++"        { yylval.str = strdup(yytext); return PP; }
"--"        { yylval.str = strdup(yytext); return MM; }
"->"        { yylval.str = strdup(yytext); return ARROW; }
\.          { yylval.str = strdup(yytext); return DOT;  }

"||"        { yylval.str = strdup(yytext); return OR;  }
"&&"        { yylval.str = strdup(yytext); return AND; }
"=="        { yylval.str = strdup(yytext); return EQUAL;    }
"!="        { yylval.str = strdup(yytext); return NOTEQUAL; }


L?\"(\\.|[^\\"])*\" { yylval.str = strdup(yytext); return string;      }

%{
/*
 * Identifier
 * An identifier is a sequence of letters and digits. The first character must be a letter; the
 * underscore _ counts as a letter. Upper and lower case letters are different. Identifiers may have
 * any length, and for internal identifiers, at least the first 31 characters are significant; some
 * implementations may take more characters significant. Internal identifiers include preprocessor
 * macro names and all other names that do not have external linkage (Par.A.11.2). Identifiers
 * with external linkage are more restricted: implementations may make as few as the first six
 * characters significant, and may ignore case distinctions.
 */
%}
{letters}({letters}|{digits})*  {
                                    yylval.str = strdup(yytext);
                                    return identifier;
                                }


%{
/*
 * An integer constant consisting of a sequence of digits is taken to be octal if it begins with 0
 * (digit zero), decimal otherwise. Octal constants do not contain the digits 8 or 9. A sequence of
 * digits preceded by 0x or 0X (digit zero) is taken to be a hexadecimal integer. The hexadecimal
 * digits include a or A through f or F with values 10 through 15.
 * An integer constant may be suffixed by the letter u or U, to specify that it is unsigned. It may
 * also be suffixed by the letter l or L to specify that it is long
 */
%}

(0[xX])?([0-9a-fA-F]+)[uUlL]?  {   
                                    yylval.str = strdup(yytext); 
                                    return integer_constant; 
                               }

{digit}\.{digit}+[eE]?{sign}?{digit}+[flFL]? |
{digit}?\.{digit}                            { 
                                                yylval.str = strdup(yytext);
                                                return floating_constant; 
                                             }

\'.\'                           { 
                                    yylval.str = strdup(yytext);
                                    return character_constant; 
                                }

.                               {
                                    switch( yytext[0] )
                                    {
                                        case '{' :
                                        case '}' :
                                        default  : yylval.str = strdup(yytext);
                                    }
                                    return g_line, yytext[0]; 
                                }
%%

void yyerror(const char *s)
{
    printf("error line = %u: %s (%s)\n", g_line, yylval.str, s);
}
