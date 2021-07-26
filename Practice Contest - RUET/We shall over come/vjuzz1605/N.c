#include <stdio.h>
#include <math.h>

int main()
{
    int n, r, p, q;

    int testcase;

    scanf("%d", &testcase);

    int i;

    long long int C, res, count, A, B;

    int x;

    for(i = 1; i <= testcase; i++)
    {
        scanf("%d%d%d%d", &n, &r, &p, &q);

        A = 1;
        B = 1;

        if(r <= (n / 2))
        {
            for(x = (n - r + 1); x <= n; x++)
            {
                A = A * x;
            }

            for(x = 1; x <= r; x++)
            {
                B = B * x;
            }
        }
        else
        {
            for(x = (r + 1); x <= n; x++)
            {
                A = A * x;
            }

            for(x = 1; x <= (n - r); x++)
            {
                B = B * x;
            }
        }



        //printf("DBUG A = %lld\n", A);



        //printf("DBUG B = %lld\n", B);

        C = A / B;

        //printf("DBUG C = %lld\n", res);

        res = C * pow(p,q);

        //printf("DBUG %lld\n", res);

        count = 0;

        while(res % 10 == 0)
        {
            count++;

            res = res / 10;
        }

        printf("Case %d: %lld\n",i, count);
    }

    return 0;
}
