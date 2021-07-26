#include <stdio.h>

int main()
{
    int testcase;

    scanf("%d", &testcase);

    long long int i, count;

    long long int a, b, x;

    for(i = 1; i <= testcase; i++)
    {
        count = 0;
        scanf("%lld%lld", &a, &b);



        printf("Case %lld: %lld\n", i, count);
    }
    return 0;
}
