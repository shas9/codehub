#include <stdio.h>

int main()
{
    int i, j, k;

    char inst;

    int testcase, l;

    scanf("%d", &testcase);

    for(k = 1; k <= testcase; k++)
    {
        char initial[200];
        char back[200];
        char current[200] = "http://www.lightoj.com/";
        char store[200]  = "http://www.lightoj.com/";

        int lnlo;

        for(lnlo = 0; current[lnlo] != '\0'; lnlo++);
        char forward[200];
        char maxfor[200];

        char c[10];

        initial[0] = '\0';
        back[0] = '\0';
        forward[0] = '\0';
        maxfor[0] = '\0';
        printf("Case %d:\n", k);
        while(1)
        {
            scanf("%s", c);

            if(c[0] == 'Q')
            {
                break;
            }
            if(c[0] == 'V')
            {
                if(back[0] != '\0')
                {
                    for(i = 0; i < 60; i++)
                    {
                        initial[i] = back[i];
                    }
                }

                for(i = 0; i < 60; i++)
                {
                    back[i] = current[i];
                }

                scanf("%s", current);
                printf("%s\n", current);
            }
            else if(c[0] == 'B')
            {
                if(back[0] == '\0')
                {
                    for(j = 0; j < lnlo; j++)
                    {
                        if(current[j] != store[j])
                        {
                            break;
                        }
                    }
                    if((j != lnlo) && (l != 103))
                    {
                        printf("%s", store);
                        l = 103;
                    }
                    else
                    {
                        printf("Ignored\n");
                    }

                }
                else
                {
                    for(i = 0; i < 60; i++)
                    {
                        maxfor[i] = forward[i];
                    }
                    for(i = 0; i < 60; i++)
                    {
                        forward[i] = current[i];
                    }
                    for(i = 0; i < 60; i++)
                    {
                        current[i] = back[i];
                    }
                    if(initial[0] != '\0')
                    {
                        for(i = 0; i < 60; i++)
                        {
                            back[i] = initial[i];
                        }
                        initial[0] = '\0';
                    }
                    else
                    {
                        back[0] = '\0';
                    }
                    printf("%s\n", current);
                }


            }
            else if(c[0] == 'F')
            {
                if(forward[0] == '\0')
                {
                    printf("Ignored\n");
                }
                else
                {
                    for(i = 0; i < 60; i++)
                    {
                        initial[i] = back[i];
                    }
                    for(i = 0; i < 60; i++)
                    {
                        back[i] = current[i];
                    }
                    for(i = 0; i < 60; i++)
                    {
                        current[i] = forward[i];
                    }
                    for(i = 0; i < 60; i++)
                    {
                        forward[i] = maxfor[i];
                    }
                    maxfor[0] = '\0';
                    printf("%s\n", current);
                }
            }
        }
    }



    return 0;
}
