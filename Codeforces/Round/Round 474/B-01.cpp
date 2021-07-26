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


using namespace std;

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    ll k1, k2;

    cin >> n >> k1 >> k2;

    k = k1 + k2;

    ll a[2000];
    ll b[2000];

    for(i = 1; i <= n; i++) slld(a[i]);

    for(i = 1; i <= n; i++) slld(b[i]);

    while(k > 0)
    {
        ll mx = -1;

        for(i = 1; i <= n; i++) mx = max(mx,abs(a[i] - b[i]));

        if(mx == 0) break;

        for(i = 1; i <= n; i++)
        {
            if(mx == abs(a[i] - b[i]))
            {
                if(a[i] > b[i])
                {
                    a[i] -= min(k,1LL);
                }
                else
                {
                    b[i] -= min(k,1LL);
                }

                k -= min(k,1LL);
            }
        }
    }

    if(k < 0) k = 0;

    ans = 0;

    for(i = 1; i <= n; i++) ans += ((a[i] - b[i]) * (a[i] - b[i]));

    if(k % 2 != 0) ans++;

    cout << ans << endl;




}

