// God put a smile upon your face <3

#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%d", &longvalue)

#define ll int
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


const ll tot_nodes = 1e5 + 5;

vector < ll > g[tot_nodes];
ll bigchild[tot_nodes];
bool big[tot_nodes];
ll depth[tot_nodes];

struct qq
{
	ll p, id;

	qq(ll _p, ll _id)
	{
		p = _p;
		id = _id;
	}
};

struct qqq
{
	ll d, u, id;

	qqq(ll _d, ll _u, ll _id)
	{
		d = _d;
		u = _u;
		id = _id;
	}
};

ll ans[tot_nodes];

vector < qq > qq1[tot_nodes];
vector < qqq > qq2[tot_nodes];

ll big_dsu(ll node, ll par, ll d = 0)
{
	ll cn = 1, x, mx = 0, bigc = -1;

	depth[d] = node;

	for(auto it: qq1[node])
	{
		ll p_parents = d - it.p;

		if(p_parents < 0) ans[it.id] = 0;
		else qq2[depth[p_parents]].push_back(qqq(it.p,node,it.id));
	}

	for(auto it: g[node])
	{
		if(it != par)
		{
			x = big_dsu(it,node,d + 1);

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

deque < ll > dq;

void add(ll node, ll par, ll d)
{
	if(d == dq.size()) dq.push_back(0);

	dq[d]++;
	for(auto it: g[node])
	{
		if(it != par && big[it] == 0)
		{
			add(it, node, d + 1);
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

	dq.push_front(0);

	add(node, par, 0);

	for(auto it: qq2[node])
	{
		if(it.d < dq.size()) ans[it.id] = dq[it.d] - 1;
	}

	if(bigchild[node] != -1)
	{
		big[bigchild[node]] = 0;
	}

	if(keep == 0) dq.clear();

	return;
}

vector < ll > root;
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

	dq.clear();

	slld(n);


    for(ll i = 1; i <= n; i++)
    {
		slld(input);

		if(input == 0) root.push_back(i);
		else
		{
			g[i].pb(input);
			g[input].pb(i);
		}
    }


    slld(m);

    for(ll i = 1; i <= m; i++)
    {
		ll v, p;
		slld(v);
		slld(p);

		qq1[v].pb(qq(p,i));
    }

    memset(bigchild,-1,sizeof bigchild);

    for(auto it: root)
    {
		big_dsu(it,-1);
    }

    for(auto it: root)
    {
		dfs(it,-1);
    }

    for(ll i = 1; i <= m; i++) printf("%d ", ans[i]);

    printf("\n");
}

