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

#define mod 998244353


using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

ll nCr(ll n, ll k )
{
//    cout << n << " !! " << k <<endl;
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;

//    ll result = n;
//    for( int i = 2; i <= k; ++i ) {
//        result *= (n-i+1);
//        result /= i;
//    }
//
//    return result;

    ll x = 1, y = 1;

    for(ll i = n - k + 1; i <= n; i++) x *= i, x %= mod;
    for(ll i = 1; i <= k; i++) y *= i, y %= mod;

    return (x / y) % mod;
}


ll solve(ll n, ll m, ll i)
{
    ll lft = nCr(m - 2, i - 2) * nCr(m - i, n - i - 1);

//    cout << nCr(m - 1, i - 2) << " " << nCr(m - 1 - i - 2, n - i) << endl;

    return lft * (m - n + 2) % mod;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m)
    {
        ans = 0;
        for(i = 2; i < n; i++)
        {
            ans += solve(n,m,i);
            ans %= mod;
        }

        cout << ans << endl;
    }


}



