#include <stdio.h>
#include <math.h>

int main()
{
    int a, b;
    double r;
    int input;
    int i, sum;
    int number;

    int h, k;

    int habla = 0, kebla = 0;

    while(scanf("%lf", &r)!= EOF)
    {
        scanf("%d%d", &a, &b);

        sum = 0;

        //printf("%lf\n%d\n%d", r, a, b);

        input = (r - 1) * 5;

        for(i = 1; i <= input; i++)
        {
            sum = sum + i;
            if(sum == input)
            {
                number = i;
                break;
            }
        }

        h = abs(number - a);
        k = abs(number - b);

        if(h < k)
        {
            habla = habla + 1;
        }
        else if(k < h)
        {
            kebla = kebla + 1;
        }
    }

    if(habla > kebla)
    {
        printf("Huhaha\n");
    }
    else if(kebla > habla)
    {
        printf("Opss\n");
    }
    else if(kebla == habla)
    {
        printf("aha\n");
    }

    return 0;
}
