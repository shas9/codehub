#include <stdio.h>

long long int comb(int n, int r)
{
    int i;

    long long int a = 1, b = 1, c;

    long long int x, y;
    if(r < (n / 2))
    {
        x = (n - n + r) + 1;

        for(i = x; i <=n; i++)
        {
            a = a * i;
        }
        for(i = 1; i <= r; i++)
        {
            b = b * i;
        }
    }
    else
    {
        x = (n - r) + 1;
        for(i = x; i <=n; i++)
        {
            a = a * i;
        }
        for(i = 1; i <= (n - r); i++)
        {
            b = b * i;
        }
    }

    c = (a / b);

    return c;
}

int main()
{

}
