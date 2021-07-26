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

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

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

    ll tot = 0;
    ll mx = mnlld;
    ll mn = mxlld;
    cin >> n >> k;

    for(i = 1; i <= n; i++)
    {
        slld(input);
        tot += input;

        mx = max(mx,tot);
        mn = min(mn,tot);
    }

    ll a, b;

//    if(mx >= 0)
//    {
//        ans = k - mx + 1;
//
//        if(mn < 0) ans--;
//    }
//    else
//    {
//        ans = k + mn + 1;
//    }
//
//    if(mx > k || abs(mn) > k || abs(mx - mn) > k) ans = 0;
//
//    cout << ans << endl;

    if(mn < 0) a = abs(mn);
    else a = 0;

    if(mx <= 0) b = k;
    else b = k - mx;

    ans = 0;

    if(a <= b) ans = b - a + 1;

    cout << ans << endl;

}


