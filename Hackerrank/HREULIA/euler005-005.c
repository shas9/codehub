#include <stdio.h>

int main()
{
    long long int x, y, z, a, b, input, result, ans;

    int testcase;

    scanf("%d", &testcase);

    int i, j;

    for(i = 1; i <= testcase; i++)
    {
        scanf("%lld", &input);
        x = 1;


        for(j = 1; j <= input; j++)
        {
            z = 1;
            y = j;
            a = y;
            b = x;
            //printf("d-bug1 x = %lld, y = %lld\n", x, y);
            while(1)
            {
                z = x % y;
                //printf("debug y %lld, z %lld\n", y, z);

                if(z == 0)
                {
                    ans = y;
                    break;
                }
                else
                {
                    x = y;
                    y = z;
                }
            }
            result = (a * b) / ans;
            x = result;
        }
        printf("%lld\n", result);
        result = 0;
    }
    return 0;
}
