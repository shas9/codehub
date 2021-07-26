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

vector < pll > v;
vector < ll > p;
map < ll, bool > mp;

ll calc(ll x, ll y)
{
	ll xx = (v[x].first - v[y].first) * (v[x].first - v[y].first);
	ll yy = (v[x].second - v[y].second) * (v[x].second - v[y].second);

	return xx + yy;
}

void solve()
{
	mp.clear();
	p.clear();

	ll last = 0;
	mp[0] = 1;
	p.push_back(1);

	for(ll i = 1; i < v.size(); i++)
	{
		ll dist = 0;
		ll pos = 0;

		for(ll j = 0; j < v.size(); j++)
		{
			if(mp[j]) continue;

			ll d = calc(last, j);

			if(d > dist)
			{
				dist = d;
				pos = j;
			}
		}

		p.push_back(pos + 1);
		last = pos;
		mp[last] = 1;
	}

	return;
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
		v.resize(n);

		for(auto &it: v) cin >> it.first >> it.second;

		solve();

		for(auto it: p) cout << it << " ";

		cout << "\n";
    }


}


