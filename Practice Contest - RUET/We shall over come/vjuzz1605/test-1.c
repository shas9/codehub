#include <stdio.h>

int main()
{
    int j, temp, flag, sum, max = 8;
    int arr1[] = {0, 0, 0, 2, 8, 6, 5, 7};

    int arr2[] = {0, 0, 0, 4, 6, 3, 6, 8};

    int arr3[max];

    int tag = 0;

    flag = 0;
        for(j = 1; j < max; j++)
        {
            sum = arr1[max - j] + arr2[max - j];

            temp = (sum + flag) % 10;

            printf("DBUG temp = %d, j = %d, sum = %d\n", temp, j, sum);

            arr3[max - j] = temp;

            printf("DBUG arr3 = %d\n", arr3[max - j]);

            flag = (sum + flag) / 10;

            printf("DBUG flag = %d\n", flag);
        }

        for(j = 0; j < max; j++)
        {
            arr1[j] = arr2[j];
        }
        for(j = 0; j < max; j++)
        {
            arr2[j] = arr3[j];
        }

        printf("\n");

        for(j = 0; j < max; j++)
        {
            if(tag || arr3[j])
            {
                printf("%d ", arr3[j]);

                tag = 1;
            }
        }
        /*int x;

    read:

    tag = 0;

    scanf("%d", &x);

    for(i = 0; i < max; i++)
    {
        if(tag || fib[x][i])
        {
            printf("%d ", fib[x][i]);
            tag = 1;
        }
    }
    printf("\n\n");

    goto read;*/

}
