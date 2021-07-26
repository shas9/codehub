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
	return n & (1 << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1 << pos);
}

ll arr[2000];
ll a, b, c, t, n;

int main()
{
    ll i, j, k, l, m, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    slld(n);

    cin >> a >> b >> c >> t;

    for(i = 1; i <= n; i++) slld(arr[i]);

    ll mx = mnlld;

    ans = 0;
    if((c - b) <= 0)
    {
        ans = n * a;
    }
    else
    {
        for(i = 1; i <= n; i++)
        {
            ans += (t - arr[i]) * c;
        }

        for(i = 1; i <= n; i++)
        {
            ans += a - ((t - arr[i]) * b);
        }
    }

    cout << ans << endl;


}

