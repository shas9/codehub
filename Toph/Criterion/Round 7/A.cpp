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

ll arr[100005];

bool solve(ll k, ll n, ll m)
{
	ll cnt = 0;

	for(ll i = 1; i <= n; i++)
	{
		ll vag = arr[i] / k;

		cnt += vag;
	}

//	cout << k << ": " << cnt << endl;

	return cnt >= m;
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
		cin >> n >> m;

		for(ll i = 1; i <= n; i++) cin >> arr[i];

		ll lo = 1;
		ll hi = 1e17;

		ans = 1;

		while(lo <= hi)
		{
			ll mid = (lo + hi) / 2;

			if(solve(mid, n, m))
			{
				ans = mid;

				lo = mid + 1;
			}
			else
			{
				hi = mid - 1;
			}
		}

		printf("Case %lld: %lld\n", cs, ans);
    }


}



