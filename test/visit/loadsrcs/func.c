
#include <stdio.h>

int aafunctionName(int hoge)
{
    int a = 0;
    int b = 1;

    if ( a == 0 ) 
    {
        printf("hogehoge\n");
    }
    else 
    {
        printf("geho\n");
        return 10;
    }

    printf("ho\n");

    return 10;
}

void func2()
{
    int a, b;
    if ( (a == 0) && b == 2 ) 
    {
        printf("hogehoge\n");
        return;
    }
    else 
    {
        printf("geho\n");
    }

    printf("ho\n");
}



void funchogehoge(int hoge)
{
    int a, b;
    if ( ( a == 0 ) 
            && ( b = 1)
       )
    {
        printf("hogehoge\n");
    }
    else 
    {
        printf("geho\n");
    }

    printf("ho\n");
}

void func3()
{
    int a, b;
    if ( (a == 0) && b == 2 ) 
    {
        func(A,B,C,D,
                    ABCDEFGH,
                    EFGHIJKLMN,
                    OPQRSTU_VWXYZHOGEHOGE);
    }
    else 
    {
        printf("geho\n");
    }

    printf("ho\n");
}

void nest3(int a)
{
    int b, c;

    if ( a == 0 
          && b == 2 
          || c == 2)
    {
        if ( a == 0)
        {
            char* hogehoge;
            printf("a == 0\n", hogehoge);
            if ( b == 0 )
            {
                printf("b == 0 hogehoge\n");
            }
        }
    }
    else
    {
        if ( b == 0 )
        {
            printf("else b == 0 hoge");
        }
        return ;
    }

}


