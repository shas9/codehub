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

ll calc(ll x, ll n)
{
	ll comb = 1;
	ll ret = 0;

	for(ll i = 0; i < 32 && n; i++)
	{
		if(check(n,i))
		{
			n ^= (1 << i);

			if(!(x & n)) ret += comb;
		}

		if(check(x,i) == 0)
		{
			comb = (comb << 1);
		}
	}

	return ret;
}

ll solve(ll l, ll r)
{
	if(l == r) return 0;

	if(l == 0) return 2*r - 1 + solve(1,r);

	ll ret = 0;


	if(l & 1)
	{
		ret += 2 * (calc(l,r) - calc(l,l));
		l++;
	}

	if(r & 1)
	{
		ret += 2 * (calc(r - 1,r) - calc(r - 1, l));
		r--;
	}

	return ret + 3 * solve(l / 2, r / 2);
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
		slld(l);
		slld(r);

		ans = solve(l,r + 1);

		printf("%lld\n", ans);
    }


}




