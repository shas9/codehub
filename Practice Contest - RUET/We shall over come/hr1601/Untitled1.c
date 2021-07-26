#include <stdio.h>

int main()
{
    long long int  result, X, Y;

    int i, T;

    scanf("%d", &T);

    for(i = 1; i <= T; i++)
    {
        scanf("%lld%lld", &X, &Y);
        result = X + Y;

        printf("Case %d: %lld\n", i, result);
    }

    return 0;
}
