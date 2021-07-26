#include <stdio.h>

int main()
{
    int testcase;
    scanf("%d", &testcase);

    int i;
    long long int input, sum3, sum5, sum15, sum;
    int j;

    long long int a, b, c;
    for(i = 1; i <= testcase; i++)
    {
        sum = 0;

        scanf("%lld", &input);

        input = input - 1;

        a = input / 3;
        b = input / 5;
        c = input / 15;

        sum3 = 3 * (a * (a + 1)) / 2;

        sum5 = 5 * (b * (b + 1)) / 2;

        sum15 = 15 * (c * (c + 1)) / 2;

        sum = sum3 + sum5 - sum15;


        printf("%lld\n", sum);
    }

    return 0;
}

