#include <stdio.h>

int main()
{
    char a[200];

    int testcase;

    int i, j, k;


    scanf("%d", &testcase);

    for(i = 1; i <= testcase; i++)
    {
        scanf("%s", a);

        for(j = 0; a[j] != '\0'; j++);

        if(j <= 10)
        {
            for(k = 0; k < j; k++)
            {
                printf("%c", a[k]);
            }
            printf("\n");
        }
        else
        {
            printf("%c%d%c\n", a[0], j - 2, a[j - 1]);
        }
    }
    return 0;
}
