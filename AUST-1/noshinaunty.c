#include <stdio.h>
int inversion_merge(int arr[], int p, int r)
{
    int q = (p+r)/2;
    int firsti = p;

    int lasti = q+1;

    int c[p-r+1], ci=0;

    int inversion = 0, i;

    while (firsti <= q && lasti <= r)
    {

        if (arr[firsti] <= arr[lasti])
        {
            //printf("---2\n");
            c[ci++] = arr[firsti++];
        }
        else
        {
            //printf("---1\n");
            c[ci++] = arr[lasti++];
            inversion += q - firsti + 1;
        }

    }


    while (firsti <= q)

    c[ci++] = arr[firsti++];


    while (lasti <= r)

    c[ci++] = arr[lasti++];


    for (i=0 ; i<p-r+1 ; i++)

    arr[i+p] = c[i];

    //printf("-----3\n");


    return inversion;

}


int counting_inversion(int arr[], int first, int last)

{

    int m, n, o, q;

    if (first == last)

    return 0;


    q = (first+last)/2;


    m = counting_inversion(arr, first, q);

    n = counting_inversion(arr, q+1, last);

    o = inversion_merge(arr, first, last);


    return m+n+o;
}

int main()
{
    int i, n, size;

    printf("Enter n: ");

    scanf("%d", &n);

    int elements[n];


    for(i=0; i<n; ++i)
    {

        printf("Enter elements %d: ",i+1);
        scanf("%d", &elements[i]);
    }

    size = n;

    //printf("--\n");

    int inversion = counting_inversion(elements, 0, size-1);

    //printf("----\n");
    for (i=0 ; i<size; i++)
    {
        printf("%d ", elements[i]);
    }

    printf("\n");


    printf("Total inversions : %d\n", inversion);

    return 0;
}

