
#include <getopt.h>
#include <stdio.h>

#include "cflowcase.h"
#include "vst/CyFlowVisitor.h"

struct ArgOption
{
    const char* odir;
};
struct ArgOption option;

int argoptions(int argc, char** argv)
{
    int opt;
    int ind = 1;
    option.odir = "./";

    while ( (opt = getopt(argc, argv, "o:")) != -1 )
    {
        switch(opt)
        {
            case 'o': option.odir = argv[++ind]; break;
            default: printf("Unknoun option %c\n", opt);break;
        }
        ind++;
    }
    return ind;
}




int main(int argc, char** argv)
{

    int opt = argoptions(argc, argv);
    for ( ; opt < argc; opt++ ) 
    {
        CyFlowVisitor* visitor = new CyFlowVisitor();

        /* ソース解析 */
        printf("argv[%d] = %s\n", opt, argv[opt]);
        if ( cflowSrcParse(argv[opt]) == 0 ) 
        {
            /* Flow作成 */
            TranslationUnit* unit = TranslationUnit::getInstance();
            unit->accept(visitor);
            visitor->save(option.odir);
        }
        else
        {
            printf("Error. %s\n", argv[opt]);
        }

        TranslationUnit::getInstance()->deleteInstance();
        delete visitor;
    }
    return 0;
}

