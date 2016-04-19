
#include "gtest/gtest.h"
#include "pars/cytypes.h"
#include "pars/cyparse.h"

#include <stdio.h>

extern int yydebug;
TEST(switch, SwtStatement)
{
    const char* path = "loadsrcs/swtstmt.c";
    EXPECT_EQ( 0 ,cflowSrcParse(path));
}

TEST(switch, SwtStatement2)
{
    const char* path = "loadsrcs/swtstmt2.c";
    EXPECT_EQ( 0 ,cflowSrcParse(path));
}

