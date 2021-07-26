#include <stdio.h>

int main()
{
    int t;
    unsigned long int x;

    scanf("%d", &t);

    while(t--)
    {
        scanf("%lu", &x);

        if(((x/2)*2 == x))
        {
            printf("-%lu\n", x/2);
        }
        else
        {
            printf("-%lu\n", (x/2)-1);
        }
    }
}
