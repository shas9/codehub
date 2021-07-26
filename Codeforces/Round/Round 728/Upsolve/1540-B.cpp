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

vector < ll > g[203];

const ll K = 10;
const ll N = 203;

ll anc[N][K];
ll depth[N];

void setup(ll u, ll par) {
    depth[u] = depth[par]+1;

    memset(anc[u],0,sizeof anc[u]);

    anc[u][0] = par;

    for (ll k=1; k<K; k++) anc[u][k] = anc[anc[u][k-1]][k-1];

    for (ll v: g[u]) {
        if (v == par)   continue;
        setup(v, u);
    }
}

ll lca(ll u, ll v) {

    if (depth[u] > depth[v])    swap(u, v);

    for (ll k=K-1; k>=0; k--)
        if (depth[u] + (1<<k) <= depth[v])  v = anc[v][k];

    if (u == v) return u;

    for (ll k=K-1; k>=0; k--)
        if (anc[u][k] != anc[v][k])
            u = anc[u][k], v = anc[v][k];

    return anc[u][0];
}

ll getanc(ll u, ll d) {

    for (ll k=0; k<K; k++)
        if (d & (1<<k))
            u = anc[u][k];

    return u;
}

ll dist(ll u, ll v) {

    ll g = lca(u, v);

    return depth[u] + depth[v] - 2*depth[g];
}

ll power(ll x, ll y, ll p)
{
    ll res = 1;      // Initialize result

    x = x % p;  // Update x if it is more than or
                // equal to p

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;

        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}

const ll mod = 1e9 + 7;

ll dp[203][203];

ll solve(ll x, ll y)
{
    if(y == 0) return 1;
    if(x == 0) return 0;

    ll &ret = dp[x][y];

    if(ret != -1) return ret;

    ret = (solve(x - 1, y) + solve(x, y - 1)) % mod;

    ret = (ret * power(2, mod - 2, mod)) % mod;

    return ret;
}

int main()
{
    ll i, j, k, l, m, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    memset(dp,-1,sizeof dp);

    while(cin >> n)
    {
        for(ll i = 1; i <= n; i++) g[i].clear();

        for(ll i = 1; i < n; i++)
        {
            ll u, v;
            cin >> u >> v;

            g[u].push_back(v);
            g[v].push_back(u);
        }

        ans = 0;

        for(ll i = 1; i <= n; i++)
        {
            memset(par,-1,sizeof par);
            dfs0(i,-1,1);
            preL();

            for(ll j = 1; j <= n; j++)
            {
                for(ll k = j + 1; k <= n; k++)
                {
                    ll llca = lca(j,k);

                    ll sz1 = depth[k] - depth[llca];
                    ll sz2 = depth[j] - depth[llca];

//                    cout << i << " = " << j << " " << k << "\n";
//                    cout << llca << " ++ " << sz2 << " " << sz1 << "\n";

                    ans = (ans + solve(sz2, sz1)) % mod;
                }
            }
        }

        ans = (ans * power(n,mod - 2, mod)) % mod;

        cout << ans << "\n";
    }


}
