#include<stdio.h>

int arr[100005];

void mergesort(int left, int right)
{
    if(left == right) // Base Case
    {
        return; // When the size of box is 1, you don't need to merge.
    }

    int mid = (left + right) / 2; // Half of the segment

    mergesort(left, mid); // Bam Side L = left, R = mid;
    mergesort(mid + 1, right); // Dan side L = mid + 1, R = right;

    int leftsize = (mid - left + 1);
    int rightsize = (right - (mid + 1) + 1); // L = mid + 1

    int L[leftsize]; // array for left part
    int R[rightsize]; // array for right part
    int i, j;

    for(i = left, j = 0; i <= mid; i++, j++) // Initialization, Condition, Incrementation
    {
        L[j] = arr[i]; // Left side in sorted
    }

    for(i = mid + 1, j = 0; i <= right; i++, j++)
    {
        R[j] = arr[i]; // Right side in sorted
    }

    // Start Merging Part

    int cursor1 = 0, cursor2 = 0;

    for(i = left; i <= right; i++)
    {
        if(cursor1 == leftsize) // Left array has ended
        {
            arr[i] = R[cursor2];
            cursor2++;
        }
        else if(cursor2 == rightsize) // right array has ended
        {
            arr[i] = L[cursor1];
            cursor1++;
        }
        else if(L[cursor1] < R[cursor2]) // Left cursor has smaller value
        {
            arr[i] = L[cursor1];
            cursor1++;
        }
        else // Right cursor has smaller value
        {
            arr[i] = R[cursor2];
            cursor2++;
        }
    }

    // End merging part

    return;
}

int main()
{
    int n, i;

    scanf("%d", &n);

    for(i = 1; i <= n; i++)
    {
        arr[i] = rand() % 5; // Random number assign
    }

    // Printing the array after taking input
    printf("The array is: ");
    for(i = 1; i <= n; i++) printf("%d ", arr[i]);
    printf("\n");
    // End

    mergesort(1,n); // Function to make


    // Printing the array after sorted the input
    printf("The array is after sorting: ");
    for(i = 1; i <= n; i++) printf("%d ", arr[i]);
    printf("\n");
    // End

    return;
}
