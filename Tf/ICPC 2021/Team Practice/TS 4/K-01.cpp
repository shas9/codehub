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

vector < ll > v;

ll solve()
{
	ll ret = 1;

	if(v.empty()) return 0;

	sort(v.begin(), v.end());

	for(auto it: v) cout << it << " + ";
	cout << endl;

	ll n = v.size();

	for(ll i = 0; i < n; i++)
	{
		ret *= max(1LL, (n - max(0LL, v[i] - 1) - i));
		ll cnt = 0;

		for(ll j = 0; j <= i; j++) cnt += v[i] == v[j];

		ret /= cnt;

		cout << ret << " ";
	}

	cout << endl;

	return ret;
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
		v.clear();
		m = 2;

		while(n)
		{
			v.push_back(n % m);
			n /= m;
			m++;
		}

		ans = solve();



		if(v.front() == 0LL) v.erase(v.begin());

		ans -= solve();

		cout << ans - 1 << "\n";
    }


}

