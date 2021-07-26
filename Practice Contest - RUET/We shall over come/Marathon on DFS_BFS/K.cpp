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

#define printcase(indexing) printf("Case %lld:\n", indexing)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld 99999999999999999
#define mnlld -99999999999999999

#define mxd 99999999
#define mnd 99999999

using namespace std;

map < ll, vector < ll > > graph;
map < ll, vector < ll > > value;

ll dis[2][30005];
bool vis[30005];
ll lft,rght;
ll mx;

void dfs(ll n, ll s = 0)
{
    vis[n] = true;

    for(ll i = 0; i < graph[n].size(); i++)
    {
        ll v = graph[n][i];
        ll d = value[n][i];

        if(vis[v] == false)
        {
            vis[v] = true;

            if(s + d > mx)
            {
                mx = s + d;
                lft = v;
            }

            dfs(v,s+d);
        }
    }
}

void dfs1(ll n, ll k, ll s = 0)
{
    vis[n] = true;

    for(ll i = 0; i < graph[n].size(); i++)
    {
        ll v = graph[n][i];
        ll d = value[n][i];

        if(vis[v] == false)
        {
            vis[v] = true;

            if(s + d > mx)
            {
                mx = s + d;
                rght = v;
            }

            dis[k][v] = s + d;

            dfs1(v,k,s+d);
        }

    }
}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag;

    slld(testcase);

    ll node;

    ll a, b, c;

    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(node);

        graph.clear();
        value.clear();

        for(i = 1; i < node; i++)
        {
            slld(a);
            slld(b);

            slld(c);

            graph[a].pb(b);
            graph[b].pb(a);

            value[a].pb(c);
            value[b].pb(c);
        }

        lft = 0;
        rght = 0;
        mx = 0;

        memset(vis,false,sizeof(vis));
        memset(dis,0,sizeof(dis));
        dfs(1);

        memset(vis,false,sizeof(vis));

        mx = 0;

        dfs1(lft,0);

        memset(vis,false,sizeof(vis));
        dfs1(rght,1);

        printcase(cs);

        for(i = 0; i < node; i++)
        {
            printf("%lld\n", max(dis[0][i],dis[1][i]));
        }

    }


}

