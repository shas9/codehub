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

ll subdp[203];
vector < ll > graph[203];
ll n, k;
ll arr[203];


void dfs(ll node, ll par = 0)
{
	subdp[i] = arr[node];

	for(auto it: graph[node])
	{
		if(it == par) continue;

		dfs(it, node);
	}

	ll dist[205];

	memset(dist,-1,sizeof dist);

	queue < ll > qq;

	qq.push(node);
	dist[node] = 0;
	dist[par] = 0;

	while(!qq.empty())
	{
		ll top = qq.front();
		qq.pop();

		for(auto it: graph[top])
		{
			if(dist[it] == -1)
			{
				dist[it] = dist[top] + 1;
				qq.push(it);
			}
		}
	}

	for(ll i = 1; i <= n; i++)
	{
		if(dist[i] > k)
		{
			subdp[node] = max(subdp[node], arr[node] + subdp[i]);
		}
	}
}

ll solve(ll node, ll par = 0, ll dist = 0)
{

}
int main()
{
    ll i, j, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> k)
    {
		for(i = 1; i <= n; i++)
		{
			graph[i].clear();
		}

		for(i = 1; i <= n; i++) slld(arr[i]);
		for(i = 1; i < n; i++)
		{
			ll u, v;
			slld(u);
			slld(v);

			graph[u].pb(v);
			graph[v].pb(u);
		}

		dfs(1);

		ans = solve(1);
    }


}



