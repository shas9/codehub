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

ll brute(ll n)
{
	ll mat[n + 1][n + 1];

	for(ll i = 1; i <= n; i++)
	{
		for(ll j = 1; j <= n; j++) mat[i][j] = 1;
	}

	ll tc = n / 2 + 1;

	ll cost = 0;

	for(ll i = 1; i <= n; i++)
	{
		for(ll j = 1; j <= n; j++)
		{
			bug;
		}
	}
}

ll solve(ll n)
{
	ll ret = 0;
	ll tn = 1;
	ll cnt = 1;
	ll tot = 8;
	while(tn < n)
	{
		ret += (cnt * tot);
		tot += 8;
		cnt++;
		tn += 2;
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

//	while(1)
//	{
//		cin >> n;
//		cout << brute(n) << endl;
//	}
    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		cin >> input;

		ans = solve(input);

		printf("%lld\n", ans);
    }


}


