
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

vector < ll > g[1003];
ll dp[1003][1003];
map < ll, ll > mp[6];

ll solve(ll node, ll d)
{
	ll &ret = dp[node][d];

	if(ret != -1) return ret;

	ret = 0;

	for(auto it: g[node])
	{
		ret = max(ret, solve(it, d + 1));
	}

	return ret += 1;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m)
    {
		for(ll i = 1; i <= m; i++)
		{
			mp[i].clear();

			for(ll j = 1; j <= n; j++)
			{
				ll in;

				cin >> in;

				mp[i][in] = j;
			}
		}

		for(ll i = 1; i <= n; i++) g[i].clear();

		for(ll i = 1; i <= n; i++)
		{
			for(ll j = 1; j <= n; j++)
			{
				bool on = 1;

				for(ll k = 1; k <= m; k++)
				{
					if(mp[k][i] >= mp[k][j]) on = 0;
				}

				if(on) g[i].push_back(j);
			}
		}

		ans = 1;

		memset(dp,-1,sizeof dp);

		for(ll i = 1; i <= n; i++)
		{
			ans = max(ans, solve(i,0));
		}

		cout << ans << "\n";

    }


}


