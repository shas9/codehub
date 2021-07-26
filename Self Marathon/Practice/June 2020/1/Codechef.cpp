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

using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

map < ll, ll > freq, a1;

ll solve()
{
	ll swapneed = 0;

	ll mn = mxlld;

	for(auto it: freq)
	{
		if(it.second & 1) return -1;

		mn = min(mn, it.first);

		swapneed += abs(it.second / 2 - a1[it.first]);
	}

	ll ret = 0;

	assert(!(swapneed & 1));

	swapneed /= 2;


	for(auto it: freq)
	{
		assert(!(it.second & 1));

		ll x = min(swapneed, abs(it.second / 2 - a1[it.first]));

		ret += x * min(it.first, mn * 2);

//		cout << it.first << " " << it.second << " " << a1[it.first] << " " << ret << endl;

		swapneed -= x;
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
		freq.clear();
		a1.clear();

		slld(n);

		for(ll i = 1; i <= n; i++) slld(input), freq[input]++, a1[input]++;
		for(ll i = 1; i <= n; i++) slld(input), freq[input]++;

		ans = solve();

		printf("%lld\n", ans);
    }


}


