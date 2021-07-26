#include <stdio.h>

int main()
{

    int testcase;

    char binaryA[8000];
    char binaryB[8000];

    scanf("%d", &testcase);

    int i, j, k, l, o, m, n;

    int lA, lB;


    for(j = 1; j <= testcase; j++)
    {
        read:

        scanf("%s", binaryA);
        scanf("%s", binaryB);

        for(lA = 0; binaryA[lA] != '\0'; ++lA);
        for(lB = 0; binaryB[lB] != '\0'; ++lB);

        /*for(m = 0; m < lA; m++)
        {
            if(binaryA[m] == '1')
            {
                break;
            }
        }
        if(m == lA)
        {
            printf("Case %d: B\n", j);
            j = j + 1;
            goto read;
        }

        for(m = 0; m < lB; m++)
        {
            if(binaryB[m] == '1')
            {
                break;
            }
        }
        if(m == lB)
        {
            printf("Case %d: A\n", j);
            j = j + 1;
            goto read;
        }*/


        while(1)
        {
            i = 0;
            if(lA == 1 && (binaryA[0] == '0'))
            {
                /*printf("Case %d: B\n", j);
                j = j + 1;
                goto read;*/
                break;
            }
            else
            {
                if(binaryA[i] == '1')
            {
                break;
            }
            else if(binaryA[i] == '0')
            {

                for(k = 0; k < (lA - 1); k++)
                {
                    binaryA[k] = binaryA[k + 1];
                }
                lA = lA - 1;
            }
            }
        }

        while(1)
        {
            i = 0;
            if(lB == 1 && (binaryB[0] == '0'))
            {
                /*printf("Case %d: A\n", j);
                j = j + 1;
                goto read;*/
                break;
            }
            else
            {
               if(binaryB[i] == '1')
            {
                break;
            }
            else if (binaryB[i] == '0')
            {

                for(k = 0; k < (lB - 1); k++)
                {
                    binaryB[k] = binaryB[k + 1];
                }
                lB = lB - 1;

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

        if((lB == 1 && (binaryB[0] == '0')) || (lA == 1 && (binaryA[0] == '0')))
        {
            if((lB == 1 && (binaryB[0] == '0')) && (lA == 1 && (binaryA[0] == '0')))
            {
                printf("Case %d: Same\n", j);
            }
            else if(lA == 1 && (binaryA[0] == '0'))
            {
                printf("Case %d: B\n", j);
            }
            else
            {
                printf("Case %d: A\n", j);
            }

        }
        else
        {
             if(lA > lB)
        {
            printf("Case %d: A\n", j);
        }

        else if(lB > lA)
        {
            printf("Case %d: B\n", j);
        }
        else if(lB == lA)
        {
            for(l = 1; l < lB; l++)
            {
                if(binaryA[l] == '0' && binaryB[l] == '1')
                {
                    printf("Case %d: B\n", j);
                    break;
                }
                else if(binaryA[l] == '1' && binaryB[l] == '0')
                {
                    printf("Case %d: A\n", j);
                    break;
                }
            }
            if(l == lB)
            {
                printf("Case %d: Same\n", j);
            }

        }

        }



    }
    return 0;
}

