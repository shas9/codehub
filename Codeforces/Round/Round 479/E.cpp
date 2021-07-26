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


using namespace std;

bool vis[200005];
vector < ll > graph[200005];

bool dfs(ll par, ll tt)
{
    ll sz = graph[par].size();

    bool on;
    for(ll i = 0; i < sz; i++)
    {
        ll top = graph[par][i];

        if(top == tt) continue;

        if(vis[top] == true)
        {
            return true;
        }

        vis[top] = true;
        on = on || dfs(top,par);

        if(on) return true;

        vis[top] = false;
    }

    return false;
}


ll solve(ll n)
{
    memset(vis,false,sizeof vis);

    ll ans = 0;
    for(ll i = 0; i < n; i++)
    {
        if(vis[i] == false)
        {
            if(dfs(i, -1)) ans++;
        }
    }

    return ans;
}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    cin >> n >> m;

    for(i = 1; i <= m; i++)
    {
        ll u, v;

        cin >> u >> v;

        graph[u].pb(v);
        graph[v].pb(u);
    }

    ans = solve(n);

    cout << ans << endl;


}



