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

vector < ll > g[30];
string s, t;

void process()
{
	for(ll i = 0; i < s.size(); i++)
	{
		g[s[i] - 'a'].push_back(i);
	}
}

ll arr[200005];

ll bs(ll pos, ll x, ll y)
{
	ll lo = 0;
	ll hi = g[pos].size() - 1;
	ll ret = x;

	while(lo <= hi)
	{
		ll mid = (lo + hi) / 2;

		if(g[pos][mid] >= x && g[pos][mid] <= y)
		{
			ret = g[pos][mid];
			lo = mid + 1;
		}
		else if(g[pos][mid] < x)
		{
			lo = mid + 1;
		}
		else if(g[pos][mid] > y)
		{
			hi = mid - 1;
		}
	}

	return ret;
}

ll solve()
{
	ll now = -1;
	ll pos = 1;
	ll ret = 0;

	for(auto it: t)
	{
		auto jt = upper_bound(g[it - 'a'].begin(), g[it - 'a'].end(), now);

		arr[pos] = *jt;
		now = arr[pos];

		if(pos > 1) ret = max(ret, arr[pos] - arr[pos - 1]);

		pos++;
	}

	arr[pos] = 1e10;

	for(ll i = t.size(); i >= 1; i--)
	{
		ll nxt = bs(t[i - 1] - 'a', arr[i], arr[i + 1] - 1);

		if(i < t.size()) ret = max(ret, arr[i + 1] - arr[i]);

//		cout << nxt << " " << arr[i] << " " << arr[i + 1] << endl;

		arr[i] = nxt;
	}

	return ret;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m)
    {
		cin >> s >> t;

		for(ll i = 0; i < 30; i++) g[i].clear();

		process();

		ans = solve();

		cout << ans << '\n';
    }


}


