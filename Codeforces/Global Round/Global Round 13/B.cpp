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

vector < ll > obs;

ll solve1(ll u, ll v)
{
	for(ll i = 0; i < (obs.size() - 1); i++)
	{
		if(obs[i] != obs[i + 1]) return u;
	}

	return min(u + v, 2 * v);
}

ll solve2(ll u, ll v)
{
	for(ll i = 0; i < obs.size() - 1; i++)
	{
		if(abs(obs[i] - obs[i + 1]) >= 2) return 0;
	}

	for(ll i = 0; i < obs.size() - 1; i++)
	{
		if(abs(obs[i] - obs[i + 1]) >= 1) return v;
	}

	return mxlld;
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
		cin >> n >> m >> k;

		obs.resize(n);

		for(auto &it: obs) cin >> it;

		ans = min(solve1(m,k), solve2(m,k));

		cout << ans << "\n";
    }


}


