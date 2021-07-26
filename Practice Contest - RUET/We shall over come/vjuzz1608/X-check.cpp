#include <stdio.h>
#include <ctime>
#include <math.h>
#include <limits.h>
#include <complex>
#include <string>
#include <functional>
#include <iterator>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <bitset>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <ctime>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>

using namespace std;

int a[1010];
int t;
int n, k;
int tmp;
int sum[1010];
int ans;
int g[1010];

int is_ok(int x)
{
    int res;
    int num = 0;
    int pos = 0;

    for (int i = 1; i <= n; i++)
        if (sum[i] - sum[i - 1] > x) return 0;

    for (int i = 1; i <= n; i++)
    {
        if (sum[i] -sum[pos] == x  || (i == n && sum[i] -sum[pos] <= x) || (i != n && sum[i+1] - sum[pos] > x))
        {
            if (i != n) num++;
            pos = i;
        }
    }
    if (num <= k) return 1;
    else return 0;
}

void get_ans()
{
    int res;
    int now = 1;

    int remain = n - k -1;
    while (now <= n)
    {
        int pos = now - 1;
        int tmp = sum[now] - sum[now-1];
        now++;
        if (remain != 0)
        {
            for (; now <= n; now++)
            {
                if (sum[now] - sum[pos] <= ans)
                    tmp = sum[now] - sum[pos], remain --;
                else
                {
                    printf("%d\n",tmp);
                    break;
                }
            }
            if (remain == 0)
            {
                printf("%d\n",tmp);
                now++;
                break;
            }

        }
        else
        {
            printf("%d\n", tmp);
        }

    }
}

int main()
{
    scanf("%d",&t);
    int cases = 1;
    while (t--)
    {
        scanf("%d%d", &n, &k);
        n++;

        int tot = 0;
        memset(sum,0,sizeof(sum));

        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            sum[i] = sum[i - 1] + a[i];
            tot += a[i];
        }

        int left = 1;
        int right = tot;
        int mid;

        while (left <= right)
        {
            mid = (left + right) / 2;
            if (is_ok(mid))
            {
                ans = mid;
                right = mid - 1;
            }
            else
                left = mid + 1;
        }

        printf("Case %d: ", cases++);
        printf("%d\n", ans);
        get_ans();
    }
    return 0;
}
