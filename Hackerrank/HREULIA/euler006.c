#include <stdio.h>

int main()
{
    int testcase, i, input, a, b;

    long long int r1, r2, result;

    scanf("%d", &testcase);

    for(i = 1; i <= testcase; i++)
    {
        scanf("%d", &input);

        r1 = 0; r2 = 0;

        for(a = 1; a <= input; a++)
        {
            r1 = r1 + a;
            r2 = r2 + (a * a);
        }
        result = (r1 * r1) - r2;
        printf("%lld\n", result);
    }
    return 0;
}
