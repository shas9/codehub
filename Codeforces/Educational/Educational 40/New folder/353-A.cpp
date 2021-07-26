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

vector < pair< ll, ll > > vc;

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    slld(testcase);

    ll s1 = 0, s2 = 0;

    for(ll cs = 1; cs <= testcase; cs++)
    {
        ll u, v;

        slld(u);
        slld(v);

        s1 += u;
        s2 += v;

        if(u % 2 == 1 || v % 2 == 1)
        {
            vc.push_back(make_pair(u,v));
        }
    }

    ll sz = vc.size();

    if(s1 % 2 == 0 && s2 % 2 == 0)
    {
        cout << 0 << endl;

        exit(0);
    }

    if(s1 % 2 == 0 || s2 % 2 == 0)
    {
        if(s1 % 2 == 1 || s2 % 2 == 1)
        {
            cout << -1 << endl;
            exit(0);
        }
    }

    for(i = 0; i < sz; i++)
    {
        if(vc[i].first % 2 == 0 || vc[i].second % 2 == 0)
        {
            cout << 1 << endl;
            exit(0);
        }
    }

    cout << -1 << endl;


}

