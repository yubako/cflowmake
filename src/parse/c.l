%{

#include "cy.h"
#include <stdio.h>

unsigned int g_line = 1;

%}

%x cpp_comment c_comment

letters ([a-zA-Z_]+)
digits  ([0-9]+)

%%

"/*"             { BEGIN c_comment;              }
"*/"             { BEGIN 0;                      }
"//"             { BEGIN cpp_comment;            }
<cpp_comment>\n  { g_line ++; BEGIN 0;           }
<cpp_comment>.   { /* ignore; */                 }
<c_comment>.     { /* ignore; */                 }
"\n"             { g_line++ ;                    }
[ \t]+           { /* ignore spaces */           }

%{
/*
 * keywords
 */
%}

auto        |
register    |
static      |
extern      |
typedef     { return storage_class_specifier; }

void        |
char        |
short       |
int         |
long        |
float       |
double      |
signed      |
unsigned    { return type_specifier_keywords; }


const       |
volatile    { return type_qualifier_keywords; }

struct      |
union       { return struct_or_union; }

enum        { return ENUM;      }
if          { return IF;        }
else        { return ELSE;      }
switch      { return SWITCH;    }
do          { return DO;        }
for         { return FOR;       }
case        { return CASE;      }
while       { return WHILE;     }
goto        { return GOTO;      }
continue    { return CONTINUE;  }
break       { return BREAK;     }
return      { return RETURN;    }
default     { return DEFAULT;   }
sizeof      { return SIZEOF;    }
"..."       { return DOTS;      }

"="         |
"*="        |
"/="        |
"%="        |
"+="        |
"-="        |
"<<="       |
">>="       |
"&="        |
"^="        |
"|="        { return assignment_operator; }

"<"         { return GT; }
">"         { return LT; }
"<="        { return GE; }
">="        { return LE; }

"<<"        { return LSHIFT; }
">>"        { return RSHIFT; }

"++"        { return PP; }
"--"        { return MM; }
"->"        { return ARROW; }



\"[^\\\"]+\" { return string;      }

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

                                    /*
                                     * シンボルテーブルを検索し、typedef宣言されたものと一致すれば
                                     * typedef_name を返却する。
                                     * それ以外はidentifierとする
                                     */
                                     printf("identifier %s\n", yytext);

                                     //return typedef_name;
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
([0-9a-fA-F]+)[uUlL]{1}       { printf("integer constants %s\n", yytext); }


. { return yytext[0]; }
%%


void yyerror(char *s)
{
    printf("error line = %u %s %s\n", g_line, yytext, s);
}

