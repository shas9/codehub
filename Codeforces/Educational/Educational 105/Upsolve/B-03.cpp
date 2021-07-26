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
ll app[100005];
vector < pll > need[100005];
bool nei[100005];
bool ans[100005];
ll sz[100005];

void clr(ll n)
{
	for(ll i = 1; i <= n; i++)
	{
		g[i].clear();
		app[i] = 0;
		need[i].clear();
		nei[i] = 0;
		ans[i] = 0;
		sz[i] = 0;
	}
}

bool comp(ll a, ll b)
{
	return app[a] < app[b];
}

bool solve(ll n, ll m, ll k)
{
	if(k * k > (2 * m + k)) return 0;

	set < pll > st;
	vector < ll > tmp;

	for(ll i = 1; i <= n; i++)
	{
		sz[i] = g[i].size();
		st.insert({sz[i], i});
	}

	while(!st.empty())
	{
		pll top = *st.begin();

		if(top.first >= k)
		{
			cout << 1 << " " << st.size() << "\n";

			for(auto it: st)
			{
				cout << it.second << " ";
			}

			cout << "\n";

			return 1;
		}
		else
		{
			st.erase(top);

			for(auto it: g[top.second])
			{
				if(app[it] == 0)
				{
					st.erase({sz[it],it});
					sz[it]--;
					st.insert({sz[it],it});

				}
			}

			tmp.push_back(top.second);

			app[top.second] = tmp.size();
		}
	}

	for(auto it: tmp)
	{
//		cout << it << " + \n";
		vector < ll > vec;

		for(auto jt: g[it])
		{
			if(app[jt] > app[it])
			{
				nei[jt] = 1;
				vec.push_back(jt);
			}
		}

		for(auto jt: need[it])
		{
			if(nei[jt.first] == 0)
			{
				ans[jt.second] = 0;
			}
		}

		for(auto jt: g[it])
		{
			if(app[jt] > app[it])
			{
				nei[jt] = 0;
			}
		}

		if(vec.size() != (k - 1)) continue;

		ans[it] = 1;

		sort(vec.begin(),vec.end(), comp);

		for(ll i = 0; i < vec.size(); i++)
		{
			for(ll j = i + 1; j < vec.size(); j++)
			{
				need[vec[i]].pb({vec[j],it});
			}
		}
	}

	for(auto it: tmp)
	{
		if(ans[it])
		{
			cout << 2 << "\n";

			for(auto jt: g[it])
			{
				if(app[it] < app[jt]) cout << jt << " ";
			}

			cout << it << "\n";

			return 1;
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

		clr(n);

		for(ll i = 1; i <= m; i++)
		{
			ll u, v;

			cin >> u >> v;

			g[u].pb(v);
			g[v].pb(u);
		}

		if(solve(n,m,k) == 0) cout << "-1\n";
    }


}


