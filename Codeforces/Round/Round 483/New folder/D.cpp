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

map < ll, ll > xy;
map < pair < ll, ll >, ll > same;

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    xy.clear();
    same.clear();

    ll a, b;

    cin >> n >> a >> b;

    ll x, vx, y, vy;

    for(i = 1, ans = 0; i <= n; i++)
    {
        cin >> x >> vx >> vy;

        ll eq = (a * vx) - vy;

        ans += xy[eq];
        ans -= same[make_pair(vx,vy)];;

        xy[eq]++;
        same[make_pair(vx,vy)]++;
    }

    cout << ans * 2 << endl;


}


