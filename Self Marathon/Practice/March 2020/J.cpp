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

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

ll rest[400005];
ll pardsu[400005];
vector < ll > graph[400005];
ll par[19][400005];
ll depth[400005];
ll pwr[20];
ll n, r;
ll dist[400005];


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

    for(ll i=1; i<=18; i++)
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
    for(ll i=0; i<=18; i++)
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
    for(ll i=18; i>=0; i--)
    {
        if(par[i][u]!=par[i][v])
        {
            u=par[i][u];
            v=par[i][v];
        }
    }
    return par[0][u];
}

ll fnd(ll node)
{
    if(pardsu[node] == node) return node;

    return pardsu[node] = fnd(pardsu[node]);
}

void bfs1(ll k)
{
    queue < ll > q;

    memset(dist,-1,sizeof dist);

    for(ll i = 1; i <= r; i++)
    {
        q.push(rest[i]);

        dist[rest[i]] = 0;
    }

    while(!q.empty())
    {
        ll top = q.front();
        q.pop();

        if(dist[top] == k) return;

        for(auto v : graph[top])
        {
//            cout << v << endl;
            ll pu = fnd(top);
            ll pv = fnd(v);

            pardsu[pv] = pu;

            if(dist[v] != -1) continue;

            dist[v] = dist[top] + 1;

            q.push(v);

        }
    }
}

ll dst(ll u, ll v)
{
    ll llca = lca(u,v);

    return depth[u] + depth[v] - (2 * depth[llca]);
}

ll go(ll u, ll k)
{

    for(ll i = 18; i >= 0; i--)
    {
        if(k & (1 << i))
        {
            u = par[i][u];
        }
    }

    return u;
}

ll solve(ll u, ll v, ll kk)
{
    ll llca = lca(u,v);
    ll da = depth[u] - depth[llca];
    ll db = depth[v] - depth[llca];

    if(kk <= da)
    {
        return go(u,kk);
    }

    ll xx = kk - da;
    return go(v,db - xx);
}

bool walk(ll u, ll v, ll kk)
{
//    cout << solve(u,v,kk) << " " << solve(v,u,kk) << endl;
    if(fnd(solve(u,v,kk)) == fnd(solve(v,u,kk))) return 1;

    return 0;
}

int main()
{
    ll i, j, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    ll k;
    slld(n);
    slld(k);
    slld(r);

    for(i = 1; i <= n + n; i++)
        pardsu[i] = i;

    for(i = 1; i < n; i++)
    {
        ll u, v;

        slld(u);
        slld(v);

        graph[u].pb(n + i);
        graph[n + i].pb(u);

        graph[v].pb(n + i);
        graph[n + i].pb(v);
    }

    for(i = 1; i <= r; i++)
    {
        slld(rest[i]);
    }

    bfs1(k);

    dfs0(1,-1,0);
    preL();

    slld(q);

    for(i = 1; i <= q; i++)
    {
        ll u, v;

        slld(u);
        slld(v);

        if(dst(u,v) <= (2*k))
        {
            cout << "YES" << endl;
        }
        else if(walk(u,v,k))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

}


