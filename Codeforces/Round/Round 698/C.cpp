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

void brute()
{
	ll n;

	cin >> n;

	vector < ll > v;
	v.resize(n);

	for(auto &it: v) cin >> it;

	for(auto it: v)
	{
		ll ans = 0;

		for(auto jt: v)
		{
			ans += abs(it - jt);
		}

		cout << ans << "\n";
	}
}

vector < ll > v, v1;
map < ll, ll > mp;

bool solve()
{
	sort(v.rbegin(), v.rend());
	mp.clear();

	ll n = v.size();

	ll now = n;
	ll sum = 0;

	mp.clear();

	for(ll i = 0; i + 1 < n; i += 2)
	{
		if(v[i] != v[i + 1]) return 0;

		ll x = v[i] - (sum * 2);

		if(x % now || x <= 0) return 0;

		sum += x / now;

		if(mp.find(x / now) != mp.end()) return 0;

		mp[x / now] = 1;

		now -= 2;
	}

	return 1;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

//	while(1) brute();

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		cin >> n;

		n *= 2;

		v.resize(n);

		for(auto &it: v) cin >> it;

		if(solve()) cout << "YES\n";
		else cout << "NO\n";
    }


}


