// God put a smile upon your face <3

#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long int
#define ull unsigned long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 958585860497

#define base 2001487

using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

ll dp[(1 << 18) + 5][19];
ll match[(1 << 18) + 5];
ll bribe[(1 << 18) + 5];

ll solve(ll pos, ll def)
{
	ll &ret = dp[pos][def];

	if(ret != -1) return ret;

	if(bribe[pos] == -1) return ret = 0;

	ll need = match[def] - pos;

	ret = (1 << 52);

	if(def < 18) ret = solve(pos + 1, def + 1) + bribe[pos];

	if(need > 0) ret = min(ret, solve(pos + 1, def));

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
		for(i = n - 1; i >= 0; i--) slld(bribe[i]);

		memset(dp,-1,sizeof dp);

		for(i = 1, j = n / 2; i < n; i++, j /= 2)
		{
			match[i] = match[i - 1] + j;
		}

		ans = solve(0,0);

		printf("%lld\n", ans);
    }


}



