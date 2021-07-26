#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%d", &longvalue)
#define plld(longvalue) printf("%d\n", longvalue)

#define slf(longvalue) scanf("%lf", &longvalue)
#define plf(longvalue) printf("%lf\n", longvalue)
#define sc(letter) scanf("%c", &letter)
#define pc(letter) printf("%c", letter)

#define ss(name) scanf("%s", name)
#define ps(name) printf("%s", name)

#define pnew printf("\n")

#define ll int

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

vector<ll>graph[500005];
ll par[21][500005];
ll depth[500005];
ll pwr[21];
ll n;
ll arr[500005];
bitset < 255 > bit[500005];

void dfs0(ll src,ll p,ll h = 0)
{
    bit[src][arr[src]] = 1;
    depth[src] = h;
    par[0][src]=p;
    ll sz = graph[src].size();
    for(ll i=0; i<sz; i++)
    {
        ll adj=graph[src][i];
        if(adj!=p)
        {
            //depth[adj] = depth[src] + 1;
            dfs0(adj,src, h + 1);

            bit[src] |= bit[adj];
        }
    }
}
void preL()
{

    for(ll i=1; i<=19; i++)
    {
        for(ll j=1; j<=n; j++)
        {
            if(par[i-1][j]==-1)continue;
            par[i][j]=par[i-1][par[i-1][j]];                       ///i means 2^i th parent of j th node par[i][j] means 2^i th parent of jth node
        }
    }
}
ll lca(int a, int b){
    if(depth[a] < depth[b])
        swap(a, b);
    for(int i = 19; i >= 0; i --)
        if(depth[a] - (1 << i) >= depth[b])
            a = par[i][a];
    if(a == b)
        return a;
    for(int i = 19; i >= 0; i --)
        if(par[i][a] != -1 && par[i][a] != par[i][b]){
            a = par[i][a];
            b = par[i][b];
        }
    return par[0][a];
}

void cle()
{
    memset(pwr, 0, sizeof pwr);
    memset(par,-1,sizeof par);

    for(ll i = 1; i <= n; i++)
    {
        graph[i].clear();
        //memset(dis,false,sizeof dis);
        //depth[i] = 0;
        bit[i].reset();
    }
}


int main()
{
    ll i, j, k, l, m;
    ll testcase;
    ll root;

    slld(testcase);
    n = 1;
    for(i = 1; i <= testcase; i++)
    {
        cle();
        slld(n);
        slld(m);
        slld(root);


        root++;
        for(i = 1; i <= n; i++) slld(arr[i]);

        for(i = 1; i <= n - 1; i++)
        {
            ll u,v;
            slld(u);
            slld(v);

            u++;
            v++;

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        dfs0(root,-1);
        preL();

        for(i = 1; i <= m; i++)
        {
            ll u,v;

            slld(u);
            slld(v);
            u++;
            v++;

            ll lcaa=lca(u,v);

            ll ans = bit[lcaa].count();
            plld(ans);
        }
    }
    return 0;
}


