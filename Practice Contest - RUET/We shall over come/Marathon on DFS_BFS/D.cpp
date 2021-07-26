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

vector < ll > graph[100010];
bool visited[100010];

void dfs(ll source)
{
    visited[source] = true;

    ll i, j, k, l, m, n;

    n = graph[source].size();

    for(i = 0; i < n; i++)
    {
        if(visited[graph[source][i]] == false)
        {
            dfs(graph[source][i]);
        }
    }

    return;
}
int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag;
    ll st;
    ll fr;

    ll a, b;

    slld(testcase);

    ll ans = 0;

    for(i = 1; i <= testcase; i++)
    {
        slld(st);
        slld(fr);
        ans = 0;

        memset(visited,false,sizeof(visited));



        for(j = 0; j <= st; j++)
        {
            graph[j].clear();
        }

        for(j = 1; j <= fr; j++)
        {
            slld(a);
            slld(b);

            graph[a].pb(b);
            graph[b].pb(a);
        }

        for(j = 0; j < st; j++)
        {
            if(visited[j] == false)
            {
                ans++;

                dfs(j);
            }
        }

        cout << ans << endl;

    }


}


