// God put a smile upon your face <3

#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%d", &longvalue)

#define ll int
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

map < ll, ll > mp, oa;

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		mp.clear();
		oa.clear();

//		mp.reserve(1 << 15);
//		mp.max_load_factor(0.25);
//
//		oa.reserve(1 << 15);
//		oa.max_load_factor(0.25);

		slld(n);

		for(ll i = 1; i <= n; i++) slld(input), mp[input]++, oa[input]++;
		for(ll i = 1; i <= n; i++) slld(input), mp[input]++;

		long long ans = 0;
		ll swapneed = 0;

		ll tot = 0;

		for(auto it: mp)
		{
			if(it.second & 1)
			{
				ans = -1;
				break;
			}

			if((it.second / 2) > oa[it.first])
			{
				swapneed += (it.second / 2) - oa[it.first];
			}

			assert(it.second >= oa[it.first]);

			tot += abs(it.second / 2 - oa[it.first]);
		}

		if(ans == -1)
		{
			printf("-1\n");
			continue;
		}

		assert(swapneed * 2 == tot);

		for(auto it: mp)
		{
			if(it.second & 1)
			{
				assert(0);
			}

			if((it.second / 2) != oa[it.first])
			{
				ans += min(abs((it.second / 2) - oa[it.first]), swapneed) * it.first;
				swapneed -= min(abs((it.second / 2) - oa[it.first]), swapneed);
			}
		}

		printf("%lld\n", ans);
    }


}



