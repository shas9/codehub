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

vector < ll > v1, v2, v3;

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);


    while(cin >> n >> m >> k)
    {
		v1.clear();
		v2.clear();
		ll tot = 0;

		v2.push_back(0);
		ll mn = mxlld;

		for(ll i = 1; i <= n; i++)
		{
			cin >> input;

			mn = min(mn, input);
			tot += input;

			v2.back() += input;
		}

		v1.push_back(mn);

		v2.push_back(0);
		mn = mxlld;

		for(ll i = 1; i <= m; i++)
		{
			cin >> input;

			mn = min(mn, input);
			tot += input;

			v2.back() += input;
		}

		v1.push_back(mn);

		v2.push_back(0);
		mn = mxlld;

		for(ll i = 1; i <= k; i++)
		{
			cin >> input;

			mn = min(mn, input);
			tot += input;

			v2.back() += input;
		}

		v1.push_back(mn);

		sort(v1.begin(),v1.end());
		sort(v2.begin(),v2.end());

//		for(auto it: v1) cout << it << endl;
//		for(auto it: v2) cout << it << endl;

		ans = tot - (min(v1[0] + v1[1], v2.front()) * 2);

		cout << ans << "\n";

    }


}




