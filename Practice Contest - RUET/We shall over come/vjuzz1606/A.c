#include<stdio.h>

int main()
{
    char input[100000];
    int i,ln,j;

    while(scanf("%s", input) != EOF)
    {
        for(ln = 0; input[ln] != '\0'; ln++);

        for(i = ln - 1; i >= 0; i--)
        {
            if(input[i] == '[')
            {
                input[i] = ' ';
                j = i + 1;
                while(1)
                {
                    if((input[j] == ']')|| (input[j] == '\0')||(input[j] == ' '))
                    {
                        break;
                    }

                    printf("%c",input[j]);
                    input[j] = ' ';

                    j++;

                }

            }
        }

        for(i = 0; i < ln; i++)
        {
            if(input[i] == ']')
            {
                input[i] = ' ';
            }
        }


        for(i = 0; i < ln; i++)
        {
            if(input[i] != ' ')
            {
                printf("%c",input[i]);
            }
        }

        printf("\n");

    }

    return 0;
}


