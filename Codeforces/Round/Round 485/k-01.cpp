#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%d", &longvalue)
#define plld(longvalue) printf("%lld\n", longvalue)

#define slf(longvalue) scanf("%lf", &longvalue)
#define plf(longvalue) printf("%lf\n", longvalue)
#define sc(letter) scanf("%c", &letter)
#define pc(letter) printf("%c", letter)

#define ss(name) scanf("%s", name)
#define ps(name) printf("%s", name)

#define pnew printf("\n")

#define ll int

#define printcase(indexing,ans) printf("Case %d: %d\n", indexing, ans)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009

#define N 16
using namespace std;

ll n;

bool check(ll a, ll pos)
{
	return a & (1 << pos);
}

ll Set(ll a, ll pos)
{
	return a = a | (1 << pos);
}

ll x[20];
ll y[20];
ll mask[N + 3][N + 3];
ll dp[1 << N + 2];

bool col(ll i, ll j, ll k)
{
    int x1 = x[i];
	int y1 = y[i];

	int x2 = x[j];
	int y2 = y[j];

	int x3 = x[k];
	int y3 = y[k];

	return (y2 - y1) * (x3 - x2) == (x2 - x1) * (y3 - y2);
}

ll solve(ll st)
{
    ll cnt = 0;
    ll temp;
    ll mn = 2e8;

    ll i, j;

    if(dp[st] != -1) return dp[st];

    for(i = 1; i <= n; i++)
    {
        if(check(st,i)) cnt++;
    }

    if(cnt == (n - 1)) return 1;
    if(cnt == n) return 0;


    for(i = 1; i <= n; i++)
    {
        if(check(st,i) == 0)
        {
            for(j = i + 1; j <= n; j++)
            {
                if(check(st,j) == 0)
                {
                    temp = Set(st,i);
                    temp = Set(temp,j);

                    temp |= mask[i][j];

                    mn = min(mn, solve(temp));
                }
            }
            break;
        }
    }

    return dp[st] = 1 + mn;


}


int main()
{
    ll i, j, k;
    ll testcase;
    ll ans;

    // freopen("in.txt", "r", stdin);
    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(n);

        for(i = 1; i <= n; i++)
        {
            slld(x[i]);
            slld(y[i]);
        }

        memset(mask,0,sizeof mask);
        memset(dp, -1, sizeof dp);

        for(i = 1; i <= n; i++)
        {
            for(j = i + 1; j <= n; j++)
            {

                for(k = 1; k <= n; k++)
                {
                    if(i == k || j == k) continue;

                    if(col(i,j,k))
                    {
                        mask[i][j] |= (1 << k);
                        mask[j][i] |= (1 << k);
                    }
                }
            }
        }

        ans = solve(0);

        printf("Case %d: %d\n", cs, ans);
    }


}

