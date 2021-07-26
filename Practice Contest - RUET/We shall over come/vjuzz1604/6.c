#include <stdio.h>

int main()
{
    int tc, i;

    char a[100];
    char b[100];

    int lna, lnb, j, k;

    scanf("%d", &tc);

    for(i = 1; i <= tc; i++)
    {
        scanf("%s", a);

        for(lna = 0; a[lna] != '\0'; lna++);

        lnb = lna;

        for(j = 0; j < lnb; j++)
        {
            b[j] = a[lnb - 1- j];
        }

        /*for(j = 0; j < lnb; j++)
        {
            printf("%c ", b[j]);
        }*/

        for(k = 0; k <lna; k++)
        {
            if(b[k] != a[k])
            {
                printf("Case %d: No\n", i);
                break;
            }
        }
        if(k == lna)
        {
            printf("Case %d: Yes\n", i);
        }
    }
    return 0;
}

