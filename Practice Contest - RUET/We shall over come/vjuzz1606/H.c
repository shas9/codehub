#include<stdio.h>

int main()
{
    int number;
    scanf("%d", &number);

    number = (number + number);

    char slogan[number][200];

    int i;

    for(i = 0; i < number; i++)
    {
        scanf(" %[^\n]s", slogan[i]);
    }

    int testcase;

    scanf("%d", &testcase);

    int ln, j, k;
    char input[200];

    for(i = 0; i < testcase; i++)
    {
        scanf(" %[^\n]s", input);
        for(ln = 0; input[ln] != '\0'; ln++);

        for(j = 0; j < number; j=j+2)
        {
            for(k = 0; k < ln; k++)
            {
                if(input[k] != slogan[j][k])
                {
                    break;
                }
            }
            if(k == ln)
            {
                break;
            }
        }

        for(ln = 0; slogan[j+1][ln] != '\0'; ln++);

        for(k = 0; k < ln; k++)
        {
            printf("%c", slogan[j+1][k]);
        }
        printf("\n");
    }

    return 0;
}
