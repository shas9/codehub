#include<stdio.h>

int main()
{
    char large;

    char input[200];

    int i, ln;

    int count;


    while(scanf("%s", input) != EOF)
    {
        for(ln = 0; input[ln] != '\0'; ln++);

    large = input[0];
    count = 0;

    for(i = 0; i < ln; i++)
    {
        if(input[i] > large)
        {
            large = input[i];
            count = 1;
        }
        else if(input[i] == large)
        {
            count++;
        }

        //printf("str = %c, count = %d\n", input[i], count);
    }

    for(i = 1; i <= count; i++)
    {
        printf("%c", large);
    }
    }

    return 0;
}





