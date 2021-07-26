#include<stdio.h>

int main()
{
    char a[200];

    scanf("%s", a);

    int i, ln, j;

    for(ln = 0; a[ln] != '\0'; ln++);

    for(i = 0; i < ln; i++)
    {
        if(a[i] >= 'A' && a[i] <= 'Z')
        {
            a[i] = a[i] + 32;
        }
    }
    //printf("DBUG !! %s\n", a);

    for(i = 0; i < 200; i++)
    {
        if((a[i] == 'a') || (a[i] == 'e') || (a[i] == 'i') || (a[i] == 'o') || (a[i] == 'u') || (a[i] == 'y'))
        {
            for(j = i; j < 200; j++)
            {
                a[j] = a[j + 1];
            }
            if((a[i] == 'a') || (a[i] == 'e') || (a[i] == 'i') || (a[i] == 'o') || (a[i] == 'u') || (a[i] == 'y'))
            {
                i = i - 1;
            }
        }
        /*else
        {
            for(j = i + 1; j < 200; j++)
            {
                a[j] = a[j - 1];
            }
            a[i] = '.';
        }*/
    }

    //printf("DBUG !!! %s\n", a);

    int lnb;

    for(lnb = 0; a[lnb] != '\0'; lnb++);

    /*for(i = 0; i < lnb; i = i + 1)
    {
        for(j = 200; j >= i; j--)
        {
            a[j] = a[j - 1];
            lnb = lnb + 1;
        }
        a[i] = '.';
    }*/

    /*int lnb;

    for(lnb = 0; a[lnb] != '\0'; lnb++);

    for(i = 0; i < lnb; i++)
    {
        printf("%c", a[i]);
    }
    printf("\n");*/

    for(i = 0; i < lnb; i = i + 2)
    {
        for(j = lnb; j > i; j--)
        {
            a[j] = a[j - 1];
        }
        lnb = lnb + 1;
        a[i] = '.';

    }

    for(i = 0; i < lnb; i++)
    {
        printf("%c", a[i]);
    }
    printf("\n");
    return 0;
}
