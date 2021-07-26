#include <stdio.h>

int main()
{
    int testcase;

    scanf("%d", &testcase);

    int i;

    int a, b, n;

    for(i = 1; i <= testcase; i++)
    {
        scanf("%d", &n);

        if(n <= 10)
        {
            printf("0 %d\n", n);
        }
        else
        {
            a = 10;
            b = n - a;

            printf("%d %d\n", a, b);

        }
    }

    return 0;
}
