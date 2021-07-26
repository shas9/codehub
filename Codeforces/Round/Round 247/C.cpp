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

#define mod 1000000007



using namespace std;

int main()
{
    ll i, j, k, l, m, n, o, d;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);
    //slld(testcase);

    ll p2[200];

    p2[0] = 1;

    for(i = 1; i <= 120; i++)
    {
        p2[i] = p2[i-1] * 2;
        p2[i] %= mod;
    }

    cin >> n >> k >> d;

    ans = 0;

    for(i = d; i <= k && i <= n; i++)
    {
        ans += p2[n - i];

        //cout << ans << " " << n - d << " " << p2[n - d] << endl;

        ans %= mod;
    }

    cout << ans << endl;


}


