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
ll dp[105][205][205];
pll arr[105];
ll n;

ll solve(ll pos, ll ver, ll hor)
{
    if(hor >= 200) return mxlld;

    if(pos == n)
    {
        if(hor > ver) return mxlld;
        return ver;
    }

    ll &res = dp[pos][ver][hor];

    if(res != -1) return res;

    res = 0;

    res = min(solve(pos + 1, ver, hor + arr[pos + 1].second), solve(pos + 1, ver + arr[pos + 1].first, hor));

    return res;

}

int main()
{
    ll i, j, k, l, m, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);
    slld(testcase);

    n = testcase;

    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(arr[cs].first);
        slld(arr[cs].second);
    }

    memset(dp,-1,sizeof dp);

    ans = solve(0,0,0);

    cout << ans << endl;



}


