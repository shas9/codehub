 // God put a smile upon your face <3

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

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

string s1, s2;
ll dp[152][52][52][52];
const ll mod = 51123987;

ll solve(ll pos, ll a, ll b, ll c)
{
	if(a >= 52 || b >= 52 || c >= 52) return 0;
	if(pos == s2.size()) return 0;

	ll &ret = dp[pos][a][b][c];

	if(ret != -1) return ret;

	if(a + b + c == s1.size())
	{
		return ret = (abs(a - b) <= 1 && abs(a - c) <= 1 && abs(b - c) <= 1);
	}

	ret = 0;

	if(s2[pos] == 'a') ret += solve(pos, a + 1, b, c);
	if(s2[pos] == 'b') ret += solve(pos, a, b + 1, c);
	if(s2[pos] == 'c') ret += solve(pos, a, b, c + 1);

	ret += solve(pos + 1, a, b, c);

//	cout << s2 << " -> " << pos << " " << a << " " << b << " " << c << " = " << ret << endl;

	return ret %= mod;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> s1)
    {
		s2 = s1.front();

		for(ll i = 1; i < n; i++)
		{
			if(s1[i] != s1[i - 1]) s2.push_back(s1[i]);
		}

		memset(dp,-1,sizeof dp);

		ans = solve(0,0,0,0);

		cout << ans << '\n';
    }


}


