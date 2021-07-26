#include <stdio.h>

int main()
{

    char a[200];
    char b[200];

    //read:

    scanf("%s", a);
    scanf("%s", b);

    int lna, lnb;

    int i;

    for(lna = 0; a[lna] != '\0'; lna++);
    //for(lnb = 0; b[lnb] != '\0'; lnb++);

    lnb = lna;

    char A[200];
    char B[200];

    int sumA, sumB;

    for(i = 0; i < lna; i++)
    {
        if(a[i] >= 'A' && a[i] <= 'Z')
        {
            a[i] = a[i] + 32;
        }
    }

    for(i = 0; i < lnb; i++)
    {
        if(b[i] >= 'A' && b[i] <= 'Z')
        {
            b[i] = b[i] + 32;
        }
    }

    /*printf("DBUG A = %d\n", sumA);
    printf("DBUG B = %d\n", sumB);

    if(sumA == sumB)
    {
        printf("0\n");
    }
    else if(sumA > sumB)
    {
        printf("1\n");
    }
    else if(sumB > sumA)
    {
        printf("-1\n");
    }*/

    for(i = 0; i < lna; i++)
    {
        if(a[i] != b[i])
        {
            sumA = a[i];
            sumB = b[i];
            break;
        }
    }
    if(i == lna)
    {
        printf("0\n");
    }
    else if(sumA > sumB)
    {
        printf("1\n");
    }
    else if(sumB > sumA)
    {
        printf("-1\n");
    }


    //goto read;

    return 0;
}
