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

vector < ll > nodes;
set < ll > g[100005];

bool solve1(ll n, ll k)
{
	for(ll i = 1; i <= n; i++)
	{
		if(g[i].size() >= k) nodes.push_back(i);
	}

	if(!nodes.empty())
	{
		cout << 1 << " " << nodes.size() << "\n";

		for(auto it: nodes) cout << it << " ";

		cout << "\n";

		return 1;
	}

	return 0;
}

bool vis[100005];

bool solve(ll x)
{
	map < ll, ll > mp;

	queue < ll > q;
	q.push(x);

	for(auto it: g[x])
	{
		if(vis[it]) return 0;

		mp[it] = 1;
		vis[it] = 1;
	}

	for(auto it: g[x])
	{
		for(auto jt: g[it])
		{
			if(mp.find(jt) == mp.end()) return 0;
		}
	}

	cout << 2 << "\n";

	for(auto it: mp)
	{
		cout << it.first << " ";
	}

	cout << "\n";

	return 1;
}

bool solve2(ll n, ll k)
{
//	assert(nodes.empty());

//	bug;

	for(ll i = 1; i <= n; i++)
	{
//		assert(g[i].size() <= k);

		if(g[i].size() == k) nodes.push_back(i);
	}

//	for(auto it: nodes) cout << it << " + ";
//	cout << endl;

	for(ll i = 1; i <= n; i++) vis[i] = 0;

	for(auto it: nodes)
	{
		if(vis[it]) continue;

		if(solve(it)) return 1;
	}

	return 0;
}

void process(ll n, ll k)
{
	queue < ll > q;

	for(ll i = 1; i <= n; i++)
	{
		if(g[i].size() < (k - 1)) q.push(i);
	}

	while(!q.empty())
	{
		ll top = q.front();
		q.pop();

//		cout << top << " + ";

		for(auto it: g[top])
		{
			g[it].erase(top);
			if(g[it].size() == (k - 2)) q.push(it);
		}

		g[top].clear();
	}

	return;
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
		cin >> n >> m >> k;

		for(ll i = 1; i <= n; i++) g[i].clear();
		nodes.clear();

		for(ll i = 1; i <= m; i++)
		{
			ll u, v;

			cin >> u >> v;
			g[u].insert(v);
			g[v].insert(u);
		}

		if(k * k > (2 * m + k))
		{
			cout << -1 << "\n";
			continue;
		}

		process(n,k);

		if(solve1(n, k));
		else if(solve2(n, k - 1));
		else cout << -1 << "\n";
    }


}


