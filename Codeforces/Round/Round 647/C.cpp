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

void brute(ll n)
{

	ll ans = 0;

	for(ll i = 1; i <= n; i++)
	{
		ll cnt = 0;

		for(ll j = 0; j <= 32; j++)
		{
			if(check(i,j) ^ check(i-1,j)) cnt++;
		}

//		cout << cnt << " ";

		ans += cnt;
	}

	cout << ans << endl;

//	for(ll i = 1; i <= n; i++)
//	{
//		ll cnt = 0;
//
//		for(ll j = 0; j <= 32; j++)
//		{
//			if(check(i,j) ^ check(i-1,j)) cnt++;
//		}
//
////		cout << cnt << " ";
//
//		if(i % 8 == 0) cout << cnt << " ";
//	}
//
//	cout << endl;
//
//	for(ll i = 1; i <= n; i++)
//	{
//		ll cnt = 0;
//
//		for(ll j = 0; j <= 32; j++)
//		{
//			if(check(i,j) ^ check(i-1,j)) cnt++;
//		}
//
////		cout << cnt << " ";
//
//		if(i % 16 == 0) cout << cnt << " ";
//	}
//
//	cout << endl;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

//	brute();
    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		slld(n);

//		brute(n);

		ans = 0;

		ll num = 1;
		ll first = 1;
		ll dff = 2;

		while(first <= n)
		{
			ll koto = ((n + first) / dff);

			ans += (koto * num);

			num++;
			first *= 2;
			dff *= 2;
		}

		cout << ans << '\n';
    }


}


