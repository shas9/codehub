#include <stdio.h>

int main()
{
    int testcase;
    scanf("%d", &testcase);

    int i;
    double input, sum3, sum5, sum15, sum;
    int j;

    //long long int a, b, c;
    for(i = 1; i <= testcase; i++)
    {
        sum = 0;

        scanf("%lf", &input);

        input = input - 1;

        sum3 = (input * (input + 3)) / 6;

        sum5 = (input * (input + 5)) / 10;

        sum15 = (input * (input + 15)) / 30;

        sum = sum3 + sum5 - sum15;


        printf("%.0lf\n", sum);
    }

    return 0;
}


