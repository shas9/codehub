#include <stdio.h>

int main()
{
    int a, b, c, d, e, f, g, h, i, j;

    scanf("%d %d %d %d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &g, &h, &i, &j);
    //printf("Your number is %d\n and a = %d, b = %d, c = %d, d = %d, e = %d, f = %d, g = %d, h = %d, i = %d, j = %d\n", input, a, b, c, d, e, f, g, h, i, j);


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
        }
    }
    else
    {
        printf("NO\n");
    }

    return 0;

}
