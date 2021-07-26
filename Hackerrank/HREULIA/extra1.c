#include <stdio.h>

int main()
{
    int testcase;

    scanf("%d", &testcase);

    int a;
    for(a = 1; a <= testcase; a++)
    {
        double c;

    scanf("%lf", &c);

    int i, j;

    double k;
    int count = 0;

    for(i = 1; i <= c; i++)
    {
        for(j = 1; j <= c; j++)
        {
            k = sqrt((i * i) + (j * j));
            if(k == c)
            {
                count = count + 1;
            }
        }
    }
    printf("Case %d: %d\n", a, count);
    }
    return 0;
}
