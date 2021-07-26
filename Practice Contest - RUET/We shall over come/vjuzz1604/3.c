#include <stdio.h>

int main()
{



int n, h;

scanf("%d%d", &n, &h);

int i, j;

int res = 0;

for(i = 1; i <=n; i++)
{
    scanf("%d", &j);

    if(j > h)
    {
        res = res + 2;
    }

    else if(j <= h)
    {
        res = res + 1;
    }
}

printf("%d\n", res);

return 0;
}

