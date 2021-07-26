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

bool comp(pll a, pll b)
{
	if(a.second == b.second) return a.first > b.first;
	return a.second < b.second;
}

bool solve()
{
	ll tot1 = 0;
	ll tot2 = 0;
	ll cnt = 0;

	for(auto it: vec) tot1 += it.first, tot2 += it.second;

	sort(vec.begin(),vec.end(),comp);

	ll vax = vec.size() - 1;

	for(ll i = 0; i < vec.size(); i++)
	{
		ll lft = tot1 - vec[i].first;

		if(lft < vec[i].second)
		{
			cnt++;
			vax = i;
		}
	}

	if(cnt > 1) return 0;

	tot2 -= vec[vax].second;

	if(tot2 <= tot1) return 1;

	return 0;
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
		cin >> n;

		vec.resize(n);

		for(auto &it: vec) cin >> it.first;
		for(auto &it: vec) cin >> it.second;

		if(solve()) cout << "YES\n";
		else cout << "NO\n";
    }


}



