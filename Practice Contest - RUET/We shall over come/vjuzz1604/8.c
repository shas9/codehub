#include <stdio.h>

int main()
{
    int x[5][5] = {1, 4, 5, 16, 17, 2, 3, 6, 15, 18, 9, 8, 7, 14, 19, 10, 11, 12, 13, 20, 25, 24, 23, 22, 21};

    long long int testcase, i;

    scanf("%lld", &testcase);

    long long int a, b;

    long long int n;

    for(i = 1; i <= testcase; i++)
    {
        scanf("%lld", &n);

        for(a = 0; a < 5; a++)
        {
            for(b = 0; b < 5; b++)
            {
                if(x[a][b] == n)
                {
                    printf("Case %lld: %lld %lld\n", i, b + 1, a + 1);
                    break;
                }
            }
        }
    }

    return 0;

}
