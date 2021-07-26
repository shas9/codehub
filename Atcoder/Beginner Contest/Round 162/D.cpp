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

vector < ll > g[3];
string str;
map < char, ll > mp;

ll solve(ll id, ll id1, ll id2)
{
	ll cnt = upper_bound(g[id1].begin(), g[id1].end(), id) - g[id1].begin();

	ll ret = 0;

	for(auto it: g[id2])
	{
		if(it < id) continue;

		ret += cnt;

		ll minuss = 2 * id - it;

		auto jt = lower_bound(g[id1].begin(), g[id1].end(), minuss);

		if(jt == g[id1].end()) continue;

//		cout << *jt << " " << minuss << endl;

		if(*jt < id && *jt == minuss) ret--;
	}

//	cout << id1 << " " << id2 << " " << cnt << " " << ret << endl;

	return ret;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> str)
    {
		ans = 0;

		for(ll i = 0; i < 3; i++) g[i].clear();

		mp['R'] = 0;
		mp['G'] = 1;
		mp['B'] = 2;

		for(ll i = 0; i < str.size(); i++)
		{
			g[mp[str[i]]].pb(i);
		}

		for(ll i = 1; i + 1 < str.size(); i++)
		{
			ll idx = mp[str[i]];

			ll idx1 = (idx + 1) % 3;
			ll idx2 = (idx + 2) % 3;

			ans += solve(i, idx1, idx2);
			ans += solve(i, idx2, idx1);
		}

		cout << ans << "\n";
    }
}



