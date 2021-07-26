#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)
#define plld(longvalue) printf("%lld\n", longvalue)

#define slf(longvalue) scanf("%lf", &longvalue)
#define plf(longvalue) printf("%lf\n", longvalue)
#define sc(letter) scanf("%c", &letter)
#define pc(letter) printf("%c", letter)

#define ss(name) scanf("%s", name)
#define ps(name) printf("%s", name)

#define pnew printf("\n")

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >
#define pii pair < int, int >

#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009

using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

ll dp[5005][5005][2];
ll arr[5005];

ll solve(ll l, ll r, ll d)
{
    ll &ret = dp[l][r][d];

    if(abs(l - r) <= 1) return ret = 0;

    if(l >= r) return ret = 0;

    if(ret != -1) return ret;

    ret = 0;

    if(d == 0)
    {
        for(ll i = r - 1; i > l; i--)
        {
            if(arr[r] <= arr[i]) continue;

            ret = max(ret, solve(i,r,d^1));
        }
    }
    else
    {
        for(ll i = l + 1; i < r; i++)
        {
            if(arr[l] <= arr[i]) continue;

            ret = max(ret,solve(l,i,d^1));
        }
    }

    return ret = ret + 1;


}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    memset(dp, -1, sizeof dp);

    slld(n);

    for(i = 1; i <= n; i++)
        slld(arr[i]);

    for(i = 1; i <= n; i++)
    {
        ll mx = 0;

        for(j = 1; j <= n; j++)
        {
            ll dd;

            if(i == j) continue;

            if(arr[i] <= arr[j]) continue;

            if(i < j)
            {
                mx = max(mx,solve(i,j,0));
            }
            if(i > j)
            {
                mx = max(mx,solve(j,i,1));
            }


        }

        printf("%lld ", mx);
    }

    printf("\n");


}


