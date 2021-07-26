#include<stdio.h>

int main()
{
    int rose;

    int i, j;
    int sum = 0, position = 0, great = 0, count = 0;


    read:
    while(scanf("%d", &rose)!= EOF)
    {
        count = count + 1;
        for(i = 2; i < rose; i++)
        {
            if(rose % i == 0)
            {
                goto read;
            }
        }
        sum = (rose * (rose+1)) / 2;
        if((sum > great) && (sum % 2 == 0))
        {
            great = sum;
            position = count;
        }

    }
    if(position == 0)
        {
            printf("No marriage\n");
        }
        else
        {
            printf("%d\n", position);
        }

    return 0;
}
