
#include "gtest/gtest.h"
#include "pars/cyparse.h"

#include <stdio.h>

extern int yydebug;
//yydebug = 1;

TEST(globaldecl, void_func )
{
    const char* path = "loadsrcs/global_decl.c";
    EXPECT_EQ( 0 ,cflowSrcParse(path));
}

