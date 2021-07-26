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

		lft.front() = v.front();
		rgt.back() = v.back();

		for(ll i = 1; i < n; i++)
		{
			lft[i] = max(lft[i - 1], v[i]);
		}

		for(ll i = n - 2; i >= 0; i--)
		{
			rgt[i] = max(rgt[i + 1], v[i]);
		}

		ans = mxlld;

		for(ll i = 0; i < n; i++)
		{
			ll mx = -2;
			if(i) mx = max(mx, lft[i - 1]);
			if(i < (n - 1)) mx = max(mx, rgt[i + 1]);

			m = (n - 1);

			ll ta = m * mx - tot;

			if(ta < 0)
			{
				ans = min(ans, (m - (tot % m)) % m);
			}
			else
			{
				ans = min(ans, ta);
			}
		}

		cout << ans << "\n";
    }


}


