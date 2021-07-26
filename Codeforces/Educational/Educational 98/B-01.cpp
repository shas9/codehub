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
		ll tot = 0;
		cin >> n;
		vector < ll > v(n);
		vector < ll > lft(n), rgt(n);

		for(auto &it: v)
		{
			cin >> it;
			tot += it;
		}

		lft.front() = v.front() % 2;
		rgt.back() = v.back() % 2;

		for(ll i = 1; i < n; i++)
		{
			lft[i] = lft[i - 1] + v[i] % 2;
		}

		for(ll i = n - 2; i >= 0; i--)
		{
			rgt[i] = rgt[i + 1] + v[i] % 2;
		}

		ans = 0;

		for(ll i = 0; i < n; i++)
		{
			ll mx = 0;
			if(i) mx +=  lft[i - 1];
			if(i < (n - 1)) mx += rgt[i + 1];

			if(n & 1);
			else mx = (n - 1 - mx);

			ll m = (n - 1);

//			cout << mx << " + ";

			if(mx >= v[i])
			{
				ans += mx - v[i];
				v[i] = mx;
			}
			else
			{
				ll prv = ans;

				ll x = v[i] - mx;

				ans += (m - x % m) % m;

				v[i] += ans - prv;
			}

			if(v[i] & 1) lft[i] = 1;
			else lft[i] = 0;

			if(i) lft[i] += lft[i - 1];

//			cout << v[i] << " " << ans << "\n";
		}

		cout << ans << "\n";
    }


}


