#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool check(ll N,ll pos)
{
    return (bool)(N & (1LL<<pos));
}

vector<ll>graph[200005];
ll par[19][200005];
ll depth[200005];
ll pwr[19];
ll n;

void dfs0(ll src,ll p,ll level)
{
    depth[src]=level;
    par[0][src]=p;
    for(ll i=0; i<graph[src].size(); i++)
    {
        ll adj=graph[src][i];
        if(adj!=p)
        {
            dfs0(adj,src,level+1);
        }
    }
}
void preL()
{

    for(ll i=1; i<=17; i++)
    {
        for(ll j=1; j<=n; j++)
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
    for(ll i=0; i<=17; i++)
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
    for(ll i=17; i>=0; i--)
    {
        if(par[i][u]!=par[i][v])
        {
            u=par[i][u];
            v=par[i][v];
        }
    }
    return par[0][u];
}

ll arr[200005];

bool comp(ll a, ll b)
{
    return depth[a] >= depth[b];
}
int main()
{
    memset(par,-1,sizeof par);
    ll m;

    scanf("%lld%lld", &n, &m);

    for(ll i=1; i<=n-1; i++)
    {
        ll u,v;
        scanf("%lld%lld", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs0(1,-1,0);
    preL();

//    cout << "INPUT TAKEN" << endl;
    for(ll ii=1; ii<=m; ii++)
    {
        ll k;

        scanf("%lld", &k);

        for(ll i = 1; i <= k; i++) scanf("%lld", &arr[i]);

        if(k == 1)
        {
            cout << "YES" << endl;
            continue;
        }

//        cout << "NOT SORTED" << endl;
        sort(arr + 1, arr + 1 + k, comp);

        ll node = arr[1];

        ll mx = 1;

//        cout << "BUGGED" << endl;

        ll i;
        for(i = 2; i <= k; i++)
        {
            ll llca = lca(node,arr[i]);

            ll distx = depth[node] - depth[llca];
            ll disty = depth[arr[i]] - depth[llca];

            if(distx > 1 && disty > 1) break;
        }

        if(i <= k)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }



    return 0;
}
