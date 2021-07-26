#include<cstdio>

int main()
{
    int n, sum;
    while (scanf("%d", &n))
    {
        sum = n;
        while (n > 2)
        {
            sum = sum + (n / 3);
            n = n - ((n / 3) * 2);
        }
        if (n == 2) ++sum;
        printf("%d\n", sum);
    }
    return 0;
}
