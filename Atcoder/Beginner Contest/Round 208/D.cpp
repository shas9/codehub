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

ll dist[403][403];
vector < pll > g[403], g2[403];

ll dd[403], ddd[403];

ll bfs(ll node)
{
    priority_queue < pll > q;
    for(ll i = 1; i <= 400; i++) dd[i] = mxlld, ddd[i] = mxlld;

    q.push({0,node});
    dd[node] = 0;

    while(!q.empty())
    {
        pll top = q.top();
        q.pop();
        top.first *= -1;

        if(dd[top.second] != top.first) continue;
        if(top.second > node) continue;

        for(auto it: g[top.second])
        {
            if(dd[it.first] > dd[top.second] + it.second)
            {
                dd[it.first] = dd[top.second] + it.second;
                q.push({-dd[it.first], it.first});
            }
        }
    }


    q.push({0,node});
    ddd[node] = 0;

    while(!q.empty())
    {
        pll top = q.top();
        q.pop();
        top.first *= -1;

        if(ddd[top.second] != top.first) continue;
        if(top.second > node) continue;

        for(auto it: g2[top.second])
        {
            if(ddd[it.first] > ddd[top.second] + it.second)
            {
                ddd[it.first] = ddd[top.second] + it.second;
                q.push({-ddd[it.first], it.first});
            }
        }
    }

    ll ret = 0;

    for(ll i = 1; i <= 400; i++)
    {
        if(ddd[i] == mxlld) continue;

        for(ll j = 1; j <= 400; j++)
        {
            if(dd[j] == mxlld) continue;

            if(i == j) continue;

            ll d = ddd[i] + dd[j];

            if(dist[i][j] == 0)
            {
                dist[i][j] = d;

                ret += d;

//                cout << "add: " << i << " " << j << " " << d << "\n";
            }
            else if(dist[i][j] > d)
            {
//                cout << "rem: " << i << " " << j << " " << d << "\n";
                ret -= dist[i][j] - d;
                dist[i][j] = d;
            }
        }
    }

    return ret;


}

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m)
    {
        for(ll i = 1; i <= n; i++)
        {
            g[i].clear();
            g2[i].clear();
        }

        ll add = 0;

        memset(dist,0,sizeof dist);

        for(ll i = 1; i <= m; i++)
        {
            ll u, v, c;
            cin >> u >> v >> c;

            g[u].pb({v,c});
            g2[v].pb({u,c});

            add += c;

            dist[u][v] = c;
        }

        ans = 0;

        for(ll i = 1; i <= n; i++)
        {
            add += bfs(i);

//            cout << add << "\n";

            ans += add;
        }

        cout << ans << "\n";
    }


}


