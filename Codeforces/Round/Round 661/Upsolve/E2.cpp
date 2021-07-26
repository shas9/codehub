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

map < ll, ll > typ;

ll get(pll top)
{
    ll ret = top.first * top.second;
    top.second /= 2;
    ret -= top.first * top.second;

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
        cin >> n >> m;

        for(ll i = 1; i <= n; i++) g[i].clear(), arr[i].first = 0;
        mp.clear();
        typ.clear();

        for(ll i = 1; i < n; i++)
        {
            ll u, v, w, c;

            cin >> u >> v >> w >> c;

            g[u].pb(v);
            g[v].pb(u);

            mp[{u,v}] = i;
            mp[{v,u}] = i;

            arr[i].second = w;
            typ[i] = c;

        }

        dfs(1,-1);

        ll cost = 0;

        priority_queue < pll, vector < pll >, comp > pq1, pq2;

        for(ll i = 1; i < n; i++)
        {
            cost += arr[i].first * arr[i].second;
            if(typ[i] == 1) pq1.push({arr[i].first, arr[i].second});
            else pq2.push({arr[i].first, arr[i].second});
        }

        vector < ll > v1, v2;

        v1.push_back(0);
        v2.push_back(0);

        while(!pq1.empty())
        {
            pll top = pq1.top();
            pq1.pop();

            ll g = get(top);

            top.second /= 2;

            v1.push_back(g);

            if(top.second) pq1.push(top);
        }

        while(!pq2.empty())
        {
            pll top = pq2.top();
            pq2.pop();

            ll g = get(top);

            top.second /= 2;

            v2.push_back(g);

            if(top.second) pq2.push(top);
        }

        for(ll i = 1; i < v1.size(); i++) v1[i] += v1[i - 1];
        for(ll i = 1; i < v2.size(); i++) v2[i] += v2[i - 1];

        ans = mxlld;

        for(ll i = 0; i < v1.size(); i++)
        {
            ll need = cost - m - v1[i];

            if(v2.back() < need) continue;

            ll lo = 0;
            ll hi = v2.size() - 1;
            ll ret = hi;

            while(lo <= hi)
            {
                ll mid = (lo + hi) / 2;

                if(v2[mid] >= need)
                {
                    ret = mid;
                    hi = mid - 1;
                }
                else
                {
                    lo = mid + 1;
                }
            }

//            cout << i << " " << ret << " " << need << "\n";

            ans = min(ans, i + (ret * 2));
        }

        cout << ans << "\n";


    }


}

/*
1
10 22
6 5 1 1
3 2 5 1
10 8 4 1
8 7 6 2
7 6 6 1
9 8 9 1
5 3 3 1
2 1 7 1
4 3 9 2
*/
