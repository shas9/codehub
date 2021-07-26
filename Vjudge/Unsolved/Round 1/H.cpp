 // God put a smile upon your face <3

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%d", &longvalue)

#define ll int
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

ll dp[100001][315];
ll arr[100001];
ll n;

ll solve(ll p, ll k)
{
	if(p > n) return 0;

	ll &ret = dp[p][k];

	if(ret != -1) return ret;

	return ret = solve(p + arr[p] + k, k) + 1;
}

ll solve1(ll p, ll k)
{
	ll cnt = 0;

	while(p <= n)
	{
		p = (p + arr[p] + k);
		cnt++;
	}

	return cnt;
}

int main()
{
    ll i, j, k, l, m, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

	fastio;

    while(cin >> n)
    {
		memset(dp,-1,sizeof dp);

		for(ll i = 1; i <= n; i++) cin >> arr[i];

		cin >> m;

		for(ll i = 1; i <= m; ++i)
		{
			ll p, k;

			cin >> p >> k;

			if(k < 315) ans = solve(p,k);
			else ans = solve1(p,k);

			cout << ans << "\n";
		}
    }


}


