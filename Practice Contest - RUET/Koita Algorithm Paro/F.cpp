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

vector < pll > neg, pos;

bool solve(ll n, ll m)
{
	for(auto it: pos)
	{
		if(it.first > m) return 0;

		m += it.second;
	}


	for(auto it: neg)
	{
		if(it.first > m) return 0;

		m += it.second;

		if(m < 0) return 0;
	}

	return m >= 0;
}

bool comp(pll a, pll b)
{
	ll x = a.first + a.second;
	ll y = b.first + b.second;

	return x > y;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m)
    {
		pos.clear();
		neg.clear();

		for(ll i = 1; i <= n; i++)
		{
			ll u, v;
			cin >> u >> v;

			if(v < 0)
			{
				neg.push_back({u, v});
			}
			else
			{
				pos.push_back({u,v});
			}
		}

		sort(neg.begin(),neg.end(),comp);
		sort(pos.begin(),pos.end());

		if(solve(n,m)) cout << "YES\n";
		else cout << "NO\n";

    }


}


