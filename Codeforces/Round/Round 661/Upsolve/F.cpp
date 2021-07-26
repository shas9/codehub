 // Lights will guide you home

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll int
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

vector < pll > v;
map < pll, ll > p;
ll dp[6003][6003];
vector < ll > g[6003];

ll solve(ll l, ll r)
{
    if(l > r) return 0;

    ll &ret = dp[l][r];

    if(ret != -1) return ret;

    ret = 0;

    if(p.find({l,r}) != p.end()) ret = p[{l,r}];

    if(l == r) return ret;

    ll mx = max(solve(l + 1, r), solve(l, r - 1));

    for(auto it: g[l])
    {
        if(it >= r) continue;

        mx = max(mx, solve(l,it) + solve(it + 1, r));
    }

    ret += mx;

//    cout << l << " " << r << " " << ret << " " << p[{l,r}] << endl;

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
        map < ll, ll > mp;

        cin >> n;
        v.resize(n);

        for(auto &it: v) cin >> it.first >> it.second, mp[it.first] = 0, mp[it.second] = 0;

        ll cnt = 0;

        for(auto &it: mp)
        {
            it.second = ++cnt;
        }

        p.clear();

        for(auto &it: v) it.first = mp[it.first], it.second = mp[it.second];

        for(ll i = 0; i <= cnt; i++) for(ll j = 0; j <= cnt; j++) dp[i][j] = -1;

        for(ll i = 0; i <= cnt; i++) g[i].clear();

        for(auto it: v) p[it]++, g[it.first].push_back(it.second);

        ans = solve(1,cnt);

        cout << ans << '\n';


    }


}
