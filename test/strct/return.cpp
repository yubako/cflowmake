
#include "gtest/gtest.h"
#include "pars/cytypes.h"
#include "pars/cyparse.h"

#include <stdio.h>


extern int yydebug;
TEST(return, RtnStatement)
{
    const char* path = "loadsrcs/rtnstmt.c";
    EXPECT_EQ( 0 ,cflowSrcParse(path));
}


