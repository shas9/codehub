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

struct p
{
    ll x, y, z;
};

const bool operator<(const p& a, const p& b)
{

    if(a.x < b.x) return 1;
    if(a.x > b.x) return 0;

    if(a.y < b.y) return 1;
    if(a.y > b.y) return 0;

    if(a.z < b.z) return 1;
    if(a.z > b.z) return 0;

    return 0;
}

ll comp1(p a, p b)
{
    if(a.x == b.x)
    {
        if(a.y == b.y)
        {
            if(a.z == b.z) return 2;
            return a.z < b.z;
        }

        return a.y < b.y;
    }

    return a.x < b.x;
}

ll comp2(pll a, pll b)
{
    if(a.first == b.first)
    {
        if(a.second == b.second) return 2;

        return a.second < b.second;
    }

    return a.first < b.first;
}

vector < pair < p, p > > v;
vector < bool > vis;
vector < vector < ll > > g;

bool dfs(ll x, ll par)
{
    if(vis[x]) return 1;

    vis[x] = 1;

    for(auto it: g[x])
    {
        if(it == x) continue;
        if(it == par) continue;

        bool on = dfs(it, x);

        if(on) return 1;
    }

    return 0;
}

bool solve1()
{
    map < p, ll > mp;

    ll cnt = 0;

    for(auto it: v)
    {
        if(mp.find(it.first) == mp.end()) mp[it.first] = ++cnt;
        if(mp.find(it.second) == mp.end()) mp[it.second] = ++cnt;
    }

    map < pair < ll, ll >, bool > mp1;

    g.assign(cnt + 2, {});
    vis.assign(cnt + 2, 0);

    for(auto it: v)
    {
        ll u = mp[it.first];
        ll vv = mp[it.second];

        assert(u && vv);

//        cout << u << " " << vv << "\n";

        if(u == vv) continue;

        if(u > vv) swap(u, vv);

        if(mp1.find({u,vv}) != mp1.end()) continue;

        mp1[{u,vv}] = 1;

//        cout << "Dhukse\n";


        g[u].push_back(vv);
        g[vv].push_back(u);
    }

    for(ll i = 1; i <= cnt; i++)
    {
        if(vis[i] == 0)
        {
            bool d = dfs(i,-1);

            if(d) return 1;
        }
    }

    return 0;
}


bool solve2()
{
    vector < pair < pll, pll > > v1;

    map < pll, ll > mp;

    ll cnt = 0;

    for(auto it: v)
    {
        v1.push_back({{it.first.x, it.first.y}, {it.second.x, it.second.y}});
    }

    for(auto it: v1)
    {
        if(mp.find(it.first) == mp.end()) mp[it.first] = ++cnt;
        if(mp.find(it.second) == mp.end()) mp[it.second] = ++cnt;
    }

    map < pll , bool > mp1;

    g.assign(cnt + 2, {});
    vis.assign(cnt + 2, 0);

    for(auto it: v1)
    {
        ll u = mp[it.first];
        ll vv = mp[it.second];


        assert(u && vv);

        if(u == vv) continue;

        if(u > vv) swap(u, vv);

        if(mp1.find({u,vv}) != mp1.end()) continue;

        mp1[{u,vv}] = 1;

        g[u].push_back(vv);
        g[vv].push_back(u);
    }

    for(ll i = 1; i <= cnt; i++)
    {
        if(vis[i] == 0)
        {
            bool d = dfs(i,-1);

            if(d) return 1;
        }
    }

    return 0;
}

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
        v.resize(n);

        for(auto &it: v)
        {
            cin >> it.first.x;
            cin >> it.first.y;
            cin >> it.first.z;

            cin >> it.second.x;
            cin >> it.second.y;
            cin >> it.second.z;

        }

        if(solve1()) cout << "True closed chains\n";
        else cout << "No true closed chains\n";

        if(solve2()) cout << "Floor closed chains\n";
        else cout << "No floor closed chains\n";
    }


}

