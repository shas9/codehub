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

map < ll, vector < ll > > g;
vector < ll > v;

void build(ll x, ll l, ll r)
{
	for(ll i = 1; i * i <= x; i++)
	{
		if(x % i == 0)
		{
			ll a = i;
			ll b = x / i;

			if(l < a && a < r) g[a].push_back(x);
			if(l < b && b < r && a != b) g[b].push_back(x);
		}
	}

	return;
}

ll solve(ll x)
{
	ll gc = 0;

	for(auto it: g[x])
	{
		gc = __gcd(gc, it);
	}

	return gc;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
		ll gc = 0;

		v.resize(n);

		for(auto &it: v) cin >> it, gc = __gcd(it, gc);

		sort(v.begin(),v.end());
		g.clear();

		for(auto it: v)
		{
			build(it,gc,v.front());
		}

		ans = 2;

		if(gc == v.front()) ans--;

		for(auto it: g)
		{
			if(solve(it.first) == it.first) ans++;
		}

		cout << ans << "\n";
    }


}


