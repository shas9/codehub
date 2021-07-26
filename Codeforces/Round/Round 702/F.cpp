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

vector < ll > vec;
map < ll, ll > mp;

ll solve(ll c)
{
	ll ret = 0;

	for(auto it: mp)
	{
		if(it.second < c) ret += it.second;
		else ret += it.second - c;
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
		cin >> n;
		vec.resize(n);
		mp.clear();

		for(auto &it: vec) cin >> it, mp[it]++;

		ll lo = 1;
		ll hi = n;
		ll ans = n;

		while(lo <= hi)
		{
			ll mid1 = (lo + lo + hi) / 3;
			ll mid2 = (lo + hi + hi) / 3;

			ll ans1 = solve(mid1);
			ll ans2 = solve(mid2);

			if(ans1 < ans2)
			{
				ans = min(ans,ans1);
				hi = mid2 - 1;
			}
			else
			{
				lo = mid1 + 1;
				ans = min(ans, ans2);
			}
		}

		cout << ans << "\n";
    }


}



