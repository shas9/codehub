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

#define mod 1000000007


using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

ll arr[2005];
ll kcr[2005];

ll power(ll x, ll y, ll p)
{
    ll res = 1;      // Initialize result

    x = x % p;  // Update x if it is more than or
                // equal to p

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;

        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}

ll nCr(ll n, ll k )
{


    ll x = 1, y = 1;

    for(ll i = n - k + 1; i <= n; i++) x *= i, x %= mod;
    for(ll i = 1; i <= k; i++) y *= i, y %= mod;

    return (x * power(y,mod - 2, mod)) % mod;
}


ll ans[2005];
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag;

    // freopen("in.txt", "r", stdin);

    slld(n);
    slld(k);

    for(i = 1; i <= n; i++) slld(arr[i]);
    if(k == 0)
    {
        for(i = 1; i <= n; i++) cout << arr[i] << " ";
        cout << endl;

        return 0;
    }

    for(i = 1, j = k - 1; i <= n; i++, j++) kcr[i] = nCr(j,i - 1);

    for(i = 1; i <= n; i++)
    {
        ans[i] = 0;
        for(j = i, m = 1; j >= 1; j--, m++)
        {
            ans[i] += arr[m] * kcr[j];
            ans[i] %= mod;
        }
    }

    for(i = 1; i <= n; i++) cout << ans[i] << " ";

    cout << endl;


}


