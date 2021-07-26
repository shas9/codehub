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

		ll b1, b2;

		slld(b1);
		slld(b2);

		if(b1 > b2) swap(b1,b2);

		ll a = 0, b = 0;

		a = (b2 - b1 - 1);
		b = (n - b2) + (b1 - 1);

		ans = 0;

		for(i = 1; i <= n; i++)
		{
			ll t1 = i, t2 = i + 1;

			if(t2 > n) t2 = 1;

			if(t1 == b1 || t2 == b1) continue;
			if(t1 == b2 || t2 == b2) continue;


			ll lft = t1 - 1;

			if(lft < 1) lft = n;

			ll rgt = t2 + 1;

			if(rgt > n) rgt = 1;

//			cout << t1 << " " << t2 << " " << lft << " " << rgt << endl;

			ans += (n - 6);

			if(lft == b1 || lft == b2) ans++;

			if(rgt == b1 || rgt == b2) ans++;
			else ans++;
		}

		printf("%lld\n", ans);

    }


}


