#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009


using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

ll arr[10004];

//ll one(ll x)
//{
//	ll ret = 0;
//	for(ll i = 0; i <= 15; i++)
//	{
//		if(check(x,i)) ret++;
//	}
//
//	return ret;
//}

//ll pw2(ll x)
//{
//	for(ll i = 15; i >= 0; i--)
//	{
//		if(check(x,i))
//		{
//			return (1LL << i);
//		}
//	}
//}

ll one(ll n)
{
	ll cnt = 0;
	while(n) cnt++, n &= (n-1);

	return cnt;
}

ll pw2(ll x)
{
	x = 63 - __builtin_clz(x);

	return (1 << x);
}

ll solve(ll l, ll r)
{
	ll rnge = (r - l  + 1);

	if(one(rnge) == 1) return arr[r] ^ arr[l - 1];

	ll x = pw2(rnge);

	return solve(l, r - x) ^ solve(l + x, r);
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

		for(i = 1; i <= n; i++) slld(arr[i]);

		for(i = 1; i <= n; i++) arr[i] ^= arr[i - 1];

		slld(m);

		printf("Case %lld:\n", cs);

		while(m--)
		{
			slld(l);
			slld(r);

			l++;
			r++;

			printf("%lld\n", solve(l,r));
		}
    }


}



