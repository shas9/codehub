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
		pll a, b;

		cin >> n >> m;

		cin >> a.first >> b.first;
		cin >> a.second >> b.second;

		if(a.second > b.second) swap(a,b);

		ans = 0;

		for(ll i = 0; i <= a.first; i++)
		{
			if(i * a.second > n) break;

			ll bb = b.first;

			ll lft = n - (i * a.second);

			ll tans = i;

			tans += min((lft / b.second), bb);
			bb -= min((lft / b.second), bb);

			ll llft = a.first - i;

			lft = m - (min(m / a.second, llft) * a.second);

			tans += min(m / a.second, llft);

			tans += min(lft / b.second, bb);

			ans = max(ans, tans);

		}

		cout << ans << "\n";
    }


}



