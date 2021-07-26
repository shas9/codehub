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

ll arr[1003];
ll n, m;

bool solve(ll mid)
{
	for(ll i = 1, cnt = 0,cont = 1; i <= n; i++)
	{
		if(arr[i] > mid) return 0;

		if(cnt + arr[i] > mid)
		{
			cnt = 0;
			cont++;
		}

		cnt += arr[i];

		if(cont > m) return 0;
	}

	return 1;
}
int main()
{
    ll i, j, k, l, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		slld(n);
		slld(m);

		for(i = 1; i <= n; i++)
		{
			slld(arr[i]);
		}

		ll lo = 1;
		ll hi = 1000000000;

		ans = hi;

		while(lo <= hi)
		{
			ll mid = (lo + hi) / 2;

			if(solve(mid))
			{
				hi = mid - 1;
				ans = mid;
			}
			else
			{
				lo = mid + 1;
			}
		}

		printf("Case %lld: %lld\n", cs, ans);

    }


}


