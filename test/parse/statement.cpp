
#include "gtest/gtest.h"
#include "pars/cyparse.h"

#include <stdio.h>

extern int yydebug;

TEST(statement, void_func )
{
    const char* path = "loadsrcs/statement.c";
    EXPECT_EQ( 0 ,cflowSrcParse(path));
}

