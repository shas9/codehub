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

vector < ll > vec[3];

ll dp[203][203][203];

ll solve(ll p1, ll p2, ll p3)
{
	ll &ret = dp[p1][p2][p3];

	if(ret != -1) return ret;

	ret = 0;

	if(p1 < vec[0].size() && p2 < vec[1].size())
	{
		ret = max(ret, solve(p1 + 1, p2 + 1, p3) + vec[0][p1] * vec[1][p2]);
	}

	if(p1 < vec[0].size() && p3 < vec[2].size())
	{
		ret = max(ret, solve(p1 + 1, p2, p3 + 1) + vec[0][p1] * vec[2][p3]);
	}

	if(p3 < vec[2].size() && p2 < vec[1].size())
	{
		ret = max(ret, solve(p1, p2 + 1, p3 + 1) + vec[2][p3] * vec[1][p2]);
	}

	return ret;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m >> k)
    {
		for(ll i = 0; i < 3; i++) vec[i].clear();

		for(ll i = 0; i < n; i++)
		{
			cin >> input;

			vec[0].push_back(input);
		}

		for(ll i = 0; i < m; i++)
		{
			cin >> input;

			vec[1].push_back(input);
		}

		for(ll i = 0; i < k; i++)
		{
			cin >> input;

			vec[2].push_back(input);
		}

		for(ll i = 0; i < 3; i++) sort(vec[i].rbegin(), vec[i].rend());

		memset(dp,-1,sizeof dp);

		ans = solve(0,0,0);

		cout << ans << "\n";
    }


}



