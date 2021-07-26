#include <bits/stdc++.h>`

#define scanlld(longvalue) scanf("%lld", &longvalue)
#define printlld(longvalue) printf("%lld\n", longvalue)

#define scanlf(longvalue) scanf("%lf", &longvalue)
#define printlf(longvalue) printf("%lf\n", longvalue)
#define scanc(letter) scanf("%c", &letter)
#define printc(letter) printf("%c", letter)

#define scans(name) scanf("%s", name)
#define prints(name) printf("%s", name)

#define printnewline printf("\n")

#define ll long long

#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mx 10005

using namespace std;

stack < ll > topsort;
vector < ll > graph[mx];
ll visited[mx];
ll ans;

void dfs_1(ll u)
{
    ll i, j, k, l;

    visited[u] = 1;

    l = graph[u].size();

    for(i = 0; i < l; i++)
    {
        ll v = graph[u][i];

        if(visited[v] == 0)
        {
            dfs_1(v);
        }
    }

    topsort.push(u);

}

void dfs_2(ll u)
{
    ll i, j, k, l;

    visited[u] = 1;

    l = graph[u].size();

    for(i = 0; i < l; i++)
    {
        ll v = graph[u][i];

        if(visited[v] == 0)
        {
            dfs_2(v);
        }
    }
}

void solve(ll n)
{
    ll i, j, k, l;
    for(i = 1; i <= n; i++)
    {
        if(visited[i] == 0)
        {
            dfs_1(i);
        }
    }

    memset(visited,0,sizeof(visited));

    k = topsort.size();

    for(i = 1; i <= k; i++)
    {
        j = topsort.top();

        topsort.pop();

        if(visited[j] == 0)
        {
            ans++;
            dfs_2(j);
        }
    }

}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, light, quest;

    scanlld(testcase);

    for(i = 1; i <= testcase; i++)
    {
        scanlld(light);
        scanlld(quest);

        while(!topsort.empty())
        {
            topsort.pop();
        }

        for(j = 1; j <= light; j++)
        {
            graph[j].clear();
            visited[j] = 0;
        }

        for(j = 1; j <= quest; j++)
        {
            scanlld(m);
            scanlld(n);

            graph[m].pb(n);
        }

        ans = 0;

        solve(light);

        printf("Case %lld: %lld\n", i, ans);
    }


}


