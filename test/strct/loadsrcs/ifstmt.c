

int hoge(int hogehoge)
{
    int b;
    int a;

    if ( a == 0 )
        printf("hogehoge \n");

}

int hogehoge(int hoge)
{
    int a = 0;
    int b = 1;

    if ( a == 0 && b == 1) 
        printf("true");
    else
        printf("false");

}

void func(int hoge)
{
    int a = 0;
    int b = 1;

    if ( a == 0 && b == 1) 
    {
        printf("true");
    }
    else if ( (a == b) || (a + 1 == 2) )
    {
        printf("elseif 1");
        printf("elseif 2");
    }
    else
    {
        printf("false");
    }

}



