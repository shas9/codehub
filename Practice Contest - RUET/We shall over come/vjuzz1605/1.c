#include <stdio.h>

int main()
{
    int n;

    scanf("%d", &n);

    int i;

    long long int res = 2, resf = 2;

    for(i = 2; i <= n; i++)
    {
        res = res * 2;
        //printf("DBUG RES = %lld, resf = %lld\n", res, resf);
        resf = resf + res;
        //printf("DBUG RESf = %lld\n",resf);
    }

    printf("%lld\n", resf);

    return 0;
}
