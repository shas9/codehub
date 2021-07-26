// God put a smile upon your face <3

#include <bits/stdc++.h>`

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

#define mod 958585860497


using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

ll dp[20][1 << 16];
ll base, k;
string str;

ll solve(ll rem, ll mask)
{
//	cout << rem << " " << mask << endl;
	if(mask == (1 << str.size()) - 1)
	{
		return rem == 0;
	}

	ll &ret = dp[rem][mask];

	if(ret != -1) return ret;

	ret = 0;

	for(ll i = 0; i < str.size(); i++)
	{
//		cout << i << endl;
		if(check(mask,i) == 0)
		{
			ll x = rem * base;

			if(str[i] >= 'A') x += (str[i] - 'A' + 10);
			else x += (str[i] - '0');

//			cout << str[i] << " " << x << endl;

			ret += solve(x % k, Set(mask,i));
		}
	}

	return ret;
}

int main()
{
    ll i, j, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		slld(base);
		slld(k);
		cin >> str;

		memset(dp,-1,sizeof dp);

		ans = solve(0,0);

		printf("Case %lld: %lld\n", cs, ans);
    }


}


