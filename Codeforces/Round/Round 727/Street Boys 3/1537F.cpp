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

vector < ll > g[200005];
int vis[200005];
ll v[200005];
ll t[200005];

bool solve(ll n)
{
    ll t1 = 0, v1 = 0;

    for(ll i = 1; i <= n; ++i) t1 += t[i], v1 += v[i];

    if((t1 & 1) != (v1 & 1)) return 0;

    queue < ll > q;

    q.push(1);

    ll s1 = 0, s2 = 0;

    vis[1] = 0;
    s1 += t[1] - v[1];



    while(!q.empty())
    {
        ll top = q.front();
        q.pop();

        for(auto it: g[top])
        {
            if(vis[it] == vis[top]) return 1;
            if(vis[it] != -1) continue;

            vis[it] = vis[top] ^ 1;
            q.push(it);

            if(vis[it] == 1) s2 += t[it] - v[it];
            else s1 += t[it] - v[it];
        }
    }

    return s1 == s2;
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

        for(i = 0; i <= n; i++)
        {
            g[i].clear();
            vis[i] = -1;
        }

        for(ll i = 1; i <= n; i++) cin >> v[i];
        for(ll i = 1; i <= n; i++) cin >> t[i];

        for(ll i = 1; i <= m; i++)
        {
            ll u, v;
            cin >> u >> v;

            g[u].pb(v);
            g[v].pb(u);
        }

        if(solve(n)) cout << "YES\n";
        else cout << "NO\n";
    }


}



