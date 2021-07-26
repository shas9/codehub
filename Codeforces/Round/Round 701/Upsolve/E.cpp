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

const ll lim = 200005;

vector < ll > g[lim];
ll val[lim];
vector < ll > lev[lim];

ll dp[lim];
ll par[lim];

void dfs(ll node, ll ppar, ll d)
{
	par[node] = ppar;
	lev[d].push_back(node);

	for(auto it: g[node])
	{
		if(it != ppar)
		{
			dfs(it, node, d + 1);
		}
	}

	return;
}

bool comp(ll a, ll b)
{
	return val[a] < val[b];
}

void solve(ll d)
{
	for(auto it: lev[d]) //noswap
	{
		dp[it] = dp[par[it]] + max(abs(val[it] - val[lev[d].front()]), abs(val[it] - val[lev[d].back()]));
	}

	ll mx = -1e13;

	for(auto it: lev[d]) //lefttoright
	{
		dp[it] = max(dp[it], mx + val[it]);

		mx = max(mx, dp[par[it]] - val[it]);
	}

	mx = -1e13;

	reverse(lev[d].begin(), lev[d].end());

	for(auto it: lev[d]) //lefttoright
	{
		dp[it] = max(dp[it], mx - val[it]);

		mx = max(mx, dp[par[it]] + val[it]);
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
		cin >> n;

		for(ll i = 0; i <= n; i++)
		{
			g[i].clear();
			dp[i] = 0;
			lev[i].clear();
		}

		for(ll i = 2; i <= n; i++)
		{
			cin >> input;

			g[input].push_back(i);
			g[i].push_back(input);
		}

		for(ll i = 2; i <= n; i++)
		{
			cin >> val[i];
		}

		dfs(1,-1,0);

		for(ll i = 1; i <= n; i++)
		{
			if(lev[i].empty()) break;

			sort(lev[i].begin(),lev[i].end(), comp);
		}

		ans = 0;

		for(ll i = 1; i <= n; i++)
		{
			if(lev[i].empty())
			{
				for(auto it: lev[i - 1])
				{
					ans = max(ans, dp[it]);
				}

				break;
			}

			solve(i);
		}

		cout << ans << "\n";

    }


}


