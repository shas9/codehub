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


using namespace std;

ll start, meet;
vector < ll > graph[110];

ll dis[3][150];

queue < ll > q;

void bfs(ll source, ll k)
{
    while(!q.empty())
    {
        q.pop();
    }

    q.push(source);

    dis[k][source] = 0;

    while(!q.empty())
    {
        ll u = q.front();
        q.pop();

        for(ll i = 0; i < graph[u].size(); i++)
        {
            ll v = graph[u][i];

            if(dis[k][v] == -1)
            {
                dis[k][v] = dis[k][u] + 1;

                q.push(v);
            }
        }
    }
}


int main()
{
    ll i, j, l, m, n, o;
    ll testcase;
    ll input, flag, tag;

    slld(testcase);

    ll a, b;
    ll node, edge;
//    ll start, meet;

    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(node);
        slld(edge);

        for(i = 0; i <= 100; i++)
        {
            graph[i].clear();
        }

        for(i = 1; i <= edge; i++)
        {
            slld(a);
            slld(b);

            graph[a].pb(b);
            graph[b].pb(a);
        }

        memset(dis,-1,sizeof(dis));

        slld(start);
        slld(meet);

        bfs(start,1);
        bfs(meet,2);

        ll ans = 0;

        for(i = 0; i < node; i++)
        {
            ans = max(ans, dis[1][i] + dis[2][i]);
        }

        printcase(cs,ans);
    }

    return 0;
}


