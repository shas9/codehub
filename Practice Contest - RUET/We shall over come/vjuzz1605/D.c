#include <stdio.h>
#define max 1100

int arr1[max],arr2[max],arr3[max];
int fib[5001][1100];

int main()
{
    int flag, num;

    int tag = 0;

    int i, j, k, l;

    int sum, temp;

    arr1[max - 1] = 0;
    arr2[max - 1] = 1;

    for(i = 1; i < 5000; i++)
    {
        flag = 0;
        for(j = 1; j < max; j++)
        {
            sum = arr1[max - j] + arr2[max - j];

            temp = (sum + flag) % 10;

            arr3[max - j] = temp;

            flag = (sum + flag) / 10;
        }

        for(j = 0; j < max; j++)
        {
            arr1[j] = arr2[j];
        }
        for(j = 0; j < max; j++)
        {
            arr2[j] = arr3[j];
        }

        for(l = 0; l < max; l++)
        {
            fib[i + 1][l] = arr3[l];
        }
    }



    while(scanf("%d", &num) != EOF)
    {
        num = num + 2;

    if(num == 0)
    {
        printf("0");
    }

    if(num == 1)
    {
        printf("1");
    }

    tag = 0;

    for(i=0;i<max;i++)
    {
        if(tag||fib[num][i])
        {
            tag=1;
            printf("%d",fib[num][i]);
        }
    }

    printf("\n");

    }

    return 0;

}

