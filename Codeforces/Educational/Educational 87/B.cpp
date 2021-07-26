
// God put a smile upon your face <3

#include <bits/stdc++.h>`

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

#define mod 958585860497

#define base 2001487

using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

vector < ll > g[5];
string str;

ll fnd(ll num, ll idx)
{
	if(g[num].back() < idx) return mxlld;

	ll ret = upper_bound(g[num].begin(),g[num].end(),idx) - g[num].begin();

	return g[num][ret];
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
		cin >> str;

		for(i = 0; i <= 3; i++) g[i].clear();

		for(i = 0; i < str.size(); i++)
		{
			g[str[i] - '1'].pb(i);
		}

		ans = str.size();

		if(g[0].empty() || g[1].empty() || g[2].empty())
		{
			printf("0\n");
			continue;
		}

		for(i = 0; i < str.size(); i++)
		{
			ll x = str[i] - '1';

			ll mx = max(fnd((x + 1) % 3,i),fnd((x + 2) % 3,i));

//			cout << i << " " << mx << endl;
			ll sz = mx - i + 1;

			ans = min(ans,sz);
		}

		cout << ans << "\n";
    }


}



