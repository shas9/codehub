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

#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld 2e18
#define mnlld -2e18

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009

#define maxn 500005

using namespace std;

ll arr[maxn];
ll csf[maxn];
ll csr[maxn];

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    slld(n);

    ll tot = 0;
    for(i = 1; i <= n; i++)
    {
        slld(arr[i]);

        tot += arr[i];
    }

    if(tot % 3 != 0)
    {
        cout << 0 << endl;

        return 0;
    }
    m = tot / 3;

    //cout << m << endl;

    ll x = 0;
    for(i = 1; i <= n; i++)
    {
        x += arr[i];

        if(x == m) csf[i] = 1;

        //csf[i] += csf[i - 1];
    }

    x = 0;

    for(i = n; i >= 1; i--)
    {
        x += arr[i];

        if(x == m) csr[i] = 1;

        csr[i] += csr[i + 1];
    }

    ans = 0;
    for(i = 1; i <= n - 2; i++)
    {
        ans += csf[i] * csr[i + 2];
    }

    cout << ans << endl;




}

