#include <stdio.h>

int main()
{
    int testcase, input, i;

    int x, y;

    int result, ans;

    scanf("%d", &testcase);

    for(i = 1; i <= testcase; i++)
    {
        scanf("%d", &input);

        ans = 0;

        for(x = 100; x <= 999; x++)
        {
            for(y = 100; y <= 999; y++)
            {
                result = x * y;

                int r1, r2, r3, r4, r5, r6;
                int a, b, c, d, e;

                r1 = result % 10;
                a = result / 10;

                r2 = a % 10;
                b = a / 10;

                r3 = b % 10;
                c = b / 10;

                r4 = c % 10;
                d = c / 10;

                r5 = d % 10;
                e = d / 10;

                r6 = e;

                int inverse;

                inverse = (r1 * 100000) + (r2 * 10000) + (r3 * 1000) + (r4 * 100) + (r5 * 10) + r6;

                //printf("\n\nresult = %d\n %d %d %d %d %d %d\ninverse = %d\n\n", result, r1, r2, r3, r4, r5, r6, inverse);

                if((inverse - result) == 0 && result < input)
                {
                    if(ans <= result)
                    {
                        //printf("Dbug %d\n", ans);
                        ans = result;
                    }
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
