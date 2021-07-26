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

void genbinary(ll n)
{
	for(ll i = n; i >= 1; i--)
	{
		for(ll j = 8; j >= 0; j--)
		{
			cout << check(i,j);
		}

		cout << endl;
	}
}

bool inrange(ll l, ll r, ll num)
{
	return (num >= l && num <= r);
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

//	genbinary(100);

    while(cin >> l >> r)
    {
		ans = 0;
		for(i = 62; i >= 0; i--)
		{
			ll lev = (1LL << i);

//			cout << lev << " " << l << " " << r << endl;

			if(inrange(l,r,lev) && inrange(l,r,lev - 1))
			{
				ans = (lev ^ (lev - 1));
				break;
			}

			if(r >= lev) r -= lev;
			if(l >= lev) l -= lev;
		}

		printf("%lld\n", ans);
    }


}



