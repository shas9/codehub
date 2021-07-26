 // Lights will guide you home

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define pll pair < ll, ll >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define bug(x) printf("BUG %lld\n", x)
#define pb push_back

#define mxlld 1e10
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

ll dist[100005];
vector < pll > g[100005], ed;

void calc()
{
    priority_queue < pll > pq;
    dist[0] = 0;
    pq.push({0,0});

    while(!pq.empty())
    {
        pll top = pq.top();
        pq.pop();

        top.first *= -1;

        if(dist[top.second] != top.first) continue;

        for(auto it: g[top.second])
        {
            if(dist[it.first] > dist[top.second] + it.second)
            {
                dist[it.first] = dist[top.second] + it.second;
                pq.push({-dist[it.first], it.first});
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

    while(cin >> n >> m >> l >> r)
    {
        for(i = 1; i <= n; i++) dist[i] = mxlld;
        for(i = 1; i <= n; i++) g[i].clear();

        ed.clear();

        for(i = 1; i <= m; i++)
        {
            ll u, v, w;

            cin >> u >> v >> w;

            g[u].pb({v,w});
            g[v].pb({u,w});

            ed.push_back({u,v});
        }

        calc();

        ans = 0;

        for(auto it: ed)
        {
            ll d = min(dist[it.first], dist[it.second]);

            if(d * 2 + 1 <= r) ans++;
        }

        cout << ans << "\n";

    }


}


