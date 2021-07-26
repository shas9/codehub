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

vector < ll > vec;
vector < pll > dp;

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> k)
    {
		ll a = -1, b = -1;

		vec.resize(n);
		dp.clear();
		dp.resize(n);

		ans = 0;
		ll mx = 0;

		for(ll i = 0; i < n; i++) cin >> vec[i];

		sort(vec.begin(),vec.end());

		ll bb = vec.back() + 1;
		b = bb;

//		for(auto it: vec) cout << it << " ";
//		cout << endl;

		for(ll i = n - 1; i >= 0; i--)
		{
//			cout << endl << endl << i << endl;

//			cout << " -> " << dp[i].first << " " << dp[i].second << endl;

			ll lim = vec[i] - k;
			ll pos = lower_bound(vec.begin(),vec.end(), lim) - vec.begin();
			if(vec[pos] < lim) pos++;

			ll cnt = i - pos + 1;

//			cout << pos << " " << cnt << " " << mx << " " << bb << endl;

			if(cnt + mx >= ans)
			{
//				cout << " + " << cnt + mx << " " << lim << " " << bb << endl;
				ans = cnt + mx;
				a = lim;
				b = bb;
			}

			if(dp[pos].first < cnt) dp[pos] = {cnt, lim};
			else if(dp[pos].first == cnt) dp[pos].second = lim;

			if(dp[i].first >= mx) mx = dp[i].first, bb = dp[i].second;

//			cout << a << " !! " << b << endl;
		}

		a = max(1LL, a);
		b = max(a + k, b);


		cout << a << " " << b << endl;
    }


}


