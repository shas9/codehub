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

ll arr[2003];

ll solve(ll num, ll lo, ll hi)
{
	ll tlo = lo - 1;

	ll ret = lo - 1;

//	cout << "!! " << num << " " << lo << " " << hi << endl;

	while(lo <= hi)
	{
		ll mid = (lo + hi) / 2;

		if(arr[mid] < num)
		{
			lo = mid + 1;
			ret = mid;
		}
		else
		{
			hi = mid - 1;
		}
	}

//	cout << ret << endl;

	return ret - tlo;
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
		slld(n);

		for(i = 1; i <= n; i++)
		{
			slld(arr[i]);
		}

		sort(arr + 1, arr + 1 + n);

		ans = 0;

		for(i = 1; i <= n; i++)
		{
			for(j = i + 1; j <= n; j++)
			{
				ll x = solve(arr[i] + arr[j], j + 1, n);

//				cout << i << " " << j << " " << x << endl;
				ans += x;
			}
		}

		printf("Case %lld: %lld\n", cs, ans);
    }


}


