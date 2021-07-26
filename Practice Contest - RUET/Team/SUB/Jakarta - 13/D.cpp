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

#define mxlld 99999999999999999
#define mnlld -99999999999999999

#define mxd 99999999
#define mnd 99999999

#define pi 3.14159265359

#define mod 1000000009


using namespace std;

ll pp[300];
vector < ll > p[300];
vector < ll > pc[300];
ll k, l, m, n;

bool vis[300];


ll dfs(ll point, ll cost)
{
    ll i, j, k, l;

    for(i = 0; i < p.size(); i++)
    {

    }
}


int main()
{
    ll i, j, o;
    ll testcase;
    ll input, flag, tag, ans;

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(n);
        slld(m);
        slld(k);

        for(i = 1; i < 300; i++)
        {
            p[i].clear();
            pc[i].clear();
        }

        for(i = 1; i <= k; i++)
        {
            slld(pp[i]);
        }

        for(i = 1; i <= m; i++)
        {
            ll a, b, c;

            slld(a);
            slld(b);
            slld(c);

            p[a].pb(b);
            p[b].pb(a);

            pc[a].pb(c);
            pc[b].pb(c);
        }

        ans = mxlld;
        for(j = 1; j <= k; j++)
        {
            memset(vis,false,sizeof(vis));

            for(i = 1; i <= k; i++)
            {
                vis[pp[i]] = true;
            }

            for(i = 1; i <= k; i++)
            {
                tag = dfs(pp[i],cost);
            }

            ans = min(tag,ans);
        }

        printcase(cs,ans);


    }


}


