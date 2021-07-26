#include <stdio.h>

int main()
{
    char binaryA[6000];
    char binaryB[6000];

    int testcase;

    scanf("%d", &testcase);

    int i, j;

    for(j = 1; j <= testcase; j++)
    {
        scanf("%s", binaryA);
        scanf("%s", binaryB);
        for(i = 0; i < 6000; i++)
        {
            if(binaryA[i] == 1)
            {
                break;
            }
            else
            {
                for(j = 0; j < 5000; j++)
                {
                    binaryA[j] = binaryA[j + 1];
                }
            }
        }
        for(i = 0; i < 6000; i++)
        {
            if(binaryB[i] == 1)
            {
                break;
            }
            else
            {
                for(j = 0; j < 5000; j++)
                {
                    binaryB[j] = binaryA[j + 1];
                }
            }
         }
         printf("%c\n\n%c", binaryA[1], binaryB[3]);

    }
}
