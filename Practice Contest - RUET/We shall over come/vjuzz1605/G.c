#include <stdio.h>

int abs(int x)
{
    int y;

    if(x < 0)
    {
        y = - x;
    }
    else if(x == 0 || x > 0)
    {
        y = x;
    }

    return y;
}

int main()
{
    int num[2000];

    int n;

    int r, res, res1;

    int i, min, ln;

    int a, b, c, d, neg;
    while(1)
    {
        neg = 1;
        ln = 0;
        for(i = 0; i < 2000; i++, ln++)
        {
            scanf("%d", &n);

            if(n > 0)
            {
                neg = 0;
            }

            num[i] = n;

            if(num[0] == 0)
            {
                return 0;
            }

            if(n == 0)
            {
                break;
            }
        }

        min = abs(num[0]);

        for(i = 1; i < ln; i++)
        {
            if(min > abs(num[i]))
            {
                min = abs(num[i]);
            }
        }

        /*if(neg == 1)
        {
            for(i = 1; i < ln; i++)
            {
                if(min < abs(num[i]))
                {
                    min = abs(num[i]);
                }
            }

            for(r = 2; r <= min; r++)
        }*/

        r = 0;

        for(r = 2; r <= min; r++)
        {
               if(num[0] < 0)
               {
                   d = num[0];
                   a = - d;

                   b = a / r;
                   c = b + 1;

                   res = (c * r) - a;

               }
               else
               {
                   res = num[0] % r;
               }
           for(i = 1; i < ln; i++)
           {
               if(num[i] < 0)
               {
                   d = num[i];
                   a = - d;

                   b = a / r;
                   c = b + 1;

                   res1 = (c * r) - a;
               }
               else
               {
                   res1 = num[i] % r;
               }

               if(res != res1)
               {
                   break;
               }

           }
           if(i == ln)
           {
               break;
           }
        }

        if(i == ln)
        {
            printf("%d\n", r);
        }
        else
        {
            printf("1\n");
        }
    }
}
