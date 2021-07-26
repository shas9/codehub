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

vector < ll > motu, tomu;


void solve()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    motu.clear();
    tomu.clear();
    slld(testcase);
    slld(k);
    ll tot = 0;
    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(input);
        if(cs % 2 == 1) motu.pb(input);
        else tomu.pb(input);

        tot += input;
    }
/*

5
5 2
2 6 4 7 6

*/

    sort(motu.begin(),motu.end());
    sort(tomu.begin(),tomu.end());

    flag = 0;

    for(i = motu.size() - 1, j = 0; j < tomu.size() && i >= 0; j++, i--)
    {
        if(tomu[j] <=  motu[i]) flag++;
        else break;
    }

    //cout << flag << endl;
    k = min(k,flag);

    ans = 0;

    ll sz = motu.size();
    for(i = 0; i < (sz - k); i++) ans += motu[i];

    for(i = 0; i < k; i++) ans += tomu[i];

    //cout << tot << " " << ans << endl;

    tot = tot - ans;

    if(tot > ans) cout << "YES" << endl;
    else cout << "NO" << endl;
}
int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    slld(flag);
    while(flag--)
    {
        solve();
    }


}


