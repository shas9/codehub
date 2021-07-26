#include <stdio.h>

int main()
{
    char x[200];

    //read:

    scanf("%s", x);

    int ln;

    int i, j, k;

    for(ln = 0; x[ln] != '\0'; ln++);

    for(i = 0; i < ln; i++)
    {
        //printf("DBUG i = %d\n", i);
        if(x[i] == '0')
        {
           k = i + 7;
           if(k <= ln)
           {
               //printf("DBUG k = %d\n", k);
               for(j = i; j < k; j++)
               {
                   //printf("DBUG j = %d\n", j);
                   if(x[j]== '1')
                   {
                       //printf("DBUG x[j] = %d\n", j);
                       break;
                   }
               }
               if(j == k)
               {
                   printf("YES\n");
                   break;
               }
            }

        }
        else if(x[i] == '1')
        {
           k = i + 7;
           if(k <= ln)
           {
               //printf("DBUG k = %d\n", k);
               for(j = i; j < k; j++)
               {
                   //printf("DBUG j = %d\n", j);
                   if(x[j]== '0')
                   {
                       //printf("DBUG x[j] = %d\n", j);
                       break;
                   }
               }
               if(j == k)
               {
                   printf("YES\n");
                   break;
               }
            }

        }

    }
    if(i == ln)
    {
        printf("NO\n");
    }

    //goto read;

    return 0;
}
