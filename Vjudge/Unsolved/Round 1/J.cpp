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

ll dp[100005][53];
vector < pll > vec;

ll dist[100005];
ll nxt[100005];

ll bs(ll v)
{
	ll lo = 0;
	ll hi = vec.size() - 1;
	ll ret = -1;

	while(lo <= hi)
	{
		ll mid = (lo + hi) / 2;

		if(vec[mid].first <= v)
		{
			ret = mid;
			lo = mid + 1;
		}
		else hi = mid - 1;
	}

	return ret + 1;
}

void process(ll r)
{
	ll sum = 0;

	for(auto &it: vec)
	{
		sum += it.second;

		it.second = sum;
	}

	for(ll i = 0; i < vec.size(); i++)
	{
		ll pos = bs(vec[i].first + r);
		nxt[i] = pos;
		dist[i] = vec[pos - 1].second;
		if(i) dist[i] -= vec[i -1].second;
	}
}

ll solve(ll pos, ll k)
{
	if(pos == vec.size()) return 0;
	if(k == 0) return 0;

	ll &ret = dp[pos][k];

	if(ret != -1) return ret;

	ret = solve(pos + 1, k);

	ret = max(ret, solve(nxt[pos], k - 1) + dist[pos]);

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
		slld(n);
		slld(r);
		slld(k);

		for(ll i = 0; i <= n; i++) for(ll j = 0; j <= k; j++) dp[i][j] = -1;

		vec.resize(n);

		for(auto &it: vec)
		{
			slld(it.first);
			slld(it.second);
		}

		sort(vec.begin(),vec.end());

		r *= 2;

		process(r);

		ans = solve(0,k);

		printf("Case %lld: %lld\n", cs, ans);
    }


}


