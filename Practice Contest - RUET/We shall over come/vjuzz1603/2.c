#include <stdio.h>

int main()
{
    int w;

    scanf("%d", &w);

    int x;

    x = w % 2;

    if(x == 0 && w >= 4)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }

    return 0;

}
