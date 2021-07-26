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

vector < pll > graph[100005];
bool vis[100005];
bool flav[100005];

pll arr[100005];

ll dfs(ll ff)
{
	ll ret = 0;

	for(auto it: graph[ff])
	{
		if(vis[it.second]) continue;

		vis[it.second] = 1;

		if(arr[it.second].first == ff) swap(arr[it.second].first, arr[it.second].second);

		if(flav[arr[it.second].first]) ret++;
		else
		{
			flav[arr[it.second].first] = 1;
			ret += dfs(arr[it.second].first);
		}
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
		for(i = 1; i <= max(n,m); i++) graph[i].clear(), vis[i] = 0;
		for(i = 1; i <= n; i++) flav[i] = 0;

		for(i = 1; i <= m; i++)
		{
			ll u, v;

			slld(u);
			slld(v);

			graph[u].push_back({v,i});
			graph[v].push_back({u,i});

			arr[i] = {u,v};
		}

		ans = 0;

		for(i = 1; i <= m; i++)
		{
			if(vis[i] == 0)
			{
				vis[i] = 1;
				flav[arr[i].first] = flav[arr[i].second] = 1;

				ans += dfs(arr[i].first);
				ans += dfs(arr[i].second);
			}

		}

		printf("%lld\n", ans);
    }


}
