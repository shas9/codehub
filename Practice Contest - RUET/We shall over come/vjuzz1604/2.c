#include <stdio.h>

int main()
{
    int a, b, c, d, e;

    scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);

    int r;

    r = a + b + c + d + e;

    if(r == 0)
    {
        printf("-1\n");
    }
    else if(r % 5 == 0)
    {
        printf("%d\n", r / 5);
    }
    else
    {
        printf("-1\n");
    }

    return 0;
}
