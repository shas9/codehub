#include <stdio.h>

int main()
{
    long long int a, b, sum;

    int testcase;
    int i, count;
    long long j;

    scanf("%d", &testcase);

    for(i = 1; i <= testcase; i++)
    {
        scanf("%lld%lld", &a, &b);

        count = 0;

        for(j = a; j <= b; j++)
        {
            sum = (j * (j + 1)) / 2;

            if(sum % 3 == 0)
            {
                count = count + 1;
            }
        }

        printf("Case %d: %d\n", i, count);
    }
    return 0;
}
