#include <stdio.h>

int merge(int arr[], int p, int r)
{

int q = (p+r)/2;

int lefti = p;

int righti = q+1;

int total[r-p+1], totali=0;

int inversion = 0, i;


while (lefti <= q && righti <= r) {

if (arr[lefti] <= arr[righti]) {

total[totali++] = arr[lefti++];

} else {

total[totali++] = arr[righti++];

inversion += q - lefti + 1;

}

    }


while (lefti <= q)

total[totali++] = arr[lefti++];


while (righti <= r)

total[totali++] = arr[righti++];


for (i=0 ; i<r-p+1 ; i++)

arr[p+i] = total[i];


return inversion;

}


int counting_inversion(int arr[], int left, int right)
{

int m, n, o, q,total_inv;

if (left >= right)
return 0;


q = (left+right)/2;


m = counting_inversion(arr, left, q);

n = counting_inversion(arr, q+1, right);

o = merge(arr, left, right);
total_inv=m+n+o;


return total_inv;

}

int main(){

int arr[30], i, n;

printf("Enter n: ");

scanf("%d", &n);

for(i=0; i<n; ++i)

     {

printf("Enter number%d: ",i+1);

scanf("%d", &arr[i]);

     }


int inversion = counting_inversion(arr, 0, n-1);

printf("Total inversions : %d \n", inversion);


return 0;

}
