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

vector < pll > g[100005];
ll n, m, k;

ll solve()
{
	ll ret = 0;

	for(ll i = 1; i <= m; i++)
	{
		for(auto it: g[i])
		{
			ret = max(ret, it.second - it.first + 1);
		}
	}


	for(ll i = 1; i <= m; i++)
	{
		ll idx1 = 0;
		ll idx2 = 0;
		ll sum = 0;

		if(g[i].empty()) continue;
		ll cnt = g[i][0].second - g[i][0].first + 1;

		while(idx1 + 1 < g[i].size())
		{
			while(idx2 + 1 < g[i].size())
			{
				if(sum + g[i][idx2 + 1].first - g[i][idx2].second - 1 <= k)
				{
					sum += g[i][idx2 + 1].first - g[i][idx2].second - 1;
					cnt += g[i][idx2 + 1].second - g[i][idx2 + 1].first + 1;
				}
				else
				{
					break;
				}

				idx2++;
			}

			ret = max(ret, cnt);

			sum -= g[i][idx1 + 1].first - g[i][idx1].second - 1;
			cnt -= g[i][idx1].second - g[i][idx1].first + 1;

			idx1++;
		}
	}

	return ret;
}

int main()
{
    ll i, j, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m >> k)
    {
		ll l = 1;

		slld(input);

		ll prv = input;

		for(ll i = 2; i <= n; i++)
		{
			slld(input);

			if(prv != input)
			{
				g[prv].push_back({l, i - 1});
				l = i;
			}

			prv = input;
		}

		g[prv].push_back({l,n});

		ans = solve();

		printf("%lld\n", ans);
    }


}



