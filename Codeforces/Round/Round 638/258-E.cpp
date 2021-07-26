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

#define mod 958585860497

#define base 2001487

using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

struct segTree
{
    ll n;
    vector<ll> tree, lazy, cnt;

    segTree(ll n): n(n), tree(4*n, 0), lazy(4*n, 0), cnt(4*n,0) {}

    void init(ll node, ll i, ll j)
    {
		if(i == j)
		{
			cnt[node] = 1;
			return;
		}

		init(node * 2, i, (i + j) / 2);
		init(node * 2 + 1, (i + j) / 2 + 1, j);

		cnt[node] = cnt[node * 2] + cnt[node * 2 + 1];

//		cout << i << " " << j << " " << cnt[node] << endl;
    }

    void propagate(ll node, ll l, ll r)
    {
        tree[node] += lazy[node];
        if(l != r) lazy[2*node] += lazy[node], lazy[2*node+1] += lazy[node];
        lazy[node] = 0;
    }

    void treeUpdate(ll node, ll l, ll r, ll u, ll v, ll val)
    {
        ll mid = (l+r)>>1;

        propagate(node, l, r);

        if(l > v || r < u) return;
        if(l >= u && r <= v)
        {
            lazy[node] += val;
            propagate(node, l, r);

            return;
        }

        treeUpdate(2*node, l, mid, u, v, val);
        treeUpdate(2*node+1, mid+1, r, u, v, val);

        tree[node] = min(tree[2*node], tree[2*node+1]);

        cnt[node] = 0;

        if(tree[node] == tree[2*node]) cnt[node] += cnt[node * 2];

        if(tree[node] == tree[2*node + 1]) cnt[node] += cnt[node * 2 + 1];
    }

    void update(ll l, ll r, ll val) { treeUpdate(1, 1, n, l, r, val); }

    pll treeQuery(ll node, ll l, ll r, ll u, ll v)
    {
        ll mid = (l+r)>>1;

        propagate(node, l, r);

        if(l > v || r < u) return {mxlld,0};
        if(l >= u && r <= v) return {tree[node],cnt[node]};

        pll x = treeQuery(2*node, l, mid, u, v);
        pll y = treeQuery(2*node+1, mid+1, r, u, v);

        if(x.first == y.first) return {x.first,x.second + y.second};

        return min(x,y);
    }

    pll query(ll l, ll r) { return treeQuery(1, 1, n, l, r); }

    ll solve(ll node)
    {
		pll ask = query(1,n);

		if(ask.first != 0) return n - 1;

		ll ret = (n - ask.second);

		if(query(node,node).first) ret--;

		return ret;
    }
};

const ll maxn = 100000;
vector < ll > graph[maxn + 5];
vector < ll > qq[maxn + 5];
ll mark;
ll mp[maxn + 5];
segTree tree(maxn);
ll subtree[maxn + 5];
ll ans[maxn + 5];

void dfs(ll node, ll par = 0)
{
	++mark;
	mp[node] = mark;
	subtree[node] = 1;

//	cout << node << " !! " << mark << endl;

	for(auto it: graph[node])
	{
		if(it == par) continue;

		dfs(it,node);

		subtree[node] += subtree[it];
	}
}

void dfs1(ll node, ll par = 0)
{
	for(auto it: qq[node])
	{
		ll enode = mp[node];
		ll eit = mp[it];

		tree.update(enode, enode + subtree[node] - 1, 1);
		tree.update(eit, eit + subtree[it] - 1, 1);
	}

//	for(ll i = 1; i <= tree.n; i++)
//	{
//		cout << tree.query(i,i).first << " ";
//	}
//
//	cout << endl;

	ans[node] = tree.solve(mp[node]);

	for(auto it: graph[node])
	{
		if(it == par) continue;

		dfs1(it,node);
	}

	for(auto it: qq[node])
	{
		ll enode = mp[node];
		ll eit = mp[it];

		tree.update(enode, enode + subtree[node] - 1, -1);
		tree.update(eit, eit + subtree[it] - 1, -1);
	}
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag;

    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(n);
    slld(m);

    for(i = 1; i < n; i++)
    {
		ll u, v;
		slld(u);
		slld(v);

		graph[u].pb(v);
		graph[v].pb(u);
    }

    mark = 0;

    dfs(1);

    for(i = 1; i <= m; i++)
    {
		ll u, v;

		slld(u);
		slld(v);

		qq[u].pb(v);
		qq[v].pb(u);
    }

    tree.n = n;
    tree.init(1,1,n);

    dfs1(1);

    for(i = 1; i <= n; i++)
    {
		printf("%lld ", ans[i]);
    }

    printf("\n");
}


