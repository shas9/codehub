// God put a smile upon your face <3

#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb push_back

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

const ll maxn = 500005;
ll mp[maxn];
ll subtree[maxn];
vector < ll > g[maxn];

struct segTree
{
    ll n;
    vector <ll> tree, lazy;
    vector <bool> mark;

    segTree(ll n): n(n), tree(4*n, 0), lazy(4*n, 0), mark(4 * n, 0) {}

    void propagate(ll node, ll l, ll r)
    {
		if(mark[node]) tree[node] = 0;
        tree[node] += lazy[node];
        if(l != r)
        {
			if(mark[node])
			{
				lazy[2*node] = 0;
				lazy[2*node+1] = 0;

			}
			lazy[2*node] += lazy[node];
			lazy[2*node+1] += lazy[node];

			mark[2*node] = mark[2*node] | mark[node];
			mark[2*node + 1] = mark[2*node] | mark[node];
        }
        lazy[node] = 0;
        mark[node] = 0;
    }

    void treeUpdate(ll node, ll l, ll r, ll idx)
    {
        ll mid = (l+r)>>1;

        propagate(node, l, r);

        if(l > idx || r < idx) return;
        if(l >= idx && r <= idx)
        {
            lazy[node] = 1;
            propagate(node, l, r);

            return;
        }

        treeUpdate(2*node, l, mid, idx);
        treeUpdate(2*node+1, mid+1, r, idx);

        tree[node] = max(tree[2*node], tree[2*node+1]);
    }

    void update(ll idx) { treeUpdate(1, 1, n, idx); }

    void treeclr(ll node, ll l, ll r, ll u, ll v)
    {
        ll mid = (l+r)>>1;

        propagate(node, l, r);

        if(l > v || r < u) return;
        if(l >= u && r <= v)
        {
            mark[node] = 1;
            lazy[node] = 0;
			propagate(node, l, r);
            return;
        }

        treeclr(2*node, l, mid, u, v);
        treeclr(2*node+1, mid+1, r, u, v);

        tree[node] = max(tree[2*node], tree[2*node+1]);
    }

    void clr(ll l, ll r) { treeclr(1, 1, n, l, r); }

    ll treeQuery(ll node, ll l, ll r, ll u, ll v)
    {
        ll mid = (l+r)>>1;

        propagate(node, l, r);

        if(l > v || r < u) return mnlld;
        if(l >= u && r <= v) return tree[node];

        return max(treeQuery(2*node, l, mid, u, v), treeQuery(2*node+1, mid+1, r, u, v));
    }

    ll query(ll l, ll r) { return treeQuery(1, 1, n, l, r); }
};

ll cnt;
ll par[maxn];

void dfs(ll node, ll parr)
{
	mp[node] = ++cnt;
	subtree[node] = 1;
	par[node] = parr;

	for(auto it: g[node])
	{
		if(it != parr)
		{
			dfs(it,node);
			subtree[node] += subtree[it];
		}
	}
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(n);

    for(ll i = 1; i < n; i++)
    {
		ll u, v;

		slld(u);
		slld(v);

		g[u].pb(v);
		g[v].pb(u);
    }

	cnt = 0;

    dfs(1,-1);

    slld(m);

    segTree tree(n);

    for(ll i = 1; i <= n; i++) tree.update(i);

    for(ll i = 1; i <= m; i++)
    {
		ll t, v;

		slld(t);
		slld(v);

		if(t == 1)
		{
			ans = tree.query(mp[v],mp[v] + subtree[v] - 1);

			if(ans && par[v] != -1)
			{
				tree.update(mp[par[v]]);
			}

			tree.clr(mp[v], mp[v] + subtree[v] - 1);
		}
		else if(t == 2)
		{
			tree.update(mp[v]);
		}
		else
		{
			ans = tree.query(mp[v], mp[v] + subtree[v] - 1);

//			cout << mp[v] << " " << mp[v] + subtree[v] - 1 << endl;

			if(ans) printf("0\n");
			else printf("1\n");
		}

//		for(ll j = 1; j <= 30; j++)
//		{
//			cout << j << ": " << tree.tree[j] << " " << tree.mark[j] << " " << tree.lazy[j] << endl;
//		}
    }
}

/*

15
1 2
1 3
3 4
4 5
4 6
3 7
7 8
1 9
9 10
10 11
11 12
9 13
9 14
1 15
5
1 1
2 12
3 10
1 11
3 10

*/
