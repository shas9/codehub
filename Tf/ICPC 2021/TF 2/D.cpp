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

ll mat[103][103];

ll s1(ll x, ll n)
{
	ll sum = 0;

	for(ll i = 1; i + x - 1 <= n; i++)
	{
		sum += mat[i][i + x - 1];
	}

	return sum;
}

ll s2(ll x, ll n)
{
	ll sum = 0;

	for(ll i = 1; i + x - 1 <= n; i++)
	{
		sum += mat[i + x - 1][i];
	}

	return sum;
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
		cin >> n;

		for(ll i = 1; i <= n; i++) for(ll j = 1; j <= n; j++) cin >> mat[i][j];

		ans = 0;

		for(ll i = 1; i <= n; i++)
		{
			ans = max(ans, max(s1(i,n), s2(i,n)));
		}

		cout << ans << "\n";
    }


}



