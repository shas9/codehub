#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%d", &longvalue)

#define ll int
#define ull unsigned long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009


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
    vector<pll> tree;
    vector<ll> lazy;

    segTree(ll n): n(n), tree(4*n, {0,0}), lazy(4*n, 0) {}

    void propagate(ll node, ll l, ll r)
    {
        tree[node].first += lazy[node];
        tree[node].second += lazy[node];
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

        tree[node].first = max(tree[2*node].first, tree[2*node+1].first);
        tree[node].second = min(tree[2*node].second, tree[2*node+1].second);
    }

    void update(ll l, ll r, ll val) { treeUpdate(1, 1, n, l, r, val); }

    pll treeQuery(ll node, ll l, ll r, ll u, ll v)
    {
        ll mid = (l+r)>>1;

        propagate(node, l, r);

        if(l > v || r < u) return {mnd,mxd};
        if(l >= u && r <= v) return tree[node];

        pll x = treeQuery(2*node, l, mid, u, v);
        pll y = treeQuery(2*node+1, mid+1, r, u, v);

        return {max(x.first,y.first), min(x.second,y.second)};
    }

    pll query(ll l, ll r) { return treeQuery(1, 1, n, l, r); }
};

char str[1000006];
char cc[1000006];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);
//
//    freopen("output.txt", "a", stdout);

    slld(n);
    {
		scanf("%s", str + 1);

		n = strlen(str + 1);

		segTree tree(n);

		ll curr = 1;
		ll sum = 0;
		for(ll i = 1; i <= n; i++)
		{
			char it = str[i];

			if(it == 'R') curr++;
			if(it == 'L') curr--;

			curr = max(curr,1);

			if(it != 'R' && it != 'L')
			{
				if(cc[curr] == '(')
				{
					sum--;
					tree.update(curr,n,-1);
				}
				else if(cc[curr] == ')')
				{
					sum++;
					tree.update(curr,n,1);
				}

				cc[curr] = it;
			}

			if(it == '(')
			{
				sum++;
				tree.update(curr,n,1);
			}
			else if(it == ')')
			{
				sum--;
				tree.update(curr,n,-1);
			}

			if(sum) printf("-1 ");
			else
			{
				pll qq = tree.query(1,n);

				if(qq.second < 0) printf("-1 ");
				else printf("%lld ", qq.first);
			}
		}

		printf("\n");
    }

}



