#include<stdio.h>
#include<math.h>

int main()
{
    int testcase, input, i, j, k, l;

    scanf("%d", &testcase);

    for(i = 1; i <= testcase; i++)
    {
        int factor = 1, result = 1;
        scanf("%d", &input);
        for(j = 1; j <= input; j++)
        {
            for(k = 1; k < j; k++)
            {
                if(j % k == 0)
                {
                    factor = k * factor;
                    printf("k is %d, f is %d\n", k, factor);
                }
            }
            result = (result * j) / factor;
            printf("result is %d\n", result);
        }
        printf("%d\n", result);
    }
    return 0;
}
