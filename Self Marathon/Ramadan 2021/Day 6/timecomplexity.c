#include<stdio.h>

int main()
{
    int i, j, n, k;

    int cnt = 0;

    scanf("%d", &n);

    for(i = 1; i <= n; i++) // n
    {
        for(j = 1; j <= n; j++) // n * n => n ^ 2
        {
            for(k = 1; k <= n; k++) // n * n * n = > n ^ 3
            {
                // a = b + c
                cnt = cnt + 1;
            }
        }
    }

    for(i = 1; i <= n; i++) // n
    {
        for(j = 1; j <= n; j++) // n * n => n ^ 2
        {
            for(k = 1; k <= n; k++) // n * n * n = > n ^ 3
            {
                // a = b + c
                cnt = cnt + 1;
            }
        }
    }

    /// time complexity O(n^3) O = notation big o

    printf("%d\n", cnt);

//    cnt = 0;
//    scanf("%d", &n);

    for(i = 1; i <= n; i++) // n
    {
        for(j = 1; j <= n; j++) // n * n => n ^ 2
        {
            cnt++;
        }
    }

    for(i = 1; i <= n; i++) // n
    {
        for(j = 1; j <= n; j++) // n * n => n ^ 2
        {
            cnt++;
        }
    }

    /// time complexity O(n^2) O = notation big o

    printf("%d\n", cnt);

//    cnt = 0;
//    scanf("%d", &n);

    for(i = 1; i <= n; i++) // n
    {
        cnt++;
    }

    /// time complexity O(n) O = notation big o

    printf("%d\n", cnt);


    /// Total time Complexity: O(n^3 + n^3 + n^2 + n^2 + n) (Accurate Complexity) = O(n^3) (General Complexity)

    // O(x) O means complexity


    int m;

    scanf("%d%d", &n, &m);

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= m; j++) // Complexity: O(n * m)
        {

        }
    }

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= m; j++) // Complexity: O(n * m)
        {
            for(k = 1; k <= n; k++) // Complexity: O(n * m * n) = O(n ^ 2 * m)
        }
    }

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= m; j++) // Complexity: O(n * m)
        {
            for(k = 1; k <= m; k++) // Complexity: O(n * m * m) = O(m ^ 2 * n)
        }
    }

    // Total accurate time complexity: O(n^2 * m + m^2 * n + n * m) = O(n^2*m + m^2*n)




    if(asdasda) // Complexity: O(1)
    {
        if(asdasda) // Complexity: O(1 + 1)
        {
            for(i = 1; i <= n; i++)
            {
                for(j = 1; j <= m; j++) // Complexity: O(n * m + 2)
                {
                    if(asdasdas) // Complexity: O(n * m * 1 + 2)
                    {
                        if(asdasdas) // Complexity: O(n * m * 2 + 2)
                        {
                            for(k = 1; k <= n; k++) // Complexity: O(n*m*2*n + 2);
                        }
                    }
                }
            }
        }
    }

    // Accurate complexity: O(n * m * n * 2 + 2)
    // General time complexity: O(n * m * n * 2) = O(n^2 * m)


    /*
        n + (n / 2) + (n / 4) + (n / 8) + (n / 16) + (n / 32)
        = nlog2(n)

        n + (n / 10) + (n / 100) + (n / 1000) + (n / 10000)
        = nlog10(n)

        n + (n / m) + (n / m^2) + (n / m^3) + (n / m^4)
        = nlogm(n)
    */

}
