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

vector < ll > g[100005];
ll cnt[100005];
ll val[100005];

ll dfs(ll node, ll par)
{
	cnt[node] = val[node];

	for(auto it: g[node])
	{
		if(it != par)
		{
			cnt[node] += dfs(it,node);
		}
	}

	return cnt[node];
}

vector < ll > vec;

void dfs2(ll node, ll par)
{
	if(cnt[node] < 0)
	{
		vec.push_back(cnt[node]);
		return;
	}

	for(auto it: g[node])
	{
		if(it != par) dfs2(it, node);
	}
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> k)
    {
		for(ll i = 1; i <= n; i++)
		{
			cin >> val[i];
		}

		for(ll i = 1; i < n; i++)
		{
			ll u, v;
			cin >> u >> v;

			g[u].pb(v);
			g[v].pb(u);
		}

		ll tot = dfs(1,-1);

		vec.clear();

		dfs2(1,-1);

		sort(vec.begin(),vec.end());

		ll sz = vec.size();

		for(ll i = 0; i < min(k, sz); i++)
		{
			tot -= vec[i];
		}

		cout << tot << "\n";
    }


}



