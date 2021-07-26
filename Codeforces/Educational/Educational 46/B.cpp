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

ll m, n;
ll arr[200000];

ll precalc[200000];

int main()
{
    ll i, j, k, l, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    slld(n);
    slld(m);

    arr[0] = 0;
    for(i = 1; i <= n; i++)
    {
        slld(arr[i]);
    }

    arr[n + 1] = m;
    for(i = 2; i <= n + 1; i += 2)
    {
        precalc[i - 1] = arr[i] - arr[i - 1];
    }

    for(i = n; i >= 1; i--)

    ll mx = 0;

    ll sum = 0;
    for(i = 1; i <= n; i++)
    {
        sum += arr[i] - 1
    }




}


