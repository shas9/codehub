#include <stdio.h>

int main()
{
    int testcase;

    scanf("%d", &testcase);

    long long int i, count;

    long long int a, b;

    for(i = 1; i <= testcase; i++)
    {
        count = 0;
        scanf("%lld%lld", &a, &b);

        a = a + 1;

        while(a <= b)
        {
            if((a % 3 == 0) || ((a - 1) % 3 == 0))
            {
                count = count + 1;
            }
            a = a + 1;
        }
        if((b % 3 == 0) || ((b + 1) % 3 == 0))
        {
            count = count + 1;
        }


        printf("Case %lld: %lld\n", i, count);
    }
    return 0;
}
