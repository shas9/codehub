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

vector < ll > g[100005];
set < pll > deg;
ll sz[100005];
bool mark[100005];

void prntset()
{
	for(auto it: deg) cout << it.first << " + " << it.second << endl;
	cout << endl;

	return;

}

bool process(ll node)
{
	for(auto it: g[node])
	{
		if(mark[it] == 0) continue;

		deg.erase({sz[it], it});

		sz[it]--;

		deg.insert({sz[it], it});
	}

	for(auto it: g[node])
	{
		if(mark[it] == 0) continue;

		unordered_map < ll, bool > mp;

		mp[it] = 1;

		for(auto jt: g[it])
		{
			if(mark[jt] == 0) continue;

			mp[jt] = 1;
		}

		for(auto jt: g[node])
		{
			if(mark[jt] == 0) continue;
			if(mp[jt] == 0) return 0;
		}
	}

	cout << 2 << "\n";

	for(auto it: g[node])
	{
		if(mark[it]) cout << it << " ";
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

			mark[top.second] = 0;

			for(auto it: g[top.second])
			{
				if(mark[it] == 0) continue;

				deg.erase({sz[it], it});
				sz[it]--;
				deg.insert({sz[it], it});
			}
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
			mark[top.second] = 0;

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

		for(ll i = 1; i <= n; i++) g[i].clear(), mark[i] = 1;
		deg.clear();

		for(ll i = 1; i <= m; i++)
		{
			ll u, v;
			cin >> u >> v;

			g[u].push_back(v);
			g[v].push_back(u);
		}

		for(ll i = 1; i <= n; i++)
		{
			sz[i] = g[i].size();

			if(g[i].empty()) continue;

			deg.insert({g[i].size(), i});
		}

		if(solve(k,m) == 0) cout << -1 << "\n";
    }


}



