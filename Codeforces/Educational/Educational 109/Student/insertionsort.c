#include<stdio.h>

/*
5 3 6 8 2 1 7 5

1 2 3 5 5 6 7 8

Complexity: O(n * n)

*/

int arr[505];

int main()
{
    int n;

    int i, j;

    scanf("%d", &n);

    int cnt = n;

    for(i = 1; i <= n; i++)
    {
        arr[i] = cnt;
        cnt--;
    }

    printf("The initial array is: ");

    for(i = 1; i <= n; i++) printf("%d ", arr[i]);

    printf("\n");

    for(i = 1; i <= n; i++)
    {
        int idx = -1;

        for(j = 1; j < i; j++)
        {
            if(arr[j] > arr[i])
            {
                idx = j;
                break;
            }
        }

        if(idx != -1)
        {
            int temp = arr[i];

            for(j = i; j > idx; j--)
            {
                arr[j] = arr[j - 1];
            }

            arr[idx] = temp;
        }
    }

    printf("The final array is: ");

    for(i = 1; i <= n; i++) printf("%d ", arr[i]);

    printf("\n");

}
