 // God put a smile upon your face <3

#include <bits/stdc++.h>

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

struct segTree
{
    ll n;
    vector<ll> tree, lazy;

    segTree(ll n): n(n), tree(4*n, 0), lazy(4*n, -1) {}

    void propagate(ll node, ll l, ll r)
    {
        if(lazy[node] != -1)
        {
			tree[node] = lazy[node] * (r - l + 1);
			if(l != r) lazy[2*node] = lazy[node], lazy[2*node+1] = lazy[node];
			lazy[node] = -1;
        }
    }

    void treeUpdate(ll node, ll l, ll r, ll u, ll v, ll val)
    {
        ll mid = (l+r)>>1;

        propagate(node, l, r);

        if(l > v || r < u) return;
        if(l >= u && r <= v)
        {
            lazy[node] = val;
            propagate(node, l, r);

            return;
        }

        treeUpdate(2*node, l, mid, u, v, val);
        treeUpdate(2*node+1, mid+1, r, u, v, val);

        tree[node] = tree[2*node] + tree[2*node+1];
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

    ll query(ll l, ll r) { return treeQuery(1, 1, n, l, r); }
};

string s, t;
pll qq[200005];

bool solve(ll n, ll m)
{
	for(ll i = 1; i <= m; i++) cin >> qq[i].first >> qq[i].second;

	segTree seg(n);

	for(ll i = 0; i < n; i++) seg.update(i + 1, i + 1, t[i] - '0');

	for(ll i = m; i >= 1; i--)
	{
		ll ase = seg.query(qq[i].first, qq[i].second);

		ll len = (qq[i].second - qq[i].first + 1);
		ll half = ((len - 1) / 2);

		ll z = len - ase;

		if(z == ase) return 0;

		if(z < ase)
		{
			seg.update(qq[i].first, qq[i].second, 1);
		}
		else
		{
			seg.update(qq[i].first, qq[i].second, 0);
		}
	}

	for(ll i = 0; i < n; i++)
	{
		if(seg.query(i + 1, i + 1) != (s[i] - '0')) return 0;
	}

	return 1;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		cin >> n >> q;
		cin >> s >> t;

		if(solve(n,q)) cout << "YES\n";
		else cout << "NO\n";
    }


}


