#include <stdio.h>

int main()
{
    int testcase=1000;

    int a;
     int i, j;

    double k;
    int count = 0;

    for(a = 1; a <= testcase; a++)
    {
        double c;
        int d;

    for(d = 1; d<= c; d++)
    {

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
    }


    printf("Case %d: %d\n", d, count);
    }
    return 0;
}
