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

vector<ll>graph[200005];
ll par[19][200005];
ll depth[200005];
ll pwr[20];
ll n;

ll red[200005];
ll blue[200005];

void dfs0(ll src, ll p, ll level)
{
    depth[src] = level;
    par[0][src] = p;
    for(ll i = 0; i < graph[src].size(); i++)
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

bool solve(ll szr, ll szb)
{
    ll lcar, lcab;

    for(ll j = 1; j <= szr; j++)
    {

        if(j == 1) lcar = red[j];
        else
        {
            lcar = lca(lcar, red[j]);
        }
    }

    for(ll j = 1; j <= szb; j++)
    {

        if(j == 1) lcab = blue[j];
        else
        {
            lcab = lca(lcab, blue[j]);
        }
    }

    ll lcaa = lca(lcar,lcab);

    if(lcaa != lcab && lcaa != lcar)
    {
        return 1;
    }

    ll j;

    if(lcaa == lcab)
    {
        for( j = 1; j <= szb; j++)
        {
            if(lcar == lca(lcar, blue[j]))
            {
                return 0;
            }
        }

    }

    if(lcaa == lcar)
    {
        for(j = 1; j <= szr; j++)
        {
            if(lcab == lca(lcab, red[j]))
            {
                return 0;
            }
        }
    }

    return 1;
}

int main()
{
    memset(par,-1,sizeof par);

    slld(n);

    for(ll i=1; i<=n-1; i++)
    {
        ll u,v;

        slld(u);
        slld(v);

        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs0(1,-1,0);
    preL();

    ll q;

    slld(q);

    for(ll i=1; i<=q; i++)
    {
        ll szr, szb;

        ll lcar, lcab;

        slld(szr);
        slld(szb);

        for(ll j = 1; j <= szr; j++)
        {
            slld(red[j]);
        }

        for(ll j = 1; j <= szb; j++)
        {
            slld(blue[j]);
        }

//        cout <<  i << " ";
//
//        cout << "--" << endl;
        if(solve(szr,szb))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
