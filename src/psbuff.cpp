
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>

#include "pars/psbuff.h"

char* psbuff_realloc(const char* ptr1, const char* ptr2)
{
    size_t len = 0;
    char*  buffnew;
    
    len += strlen(ptr1);
    len += strlen(ptr2);

    buffnew = (char*)calloc(len + 2, 1);
    strcpy(buffnew, ptr1);
    strcat(buffnew, " ");
    strcat(buffnew, ptr2);

    return buffnew;
}


