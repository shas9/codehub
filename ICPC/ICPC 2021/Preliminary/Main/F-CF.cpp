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

map < ll, ll > vec, cost;
vector < ll > suffmax;

ll solve(ll n)
{
    for(ll i = 1; i <= n; i++)
    {
        ll u, v;

        cin >> u >> v;

        if(v < u)
        {
            swap(u,v);
            cost[u] = 1;
        }

        vec[u] = v;

        if(v <= n) return -1;
    }

    suffmax.assign(n + 5, 0);

    for(ll i = n; i >= 1; i--)
    {
        suffmax[i] = max(suffmax[i + 1], vec[i]);
    }

    ll prefixmin = mxlld;
    vector < ll > s1, s2;
    ll c1 = 0, c2 = 0;

    ll ret = 0;

    for(ll i = 1; i <= n; i++)
    {
        ll x = vec[i];

        prefixmin = min(prefixmin, x);

        if(s1.empty() || x < s1.back())
        {
            s1.push_back(x);
            c1 += cost[i];
        }
        else if(s2.empty() || x < s2.back())
        {
            s2.push_back(x);
            c2 += cost[i];
        }
        else return -1;

//        cout << c1 << " " << c2 << " " << s1.size() << " " << s2.size() << "\n";

        if(prefixmin > suffmax[i + 1])
        {
            ret += min(c1 + s2.size() - c2, c2 + s1.size() - c1);
            s1.clear();
            s2.clear();
            c1 = c2 = 0;
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

    cin >> n;
    {
        vec.clear();
        cost.clear();

        cout << solve(n) << "\n";
    }


}
