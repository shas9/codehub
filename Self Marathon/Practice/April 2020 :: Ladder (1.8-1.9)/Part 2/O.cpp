#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
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

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);


    while(cin >> n >> m)
    {
		set < pll > st;
		segTree tree(n);

		for(i = 1; i <= n + 1; i++)
		{
			st.insert({i,i});
		}

		for(i = 1; i <= m; i++)
		{
			ll t;

			slld(t);
			slld(l);
			slld(r);

			if(t == 2)
			{
				printf("%lld\n", tree.query(l,r));
			}
			else
			{
				slld(input);

				set < pll > ::iterator it, jt, kt, mt;

				it = st.lower_bound({l,0});

				if(it->first != l)
				{
					jt = it;
					jt--;
					st.insert({l,jt->second});
				}

				it = st.upper_bound({r,mxlld});

				if(it -> first != r + 1)
				{
					jt = it;
					jt--;
					st.insert({r + 1,jt->second});
				}

				it = st.lower_bound({l,0});
				jt = st.upper_bound({r,mxlld});

//				bug;

				for(kt = it; kt != jt; kt = st.erase(kt))
				{
					ll a = kt->first;
					mt = kt;
					mt++;
					ll b = mt->first - 1;

//					cout << a << " " << b << endl;

					tree.update(a,b,abs(input-kt->second));
				}

				st.insert({l,input});
			}
		}
    }


}


