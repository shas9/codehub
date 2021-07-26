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

vector < ll > g[103];
vector < ll > ans;
ll depth[103];
ll subtree[103];

ll dfs(ll node)
{
    depth[node] = 0;
    subtree[node] = 1;

    for(auto it: g[node])
    {
        depth[node] = max(depth[node], dfs(it));
        subtree[node] += subtree[it];
    }

    depth[node] += 1;

    return depth[node];
}

bool comp(ll a, ll b)
{
    if(depth[a] == depth[b]) return subtree[a] > subtree[b];

    return depth[a] < depth[b];
}

void dfs2(ll node, ll lim)
{
    ans.push_back(node);

    lim--;

    if(lim == 0) return;

    for(auto it: g[node])
    {
        ll x = min(subtree[it], lim);

        dfs2(it, x);

        lim -= x;

        ans.push_back(node);

        if(lim == 0) return;
    }

    assert(0);
}

void dfs1(ll node, ll k)
{
//    cout << node << "\n";
    sort(g[node].begin(), g[node].end(), comp);
    k--;
    ans.push_back(node);

    if(k == 0) return;

    if(k <= subtree[g[node].back()]) dfs1(g[node].back(), k);
    else
    {
        ll need = (k - subtree[g[node].back()]);

        for(ll i = 0; i + 1 < g[node].size(); i++)
        {
            ll x = min(need, subtree[g[node][i]]);

            dfs2(g[node][i], x);

            need -= x;

            ans.push_back(node);

            if(need == 0) break;
        }

        dfs1(g[node].back(), subtree[g[node].back()]);
    }

    return;

}


int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    cin >> testcase;

    for(ll cs = 1; cs <= testcase; cs++)
    {
        cin >> n >> k;

        for(ll i = 1; i <= n; i++)
        {
            g[i].clear();
            depth[i] = 0;
        }

        ans.clear();


        for(ll i = 2; i <= n; i++)
        {
            ll p;

            cin >> p;

            g[p].push_back(i);
        }


        dfs(1);

        dfs1(1,k);

        cout << ans.size() - 1 << '\n';

        for(auto it: ans) cout << it << " ";

        cout << "\n";
    }


}


