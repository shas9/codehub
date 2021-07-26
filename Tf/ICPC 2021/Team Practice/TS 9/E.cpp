// Lights will guide you home

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%d", &longvalue)

#define ll int
#define pll pair < int, int >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb push_back

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}
vector < ll > g[300005];
ll vis[300005];

pll dfs(ll node, ll par = -1, ll d = 1)
{
    if(vis[node]) return {0,0};

    vis[node] = d;

    pll ret = {1,0};

    for(auto it: g[node])
    {
        if(it == par) continue;

        pll get = dfs(it, node, d + 1);

        if(vis[it] > vis[node]) ret.second++;

        ret.first += get.first;
        ret.second += get.second;
    }

//    cout << node << " " << ret.first << " " << ret.second << "\n";

    return ret;
}

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    fastio;

    cin >> testcase;

    for(ll cs = 1; cs <= testcase; cs++)
    {
        cin >> n >> m;

        for(ll i = 1; i <= n; i++)
        {
            g[i].clear();
            vis[i] = 0;
        }

        for(ll i = 1; i <= m; i++)
        {
            ll u, v;

            cin >> u >> v;


            g[u].pb(v);
            g[v].pb(u);
        }

        ans = 0;

        for(ll i = 1; i <= n; i++)
        {
            pll get = dfs(i);

            ans += max(0, get.second - get.first);
        }

        cout << "Case #" << cs << ": " << ans << "\n";
    }


}
