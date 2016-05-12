
#include <getopt.h>
#include <stdio.h>

#include "cflowcase.h"
#include "vst/CyFlowVisitor.h"
#include "vst/CyComplexityVisitor.h"

struct ArgOption
{
    const char*  odir;
    unsigned int complexity;
};
struct ArgOption option;

int argoptions(int argc, char** argv)
{
    int opt;
    int ind = 1;

    memset(&option, 0, sizeof(option));
    option.odir = "./";

    while ( (opt = getopt(argc, argv, "o:c")) != -1 )
    {
        switch(opt)
        {
            case 'o': option.odir = argv[++ind]; break;
            case 'c': option.complexity = 1;
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
        /* ソース解析 */
        printf("argv[%d] = %s\n", opt, argv[opt]);
        if ( cflowSrcParse(argv[opt]) == 0 ) 
        {
            TranslationUnit* unit = TranslationUnit::getInstance();

            if ( option.complexity )
            {
                /* 複雑殿計算 */
                CyComplexityVisitor* visitor = new CyComplexityVisitor();
                unit->accept(visitor);
                delete visitor;
            }
            else
            {
                /* Flow作成 */
                CyFlowVisitor* visitor = new CyFlowVisitor();
                unit->accept(visitor);
                visitor->save(option.odir);
                delete visitor;
            }
        }
        else
        {
            fprintf(stderr, "Error. %s\n", argv[opt]);
        }

        TranslationUnit::getInstance()->deleteInstance();
    }
    return 0;
}

