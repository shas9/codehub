#include <stdio.h>

/*
arr [] = {5 3 6 8 2 1 7 5}

2 type of sorting


1. Ascending order: 1 2 3 5 5 6 7 8
2. Descending order: 8 7 6 5 5 3 2 1

Method of sorting:

1. Selection Sort. (!)
(+) 2. Bubble Sort. (!)
(+) 3. Quick Sort.
(+) 4. Merge Sort. (!)
(+) 5. Insertion Sort.
(+) 6. Shell Sort.
7. Frequency Sort. (!)

*/

int arr[503];

void mergesort(int l, int r)
{
    if(l == r) return;

    int half = (r + l) / 2;

    mergesort(l, half);
    mergesort(half + 1, r);

    // bam pashe l .... half
    // dan pashe half + 1....r
    // 18 - 11 + 1 = 8
    // 27 -> 32 = (32 - 27 + 1) = 5
    // l -- r = (r - l + 1)


    int leftsize = (half - l + 1);
    int rightsize = (r - half);

    int L[leftsize];
    int R[rightsize];

    int cnt = l;

    for(int j = 0; j < leftsize; j++)
    {
        L[j] = arr[cnt];
        cnt++;
    }

    for(int j = 0; j < rightsize; j++)
    {
        R[j] = arr[cnt];
        cnt++;
    }

    // merge part

    int cursor1 = 0, cursor2 = 0;

    for(int i = l; i <= r; i++)
    {
        if(cursor1 == leftsize)
        {
            arr[i] = R[cursor2];
            cursor2++;
        }
        else if(cursor2 == rightsize)
        {
            arr[i] = L[cursor1];
            cursor1++;
        }
        else if(L[cursor1] < R[cursor2])
        {
            arr[i] = L[cursor1];
            cursor1++;
        }
        else
        {
            arr[i] = R[cursor2];
            cursor2++;
        }
    }

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
        arr[i] = cnt;
        cnt--;
    }

    printf("The initial array is: ");

    for(i = 1; i <= n; i++) printf("%d ", arr[i]);

    printf("\n");

    mergesort(1,n); // function to sort

    printf("The final array is: ");

    for(i = 1; i <= n; i++) printf("%d ", arr[i]);

    printf("\n");
}
