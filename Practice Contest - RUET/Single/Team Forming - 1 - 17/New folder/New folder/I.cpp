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

ll dp[5005];
ll arr[5005];

ll n;

ll solve(ll x)
{
    if(x > n) return 0;
    ll ret = 1;
    for(ll i = 1; i < x; i++)
    {
        bool on = 0, off = 0;

        if(arr[i] > 0) on = 1;
        if(arr[x] > 0) off = 1;

        if(abs(arr[i]) < abs(arr[x]))
        {
            if(!(on & off) && (on | off))
            {
                dp[x] = max(dp[i] + 1, dp[x]);
            }
        }

        ret = max(ret,dp[x]);
    }

    return max(ret, solve(x + 1));
}
int main()
{
    ll i, j, k, l, m, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    for(i = 1; i <= 5000; i++) dp[i] = 1;

    slld(n);

    for(i = 1; i <= n; i++) slld(arr[i]);

    ans = solve(1);

    cout << ans << endl;

}


