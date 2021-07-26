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

vector < ll > graph[100005];
ll d, n, m;
bool marked[100005];
ll subtree[100005];

void dfs(ll node, ll par)
{
	subtree[node] = mnlld;

	if(marked[node]) subtree[node] = 0;

	for(auto it: graph[node])
	{
		if(it == par) continue;

		dfs(it,node);

		subtree[node] = max(subtree[node], subtree[it] + 1);
	}

//	cout << node << " " << subtree[node] << endl;
}

bool comp(ll a, ll b)
{
	return a > b;
}

ll dfs1(ll node, ll par, ll lev = mnlld)
{

	vector < ll > vec;

	vec.push_back(lev);

	for(auto it: graph[node])
	{
		if(it == par) continue;

		vec.push_back(subtree[it] + 1);
	}

	if(marked[node]) vec.push_back(0);

	sort(vec.begin(),vec.end(), comp);

//	cout << node << ": ";
//
//	for(auto it: vec) cout << it << " ";
//
//	cout << endl;

	ll ret = 0;

	if(vec[0] <= d) ret++;

	for(auto it: graph[node])
	{
		if(it == par) continue;

		if(subtree[it] + 1 == vec[0]) ret += dfs1(it,node,vec[1] + 1);
		else ret += dfs1(it,node,vec[0] + 1);
	}

	vec.clear();

	return ret;
}
ll solve()
{
	dfs(1,0);

	return dfs1(1,0);
}

int main()
{
    ll i, j, k, l, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(n);
    slld(m);
    slld(d);

    for(i = 1; i <= m; i++) slld(input), marked[input] = 1;

    for(i = 1; i < n; i++)
    {
		ll u, v;

		slld(u);
		slld(v);

		graph[u].pb(v);
		graph[v].pb(u);
    }

    ans = solve();

    printf("%lld\n", ans);

}


