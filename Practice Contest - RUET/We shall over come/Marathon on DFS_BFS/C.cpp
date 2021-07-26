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

vector < ll > graph[10005];
ll ans;
bool visited[10005];

ll dfs(ll source)
{
    ll i, j, k, l, m, m1 = -1, m2 = -1, n;
    k = graph[source].size();

    visited[source] = true;



    for(i = 0; i < k; i++)
    {
        if(visited[graph[source][i]] == false)
        {
            m = dfs(graph[source][i]);

            if(m >= m1)
            {
                m2 = m1;
                m1 = m;
            }
            else if(m >= m2)
            {
                m2 = m;
            }
        }
    }

    ans = max(ans, m1 + m2 + 2);
    return (m1 + 1);
}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag;

    ll a, b;

    ll nodes, edges;

    slld(nodes);

    edges = nodes - 1;

    for(i = 0; i <= nodes; i++)
    {
        graph[i].clear();
    }

    for(i = 1; i <= edges; i++)
    {
        slld(a);
        slld(b);

        graph[a].pb(b);
        graph[b].pb(a);
    }

    ans = 0;

    memset(visited,false,sizeof(visited));

    dfs(1);

    cout << ans << endl;

}

