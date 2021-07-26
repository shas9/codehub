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

vector < ll > v[26];
string str;

ll dp[103][103];

const ll mod = 1e16;

ll solve(ll pos, ll rem)
{
	if(rem == 0) return 1;
	if(pos == str.size()) return 0;

	ll &ret = dp[pos][rem];

	if(ret != -1) return ret;

	ret = 0;

	for(ll i = 0; i < 26; i++)
	{
		auto it = upper_bound(v[i].begin(), v[i].end(), pos);

		if(it == v[i].end()) continue;

		ret = (solve(*it, rem - 1) + ret) % mod;
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

    while(cin >> n >> m >> str)
    {
		for(ll i = 0; i < 26; i++) v[i].clear();
		memset(dp,-1,sizeof dp);

		for(ll i = 0; i < n; i++)
		{
			v[str[i] - 'a'].pb(i + 1);
		}

		ans = 0;

		for(ll i = n; i >= 0; i--)
		{
			ll cnt = solve(0,i);

			ll biyog = min(m, cnt);

			ans += biyog * (n - i);
			m -= biyog;
		}

		if(m) ans = -1;

		cout << ans << "\n";
    }


}


