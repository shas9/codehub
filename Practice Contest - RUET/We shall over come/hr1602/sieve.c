#include <stdio.h>

int main()
{
    int num[8101];
    int prime[1500];

    int i;

    for(i = 0; i <= 8100; i++)
    {
        num[i] = 0;
    }
    for(i = 0; i < 1500; i++)
    {
        prime[i] = 0;
    }
    int j, k;

    int root;

    root = 90;

    for(j = 2; j <= root; j++)
    {
        if(num[j] == 0)
        {
            for(k = (j + j); k <= 8100; k = k + j)
            {
                num[k] = 1;
            }
        }
    }
    int l, m = 0;
    for(l = 2; l <= 8100; l++)
    {
        if(num[l] == 0)
        {
            prime[m] = l;
            m = m + 1;
        }
    }
    int n;
    for(n = 0; n <= 1500; n++)
    {
        printf("%d\n", prime[n]);
    }
    return 0;
}
