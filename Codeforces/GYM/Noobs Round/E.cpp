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

string str;
ll dp[100005][10];
const ll mod = 1000000007;

ll solve(ll pos, ll last)
{
	if(last > 9) return 0;
	if(pos == str.size()) return 1;

	ll &ret = dp[pos][last];

	if(ret != -1) return ret;

	ret = 0;

	if(str[pos] != '-')
	{
		ll d = str[pos] - '0';

		if(d < last) return ret = 0;

		ret = solve(pos + 1, d);
	}
	else
	{
		ret = (solve(pos, last + 1) + solve(pos + 1, last)) % mod;
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

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		cin >> n >> str;

		for(ll i = 0; i <= n; i++) for(ll j = 0; j <= 9; j++) dp[i][j] = -1;

		ans = solve(0,1);

		cout << ans << "\n";
    }


}



