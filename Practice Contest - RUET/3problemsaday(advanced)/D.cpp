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

vector < ll > g[1000006];
map < pll, ll > mp;
vector < ll > ase;

ll solve(ll n)
{
	ll idx = 1000001;
	ll cost = 0;
	ase.clear();

	while(1)
	{
		idx--;

		if(idx < 0) break;
		if(!g[idx].empty())
		{
			if(ase.empty())
			{
				if(g[idx].size() > 1) return -1;

				ase.push_back(g[idx].back());

				continue;
			}

			for(auto it: g[idx])
			{
				ll mn = mxlld;

				for(auto jt: ase)
				{
					if(mp.find({jt,it}) != mp.end())
					{
						mn = min(mn, mp[{jt,it}]);
					}
				}

				if(mn == mxlld) return -1;

				cost += mn;
			}

			for(auto it: g[idx])
			{
				ase.push_back(it);
			}
		}
	}

	return cost;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
		for(ll i = 0; i <= 1000000; i++) g[i].clear();
		mp.clear();

		for(ll i = 1; i <= n; i++)
		{
			slld(input);

			g[input].pb(i);
		}

		slld(m);

		for(ll i = 1; i <= m; i++)
		{
			ll u, v, c;
			slld(u);
			slld(v);
			slld(c);

			if(mp.find({u,v}) == mp.end()) mp[{u,v}] = c;
			else mp[{u,v}] = min(mp[{u,v}], c);
		}

		ans = solve(n);

		printf("%lld\n", ans);
    }


}



