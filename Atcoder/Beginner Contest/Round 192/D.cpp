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

string x;
ll m;

bool solve(ll base)
{
	__int128 cnt = 0;
	__int128 bse = 1;

//	cout << base << endl;

	for(auto it: x)
	{
		if(bse > m) return 0;

		cnt += ((it - '0') * bse);

		if(cnt > m) return 0;

		bse = bse * base;
	}

//	cout << base << " " << (long long)cnt << endl;

	return 1;

}
ll bs(ll lo, ll hi)
{
	ll ret = lo - 1;
	reverse(x.begin(),x.end());

	while(lo <= hi)
	{
		ll mid = (lo + hi) / 2;

		if(solve(mid))
		{
			ret = mid;
			lo = mid + 1;
		}
		else
		{
			hi = mid - 1;
		}
	}

	return ret;
}

int main()
{
    ll i, j, k, l, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> x >> m)
    {
		ll mx = 0;

		for(auto it: x)
		{
			mx = max(mx, (long long)(it - '0'));
		}

		ans = bs(mx + 1, 1e18) - mx;

		if(x.size() == 1)
		{
			if((x.front() - '0') <= m) ans = 1;
			else ans = 0;
		}

		cout << ans << "\n";
    }


}




