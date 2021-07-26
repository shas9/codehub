#include <stdio.h>

int main()
{
    int testcase;

    int x;

    int a, b, c, d, e, f, g, h, i, j;

    scanf("%d", &testcase);

    for(x = 1; x <= testcase; x++)
    {
    scanf("%d %d %d %d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &g, &h, &i, &j);

    if (a == 1)
    {
        if(b == 1)
        {
            if(c == 1)
            {
                if(g == 1 || j == 1)
                {
                    printf("YES\n");
                }
                else
                {
                    printf("NO\n");
                }
            }
            else
            {
                 if(d == 1)
        {
            if(e == 1 || h == 1)
            {
                if(f == 1 || i == 1)
                {
                    if(g == 1 || j == 1)
                    {
                        printf("YES\n");
                    }
                    else
                    {
                        printf("NO\n");
                    }
                }
                else
                {
                    printf("NO\n");
                }
            }
            else
            {
                printf("NO\n");
            }
        }
        else
            {
                printf("NO\n");
            }
            }
        }

        else
        {
             if(d == 1)
        {
            if(e == 1 || h == 1)
            {
                if(f == 1 || i == 1)
                {
                    if(g == 1 || j == 1)
                    {
                        printf("YES\n");
                    }
                    else
                    {
                        printf("NO\n");
                    }
                }
                else
                {
                    printf("NO\n");
                }
            }
            else
            {
                printf("NO\n");
            }
        }
        else
            {
                printf("NO\n");
            }
        }
    }
    else
    {
        printf("NO\n");
    }
    }

    return 0;
}
