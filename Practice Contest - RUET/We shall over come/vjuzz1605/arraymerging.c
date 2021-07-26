#include<stdio.h>

int main()
{
    int a[200][15];

    int i = 5;
    int j;

    for(j = 0; j < 10; j++)
    {
        scanf("%d", &a[i][j]);
    }

    for(j = 0; j < 15; j++)
    {
        printf("%d  ", a[5][j]);
    }


}
