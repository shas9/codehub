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

pll rng[200005];

ll solve(ll n)
{
	vector < ll > vec;

	for(ll i = 1; i <= n; i++) vec.push_back(rng[i].first);

	ll mn = 0;
	bool frac = 0;

	sort(vec.begin(),vec.end());

	if(n & 1) mn = vec[n / 2];
	else
	{
		ll x = vec[n / 2] + vec[(n - 1) / 2];

		mn = x / 2;
		if(x & 1) frac = 1;
	}

	vec.clear();

	for(ll i = 1; i <= n; i++) vec.push_back(rng[i].second);

	ll mx = 0;
	bool frac1 = 0;

	sort(vec.begin(),vec.end());

	if(n & 1) mx = vec[n / 2];
	else
	{
		ll x = vec[n / 2] + vec[(n - 1) / 2];

		mx = x / 2;
		if(x & 1) frac1 = 1;
	}

	ll ret = (mx - mn + 1);

	if(n % 2 == 0) ret = (ret * 2) - 1;

	if(frac1) ret++;
	if(frac) ret--;

	return ret;


}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
		for(i = 1; i <= n; i++) slld(rng[i].first), slld(rng[i].second);

		ans = solve(n);

		cout << ans << '\n';
    }


}



