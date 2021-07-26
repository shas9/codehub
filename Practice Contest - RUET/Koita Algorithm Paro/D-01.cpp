
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

ll dp[152][52][52][52][3];
string str;
vector < ll > v[3];
const ll mod = 51123987;

ll solve(ll pos, ll a, ll b, ll c, ll ch = 0)
{
	if(a >= 52 || b >= 52 || c >= 52) return 0;
	if(a + b + c > pos) return 0;
	if(pos > str.size()) return 0;

	ll &ret = dp[pos][a][b][c][ch];

	if(ret != -1) return ret;

	ret = 0;

	if(a + b + c == str.size())
	{
		assert(pos == str.size());

		return ret = (abs(a - b) <= 1 && abs(a - c) <= 1 && abs(b - c) <= 1);
	}

	auto it = upper_bound(v[0].begin(),v[0].end(), pos);

	if(it != v[0].end())
	{
		ret += solve(*it, a + 1, b, c, 1);
	}

	it = upper_bound(v[1].begin(),v[1].end(), pos);

	if(it != v[1].end())
	{
		ret += solve(*it, a, b + 1, c, 2);
	}

	it = upper_bound(v[2].begin(),v[2].end(), pos);

	if(it != v[2].end())
	{
		ret += solve(*it, a, b, c + 1, 0);
	}

	if(pos)
	{
		if(ch == 1) ret += solve(pos, a + 1, b, c, ch);
		else if(ch == 2) ret += solve(pos, a, b + 1, c, ch);
		else ret += solve(pos, a, b, c + 1, ch);
	}

	if(a + b + c == pos && pos)
	{
		if(ch == 1) ret += solve(pos + 1, a + 1, b, c, ch);
		else if(ch == 2) ret += solve(pos + 1, a, b + 1, c, ch);
		else ret += solve(pos + 1, a, b, c + 1, ch);
	}

	cout << pos << " " << a << " " << b << " " << c << " " << " " << ch << " = " << ret << "\n";

	return ret %= mod;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);
//
//    freopen("output.txt", "w", stdout);

    while(cin >> n >> str)
    {
		for(ll i = 0; i < 3; i++) v[i].clear();

		memset(dp,-1,sizeof dp);

		for(ll i = 0; i < n; i++)
		{
			v[str[i] - 'a'].pb(i + 1);
		}

		ans = solve(0,0,0,0);

		cout << ans << "\n";
    }


}



