 // Lights will guide you home

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define bug(x) printf("BUG %lld\n", x)

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

ll ncr[1001][1001];
const ll mod = 1000210433;

ll nCr(ll n, ll r)
{
    if(n < r) return 0;
	if(r == 0) return 1;
	if(r == 1) return n;
	if(n == r) return 1;

	ll &ret = ncr[n][r];

	if(ret != -1) return ret;

	ret = nCr(n - 1,r) + nCr(n - 1, r - 1);

	return ret = (ret % mod);
}


map < ll, pll > mp;
vector < pair < ll, pll > > edges;
ll par[2003];

ll fnd(ll node)
{
//    cout << node << " " << par[node] << endl;
    if(par[node] == node) return node;

    return par[node] = fnd(par[node]);
}

ll solve(ll n)
{
    if(edges.empty()) return 0;

    for(ll i = 1; i <= n; i++) par[i] = i;

    for(auto it: edges)
    {
        ll u = it.second.first;
        ll v = it.second.second;
        ll w = it.first;

//        cout << u << " " << v << " " << w << "\n";

        mp[w].first++;

        ll pu = fnd(u);
        ll pv = fnd(v);

//        cout << pu << " " << pv << endl;

        if(pu == pv) continue;

        par[pu] = pv;

        mp[w].second++;
    }

    ll ret = 1;

    for(auto it: mp)
    {

//        cout << it.first << " " << it.second.first << " " << it.second.second << "\n";
        ret = (ret * nCr(it.second.first, it.second.second)) % mod;
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

    memset(ncr, -1,sizeof ncr);
    cin >> testcase;

    for(ll cs = 1; cs <= testcase; cs++)
    {
        cin >> n >> m;

        mp.clear();
        edges.resize(m);

        for(auto &it: edges) cin >> it.second.first >> it.second.second >> it.first;

        sort(edges.rbegin(), edges.rend());

        ll ans = solve(n);

        cout << "Case " << cs << ": " << ans << "\n";
    }


}



