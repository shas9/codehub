#include <stdio.h>

int main()
{
    int n, k;

    scanf("%d%d", &n, &k);

    int arr[n];

    int i;

    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int num, count = 0;

    num = arr[k - 1];

    if(num > 0)
    {
        for(i = 0; i < n; i++)
        {
            if(arr[i] >= num)
            {
                count = count + 1;
            }
        }
        printf("%d\n", count);
    }
    else
    {
        num = num + 1;
        for(i = 0; i < n; i++)
        {
            if(arr[i] >= num)
            {
                count = count + 1;
            }
        }
        printf("%d\n", count);
    }

    return 0;
}
