#include <stdio.h>

int main()
{
    int n;

    scanf("%d", &n);

    if(n == 1) printf("PAGOL\n");
    else if(n == 2) printf("CHAGOL\n");
    else printf("Kisui na\n");

    switch(n)
    {
        case 1:
        {
            printf("Ek chapsen bhai\n");
            break;
        }
        case 2:
        {
            printf("Dui Chapsen bhai\n");
            break;
        }
        default:
        {
            printf("Eita ki chapsen bhai?\n");
        }
    }
}
