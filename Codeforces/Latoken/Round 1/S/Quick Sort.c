/*
r - (half + 1) + 1
=> r - half - 1 + 1;
=> r - half;

*/

#include <stdio.h>

int arr[103];

int findpivot(int l, int r)
{
    int pivot = arr[r];
    int pivotpoint = l;

    int i;

    for(i = l; i <= r - 1; i++)
    {
        if(arr[i] < pivot)
        {
            int temp = arr[i];
            arr[i] = arr[pivotpoint];
            arr[pivotpoint] = temp; // swapped

            pivotpoint++;
        }
    }

    arr[r] = arr[pivotpoint];
    arr[pivotpoint] = pivot;

    return pivotpoint;
}

void quicksort(int l, int r)
{
    if(l == r) return;
    if(l > r) return;

    int pivot = findpivot(l,r);

    quicksort(l, pivot - 1);
    quicksort(pivot + 1, r);

    return;
}

int main()
{
    int n;

    int i, j;

    scanf("%d", &n);

    int cnt = n;

    for(i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("The initial array is: ");

    for(i = 1; i <= n; i++) printf("%d ", arr[i]);

    printf("\n");


    quicksort(1,n); // Quick Sort


     printf("The final array is: ");

    for(i = 1; i <= n; i++) printf("%d ", arr[i]);

    printf("\n");

}
