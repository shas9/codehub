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

struct Line
{
    ll m, c;
};

struct nodes
{
	Line line;
	ll lft, rgt;
};


struct DynamicLichao
{
    vector < nodes > tree;

    ll n;
    ll nowroot;
    ll type;
    ll lft, rgt;
    ll idx;

    void init(ll _t, ll l, ll r)
    {
		idx = 0;
		nowroot = 0;

		lft = l;
		rgt = r;

		n = 2e5;

        tree.clear();
        tree.resize(20 * (n + 5));

        type = _t; // 1 = maximum, 0 = minimum

        if(type & 1) for(ll i = 0; i < tree.size(); i++) tree[i] = {{0,mnlld}, -1, -1};
        else for(ll i = 0; i < tree.size(); i++) tree[i] = {{0,mxlld}, -1, -1};
    }

    inline ll f(Line &line, ll &x)
    {
        return line.m*x + line.c;
    }

    void add(ll lo, ll hi, Line line, ll node)
    {
        if(lo == hi)
        {
			if(type & 1)
            {
				 if(f(line, lo) > f(tree[node].line, lo))
					tree[node].line = line;
            }
            else
            {
				if(f(line, lo) < f(tree[node].line, lo))
					tree[node].line = line;
            }

            return;
        }

        ll mid = lo+hi >> 1;

        bool left, m;

        if(type & 1)
        {
			left = f(line, lo) > f(tree[node].line, lo);
			m = f(line, mid) > f(tree[node].line, mid);
        }
        else
        {
			left = f(line, lo) < f(tree[node].line, lo);
			m = f(line, mid) < f(tree[node].line, mid);
        }

//        cout << line.m << " " << line.c << " % " << m << " "<< f(line,mid) << " " << f(tree[node].line,mid) << endl;

        if(m) swap(line, tree[node].line);

        if(left != m)
        {
			if(tree[node].lft == -1) tree[node].lft = ++idx;

			ll left = tree[node].lft;

			add(lo, mid, line, left);
        }
        else
        {
			if(tree[node].rgt == -1) tree[node].rgt = ++idx;

			ll right = tree[node].rgt;

			add(mid+1, hi, line, right);
        }
    }

    void update(ll m, ll c)
    {
        Line x;
        x.m = m;
        x.c = c;

        add(lft,rgt,x,nowroot);
    }

    ll query(ll lo, ll hi, ll pos, ll node)
    {
        if(lo == hi)
            return f(tree[node].line, pos);

        ll mid = (lo+hi) >> 1, ret = f(tree[node].line, pos);

//        cout << node << ": " << tree[node].lft << " " << tree[node].rgt << " " << tree[node].line.m << " & " << tree[node].line.c << endl;

        if(pos <= mid)
        {
			ll left = tree[node].lft;

			if(left == -1) return ret;

			if(type & 1)
			{
				return max(ret, query(lo, mid, pos, left));
			}
			else
			{
				return min(ret, query(lo, mid, pos, left));
			}
        }
        else
        {
			ll right = tree[node].rgt;

			if(right == -1) return ret;

//			bug;

			if(type & 1)
			{
				return max(ret, query(lo, mid, pos, right));
			}
			else
			{
				return min(ret, query(lo, mid, pos, right));
			}
        }
//
//        assert(0);
    }

    ll ask(ll x)
    {
		return query(lft,rgt,x,nowroot);
    }
};


const ll tot_nodes = 2e5 + 5;

pll col[tot_nodes];
vector < ll > g[tot_nodes];
ll bigchild[tot_nodes];
bool big[tot_nodes];
ll ans[150005];

DynamicLichao tree;

ll big_dsu(ll node, ll par)
{
	ll cn = 1, x, mx = 0, bigc = -1;

	for(auto it: g[node])
	{
		if(it != par)
		{
			x = big_dsu(it,node);

			cn += x;

			if(x > mx)
			{
				bigc = it;
				mx = x;
			}
		}
	}

	bigchild[node] = bigc;

	return cn;
}

void add(ll node, ll par)
{
	for(auto it: g[node])
	{
		if(it != par && big[it] == 0)
		{
			tree.update(col[it].second, ans[it]);
			add(it, node);
		}
	}
}

void dfs(ll node, ll par, bool keep = 1)
{
	for(auto it: g[node])
	{
		if(it != par && it != bigchild[node])
		{
			dfs(it, node, 0);
		}
	}

	if(bigchild[node] != -1)
	{
		dfs(bigchild[node], node, 1);
		big[bigchild[node]] = 1;
	}


	add(node, par);

	if(bigchild[node] == -1) ans[node] = 0;
	else ans[node] = tree.ask(col[node].first);

//	cout << node << ": " << ans[node] << endl;

	if(keep) tree.update(col[node].second,ans[node]);

	if(bigchild[node] != -1)
	{
		big[bigchild[node]] = 0;
	}

	if(keep == 0)
	{
		tree.nowroot = ++tree.idx;
	}
}


int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
		for(ll i = 1; i <= n; i++) g[i].clear();

		for(ll i = 1; i <= n; i++) slld(col[i].first);
		for(ll i = 1; i <= n; i++) slld(col[i].second);

		for(ll i = 1; i < n; i++)
		{
			ll u, v;

			slld(u);
			slld(v);

			g[u].pb(v);
			g[v].pb(u);
		}

		tree.init(0,-2e5,2e5);

		memset(bigchild, -1,sizeof bigchild);

		big_dsu(1,-1);

		dfs(1,-1);

//		if(n == 63054)
//		{
//			for(ll i = 1; i <= n; i++)
//			{
//				cout << i << " " << g[i].size() << endl;
//			}
//		}

		for(ll i = 1; i <= n; i++)
		{
			printf("%lld ", ans[i]);
		}

		printf("\n");

    }

}



