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

const ll mx = 300005;

ll cenpar[mx];
ll sz[mx];
bool done[mx];
ll n, ans[mx];
ll arr[mx];

vector < ll > g[mx];

struct BIT
{
       ll tree[mx];
       ll query(ll idx)
       {
              ll sum=0;
              while(idx>0){
                    sum+=tree[idx];
                    idx -= idx & (-idx);
              }
              return sum;
       }

       void update(ll idx, ll x, ll n) //n is the size of the array, x is the number to add
       {
              while(idx<=n)
              {
                    tree[idx]+=x;
                    idx += idx & (-idx);
              }
       }
} tree1, tree2;

void dfs(ll node, ll par)
{
	sz[node] = 1;

	for(auto it: g[node])
	{
		if(it != par && done[it] == false)
		{
			dfs(it,node);
			sz[node] += sz[it];
		}
	}
}

void calc(ll node, ll par, ll d = 1)
{
	ans[node] += (tree2.query(node) * d) + tree1.query(node);

	for(auto it: g[node])
	{
		if(it != par && done[it] == false)
			calc(it,node, d + 1);
	}
}

void update(ll node, ll par, ll d = 1)
{
	tree1.update(node, d, n);
	tree2.update(node, 1, n);

	for(auto it: g[node])
	{
		if(it != par && done[it] == false)
		{
			update(it,node,d + 1);
		}
	}
}

void rem(ll node, ll par, ll d = 1)
{
	tree1.update(node, - d, n);
	tree2.update(node, - 1, n);

	for(auto it: g[node])
	{
		if(it != par && done[it] == false)
		{
			rem(it,node,d + 1);
		}
	}
}

ll decompose(ll cen)
{
	dfs(cen,-1);

	ll target = sz[cen] / 2;
	ll p = -1;
	bool ok = false;

	while(!ok)
	{
		ok = true;

		for(auto it: g[cen])
		{
			if(it != p && done[it] == false && sz[it] > target)
			{
				ok = false;
				p = cen;
				cen = it;
				break;
			}
		}
	}

	done[cen] = true;

	update(cen,-1,0);

	ans[cen] += tree1.query(cen);

	for(auto it: g[cen])
	{
		if(done[it] == false)
		{
			rem(it,cen);
			calc(it,cen);
			update(it,cen);
		}
	}

	rem(cen,-1,0);

	for(auto it: g[cen])
	{
		if(done[it] == false)
		{
			cenpar[decompose(it)] = cen;
		}
	}

	return cen;
}

pll bst[mx];

struct segTree
{
    ll n;
    vector<ll> tree, lazy;

    segTree(ll n): n(n), tree(4*n, 0), lazy(4*n, 0) {}

    void propagate(ll node, ll l, ll r)
    {
        if(lazy[node]) tree[node] = lazy[node];
        if(l != r && lazy[node]) lazy[2*node] = lazy[node], lazy[2*node+1] = lazy[node];
        lazy[node] = 0;
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

        tree[node] = max(tree[2*node], tree[2*node+1]);
    }

    void update(ll l, ll r, ll val) { treeUpdate(1, 1, n, l, r, val); }

    ll treeQuery(ll node, ll l, ll r, ll u, ll v)
    {
        ll mid = (l+r)>>1;

        propagate(node, l, r);

        if(l > v || r < u) return 0;
        if(l >= u && r <= v) return tree[node];

        return max(treeQuery(2*node, l, mid, u, v), treeQuery(2*node+1, mid+1, r, u, v));
    }

    ll query(ll l, ll r) { return treeQuery(1, 1, n, l, r); }
};

void ins(ll idx)
{
	ll u = 1;

	while(u != idx)
	{
		ll v;

		if(arr[idx] < arr[u])
		{
			if(bst[u].first == -1)
			{
				bst[u].first = idx;
			}

			v = bst[u].first;
		}
		else
		{
			if(bst[u].second == -1)
			{
				bst[u].second = idx;
			}

			v = bst[u].second;
		}

		u = v;
	}
}

void trav(ll node, ll par = -1)
{
	cout << node << " " << par << endl;

	for(auto it: g[node])
	{
		if(it != par)
		{
			trav(it, node);
		}
	}
}

void construct(ll node)
{
	if(bst[node].first != -1)
	{
		g[node].pb(bst[node].first);
		g[bst[node].first].pb(node);
		construct(bst[node].first);
	}

	if(bst[node].second != -1)
	{
		g[node].pb(bst[node].second);
		g[bst[node].second].pb(node);
		construct(bst[node].second);
	}
}
pll range[mx];

int main()
{
    ll i, j, k, l, m, o, r, q;
    ll testcase;
    ll input, flag, tag;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(n);

    for(ll i = 1; i <= n; i++)
    {
		slld(arr[i]);

		bst[i] = {-1,-1};
    }

    segTree tree(n);

    tree.update(1,n,1);

    range[1] = {1,n};

//    for(ll i = 1; i <= 4 * n; i++)
//    {
//		cout << tree.tree[i] << " + ";
//    }
//
//    cout << endl;
//
//    for(ll i = 1; i <= n; i++)
//    {
//		cout << tree.query(i,i) << " ~ ";
//    }
//
//    cout << endl;

    for(ll i = 2; i <= n; i++)
    {
		ll idx = tree.query(arr[i], arr[i]);

//		cout << i << ": " << idx << endl;
//
//		for(ll i = 1; i <= 4 * n; i++)
//		{
//			cout << tree.tree[i] << " - ";
//		}
//
//		cout << endl;
//
//		    for(ll i = 1; i <= n; i++)
//		{
//			cout << tree.query(i,i) << " ~ ";
//		}
//
//		cout << endl;


		g[i].pb(idx);
		g[idx].pb(i);

		if(arr[i] < arr[idx])
		{
			if(arr[idx] > 1) tree.update(range[idx].first, arr[idx] - 1, i);
			range[i] = {range[idx].first, arr[idx] - 1};
		}
		else
		{
			if(arr[idx] < n) tree.update(arr[idx] + 1, range[idx].second, i);
			range[i] = {arr[idx] + 1, range[idx].second};
		}

    }

//    construct(1);

//    trav(1);

    decompose(1);

    ll sum = 0;

    for(ll i = 1; i <= n; i++)
    {
		sum += ans[i];

		printf("%lld\n", sum);
    }
}


