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

    segTree(ll n): n(n), tree(4*n, 0), lazy(4*n, 0) {}

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

        tree[node] = max(tree[2*node], tree[2*node+1]);
    }

    void update(ll l, ll r, ll val) { treeUpdate(1, 0, n, l, r, val); }

    ll treeQuery(ll node, ll l, ll r, ll u, ll v)
    {
        ll mid = (l+r)>>1;

        propagate(node, l, r);

        if(l > v || r < u) return mnlld;
        if(l >= u && r <= v) return tree[node];

        return max(treeQuery(2*node, l, mid, u, v), treeQuery(2*node+1, mid+1, r, u, v));
    }

    ll query(ll l, ll r) { return treeQuery(1, 0, n, l, r); }
};

map < ll , ll > mp;

vector < ll > lft, rgt, typ;
vector < ll > en[1000006];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
		lft.resize(n);
		rgt.resize(n);
		typ.resize(n);
		mp.clear();

		for(ll i = 0; i < n; i++)
		{
			cin >> lft[i] >> rgt[i] >> typ[i];

			mp[lft[i]] = mp[rgt[i]] = 0;
		}

		ll sz = 0;

		for(auto &it: mp) it.second = ++sz;

		for(ll i = 0; i <= sz; i++) en[i].clear();

		for(ll i = 0; i < n; i++)
		{
			lft[i] = mp[lft[i]];
			rgt[i] = mp[rgt[i]];
			en[rgt[i]].pb(i);
		}

		segTree t1(sz), t2(sz);

		ans = 1;

		for(ll i = 0; i <= sz; i++)
		{
			for(auto it: en[i])
			{
				if(typ[it] == 1) t1.update(0, lft[it] - 1, 1);
				else t2.update(0,lft[it] - 1, 1);
			}

			ll dp1 = t1.query(0,sz);
			ll dp2 = t2.query(0,sz);

			t1.update(i,i,dp2);
			t2.update(i,i,dp1);

			ans = max(max(dp1,dp2), ans);
		}

		cout << ans << "\n";
    }


}



