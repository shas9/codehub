#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%d", &longvalue)
#define plld(longvalue) printf("%d\n", longvalue)

#define ll int

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define maxn 500005

using namespace std;

bool check(ll N,ll pos)
{
    return (bool)(N & (1<<pos));
}
ll Set(ll n, ll pos)
{
	return n = n | (1 << pos);
}

/// Declaration:

vector<ll>graph[maxn];
ll par[20][maxn];
ll depth[maxn];
ll n;
ll arr[maxn];
bitset < 260 > bit[maxn];

/// Sesh.

void dfs0(ll src,ll p,ll level)
{
    depth[src]=level;
    par[0][src]=p;
    bit[src][arr[src]] = 1;
    for(ll i=0; i<graph[src].size(); i++)
    {
        ll adj=graph[src][i];
        if(adj!=p)
        {
            dfs0(adj,src,level+1);

            bit[src] |= bit[adj];
        }
    }
}
void preL()
{

    for(ll i=1; i<=19; i++)
    {
        for(ll j=0; j<n; j++)
        {
            if(par[i-1][j]==-1)continue;
            par[i][j]=par[i-1][par[i-1][j]];                       ///i means 2^i th parent of j th node par[i][j] means 2^i th parent of jth node
        }
    }
}
ll lca(ll u,ll v)
{
    if(depth[u]>depth[v])
    {
        swap(u,v);
    }
    ll diff=depth[v]-depth[u];
    for(ll i=0; i<=19; i++)
    {
        if(check(diff,i)==1)
        {
            v=par[i][v];
        }
    }
    if(u==v)
    {
        return u;
    }
    for(ll i=19; i>=0; i--)
    {
        if(par[i][u]!=par[i][v])
        {
            u=par[i][u];
            v=par[i][v];
        }
    }
    return par[0][u];
}
void cle()
{
    for(ll i = 0; i < n; i++)
    {
        graph[i].clear();
        bit[i].reset();
        for(ll j = 0; j < 20; j++) par[j][i] = -1;
    }
}

int main()
{
    ll i, j, k, l, m, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);
    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        cle();
        slld(n);
        slld(m);
        slld(k);

        for(i = 0; i < n; i++) slld(arr[i]);

        for(i = 0; i < n - 1; i++)
        {
            ll u, v;

            slld(u);
            slld(v);

            graph[u].pb(v);
            graph[v].pb(u);
        }

        dfs0(k,-1,0);

        preL();

        while(m--)
        {
            ll u, v;

            slld(u);
            slld(v);

            printf("%d\n", bit[lca(u,v)].count());
        }


    }


}


