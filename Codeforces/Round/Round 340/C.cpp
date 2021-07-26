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

vector < pll > vec;

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

	ll x1, x2, y1, y2;

    while(cin >> n >> x1 >> y1 >> x2 >> y2)
    {
		vec.resize(n);

		for(auto &it: vec) cin >> it.first >> it.second;

		ans = mxlld;

		vec.push_back({x1,y1});

		for(pll it: vec)
		{
			ll r1 = ((it.first - x1) * (it.first - x1)) + ((it.second - y1) * (it.second - y1));
			ll r2 = 0;

			for(pll jt: vec)
			{
				ll d1 = ((jt.first - x1) * (jt.first - x1)) + ((jt.second - y1) * (jt.second - y1));

				if(d1 <= r1) continue;

				ll d2 = ((jt.first - x2) * (jt.first - x2)) + ((jt.second - y2) * (jt.second - y2));

				r2 = max(r2, d2);
			}

			ans = min(ans, r1 + r2);
		}

		cout << ans << "\n";
    }


}



