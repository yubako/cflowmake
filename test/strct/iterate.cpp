
#include "gtest/gtest.h"
#include "pars/cytypes.h"
#include "pars/cyparse.h"

#include <stdio.h>


extern int yydebug;
TEST(iterate, WhileStatement)
{
    const char* path = "loadsrcs/iterate.c";
    EXPECT_EQ( 0 ,cflowSrcParse(path));
}

TEST(iterate, DoStatement)
{
    const char* path = "loadsrcs/dostmt.c";
    EXPECT_EQ( 0 ,cflowSrcParse(path));
}

TEST(iterate, ForStatement)
{
    const char* path = "loadsrcs/for.c";
    EXPECT_EQ( 0 ,cflowSrcParse(path));
}


