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

vector < pair < ll, ll > > p;

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    ll x, y, a, b;

    cin >> x >> y >> a >> b;

    p.clear();

    for(i = max(b + 1, a); i <= x; i++)
    {
        for(j = b; j < i && j <= y; j++)
        {
            p.pb(make_pair(i,j));
        }
    }

    ll sz = p.size();
    cout << sz << endl;

    for(i = 0; i < sz; i++)
    {
        cout << p[i].first << " " << p[i].second << endl;
    }



}

