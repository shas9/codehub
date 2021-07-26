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

vector < pll > v;
vector < pll > g[100005];

ll fnd(ll x)
{
    ll lo = 0;
    ll hi = v.size() - 1;
    ll ret = 0;

    while(lo <= hi)
    {
        ll mid = (lo + hi) / 2;

        if(v[mid].first <= x)
        {
            ret = mid;
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }

    return ret;
}
void build(ll n)
{
    for(ll i = 0; i < n; i++)
    {
        if(i) g[i].push_back({i - 1, 0});

        ll largej = fnd(v[i].first + v[i].second);

        if(largej != i) g[i].push_back({largej,0});
        else if(largej + 1 < n) g[i].push_back({largej + 1, v[largej + 1].first - (v[i].first + v[i].second)});
    }

    return;

}

vector < ll > dist;

ll solve(ll n)
{
    build(n);

    dist.assign(n, 1e16);

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
            ll d = top.first + it.second;

            if(dist[it.first] > d)
            {
                dist[it.first] = d;
                pq.push({-d,it.first});
            }
        }
    }

    return dist[n - 1];

}

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    fastio;
    while(cin >> n)
    {

        for(ll i = 0; i < n; i++) g[i].clear();

        ans = 0;

        v.resize(n);

        for(auto &it: v) cin >> it.first >> it.second, ans += it.second;

        sort(v.begin(), v.end());

        ans += solve(n);

        cout << ans << "\n";
    }


}


