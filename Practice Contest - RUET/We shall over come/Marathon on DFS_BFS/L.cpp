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

ll viscity[1010];
vector < ll > graph[1010];
bool visited[1010];

void dfs(ll source)
{
    ll i, j, k, temp;

    visited[source] = true;

    temp = graph[source].size();

    viscity[source]++;

    for(i = 0; i < temp; i++)
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

    slld(testcase);

    ll a, b;

    vector < ll > cities;

    for(i = 1; i <= testcase; i++)
    {
        slld(k);
        slld(n);
        slld(m);

        cities.clear();
        memset(viscity,0,sizeof(viscity));

        for(j = 1; j <= k; j++)
        {
            slld(input);
            cities.pb(input);
        }

        for(j = 0; j <= 1000; j++)
        {
            graph[j].clear();
        }

        for(j = 1; j <= m; j++)
        {
            slld(a);
            slld(b);

            graph[a].pb(b);
        }

        for(j = 0; j < k; j++)
        {
            input = cities[j];

            memset(visited,false,sizeof(visited));
            dfs(input);
        }

        tag = 0;

        ll ans = 0;

        for(j = 1; j <= n; j++)
        {
            if(viscity[j] >= k)
            {
                ans++;
            }
        }

        printcase(i,ans);
    }


}



