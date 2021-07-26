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

const ll tot_nodes = 1e5 + 5;

ll col[tot_nodes];
vector < ll > g[tot_nodes];
ll cnt[tot_nodes];
ll bigchild[tot_nodes];
bool big[tot_nodes];

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

vector < pll > qq[tot_nodes];
deque < set < ll >  > dq;
ll ans[tot_nodes];

void add(ll node, ll par, ll depth)
{
	if(depth == dq.size()) dq.push_back({});

	dq[depth].insert(col[node]);

	for(auto it: g[node])
	{
		if(it != par && big[it] == 0)
		{
			add(it, node, depth + 1);
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

	dq.push_front({});

	add(node, par, 0);

	if(bigchild[node] != -1)
	{
		big[bigchild[node]] = 0;
	}

	for(auto it: qq[node])
	{
		ans[it.second] = it.first < dq.size() ?  dq[it.first].size() : 0;
	}

	if(keep == 0) dq.clear();
}

map < string, ll > mp;

vector < ll > root;

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
		for(ll i = 1; i <= n; i++) g[i].clear(), qq[i].clear();

		flag = 0;

		root.clear();

		for(ll i = 1; i <= n; i++)
		{
			string str;
			cin >> str >> input;

			if(mp.find(str) == mp.end()) mp[str] = ++flag;

			col[i] = mp[str];

			if(input == 00)
			{
				root.push_back(i);
				continue;
			}

			g[input].pb(i);
			g[i].pb(input);
		}

		assert(!root.empty());

		memset(bigchild,-1,sizeof bigchild);

		slld(m);

		for(ll i = 1; i <= m; i++)
		{
			ll u, v;

			slld(u);
			slld(v);

			qq[u].pb({v,i});
		}

		for(auto it: root)
		{
			dq.clear();
			big_dsu(it,-1);
			dfs(it,-1);
		}

		for(ll i = 1; i <= m; i++)
		{
			printf("%lld\n", ans[i]);
		}

//		printf("\n");
    }


}

