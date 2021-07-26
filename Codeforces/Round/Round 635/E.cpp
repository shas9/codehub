#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
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

#define mod 998244353


using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

map < string, ll > mp;
string ss, tt;

ll solve(string x)
{
	if(mp.find(x) != mp.end())
	{
		return mp[x];
	}

	mp[x] = 0;

	if(x.size() >= tt.size())
	{
		ll i;
		for(i = 0; i < tt.size(); i++)
		{
			if(x[i] != tt[i]) break;
		}

		if(i == tt.size())
		{
			mp[x] = 1;
		}
	}

	if(x.size() == ss.size()) return mp[x];

	string a = "";
	a += ss[(int)x.size()];
	a += x;

	string b = x;
	b += ss[(int)x.size()];

	return mp[x] = (mp[x] + solve(a) + solve(b)) % mod;
}
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

	while(cin >> ss >> tt)
	{
		mp.clear();

		string a = "";

		ans = solve(a);

		ans %= mod;

		printf("%lld\n", ans);
	}


}



