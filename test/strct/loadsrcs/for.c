
int main(void) 
{
    int i;

    for ( i = 0; i < limit(); i++ )
    {
        hogehoge();
    }


    for ( j = (1 + 2), i = 20; i + j < 100; j++, i++ )
        printf("hohogege\n");

    for ( ; ;)
    {
        printf("mugen loop\n");
    }

    for( i = 0; ; )
    {
        return 10;
    }

    for ( ; i != 0; )
    {
        continue;
    }

    for ( ; ; i++ )
    {
        return 1;
    }

}


