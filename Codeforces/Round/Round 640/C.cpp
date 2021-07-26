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

ll check(ll n, ll mid)
{
	ll div = (mid / n);

	return mid - div;
}

ll solve(ll n, ll m)
{
	ll lo = 1;
	ll hi = 10 * m;
	ll ret = 0;

	while(lo <= hi)
	{
		ll mid = (lo + hi) / 2;

		if(check(n,mid) == m) return mid;

		if(check(n,mid) > m) hi = mid - 1;
		else lo = mid + 1;
	}
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
		slld(m);

		ans = solve(n,m);

		if(ans % n == 0) ans--;

		printf("%lld\n", ans);
    }


}



