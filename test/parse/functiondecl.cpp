#include "gtest/gtest.h"
#include "pars/cyparse.h"

#include <stdio.h>

extern int yydebug;
//yydebug = 1;


TEST(funcdecl, void_func )
{
    const char* path = "loadsrcs/void_func.c";
    EXPECT_EQ( 0 ,cflowSrcParse(path));
}

TEST(funcdecl, const_int_func )
{
    const char* path = "loadsrcs/const_int_func.c";
    EXPECT_EQ( 0 ,cflowSrcParse(path));
}

TEST(funcdecl, func_void_argument )
{
    const char* path = "loadsrcs/func_void_argument.c";
    EXPECT_EQ( 0 ,cflowSrcParse(path));
}

TEST(funcdecl, multi_argument )
{
    const char* path = "loadsrcs/multi_argument.c";
    EXPECT_EQ( 0 ,cflowSrcParse(path));
}

TEST(funcdecl, pointers_func )
{
    const char* path = "loadsrcs/pointers_func.c";
    EXPECT_EQ( 0 ,cflowSrcParse(path));
}

TEST(funcdecl, struct_func )
{
    const char* path = "loadsrcs/struct_func.c";
    EXPECT_EQ( 0 ,cflowSrcParse(path));
}

TEST(funcdecl, enum_func )
{
    const char* path = "loadsrcs/enum_func.c";
    EXPECT_EQ( 0 ,cflowSrcParse(path));
//   cflowStdinParse(); 
}
