#include<stdio.h>

int main()
{
    int testcase;
    scanf("%d", &testcase);

    int i, j;
    char back2[60];
    char back1[60];
    char forward1[60];
    char forward2[60];

    char input[10];
    int flag;

    for(i = 1; i <= testcase; i++)
    {

        char current[60] = "http://www.lightoj.com/";


        back2[0] = '\0';
        back1[0] = '\0';
        forward1[0] = '\0';
        forward2[0] = '\0';



        printf("Case %d:\n", i);

        while(1)
        {
            scanf("%s", input);
            flag = 0;

            if(input[0] == 'Q')
            {
                break;
            }
            else if(input[0] == 'V')
            {
                flag = 1;
                for(j = 0; j < 60; j++)
                {
                    back2[j] = back1[j];
                }
                for(j = 0; j < 60; j++)
                {
                    back1[j] = current[j];
                }

                scanf("%s", current);
                printf("%s\n", current);
                forward1[0] = '\0';
                forward2[0] = '\0';
            }
            else if(input[0] == 'B')
            {
                if(back1[0] == '\0')
                {
                    printf("Ignored\n");
                    flag = 1;
                }
                else
                {
                    for(j = 0; j < 60; j++)
                    {
                        forward2[j] = forward1[j];
                    }
                    for(j = 0; j < 60; j++)
                    {
                        forward1[j] = current[j];
                    }
                    for(j = 0; j < 60; j++)
                    {
                        current[j] = back1[j];
                    }
                    for(j = 0; j < 60; j++)
                    {
                        back1[j] = back2[j];
                    }

                    back2[0] = '\0';
                }

            }
            else if(input[0] == 'F')
            {
                if(forward1[0] == '\0')
                {
                    printf("Ignored\n");
                    flag = 1;
                }
                else
                {
                    for(j = 0; j < 60; j++)
                    {
                        back2[j] = back1[j];
                    }
                    for(j = 0; j < 60; j++)
                    {
                        back1[j] = current[j];
                    }
                    for(j = 0; j < 60; j++)
                    {
                        current[j] = forward1[j];
                    }
                    for(j = 0; j < 60; j++)
                    {
                        forward1[j] = forward2[j];
                    }
                    forward2[0] = '\0';
                }
            }

            if(flag == 0)
            {
                printf("%s\n", current);
            }
        }
    }

    return 0;
}
