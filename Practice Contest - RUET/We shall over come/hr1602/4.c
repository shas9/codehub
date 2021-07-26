#include <stdio.h>

int main()
{
    int n;

    scanf("%d", &n);

    int array[n];

    int index = n - 1;

    int min;

    min = 100000000;
    int count = 0;

    int i, j, k;
    int diff;

    for(i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
    for(j = index; j >= 2; j--)
    {
        for(k = 0; k < j; k++)
        {
            diff = (array[j] - array[k]);

            if(diff < 0)
            {
                diff = - diff;
            }
            if(diff < min)
            {
                min = diff;
            }

        }
        for(k = 0; k < j; k++)
        {
            diff = (array[j] - array[k]);

            if(diff < 0)
            {
                diff = - diff;
            }

            if(diff == min)
            {
                count = count + 1;
            }

        }
    }
    printf("%d %d\n", min, count);
    return 0;
}
