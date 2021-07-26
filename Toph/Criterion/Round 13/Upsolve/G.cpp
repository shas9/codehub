// Lights will guide you home

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define pll pair < ll, ll >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define bug(x) printf("BUG %lld\n", x)
#define pb push_back

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

vector < pll > g[1003];
ll dist[1003][1003];
vector < pll > vec;
vector < pll > edge;

pll conv(ll u, ll v)
{
    if(u > v) swap(u, v);

    return {u,v};
}

void dijkstra(ll u, ll v)
{
    priority_queue < pll > pq;
    for(ll i = 1; i <= 1000; i++) dist[u][i] = mxlld;

    pq.push({0,u});

    dist[u][u] = 0;

    while(!pq.empty())
    {
        pll top = pq.top();
        pq.pop();

        top.first *= -1;

        if(dist[u][top.second] != top.first) continue;

        for(auto it: g[top.second])
        {
            if(dist[u][it.first] > dist[u][top.second] + it.second)
            {
                dist[u][it.first] = dist[u][top.second] + it.second;
                pq.push({-dist[u][it.first], it.first});
            }
        }
    }

    return;
}


int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m >> k)
    {
        vec.clear();
        edge.clear();

        for(ll i = 1; i <= n; i++) g[i].clear();

        for(ll i = 1; i <= m; i++)
        {
            ll u, v, c;

            cin >> u >> v >> c;

            g[u].pb({v,c});
            g[v].pb({u,c});

            edge.push_back({u, v});
        }

        for(ll i = 1; i <= n; i++) dijkstra(i,i);

        for(ll i = 1; i <= k; i++)
        {
            ll u, v;

            cin >> u >> v;

            vec.push_back({u,v});
        }

        ans = mxlld;

        for(auto it: edge)
        {
            ll sum = 0;
            for(auto jt: vec)
            {
                ll cost = dist[it.first][jt.first] + dist[jt.second][it.second];
                cost = min(cost, dist[it.first][jt.second] + dist[jt.first][it.second]);
                cost = min(cost, dist[jt.first][jt.second]);

                sum += cost;
            }

            ans = min(ans, sum);
        }

        cout << ans << "\n";
    }


}
