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

#define mp make_pair


using namespace std;

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);
    slld(testcase);

    ll r, llm = mxlld, rr = -1;

    vector < pair < ll, ll > > v;

    v.clear();

    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(l);
        slld(r);

        llm = min(llm,l);
        rr = max(rr,r);

        v.pb(mp(l,r));
    }

    ll pos = -1;


    for(ll cs = 1; cs <= testcase; cs++)
    {
        l = v[cs - 1].first;
        r = v[cs - 1].second;

        if(l == llm && rr == r)
        {
            pos = cs;
            break;
        }
    }

    cout << pos << endl;

}

