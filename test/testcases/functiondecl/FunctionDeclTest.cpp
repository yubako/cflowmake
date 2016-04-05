
#include "cutest.h"
#include "cyparse.h"

#include <stdio.h>

extern int yydebug;
TEST_GROUP(SourceLoadTest) 
{

    void setup()
    {
        yydebug = 1;
    }

    void teardown()
    {
    }

};


TEST(SourceLoadTest, void_func )
{
    const char* path = "loadsrcs/void_func.c";
    LONGS_EQUAL( 0 ,cflowSrcParse(path));
}

TEST(SourceLoadTest, const_int_func )
{
    const char* path = "loadsrcs/const_int_func.c";
    LONGS_EQUAL( 0 ,cflowSrcParse(path));
}

TEST(SourceLoadTest, func_void_argument )
{
    const char* path = "loadsrcs/func_void_argument.c";
    LONGS_EQUAL( 0 ,cflowSrcParse(path));
}

TEST(SourceLoadTest, multi_argument )
{
    const char* path = "loadsrcs/multi_argument.c";
    LONGS_EQUAL( 0 ,cflowSrcParse(path));
}

TEST(SourceLoadTest, pointers_func )
{
    const char* path = "loadsrcs/pointers_func.c";
    LONGS_EQUAL( 0 ,cflowSrcParse(path));
}

TEST(SourceLoadTest, struct_func )
{
    const char* path = "loadsrcs/struct_func.c";
    LONGS_EQUAL( 0 ,cflowSrcParse(path));
}

TEST(SourceLoadTest, enum_func )
{
    const char* path = "loadsrcs/enum_func.c";
    LONGS_EQUAL( 0 ,cflowSrcParse(path));
//   cflowStdinParse(); 
}
