 // God put a smile upon your face <3

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb push_back

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

struct info
{
    ll u, v, x, id;
};

ll dist[603][603];
ll vertex[603][603];
bool mark[360005];
vector < info > edges;
vector < info > to_process;

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    fastio;
    while(cin >> n >> m)
    {
        memset(mark,0,sizeof mark);

        for(ll i = 1; i <= n; i++) for(ll j = 1; j <= n; j++) dist[i][j] = 1e16;

        ll id = 0;

        edges.resize(m);
        for(info &it: edges) cin >> it.u >> it.v >> it.x, it.id = ++id;

        cin >> q;
        to_process.resize(q);
        for(info &it: to_process) cin >> it.u >> it.v >> it.x;

        for(info it: edges) dist[it.u][it.v] = it.x, dist[it.v][it.u] = it.x;

        for(ll i = 1; i <= n; i++) dist[i][i] = 0;

        for(ll k = 1; k <= n; k++)
        {
            for(ll j = 1; j <= n; j++)
            {
                for(ll i = 1; i <= n; i++)
                {
                    if(dist[i][j] > dist[i][k] + dist[k][j])
                    {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

//        for(ll i = 1; i <= n; i++) for(ll j = 1; j <= n; j++) cout << i << " : " << j << " " << dist[i][j] << "\n";

        for(ll i = 1; i <= n; i++) for(ll j = 1; j <= n; j++) vertex[i][j] = -1e16;

        for(ll i = 1; i <= n; i++)
        {
            for(info it: to_process)
            {
                vertex[it.u][i] = max(vertex[it.u][i], it.x - dist[it.v][i]);
                vertex[it.v][i] = max(vertex[it.v][i], it.x - dist[it.u][i]);
            }
        }

//        for(ll i = 1; i <= n; i++) for(ll j = 1; j <= n; j++) cout << i << " : " << j << " " << vertex[i][j] << "\n";

        for(info it: edges)
        {
            for(ll i = 1; i <= n; i++)
            {
                if(dist[it.u][i] + it.x <= vertex[i][it.v]) mark[it.id] = 1;
                if(dist[it.v][i] + it.x <= vertex[i][it.u]) mark[it.id] = 1;
            }
        }

        ans = 0;

        for(ll i = 1; i <= m; i++) ans += mark[i];

        cout << ans << "\n";

    }


}

