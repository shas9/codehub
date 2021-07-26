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

bool solve(ll n)
{
	if(n == 1) return 0;

	if(n & 1) return 1;

	bool ret = 0;

	for(ll i = 2; i * i <= n; i++)
	{
		if(n % i) continue;

		ll x = i;
		ll y = (n / i);

		if(x & 1) ret |= solve(n / x) ^ 1;

		if(y & 1) ret |= solve(n / y) ^ 1;

		if(ret) return ret;
	}

	ret |= solve(n - 1) ^ 1;

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
		slld(n);

		if(solve(n)) printf("Ashishgup\n");
		else printf("FastestFinger\n");
    }


}




