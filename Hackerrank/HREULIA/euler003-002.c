#include<stdio.h>
#include<math.h>

int main()
{
    long long int input;
    int i, testcase;
    long long int prime;

    long long int k, j, l, m, result, result1;
    scanf("%d", &testcase);

    for(i = 1; i <= testcase; i++)
    {
        scanf("%lld", &input);
        prime = 0;

        k = sqrt(input);

        for(j = 1; j <= k; j++)
        {
            if(input % j == 0)
            {
                result = input / j;

                for(l = 2; l < sqrt(result); l++)
                {
                    printf("dbug-1 %lld\n", l);
                    if(result % l == 0)
                    {
                        printf("dbug-2 %lld\n", l);
                        break;
                    }
                    else
                    {
                        printf("dbug-3 %lld\n", l);
                        prime = result;
                    }
                }

            }
        }
        printf("%lld\n", prime);

    }
    return 0;

}
