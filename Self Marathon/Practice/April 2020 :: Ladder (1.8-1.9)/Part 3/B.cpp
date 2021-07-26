// God put a smile upon your face <3

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

vector < ll > graph[200005];
map < pll, bool > orient;
ll inv[200005];
ll subnode[200005];
ll ans[200005];

void dfs(ll node, ll par)
{
	inv[node] = 0;
	subnode[node] = 0;

	for(ll v: graph[node])
	{
		if(v == par) continue;

		dfs(v,node);

		subnode[node] += subnode[v] + 1;
		inv[node] += inv[v];

		if(orient.find({v,node}) != orient.end())
		{
			inv[node]++;
		}
	}

//	cout << node << " " << subnode[node] << " " << inv[node] << endl;

	return;
}

void dfs1(ll node, ll par, ll disor = 0)
{
	ans[node] = disor + inv[node];

	if(orient.find({par,node}) != orient.end()) ans[node]++;

	if(orient.find({node,par}) != orient.end()) ans[node]--;

	for(auto it: graph[node])
	{
		if(it == par) continue;

		dfs1(it,node,ans[node] - inv[it]);
	}


//	cout << node << " " << ans[node] << " " << disor << " " << inv[node] <<  endl;

	return;
}

void solve(ll n)
{
	ll mn = mxlld;

	for(ll i = 1; i <= n; i++) mn = min(mn,ans[i]);

	cout << mn << "\n";

	for(ll i = 1; i <= n; i++)
	{
		if(ans[i] == mn) cout << i << " ";
	}

	cout << "\n";
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
		for(i = 1; !graph[i].empty(); i++) graph[i].clear();
		orient.clear();

		for(i = 1; i < n; i++)
		{
			ll u, v;
			slld(u);
			slld(v);

			graph[u].pb(v);
			graph[v].pb(u);

			orient[{u,v}] = 1;
		}

		dfs(1,0);

		dfs1(1,0);

		solve(n);
    }


}


