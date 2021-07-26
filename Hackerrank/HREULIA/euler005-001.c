#include <stdio.h>

int main()
{
    int testcase, input, i, result, factor, x;

    scanf("%d", &testcase);

    for(i = 1; i <= testcase; i++)
    {
        scanf("%d", &input);
        result = 1;
        factor = 1;

        int j;

        for(j = 1; j <= input; j++)
        {
            int k;
            for(k = 1; k < j; k++)
            {
                if(j % k == 0)
                {
                    //printf("J Debug %d\n", k);
                    factor = factor * k;
                }
            }
            //printf("Factor = %d, J = %d\n\n", factor, j);
            x = j / factor;

            result = result * x;
            //printf("pre res %d\n", result);


        }
        printf("%d\n", result);

    }
    return 0;
}

