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


int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
		ll tot = 0;

		ll lo = 1;

		for(ll i = 1; i <= n; i++)
		{
			cin >> input;
			tot += input;
			lo = max(lo, input);
		}

		ans = mxlld;

		ll hi = 1e10;

		while(lo <= hi)
		{
			ll mid = (lo + hi) / 2;

			if(mid * n - mid >= tot)
			{
				hi = mid - 1;
				ans = mid;
			}
			else
			{
				lo = mid + 1;
			}
		}

		cout << ans << "\n";
    }


}


