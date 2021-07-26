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

ll a[200005];
ll b[200005];

bool poss(ll mid, ll n)
{
	ll cnt = 0;

	for(ll i = 1; i <= n; i++)
	{
		if(a[i] > mid) cnt += b[i];
	}

	return cnt <= mid;
}

ll solve(ll n)
{
	ll lo = 1;
	ll hi = 1e10;
	ll ret = hi;

	while(lo <= hi)
	{
		ll mid = (lo + hi) / 2;

		if(poss(mid,n))
		{
			ret = mid;
			hi = mid - 1;
		}
		else
		{
			lo = mid + 1;
		}
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

		for(ll i = 1; i <= n; i++) cin >> a[i];
		for(ll i = 1; i <= n; i++) cin >> b[i];

		ans = solve(n);

		cout << ans << "\n";
    }


}



