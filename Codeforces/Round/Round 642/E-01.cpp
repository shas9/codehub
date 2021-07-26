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

string str;
string sstr;

ll solve(ll one)
{
	ll sz = sstr.size();

	vector < ll > dp(sz);

	ll cone = 0;

	ll ret = one;

	for(ll i = 0; i < sz; i++)
	{
		ll c = (sstr[i] == '1');

		dp[i] = 1-c;

		if(i) dp[i] += min(dp[i - 1], cone);

		cone += c;

		ret = min(ret, dp[i] + (one - cone));
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
		slld(n);
		slld(k);

		cin >> str;

		ll tot = 0;

		for(auto it: str) tot += (it == '1');

		ans = tot;

		for(i = 0; i < k; i++)
		{
			sstr = "";

			for(j = i; j < n; j+=k)
			{
				sstr += str[j];
			}

			ll one = 0;

			for(auto it: sstr) if(it == '1') one++;

			ans = min(ans, solve(one) + (tot - one));
		}

		printf("%lld\n", ans);
    }


}

