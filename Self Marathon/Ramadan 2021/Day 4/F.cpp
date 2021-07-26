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

const ll N = 2e5+7;
struct DSU {
    ll rep[N], sz[N];

    void init() {
        for (ll i=0; i<N; i++)
            rep[i] = i, sz[i] = 1;
    }

    ll find(ll u) {
        while(rep[u] != u)  u = rep[u];
        return u;
    }

    bool merge(ll u, ll v) {
        u = find(u);
        v = find(v);
        if (u == v)   return false;

        if (sz[u] < sz[v])    swap(u, v);
        rep[v] = u;
        sz[u] += sz[v];

        return true;
    }
} dsu;

vector < ll > g[N];
vector < pair < ll, pll > > edge;
set < ll > st;
bool vis[N];
ll tot;

void dfs(ll node)
{
    vis[node] = 1;
    st.erase(node);

    for(set < ll > :: iterator it = st.begin(); it != st.end(); )
    {
        ll v = *it;

        if(!binary_search(g[node].begin(), g[node].end(), v))
        {
            if(dsu.merge(node,v))
            {
//                cout << node << " ++ " C<< v << "\n";
                tot++;
            }

            dfs(v);

            it = st.upper_bound(v);
        }
        else it++;
    }

    return;
}

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    fastio;
    while(cin >> n >> m)
    {
        dsu.init();

        ans = tot = 0;
        ll add = 0;

        for(ll i = 1; i <= n; i++)
        {
            g[i].clear();
            vis[i] = 0;
        }

        edge.resize(m);
        st.clear();


        for(auto &it: edge)
        {
            cin >> it.second.first >> it.second.second >> it.first;
            g[it.second.first].push_back(it.second.second);
            g[it.second.second].push_back(it.second.first);
            add ^= it.first;
        }


        for(ll i = 1; i <= n; i++)
        {
            st.insert(i);
            sort(g[i].begin(), g[i].end());
//
//            cout << i << " : ";
//            for(auto it: g[i]) cout << it << " ";
//            cout << "\n";
        }

        sort(edge.begin(), edge.end());

        for(ll i = 1; i <= n; i++)
        {
            if(vis[i] == 0)
            {
                dfs(i);
            }
        }

        DSU dsu2;

        dsu2.init();

        for(auto it: edge)
        {
            ll u = it.second.first;
            ll v = it.second.second;

            if(dsu.merge(u,v))
            {
                ans += it.first;
                dsu2.merge(u,v);
            }
        }

        ll baki = (n * (n - 1)) / 2 - m;

//        cout << tot << "\n";

        if(tot == baki)
        {
            for(auto it: edge)
            {
                ll u = it.second.first;
                ll v = it.second.second;

                if(dsu2.find(u) != dsu2.find(v))
                {
                    add = min(add, it.first);
                }
            }

            ans += add;
        }

        cout << ans << "\n";
    }


}

