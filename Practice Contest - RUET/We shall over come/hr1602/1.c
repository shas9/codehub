#include <stdio.h>

int main()
{
    int testcase;
    scanf("%d", &testcase);

    int i;
    int size, index;

    for(i = 1; i <= testcase; i++)
    {
        scanf("%d", &size);

        int arr[size];
        int arr2[size];

        scanf("%d", &index);

        int j, k, l;
        for(j = 0; j < size; j++)
        {
            scanf("%d", &arr[j]);

            arr2[size - 1 - j] = arr[j];
        }

        printf("Case %d:\n", i);
        printf("%d",arr2[0]);
        for(l = 1; l < size; l++)
        {
            printf(" %d", arr2[l]);
        }
        printf("\n%d %d\n", arr2[index], arr[index]);
    }
    return 0;
}
