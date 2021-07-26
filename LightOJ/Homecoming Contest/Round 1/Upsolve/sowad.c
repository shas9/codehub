#include <stdio.h>

int main()
{
    int val;

    int invalid = 1;

    do
    {
        printf("Please provide an integer value greater than 1: ");
        scanf("%d", &val);

        if(val <= 1)
        {
            printf("ERROR! %d is not greated than 1.\n", val);
        }
        else
        {
            invalid = 0;

            int now = 1;

            printf("All cube integers between 1 and %d are:\n", val);

            while(now * now * now <= val)
            {
                if(now > 1) printf(", ");
                printf("%d", now * now * now);
                now++;
            }

            printf("\n");
        }
    }
    while(invalid);

    return 0;

}
