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

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009

#define maxn 200005

using namespace std;

ll node, edge;
vector < ll > graoh[maxn];
ll degree[maxn];
bool vis[maxn];
bool on1, on2;

void bfs(ll st)

ll solve()
{
    ll cnt = 0;

    memset(vis,false,sizeof vis);

    for(ll i = 1; i <= node; i++)
    {
        if(vis[i] == false)
        {
            on1 = 1;
            on2 = 0;
            bfs(i);

            if(on1 && on2) cnt++;

        }
    }

    return cnt;
}
int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    cin >> node >> edge;

    memset(degree,0,sizeof degree);

    for( i = 1; i <= edge; i++ )
    {
        ll u, v;

        cin >> u >> v;

        graph[u].pb(v);
        graph[v].pb(u);

        degree[u]++;
        degree[v]++;
    }

    ans = solve();

    cout << ans << endl;


}


