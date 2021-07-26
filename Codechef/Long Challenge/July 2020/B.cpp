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

ll sum(ll x)
{
	ll ret = 0;

	while(x)
	{
		ret += (x % 10);

		x /= 10;
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
		slld(n);

		ll sum1 = 0, sum2 = 0;

		for(i = 1; i <= n; i++)
		{
			ll a, b;

			slld(a);
			slld(b);

			if(sum(a) > sum(b)) sum1++;
			else if(sum(a) < sum(b)) sum2++;
			else sum1++, sum2++;
		}

		if(sum1 > sum2) printf("0 ");
		else if(sum1 < sum2) printf("1 ");
		else printf("2 ");

		printf("%lld\n", max(sum1,sum2));
    }


}



