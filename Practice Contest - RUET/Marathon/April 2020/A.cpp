#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009


using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

ll degree[100005];
vector < ll > graph[100005];
ll ans[100005];
ll subnode[100005];


void dfs(ll node,ll par)
{
	subnode[node] = 0;

	for(auto it: graph[node])
	{
		if(it == par) continue;

		dfs(it,node);

		subnode[node] += subnode[it];
	}

	subnode[node]++;
}

void dfs1(ll node, ll par, ll parnode = 0)
{
	ll mx = parnode;
	ll sum = parnode;

	for(auto it: graph[node])
	{
		if(it == par) continue;

		mx = max(mx, subnode[it]);

		sum += subnode[it];

		dfs1(it,node,subnode[node] - subnode[it] + parnode);
	}

	sum -= mx;

	if(abs(mx - sum) == 1) ans[node] = 1;
	else if(mx > sum) ans[node] = 0;
	else if(abs(mx - sum) % 2) ans[node] = 1;
	else ans[node] = 0;

	sum += mx;
}
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		slld(n);

		for(i = 1; i <= n; i++)
		{
			graph[i].clear();
			degree[i] = ans[i] = 0;
		}

		for(i = 1; i < n; i++)
		{
			ll u, v;

			slld(u);
			slld(v);

			graph[u].pb(v);
			graph[v].pb(u);

			degree[u]++;
			degree[v]++;
		}

		for(i = 1; i <= n; i++)
		{
			if(degree[i] == 1)
			{
				dfs(i,0);
				break;
			}
		}

		dfs1(i,0);

		for(i = 1; i <= n; i++)
		{
			printf("%lld", ans[i]);
		}

		printf("\n");
    }


}



