#include <stdio.h>

int main()
{
    int n;

    scanf("%d", &n);

    int i, j;

    char z[10];

    int x = 0;

    for(i = 0; i < n; i++)
    {
        scanf("%s", z);

        for(j = 0; j < 5; j++)
        {
            if(z[j] == '+')
            {
                x = x + 1;
                break;
            }
            else if(z[j] == '-')
            {
                x = x - 1;
                break;
            }
        }
    }

    printf("%d\n", x);

    return 0;
}
