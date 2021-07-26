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

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m)
    {
		vec.resize(n);

		for(auto &it: vec) cin >> it.first >> it.second;

		sort(vec.begin(),vec.end());

		for(ll i = 1; i < vec.size(); i++) vec[i].second += vec[i - 1].second;

		ans = 0;

		for(ll i = 0; i < vec.size(); i++)
		{
			ll lim = vec[i].first + m;

			ll pos = upper_bound(vec.begin(),vec.end(),make_pair(lim,mnlld)) - vec.begin();

			ans = max(ans, vec[pos - 1].second - (i == 0 ? 0 : vec[i - 1].second));
		}

		cout << ans << "\n";
    }


}



