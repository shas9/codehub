#include <stdio.h>

/*
5 3 6 8 2 1 7 5

3 5 6 2 1 7 5 8 -> 1
3 5 2 1 6 5 7 8 -> 2
3 2 1 5 5 6 7 8 -> 3
2 1 3 5 5 6 7 8 -> 4
1 2 3 5 5 6 7 8 -> 5

break

computer can do 10^8 operation in one second

O(n * n) = n^2



*/

/*

    n = 100000;

    O(100000 * 100000) = 1e5 * 1e5 = 1e10 / 1e8 = 100s;

    for(i = 1; i <= n; i++) O(n * m)
    {
        for(k = 1; k <= m; k++)
        {

        }
    }

    for(j = 1; j <= n; j++)
    {

    }

    O(n + n) = O(1e5 + 1e5) = o(2e5) = 2e5 / 1e8 = .002s

    100000 + 100000 / 2 + 100000 / 4 + 100000 / 8 + 100000 / 16......
    log(n)

*/

/*

idx number = 1 2 3 4 5 6
value      = 6 5 4 3 2 1

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

    // bubble sort

    /*
    complexity = O(n * n)
    total operation = 10 * 10 = 100;
    total time = (100 / 1e8) = 1e(-6);

    */


    for(i = 1; i <= n; i++)
    {
        int sw = 0;

        for(j = 1; j < n; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                sw++;
            }
        }

        if(sw == 0) break;
    }

    printf("The final array is: ");

    for(i = 1; i <= n; i++) printf("%d ", arr[i]);

    printf("\n");
}
