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

ll pwr[30];
ll cnt[2000005];
ll fact[22];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

	pwr[0] = 1;

	for(ll i = 1; i <= 25; i++) pwr[i] = 2 * pwr[i - 1];

	fact[0] = 1;
	for(ll i = 1; i <= 21; i++) fact[i] = i * fact[i - 1];

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		cin >> n;

		ll one = __builtin_popcount(n);

		ans = 0;

		for(ll i = 0; i <= one; i++)
		{
			ll choice = fact[one] / fact[i];
			choice /= fact[one - i];

			ans += choice * pwr[i];
		}

		cout << ans << "\n";
    }


}



