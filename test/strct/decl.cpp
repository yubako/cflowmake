
#include "gtest/gtest.h"
#include "pars/cytypes.h"
#include "pars/cyparse.h"

#include <stdio.h>

extern int yydebug;
TEST(decl, Declarator)
{
    const char* path = "loadsrcs/decl.c";
    EXPECT_EQ( 0 ,cflowSrcParse(path));
}

