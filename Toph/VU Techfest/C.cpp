 // God put a smile upon your face <3

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define ull unsigned long long
#define pll pair < ll, ll >

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

ll arr[2000006];
ll t1[8000006];
ll t2[8000006];
ll lazy[8000006];

struct segTree
{
    ll n;

    void init(ll node, ll l, ll r)
    {
		t1[node] = 0;
		t2[node] = 0;
		lazy[node] = 0;

		if(l == r) return;

		ll mid = (l + r) >> 1;

		init(2 * node, l , mid);
		init(2 * node + 1, mid + 1, r);
    }
    void propagate(ll node, ll l, ll r)
    {
        t1[node] += lazy[node];
        t2[node] += lazy[node] * (r - l + 1);

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

        t1[node] = min(t1[2*node] , t1[2*node+1]);
        t2[node] = (t2[2*node] + t2[2*node+1]);
    }

    void update(ll l, ll r, ll val) { treeUpdate(1, 1, n, l, r, val); }

    ll treeQuery1(ll node, ll l, ll r, ll u, ll v)
    {
        ll mid = (l+r)>>1;

        propagate(node, l, r);

        if(l > v || r < u) return 1e16;
        if(l >= u && r <= v) return t1[node];

        return min(treeQuery1(2*node, l, mid, u, v), treeQuery1(2*node+1, mid+1, r, u, v));
    }

    ll querymin(ll l, ll r) { return treeQuery1(1, 1, n, l, r); }

    ll treeQuery2(ll node, ll l, ll r, ll u, ll v)
    {
        ll mid = (l+r)>>1;

        propagate(node, l, r);

        if(l > v || r < u) return 0;
        if(l >= u && r <= v) return t2[node];

        return (treeQuery2(2*node, l, mid, u, v) + treeQuery2(2*node+1, mid+1, r, u, v));
    }

    ll querysum(ll l, ll r) { return treeQuery2(1, 1, n, l, r); }
};


int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

	segTree tree;

    for(ll cs = 1; cs <= testcase; cs++)
    {
		cin >> n;

		tree.n = n;
		tree.init(1,1,n);

		for(ll i = 1; i <= n; i++)
		{
			 slld(arr[i]);
			 tree.update(i,i,arr[i] + i - 3);
		}

		pll ans = {1,min(arr[1] - 1, arr[n] - 1)};

		tree.update(1,1,2);

		for(ll i = 2; i < n; i++)
		{
			ll lft = tree.querymin(1, n);

			ll len = min(lft, min(min(i - 1, n), n - i));
			ll cost = tree.querysum(i - len, i + len) - (((len << 1) + 1) * len);

			len = ((len << 1) + 1);
			if(len > ans.first) ans = {len, cost};
			else if(len == ans.first) ans.second = min(ans.second, cost);

			tree.update(1, i, 1);
			tree.update(i + 1, n, -1);
		}

		cout << ans.first << " " << ans.second << "\n";


    }


}


