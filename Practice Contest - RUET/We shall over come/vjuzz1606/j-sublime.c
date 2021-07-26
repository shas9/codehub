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

            if(input[0] == 'Q')
            {
                break;
            }

            if(input[0] == 'V')
            {
                for(j = 0; j < 60; j++)
                {
                    back2[j] = back1[j];
                }
                for(j = 0; j < 60; j++)
                {
                    back1[j] = current[j];
                }

                scanf("%s", current);

                forward1[0] = '\0';
                forward2[0] = '\0';
            }
            else if(input[0] == 'B')
            {
                if(back1[0] == '\0')
                {
                    printf("Ignored\n");
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

                    printf("%s\n", current);
                }

            }
            else if(input[0] == 'F')
            {
                if(forward1[0] == '\0')
                {
                    printf("Ignored\n");
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

                    printf("%s\n", current);
                }
            }
        }
    }

    return 0;
}
