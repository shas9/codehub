#include<stdio.h>
#include<math.h>

int main()
{
    int testcase, input, i, j, k = 1, l, range, lcm, result;

    scanf("%d", &testcase);

    for(i = 1; i <= testcase; i++)
    {
        scanf("%d", &input);

        lcm = 1;

        while(1)
        {
            range = input;
            for(j = 2; j <= range; range--)
            {
                if(lcm % range != 0)
                {
                    lcm = lcm * range;
                }
                else
                {
                    result = lcm;
                }
            }
            break;
        }
        printf("%d\n", result);
     }
     return 0;
}
