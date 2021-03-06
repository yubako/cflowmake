
#include <iostream>
#include <fstream>
//#include <FlexLexer.h>

#include "pars/cyparse.h"
#include "pars/cytypes.h"

extern int yyparse();
extern int yyrestart(FILE* fp);

TranslationUnit *tunit;

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

int cflowSrcParse(const char* cSourceFile)
{
    int   isFault;
    FILE* fp = fopen(cSourceFile, "r");
    if ( NULL == fp ) 
    {
        return -2;
    }

    // c.y使用TranslationUnit
    tunit  = TranslationUnit::factory(cSourceFile);
    isFault = cparse(fp);
    fclose(fp);

    return isFault;
}

int cflowStdinParse()
{
    return cparse(stdin);
}

