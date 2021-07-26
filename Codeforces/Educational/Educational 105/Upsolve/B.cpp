 // God put a smile upon your face <3

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll int
#define ull unsigned long long
#define pll pair < int, int >

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

set < ll > g[100005];
set < pll > deg;

void prntset()
{
	for(auto it: deg) cout << it.first << " + " << it.second << endl;
	cout << endl;

	return;

}

bool process(ll node)
{
	map < ll, bool > mp;

	for(auto it: g[node])
	{
		mp[it] = 1;
	}


	for(auto it: g[node])
	{
		deg.erase({g[it].size(), it});

		g[it].erase(node);

		deg.insert({g[it].size(), it});
	}

	for(auto it: g[node])
	{
		for(auto jt: mp)
		{
			if(jt.first == it) continue;

			if(g[it].find(jt.first) == g[it].end()) return 0;
		}
	}

	cout << 2 << "\n";

	for(auto it: mp)
	{
		cout << it.first << " ";
	}

	cout << node << "\n";

	return 1;
}

bool solve(ll k, ll m)
{
	if(k * k > (2 * m + k)) return 0;

	while(!deg.empty())
	{
//		prntset();

		pll top = *deg.begin();

//		cout << top.first << " : " << top.second << endl << endl;

		if(top.first < (k - 1))
		{
			deg.erase(top);

			for(auto it: g[top.second])
			{
				deg.erase({g[it].size(), it});

				g[it].erase(top.second);

				deg.insert({g[it].size(), it});
			}

			g[top.second].clear();
		}
		else if(top.first >= k)
		{
			cout << 1 << " " << deg.size() << "\n";

			for(auto it: deg) cout << it.second << " ";

			cout << "\n";

			return 1;
		}
		else
		{
			deg.erase(top);

			if(process(top.second)) return 1;
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

    cin >> testcase;

    for(ll cs = 1; cs <= testcase; cs++)
    {
		cin >> n >> m >> k;

		for(ll i = 1; i <= n; i++) g[i].clear();
		deg.clear();

		for(ll i = 1; i <= m; i++)
		{
			ll u, v;
			cin >> u >> v;

			g[u].insert(v);
			g[v].insert(u);
		}

		for(ll i = 1; i <= n; i++)
		{
			if(g[i].empty()) continue;

			deg.insert({g[i].size(), i});
		}

		if(solve(k,m) == 0) cout << -1 << "\n";
    }


}


