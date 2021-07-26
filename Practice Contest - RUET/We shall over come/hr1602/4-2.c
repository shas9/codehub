#include <stdio.h>

long long int result[12502500];

int main()
{
    long long int size;

    scanf("%lld", &size);

    long long int arr[size + 1000];

    long long int a, b, diff, min, count;

    b = size - 1;

    a = ((b + 1) * b) / 2;

    long long int i, j, k, l = 0, m, n;

    for(i = 0; i < size; i++)
    {
        scanf("%lld", &arr[i]);
    }

    min = 10000000000000000;
    for(j = 1; j <= b; j++)
    {
        for(k = 0; k < j; k++)
        {
            //printf("%lld is %d %lld is %d\n", arr[j], j, arr[i], i);
            diff = (arr[j] - arr[k]);

            if(diff < 0)
            {
                diff = - diff;
            }
            if(diff < min)
            {
                min = diff;
            }

        }
    }

    count = 0;

    for(j = 1; j <= b; j++)
    {
        for(k = 0; k < j; k++)
        {
            //printf("%lld is %d %lld is %d\n", arr[j], j, arr[i], i);
            diff = (arr[j] - arr[k]);

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


    printf("%lld %lld\n", min, count);

    return 0;

}
