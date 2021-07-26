#include <stdio.h>

int main()
{
    int testcase;
    long long int input;

    long long int x, y, r, sum;

    scanf("%d", &testcase);

    int i;

    for(i = 1; i <= testcase; i++)
    {
        scanf("%lld", &input);

        sum = 0;

        x = 0;
        y = 1;

        for(r = 1; r <= input;)
        {
            if(r % 2 == 0)
            {
                sum = sum + r;
                //printf("dbug: .. %d\n", r);
            }
            x = y;
            y = r;
            r = x + y;
        }

        printf("%lld\n", sum);
    }
    return 0;
}
