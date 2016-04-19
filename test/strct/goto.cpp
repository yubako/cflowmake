
#include "gtest/gtest.h"
#include "pars/cytypes.h"
#include "pars/cyparse.h"

#include <stdio.h>


extern int yydebug;
TEST(goto, GotoStatement)
{
    const char* path = "loadsrcs/goto.c";
    EXPECT_EQ( 0 ,cflowSrcParse(path));
}

