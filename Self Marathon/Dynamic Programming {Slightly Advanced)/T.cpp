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

#define mod 10056

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

ll ncr[1001][1001];
ll dp[1001];

ll nCr(ll n, ll r)
{
	if(r == 1) return n;

	if(n == r) return 1;

	ll &ret = ncr[n][r];

	if(ret != -1) return ret;

	ret = nCr(n - 1,r) + nCr(n - 1, r - 1);

	return ret = (ret % mod);
}

ll solve(ll n)
{
	if(n == 0) return 1;

	ll &ret = dp[n];

	if(ret != -1) return ret;

	ret = 0;

	for(int i = 1; i <= n; i++)
	{
		ret = (ret + (nCr(n,i) * solve(n - i)) % mod) % mod;
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

    memset(ncr,-1,sizeof ncr);

//    cout << nCr(100,1) << endl;

    for(ll cs = 1; cs <= testcase; cs++)
    {
		slld(n);
		memset(dp,-1,sizeof dp);

		ans = solve(n);

		printf("Case %lld: %lld\n", cs, ans);
    }


}



