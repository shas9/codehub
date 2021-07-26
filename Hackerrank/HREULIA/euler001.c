#include <stdio.h>

int main()
{
    int testcase;
    scanf("%d", &testcase);

    int i;
    long long int input, sum;
    int j;

    for(i = 1; i <= testcase; i++)
    {
        sum = 0;

        scanf("%lld", &input);

        for(j = 1; j < input; j++)
        {
            if((j % 3 == 0) || (j % 5 == 0))
            {
                sum = sum + j;
            }
        }
        printf("%lld\n", sum);
    }

    return 0;
}
