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

#define maxn 100005

using namespace std;

vector < ll > graph[maxn];
bool check[maxn];
bool vis[maxn];

void bfs(ll num)
{
    queue < pair < ll, ll >> qq;

    qq.push(make_pair(1,0));

    memset(check,0,sizeof check);
    memset(vis,0,sizeof vis);
    vis[1] = true;

    while(!qq.empty())
    {
        pll top = qq.front();
        qq.pop();
        ll par = top.second;

        for(ll i = 0; i < graph[top.first].size(); i++)
        {
            ll node = graph[top.first][i];

            if(vis[node]) continue;

            vis[node] = 1;

            if(check[par] == 0)
            {
                printf("%lld %lld\n", top.first, node);
                check[top.first] = 1;
            }
            else
            {
                printf("%lld %lld\n", node, top.first);
                check[top.first] = 0;
            }

            qq.push(make_pair(node,top.first));
        }
    }
}



int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);
    slld(testcase);

    ll u, v;
    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(n);

        for(i = 1; i < n; i++)
        {
            slld(u);
            slld(v);

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        printf("Case %lld:\n", cs);

        bfs(1);

        for(i = 1; i <= n; i++) graph[i].clear();
    }


}



