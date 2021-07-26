#include <stdio.h>

int main()
{
    char binaryA[8000];
    char binaryB[8000];

    int testcase;

    scanf("%d", &testcase);

    long long int i, j, k, l;

    long long int lA, lB;

    for(j = 1; j <= testcase; j++)
    {
        scanf("%s", binaryA);
        scanf("%s", binaryB);

        for(lA = 0; binaryA[lA] != '\0'; ++lA);
        for(lB = 0; binaryB[lB] != '\0'; ++lB);



        while(1)
        {
            i = 0;
            if(binaryA[i] == '1')
            {
                break;
            }
            else if(binaryA[i] == '0')
            {
                lA = lA - 1;
                for(k = 0; k < lA; k++)
                {
                    binaryA[k] = binaryA[k + 1];
                }
            }
        }

        while(1)
        {
            i = 0;
            if(binaryB[i] == '1')
            {
                break;
            }
            else if (binaryB[i] == '0')
            {
                lB = lB - 1;
                for(k = 0; k < lB; k++)
                {
                    binaryB[k] = binaryB[k + 1];
                }

            }
        }
        /*for(i = 0; i < lA; i++)
        {
            printf("%c ", binaryA[i]);
        }
        printf("\n");
        for(i = 0; i < lB; i++)
        {
            printf("%c ", binaryB[i]);
        }*/

        //printf("\nLength of A = %d, B = %d\n", lA, lB);

        if(lA > lB)
        {
            printf("Case %lld: A\n", j);
        }

        else if(lB > lA)
        {
            printf("Case %lld: B\n", j);
        }
        else if(lB == lA)
        {
            for(l = 1; l < lB; l++)
            {
                if(binaryA[l] == '0' && binaryB[l] == '1')
                {
                    printf("Case %lld: B\n", j);
                    break;
                }
                else if(binaryA[l] == '1' && binaryB[l] == '0')
                {
                    printf("Case %lld: A\n", j);
                    break;
                }
            }
            if(l == lB)
            {
                printf("Case %lld: Same\n", j);
            }

        }


    }
    return 0;
}
