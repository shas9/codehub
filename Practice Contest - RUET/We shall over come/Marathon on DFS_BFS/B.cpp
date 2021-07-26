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

bool visited[10009];
ll flag = 0;
vector < ll > graph[10009];

void dfs(ll source, ll parent)
{
    ll i, j, k, l, m, n;
    k = graph[source].size();

    for(i = 0; i < k; i++)
    {
        if(visited[graph[source][i]] == false)
        {
            visited[graph[source][i]] = true;
            dfs(graph[source][i], source);
        }
        else
        {
             if(graph[source][i] != parent)
             {
                 flag = 1;
                 return;
             }
        }
    }
}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, tag;
    ll a, b;

    ll nodes, edges;

    slld(nodes);
    slld(edges);

    memset(visited,false,sizeof(visited));

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

    visited[1] = true;

    dfs(1,0);

    for(i = 1; i <= nodes; i++)
    {
        if(visited[i] == false)
        {
            flag = 1;
            break;
        }
    }

    if(flag)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
    }

    return 0;


}

