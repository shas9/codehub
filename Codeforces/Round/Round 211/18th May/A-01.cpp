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

#define maxn 200005

using namespace std;

map < string, ll > mp;
ll par[maxn];
ll depth[maxn];
ll sz;
string a, b;
void init()
{
    mp.clear();
    for(ll i = 0; i <= 200000; i++)
    {
        par[i] = i;
        depth[i] = 1;
    }

    sz = 0;
}

ll check(ll a)
{
    //cout << a << " " << par[a] << endl;
    if(par[a] == a) return a;
    else
    {
        //cout << par[a] << endl;
        par[a] = check(par[a]);
        return par[a];
    }
}

ll solve(ll a, ll b)
{
    //cout << a << " & " << b << endl;
    a = check(a);
    b = check(b);

    //cout << a << " " << b << endl;

    if(a == b) return depth[a];

    //bug;

    if(depth[a] > depth[b])
    {
        depth[a] += depth[b];
        par[b] = a;

        return depth[a];
    }
    else
    {
        depth[b] += depth[a];

        par[a] = b;

        return depth[b];
    }

}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);
    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        init();

        slld(n);

        for(i = 1; i <= n; i++)
        {
            cin >> a >> b;

            if(mp[a] == 0) mp[a] = ++sz;
            if(mp[b] == 0) mp[b] = ++sz;

            ans = solve(mp[a],mp[b]);

            //cout << par[mp[a]] << " : " << par[mp[b]] << endl;

            plld(ans);
        }
    }


}


