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
vector < ll > sum;

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
		cin >> n >> m;

		vec.resize(m);
		sum.clear();

		for(ll i = 0; i < m; i++) cin >> vec[i].first >> vec[i].second;

		sort(vec.begin(),vec.end());
		ll add = 0;

		sum.push_back(0);
		for(auto it: vec)
		{
			add += it.first;
			sum.push_back(add);
		}

		ans = 0;

		ll mx = 0;

		for(ll i = 0, j = m - 1; i < n && j >= 0; i++, j--) ans += vec[j].first, mx = max(mx, vec[i].second);

		ans += max(0LL, n - m) * mx;

		for(ll i = 0; i < m; i++)
		{
			ll idx = upper_bound(vec.begin(),vec.end(),make_pair(vec[i].second, mxlld)) - vec.begin();

			ll tot = m - idx;

			ll add = sum.back() - sum[idx];

//			cout << vec[i].second << " " << idx << " " << add << " " << tot << endl;

			if(tot > n) continue;

			if(tot == n)
			{
				ans = max(ans, add);
				continue;
			}

			if(idx > i)
			{
				tot++;
				add += vec[i].first;
			}

			add += vec[i].second * (n - tot);

			ans = max(ans, add);
		}

		cout << ans << '\n';
    }


}



