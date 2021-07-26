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
    vector<ll> tree, lazy;
    vector<ll> zero;

    segTree(): zero(400000,0), tree(400000, 0), lazy(400000, 0) {}

    void dec(ll x)
    {
		n = x;
    }


    void init(ll node, ll l, ll r)
    {
//		cout << l << " " << r << " " << n << endl;
		if(l == r)
		{
			zero[node] = 1;
			return;
		}

		init(node << 1, l, (l + r) >> 1);
		init((node << 1) + 1, ((l + r) >> 1) + 1, r);

		zero[node] = zero[node << 1] + zero[(node << 1) + 1];
    }

    void propagate(ll node, ll l, ll r)
    {
        tree[node] += (lazy[node] * (r - l + 1));

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

			if(tree[node]) zero[node] = 0;
			else
			{
				if(l != r) zero[node] = zero[node * 2] + zero[node * 2 + 1];
				else zero[node] = 1;
			}


            return;
        }

        treeUpdate(2*node, l, mid, u, v, val);
        treeUpdate(2*node+1, mid+1, r, u, v, val);

        tree[node] = tree[2*node] + tree[2*node+1];
        zero[node] = zero[2*node] + zero[2*node+1];
     }

    void update(ll l, ll r, ll val) { treeUpdate(1, 1, n, l, r, val); }


    ll treeQuery(ll node, ll l, ll r, ll u, ll v)
    {
        ll mid = (l+r)>>1;

        propagate(node, l, r);

        if(l > v || r < u) return 0;
        if(l >= u && r <= v) return tree[node];

        return treeQuery(2*node, l, mid, u, v) + treeQuery(2*node+1, mid+1, r, u, v);
    }

    ll query(ll l) { return treeQuery(1, 1, n, l, l); }

    ll cnt()
    {
		return (n - zero[1]);
    }
};

vector < ll > graph[100005];
ll mp1[100005], mp2[100005];
vector < ll > qq[100005];
ll subtree[100005];
ll ans[100005];
ll n;
segTree tree;
ll mark;

void dfslevel(ll node, ll par)
{
//	if(mark <= 10) cout << node << " " << par << endl;
	++mark;
	mp2[node] = mark;
	subtree[node] = 1;

	for(auto it: graph[node])
	{
		if(it == par) continue;

		dfslevel(it,node);

		subtree[node] += subtree[it];
	}
}

void dfs(ll node, ll par)
{
	ans[node] = 0;

	for(auto it: qq[node])
	{
		ll a = mp2[node];
		ll b = mp2[it];

//		cout << node << " " << a << " " << a + subtree[node] - 1 << " @ " << b << " " << b + subtree[it] - 1 << endl;

		tree.update(a, a + subtree[node] - 1,1);
		tree.update(b, b + subtree[it] - 1,1);
	}

	ans[node] = tree.cnt();

//	cout << ans[node] << " !! ";

	if(tree.query(mp2[node])) ans[node]--;

//	cout << ans[node] << endl;
	for(auto it: graph[node])
	{
		if(it == par) continue;

		dfs(it,node);
	}

	for(auto it: qq[node])
	{
		ll a = mp2[node];
		ll b = mp2[it];

		tree.update(a, a + subtree[node] - 1,-1);
		tree.update(b, b + subtree[it] - 1,-1);
	}
}

int main()
{
    ll i, j, k, l, m, o, r, q;
    ll testcase;
    ll input, flag, tag;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

	while(cin >> n >> m)
	{
		for(i = 1; i <= n; i++) graph[i].clear(), qq[i].clear();

		tree.dec(n);

		for(i = 1; i < n; i++)
		{
			ll u, v;
			slld(u);
			slld(v);

			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		mark = 0;

		dfslevel(1,0);

//		for(i = 1; i <= n; i++) cout << mp2[i] << " ";
//
//		cout << endl;

		for(i = 1; i <= m; i++)
		{
			ll u, v;
			slld(u);
			slld(v);

			qq[u].pb(v);
			qq[v].pb(u);
		}

//		bug;
		tree.init(1,1,n);

//		bug;

		dfs(1,0);

		for(i = 1; i <= n; i++)
		{
			cout << ans[i] << " ";
		}

		cout << "\n";
	}


}



