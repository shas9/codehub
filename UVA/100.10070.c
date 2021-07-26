#include <stdio.h>

int main()
{
    long long int year, z;

    while(scanf("%lld", &year) != EOF)
    {
        printf("DBUG Y + %lld\n", year);
        z = 0;
        if(year % 4 == 0)
        {
            z = 1;
            if((year % 100 == 0) && (year % 400 != 0))
            {
                z = 0;
            }
            else
            {
                printf("This is leap year.\n");
                if(year % 15 == 0)
                {
                    z = 3;
                    printf("This is huluculu festival year.\n");
                }
                if(year % 55 == 0)
                {
                    printf("This is bulukulu festival year.\n");
                }
            }
        }
        if(year % 15 == 0 && z != 3)
        {
            z = 1;
            printf("This is huluculu festival year.\n");
        }
        if(z == 0)
        {
            printf("This is an ordinary year.\n");
        }
    }

    return 0;
}
