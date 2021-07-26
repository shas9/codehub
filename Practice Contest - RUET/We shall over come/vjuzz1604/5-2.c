#include <stdio.h>

int main()
{
    char x[200];

    scanf("%s", x);

    int i, ln, r, rf = 0, j = 0;

    for(ln = 0; x[ln] != '\0'; ln++);

    if(ln == 1)
    {
        if((x[0] == 'A') || (x[0] == 'E') || (x[0] == 'I') || (x[0] == 'O') || (x[0] == 'U') || (x[0] == 'Y'))
        {
            rf = 1;
            printf("%d\n", rf);
            return 0;
        }
        else
        {
            rf = 2;
            printf("%d\n", rf);
            return 0;
        }
    }
else
{
    r = 0;
    for(i = 0; i < ln; i++)
    {

        r = r + 1;
        if(rf <= r)
        {
            rf = r;
        }
        //printf("i = %d, r = %d, rf = %d, x[i] = %c\n", i, r, rf, x[i]);
        if((x[i] == 'A') || (x[i] == 'E') || (x[i] == 'I') || (x[i] == 'O') || (x[i] == 'U') || (x[i] == 'Y'))
        {
            r = 0;
            r = r + 1;
            if(rf <= r)
            {
                rf = r;
            }
            //printf("i = %d, r = %d, rf = %d, x[i] = %c\n", i, r, rf, x[i]);
            for(j = i + 1; j < ln; j++)
            {
                if((x[j] == 'A') || (x[j] == 'E') || (x[j] == 'I') || (x[j] == 'O') || (x[j] == 'U') || (x[j] == 'Y'))
                {
                    r = 0;
                    break;
                }
                r = r + 1;
                if(rf <= r)
                {
                    rf = r;
                }
                //printf("j = %d, r = %d, rf = %dx[j] = %c\n", j, r, rf, x[j]);
                i = j;
            }
        }
    }
    if(j == 0)
    {
        rf = rf + 1;
    }
    printf("%d\n", rf);

}

    return 0;

}
