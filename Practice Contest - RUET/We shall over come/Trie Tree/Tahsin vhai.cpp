#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define LL long long
#define sl(n) scanf("%lld", &n)
#define sf(n) scanf("%lf", &n)
#define si(n) scanf("%d", &n)
#define sch(n) scanf(" %c", &n)
#define ss(n) scanf("%s", n)
#define pii pair <int, int>
#define pll pair <ll, ll>
#define plp pair <int, pll >
#define pb push_back
#define fr first
#define sc second
#define all(a)  a.begin(),a.end()
#define Unique(a)  sort(all(a)),a.erase(unique(all(a)),a.end())

#define inf (1LL<<50)
#define eps 1e-9

char s[20];

ll dp[20][2][2][2][20];

ll solve(ll pos, bool isSmall, bool isBig2, bool isStarted, ll right)
{
    if (pos > right)
    {
        return (isSmall || !isBig2 || !isStarted);
    }

    ll &ret = dp[pos][isSmall][isBig2][isStarted][right];

    if (ret != -1)
        return ret;

    ret = 0;

    ll hi = 9;
    if (!isSmall)
        hi = s[pos] - '0';

    for (ll i = 0; i <= hi; i++)
    {
        if (isStarted|i)
        {
            ret += solve(pos + 1, i < hi?1:isSmall, (i > s[right]-'0')?1:isBig2, i?1:isStarted, right-1);
        }
        else ret += solve(pos+1, i < hi?1:isSmall, isBig2, isStarted, right);
    }

    return ret;
}

int main ()
{
    //  freopen("inl.txt", "r", stdin);
    // freopen("outu.txt", "w", stdout);
    //  ios_base::sync_with_stdio(0); // no printf/scanf must be present
    ll cs, ts, i, j, k, x, y, z, q, m, n;

    sl(ts);

    for (cs = 1; cs <= ts; cs++)
    {
        sl(x);
        sl(y);

        if (x > y) swap(x, y);

        n = y;
        for (i = 0; i <= 18; i++)
        {
            s[18-i] = n%10;
            n /= 10;
        }
        memset(dp, -1, sizeof(dp));
        z = solve(0, 0, 0, 0, 18);

        if (x)
        {
            n = x-1;
            for (i = 0; i <= 18; i++)
            {
                s[18-i] = n%10;
                n /= 10;
            }
            memset(dp, -1, sizeof(dp));
            z -= solve(0, 0, 0, 0, 18);
        }

        printf("Case %lld: %lld\n", cs, z);
    }

    return 0;
}
