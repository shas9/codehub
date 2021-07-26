#include <stdio.h>

int main()
{
    int r = 0;

    int r1 = 0;

    int ln;

    char x[200];

    scanf("%s", x);

    for(ln = 0; x[ln] != '\0'; ln++);
    //printf("DBUG 1 ln = %d\n", ln);

    int i, j;

    if(ln == 1)
    {
        if((x[0] == 'A') || (x[0] == 'E') || (x[0] == 'I') || (x[0] == 'O') || (x[0] == 'U') || (x[0] == 'Y'))
        {
            r1 = 1;
            printf("%d\n", r1);
            return 0;
        }
        else
        {
            r1 = 2;
            printf("%d\n", r1);
            return 0;

        }
    }


    for(i = 0; i < ln; i++)
    {
        r = 0;
        //printf("i = %d\n", i);
        r = r + 1;
        if(r1 < r)
        {
            r1 = r;
            //printf("DBUG 1 : r1 = %d\n", r1);
        }
        if((x[i] == 'A') || (x[i] == 'E') || (x[i] == 'I') || (x[i] == 'O') || (x[i] == 'U') || (x[i] == 'Y'))
        {
            r = 0;
            //printf("x[i] = %c\n", x[i]);
            //i = i + 1;
            for(j = i + 1; j < ln; j++)
            {
                r = r + 1;
                //printf("j = %d\n", j);

                //printf("r = %d\n", r);
                if(r1 < r)
                {
                    r1 = r;
                    //printf("r1 = %d\n", r1);
                }
                if((x[j] == 'A') || (x[j] == 'E') || (x[j] == 'I') || (x[j] == 'O') || (x[j] == 'U') || (x[j] == 'Y'))
                {
                    //printf("x[j] = %c\n", x[j]);
                    /*if(r1 < r)
                    {
                        r1 = r;
                    }*/
                    r = 0;
                    //i = j - 1;
                    break;
                }
            }
        }
    }
    if(r1 == 0)
    {
        r1 = ln + 1;
    }

    printf("%d\n", r1);
    return 0;
}
