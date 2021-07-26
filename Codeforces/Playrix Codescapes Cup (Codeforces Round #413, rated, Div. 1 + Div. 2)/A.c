#include<stdio.h>

int main()
{
    int n, t, k, d;

    //read:

    scanf("%d%d%d%d", &n, &t, &k, &d);

    int flag = 0;
    int time = 0;

    if(n <= k)
    {
        printf("NO\n");
        return 0;
    }

    while(n > flag)
    {
        time = time + t;
        flag = flag + k;
    }

    int build;

    build = t + d;

    if(build < time)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
    //goto read;

    return 0;
}
