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

ll color[20005];
vector < ll > graph[20005];
bool visited[20005];
queue < ll > q;

void bfs(ll source)
{
    ll i, j, k, l, m, n;

    q.push(source);

    visited[source] = true;

    while(!q.empty())
    {
        k = q.front();
        q.pop();

        l = graph[k].size();

        for(i = 0; i < l; i++)
        {
            if(visited[graph[k][i]] == false)
            {
                visited[graph[k][i]] = true;
                if(color[k] == 1)
                {
                    color[graph[k][i]] = 0;
                }
                else if(color[k] == 0)
                {
                    color[graph[k][i]] = 1;
                }

                q.push(graph[k][i]);
            }
        }
    }
}

ll mxcolor()
{
    ll var = 0;
    ll var1 = 0;

    for(ll i = 1; i < 20005; i++)
    {
        if(color[i] == 1)
        {
            var++;
        }
        else if(color[i] == 0)
        {
            var1++;
        }
    }

    return max(var1,var);
}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag;

    slld(testcase);

    ll edges;
    ll maxnode;

    ll a, b;
    ll ans;

    for(i = 1; i <= testcase; i++)
    {
        slld(edges);

        maxnode = mnlld;

        for(j = 0; j <= 20000; j++)
        {
            graph[j].clear();
        }

        for(j = 1; j <= edges; j++)
        {
            slld(a);
            slld(b);

            graph[a].pb(b);
            graph[b].pb(a);

            maxnode = max(a,maxnode);
            maxnode = max(b,maxnode);
        }

        memset(visited,false,sizeof(visited));

        ans = 0;

        for(j = 1; j <= maxnode; j++)
        {
            if(visited[j] == false && graph[j].size() > 0)
            {
                memset(color,-1,sizeof(color));

                color[j] = 1;

                while(!q.empty())
                {
                    q.pop();
                }

                bfs(j);

                ans += mxcolor();
            }
        }

        printcase(i,ans);


    }


}


