
#include "cutest.h"
#include "cyparse.h"

#include <stdio.h>

extern int yydebug;
TEST_GROUP(GlobalDecl) 
{

    void setup()
    {
        yydebug = 1;
    }

    void teardown()
    {
    }

};


TEST(GlobalDecl, void_func )
{
    const char* path = "loadsrcs/global_decl.c";
    LONGS_EQUAL( 0 ,cflowSrcParse(path));
}

