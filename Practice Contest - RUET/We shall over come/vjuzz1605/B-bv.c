#include <stdio.h>

int main()
{
    int n, m;
    int res;

    scanf("%d%d", &n, &m);


    int arr_n[n + 1];
    int arr_m[m + 1];

    int i;

    for(i = 0; i <= n; i++)
    {
        scanf("%d", &arr_n[i]);
    }

    for(i = 0; i <= m; i++)
    {
        scanf("%d", &arr_m[i]);
    }

    if(n > m)
    {
        if(arr_n[0] < 0)
        {
            printf("-Infinity\n");
        }
        else
        {
            printf("Infinity\n");
        }
    }
    else if(m > n)
    {
        printf("0/1\n");
    }
    else if(m == n)
    {

        if(m >= n)
        {
            for(i = m; i >= 2; i--)
            {
                if((arr_n[0] % i == 0) && (arr_m[0] % i == 0))
                {
                    arr_n[0] = arr_n[0] / i;
                    arr_m[0] = arr_m[0] / i;
                }
            }
        }
        else
        {
            for(i = m; i >= 2; i--)
            {
                if((arr_n[0] % i == 0) && (arr_m[0] % i == 0))
                {
                    arr_n[0] = arr_n[0] / i;
                    arr_m[0] = arr_m[0] / i;
                }
            }
        }

        if(arr_m[0] < 0)
        {
            arr_m[0] = - arr_m[0];
            arr_n[0] = - arr_n[0];
        }
        printf("%d/%d\n", arr_n[0], arr_m[0]);
    }

    return 0;
}
