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

//bool check(ll n, ll pos)
//{
//	return n & (1LL << pos);
//}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

vector < pair < ll, bool > > g[200005];
unordered_map < ll, pll > fib;

void process()
{
	ll f1 = 0, f2 = 1;

	for(ll i = 1; i <= 10000 && f2 <= 1000000000; i++)
	{
		fib[f1 + f2] = {f1, f2};
		f2 = f2 + f1;
		f1 = f2 - f1;
	}

	return;
}

ll subtree[200005];

void dfs(ll node, ll par)
{
	subtree[node] = 1;

	for(auto it: g[node])
	{
		if(it.first != par && it.second)
		{
			dfs(it.first, node);

			subtree[node] += subtree[it.first];
		}
	}

	return;
}

bool solve(ll node, ll sz);

bool check(ll node, ll par, ll sz)
{
	for(auto &it: g[node])
	{
		if(it.first != par && it.second)
		{
			it.second = 0;

			if(subtree[it.first] == fib[sz].first)
			{
				if(solve(it.first,fib[sz].first) && solve(node,fib[sz].second)) return 1;
			}
			else if(subtree[it.first] == fib[sz].second)
			{
				if(solve(node,fib[sz].first) && solve(it.first,fib[sz].second)) return 1;
			}

			it.second = 1;

			if(check(it.first,node,sz)) return 1;
		}
	}

	return 0;
}

void cutedge(ll node, ll par, ll sz, vector < pll > &v)
{
	for(auto it: g[node])
	{
		if(it.first != par && it.second)
		{
//			cout << it.first << " " << subtree[it.first] << endl;
			if(subtree[it.first] == fib[sz].second)
			{
				v.push_back({node, it.first});
			}
			else if(subtree[it.first] == fib[sz].first)
			{
				v.push_back({it.first, node});
			}
		}
	}

	for(auto it: g[node])
	{
		if(it.first != par && it.second)
		{
//			cout << it.first << " " << subtree[it.first] << endl;
			cutedge(it.first, node, sz, v);
		}
	}

	return;
}

bool solve(ll node, ll sz)
{
	if(sz <= 3) return 1;
	if(fib.find(sz) == fib.end())
	{
//		bug;
		return 0;
	}

	dfs(node, -1);

	vector < pll > v;

	cutedge(node,-1,sz, v);

	if(v.empty()) return 0;

	for(pll cut: v)
	{
		for(auto &it: g[cut.first])
		{
			if(it.first == cut.second) it.second = 0;
		}

		for(auto &it: g[cut.second])
		{
			if(it.first == cut.first) it.second = 0;
		}

		pll szz = fib[sz];

		if(solve(cut.first, szz.first) && solve(cut.second, szz.second)) return 1;

		for(auto &it: g[cut.first])
		{
			if(it.first == cut.second) it.second = 1;
		}

		for(auto &it: g[cut.second])
		{
			if(it.first == cut.first) it.second = 1;
		}
	}

	return 0;

}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

	fastio;
	process();

    while(cin >> n)
    {
		for(ll i = 1; i <= n; i++) g[i].clear();

		for(ll i = 1; i < n; i++)
		{
			ll u, v;
			cin >> u >> v;

			g[u].push_back({v,1});
			g[v].push_back({u,1});
		}

		if(solve(1,n)) cout << "Yes\n";
		else cout << "No\n";
    }


}



