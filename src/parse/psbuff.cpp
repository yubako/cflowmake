
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>

#include "psbuff.h"

struct parse_buffer 
{
    struct linescope lscope;
    char              strbuff[4096];

};
static struct parse_buffer psbuff;


void psbuff_clear()
{
    memset(&psbuff, 0, sizeof(psbuff));
}

void psbuff_append(int line, const char* strlex)
{
    if ( psbuff.strbuff[0] )
    {
        strcat(psbuff.strbuff, " ");
    }
    strcat(psbuff.strbuff,   strlex);

    if ( psbuff.lscope.begin == 0 ) 
    {
        psbuff.lscope.begin = line;
    }
    psbuff.lscope.end = line;
}

const char* psbuff_get_string()
{
    return psbuff.strbuff;

}

const struct linescope* psbuff_get_linescope()
{
    return &psbuff.lscope;

}


char* psbuff_realloc(const char* ptr1, const char* ptr2)
{
    size_t len = 0;
    char*  buffnew;
    
    len += strlen(ptr1);
    len += strlen(ptr2);

    buffnew = (char*)malloc(len + 1);
    strcpy(buffnew, ptr1);
    strcat(buffnew, ptr1);

    return buffnew;
}



