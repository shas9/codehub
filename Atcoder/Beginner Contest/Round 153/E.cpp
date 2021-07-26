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

pll arr[1005];
ll h, n;
ll dp[1001][10001];

ll solve(ll pos, ll hit)
{
    if(hit <= 0) return 0;

    if(pos > n) return mxlld;

    ll &ret = dp[pos][hit];

    if(ret != -1) return ret;

    ret = 0;

    ll p1 = solve(pos + 1, hit);
    ll p2 = solve(pos, hit - arr[pos].first) + arr[pos].second;

    return ret = min(p1,p2);
}

int main()
{
    ll i, j, k, l, m, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> h >> n)
    {
        ans = 0;

        for(i = 1; i <= n; i++)
        {
            slld(arr[i].first);
            slld(arr[i].second);
        }

        memset(dp,-1,sizeof dp);

        ans = solve(1,h);

        cout << ans << endl;
    }


}


