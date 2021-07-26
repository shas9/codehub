 // Lights will guide you home

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long

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

struct pll
{
    ll first, second;
};

vector < ll > g[100005];
map < pll, ll > mp;
pll arr[100005];

ll dfs(ll node, ll par)
{
    if(g[node].size() == 1 && node != 1) return 1;

    ll ret = 0;

    for(auto it: g[node])
    {
        if(it != par)
        {
            ll idx = mp[{node, it}];

            ll x = dfs(it, node);

            arr[idx].first = x;

            ret += x;
        }
    }

    return ret;
}

const bool operator > (const pll &lhs, const pll &rhs)
{
    if(lhs.first == rhs.first) return lhs.second < rhs.second;

    return lhs.first > rhs.first;
}

const bool operator < (const pll &lhs, const pll &rhs)
{
    if(lhs.first == rhs.first) return lhs.second < rhs.second;

    return lhs.first < rhs.first;
}

struct comp
{
    bool operator()(pll const& lhs, pll const& rhs)
    {
        ll x1 = (lhs.first * (lhs.second)) - (lhs.first * (lhs.second / 2));
        ll x2 = (rhs.first * (rhs.second)) - (rhs.first * (rhs.second / 2));

        return (x1 < x2);
    }
};

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

//    fastio;

    cin >> testcase;

    for(ll cs = 1; cs <= testcase; cs++)
    {
        cin >> n >> m;

        for(ll i = 1; i <= n; i++) g[i].clear(), arr[i].first = 0;
        mp.clear();

        for(ll i = 1; i < n; i++)
        {
            ll u, v, c;

            cin >> u >> v >> c;

            g[u].pb(v);
            g[v].pb(u);

            mp[{u,v}] = i;
            mp[{v,u}] = i;

            arr[i].second = c;
        }

        dfs(1,-1);

        ll cost = 0;

        priority_queue < pll, vector < pll >, comp > pq;

        for(ll i = 1; i < n; i++)
        {
            cost += arr[i].first * arr[i].second;
            pq.push({arr[i].first, arr[i].second});
        }

        ans = 0;

        while(cost > m && !pq.empty())
        {
            pll top = pq.top();
            pq.pop();

            ans++;
            cost -= top.first * top.second;
            top.second /= 2;
            cost += top.first * top.second;
            if(top.second) pq.push(top);
        }

        assert(cost <= m);

        cout << ans << "\n";


    }


}

