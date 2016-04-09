
#include <iostream>
#include <fstream>
#include <FlexLexer.h>

#include "cyparse.h"
#include "cytypes.h"


extern int yyparse();
extern int yyrestart(FILE* fp);

static int cparse(FILE* fp)
{
    int          isFault;
    extern FILE* yyin;
    extern int   g_line;
    yyin = fp;

    yyrestart(fp);
    g_line = 1;
    isFault = yyparse();


    if ( isFault )
    {
        return -1;
    }
    return 0;
}
#if 0
static int cparse_cpp(const char* path)
{
    FlexLexer* lexer = new yyFlexLexer();
    std::ifstream in(path, std::ios::binary);
    lexer->switch_streams(&in);
    lexer->parse();
    return 0;
}
#endif

int cflowSrcParse(const char* cSourceFile)
{
    int   isFault;
    FILE* fp = fopen(cSourceFile, "r");
    if ( NULL == fp ) 
    {
        return -2;
    }

    isFault = cparse(fp);
    //isFault = cparse_cpp(cSourceFile);
    fclose(fp);

    return isFault;
}

int cflowStdinParse()
{
    return cparse(stdin);
}

