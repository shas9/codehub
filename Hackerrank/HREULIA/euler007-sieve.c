#include <stdio.h>

int main()
{
    int num[300000];

    int prime[15000];

    int i, j;
    int input;
    int testcase;

    for(i = 0; i < 300000; i++)
    {
        num[i] = 1;
    }

    for(i = 2; i <= 1000; i++)
    {
        if(num[i] == 1)
        {
            for(j = i + i; j < 300000; j = j + i)
            {
                num[j] = 0;
            }
        }
    }
    j = 2;
    for(i = 1; i < 15000; i++)
    {
        while(j < 300000)
        {
            if(num[j] == 1)
            {
                prime[i] = j;
                j++;
                break;
            }
            j++;
        }
    }

    scanf("%d", &testcase);

    for(i = 1; i <= testcase; i++)
    {
        scanf("%d", &input);

        printf("%d\n", prime[input]);
    }

    return 0;
}
