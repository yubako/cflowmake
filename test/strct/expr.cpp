
#include "gtest/gtest.h"
#include "pars/cytypes.h"
#include "pars/cyparse.h"

#include <stdio.h>


extern int yydebug;
TEST(expression, IfStatement)
{
    const char* path = "loadsrcs/ifstmt.c";
    EXPECT_EQ( 0 ,cflowSrcParse(path));
}

