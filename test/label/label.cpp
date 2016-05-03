
#include "gtest/gtest.h"
#include <stdio.h>

void labelstr(char* str, char* wbuff, size_t wlen);
void labelescape(char* str, char* wbuff, size_t bufflen);

TEST(visit, label)
{
    char in[1024];
    char out[1024];

    sprintf(in, "%s", 
                "sprintf(writebuff, \"\\n\\n -- %s (%p) using stack %u(0x%x) byte - before \", "
                "get_function_name(func_addr), func_addr, data.stack_size, data.stack_size );");

    //labelstr(in, out, 1024);
    //printf("--%s--", out);

    sprintf(in, "%s", "hoge\nhogehoge%d");
    labelescape(in, out, 1024);
    printf("--%s--", out);
}


