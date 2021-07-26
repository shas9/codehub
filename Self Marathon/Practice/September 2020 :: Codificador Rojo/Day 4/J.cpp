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

vector < pll > vec[2];
ll dp[200005][2];

ll solve(ll pos, ll col)
{
	ll &ret = dp[pos][col];

	if(ret != -1) return ret;

	if(pos == vec[col].size()) return ret = 0;

	ret = solve(pos + 1, col) + 1;

	ll idx = upper_bound(vec[col ^ 1].begin(), vec[col ^ 1].end(), make_pair(vec[col][pos].second, mxlld)) - vec[col ^ 1].begin();

	ret = max(ret, solve(idx, col ^ 1) + 1);

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
		vec[0].clear();
		vec[1].clear();
		memset(dp,-1,sizeof dp);

		for(ll i = 1; i <= n; i++)
		{
			ll t;
			cin >> l >> r >> t;

			t %= 2;

			vec[t].push_back({l,r});
		}

		sort(vec[0].begin(),vec[0].end());
		sort(vec[1].begin(),vec[1].end());

		ans = max(solve(0,0), solve(0,1));

		cout << solve(0,0) << " " << solve(0,1) << endl;

		cout << ans << "\n";
    }


}



