#include <stdio.h>

int main()
{
    long long int size;

    scanf("%lld", &size);

    long long int b;

    b = size - 1;

    long long int arr[size];

    long long int i, j, k, l = 0;

    long long int index = size - 1;

    long long int diff;

    long long int a;
    a = (b * (b + 1)) / 2;

    //prlong long intf("a = %lld", a);

    long long int result[a];

    for(i = 0; i < size; i++)
    {
        scanf("%lld", &arr[i]);
    }
    for(j = index; j >= 1; j--)
    {
        for(k = 0; k <= (j - 1); k++)
        {
            diff = (arr[j] - arr[k]);


            if(diff < 0)
            {
                diff = - diff;
            }

            //prlong long intf("%lld(diff) = %lld(j) - %lld(k)\n", diff, arr[j], arr[k]);

            result[l] = diff;

            //prlong long intf("r = %lld, l = %lld\n", result[l], l);

            l = l + 1;
        }

    }
    /*for(l = 0; l < a; l++)
    {
        prlong long intf("dbug %lld of %lld th \n", result[l], l);
    }*/

    long long int min, count = 0;

    min = result[0];

    for(i = 1; i < a; i++)
    {
        if(result[i] < min)
        {
            min = result[i];
        }
    }
    for(i = 0; i < a; i++)
    {
        if(result[i] == min)
        {
            count = count + 1;
        }
    }
    printf("%lld %lld\n", min, count);

    return 0;

}
