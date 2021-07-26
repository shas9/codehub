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

vector < ll > g[500005];
ll dp[500005];
ll arr[500005];

ll calc(ll pos, ll x)
{
	ll lo = 0;
	ll hi = g[x].size() - 1;
	ll ret = 0;

	while(lo <= hi)
	{
		ll mid = (lo + hi) / 2;

		if(g[x][mid] >= pos)
		{
			ret = mid;
			hi = mid - 1;
		}
		else
		{
			lo = mid + 1;
		}
	}

	return g[x].size() - ret;
}

ll solve(ll pos, ll n)
{
	if(pos > n) return 0;

	ll &ret = dp[pos];

	if(ret != -1) return ret;

	ret = solve(pos + 1, n);

	ll x = arr[pos];

	if(pos == g[x].front()) ret = max(ret, (long long)(solve(g[x].back() + 1, n) + g[x].size()));

	ret = max(ret, calc(pos, arr[pos]));

	return ret;
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
		for(ll i = 1; i <= n + 1; i++)
		{
			dp[i] = -1;
			g[i].clear();
		}

		for(ll i = 1; i <= n; i++)
		{
			cin >> arr[i];
			g[arr[i]].push_back(i);
		}

		ans = solve(1,n);

		cout << n - ans << "\n";
    }


}


