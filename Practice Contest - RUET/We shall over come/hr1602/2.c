#include<stdio.h>

int main()
{
    int x, testcase, i, j, k, position;

    scanf("%d", &x);

    int arr[x];
    int input;

    scanf("%d", &testcase);

    for(i = 0; i < x; i++)
    {
        scanf("%d", &arr[i]);
    }
    for(j = 1; j <= testcase; j++)
    {
        scanf("%d", &input);
        position = 0;

        for(k = 0; k < x; k++)
        {
            if(input == arr[k])
            {
                position = k + 1;
            }
        }
        if(position == 0)
        {
            printf("Not Found\n");
        }
        else
        {
            printf("%d\n", position);
        }
    }
    return 0;
}
