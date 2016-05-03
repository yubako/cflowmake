
#include <stdio.h>

int aa;
int b;

int swmain(void)
{

    int a;
    switch(a)
    {
        case 10: printf("a == 10"); a--; break;
        case 11: printf("a == 11"); a++; break;
        case 12: printf("a == 12"); break;
        case 13: printf("a == 13"); break;
        case 14: printf("a == 14"); a++; break;
        default:
                 {
                     printf("default");
                     break;
                 }
    }

    if ( a == 10 )
    {
        printf("hoge");
    }
    printf("hogehoge");
    return 10;
}


