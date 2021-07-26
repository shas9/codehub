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

ll solve(ll up, ll down, ll k)
{
	double x = (k / 100.0);

	ll ret = 1e15;
	ll lo = 0;
	ll hi = ret;

	while(lo <= hi)
	{
		ll mid = (lo + hi) / 2;

		double y = (up * 1.0) / (down + mid);

		if(y <= x)
		{
			ret = mid;
			hi = mid - 1;
		}
		else
		{
			lo = mid + 1;
		}
	}

//	cout << ret << endl;


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
		ans = 0;

		cin >> n >> k;

		cin >> input;

		ll sum = input;

		for(ll i = 2; i <= n; i++)
		{
			cin >> input;

			ans += solve(input, sum, k);

			sum = sum + input + solve(input, sum, k);
		}

		cout << ans << "\n";
    }


}




