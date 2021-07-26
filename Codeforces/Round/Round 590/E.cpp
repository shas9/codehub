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

    segTree(ll n): n(n), tree(4*n, 0), lazy(4*n, 0) {}

    void propagate(ll node, ll l, ll r)
    {
        tree[node] += lazy[node] * (r - l + 1);
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

        tree[node] = tree[2*node] + tree[2*node+1];
    }

    void update(ll l, ll r, ll val) {

		if(l > r) swap(l,r);
		treeUpdate(1, 1, n, l + 1, r - 1, val);
    }

    ll treeQuery(ll node, ll l, ll r, ll u, ll v)
    {
        ll mid = (l+r)>>1;

        propagate(node, l, r);

        if(l > v || r < u) return 0;
        if(l >= u && r <= v) return tree[node];

        return treeQuery(2*node, l, mid, u, v) + treeQuery(2*node+1, mid+1, r, u, v);
    }

    ll query(ll l, ll r) { return treeQuery(1, 1, n, l, r); }
};

vector < ll > g[200005];
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m)
    {
		segTree tree(n);

		for(ll i = 0; i < n; i++) g[i].clear();

		ll prv;

		ll tans = 0;

		for(ll i = 1; i <= m; i++)
		{
			slld(input);

			if(i > 1)
			{
				if(input == prv) continue;
				g[input].pb(prv);
				g[prv].pb(input);

				if(abs(input - prv) >= 2) tree.update(input, prv, 1);

				tans += abs(input - prv);
			}

			prv = input;
		}

		for(i = 1; i <= n; i++)
		{
			ans = tans;

			for(auto it: g[i])
			{
				ans -= abs(it - i);

				if(it > i) ans += (it - 1);
				else ans += it;
			}

//			cout << i << ": " << ans << endl;

			ans -= tree.query(i,i);

			printf("%lld ", ans);
		}

		printf("\n");

    }
}



