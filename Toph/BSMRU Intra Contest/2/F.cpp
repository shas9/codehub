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

vector < pll > graph[1000006];

ll cs[1000006];
ll ans[1000006];
void dfs(ll node, ll par)
{
	cs[node] = 0;

	for(auto it: graph[node])
	{
		if(it.first == par) continue;

		dfs(it.first,node);

		cs[node] = max(cs[node], cs[it.first] + it.second);
	}
}

void dfs1(ll node, ll par, ll lev = 0)
{
//	cout << node << " " << par << endl;
	ans[node] = 0;

	multiset < ll > st;

	st.insert(lev);
	st.insert(0);

	for(auto it: graph[node])
	{
		if(it.first == par) continue;

		st.insert(cs[it.first] + it.second);
	}

	for(auto it: graph[node])
	{
		if(it.first == par) continue;
		multiset < ll > :: iterator jt = st.end();

		jt--;

		if(cs[it.first] + it.second == *jt) jt--;

		dfs1(it.first,node,(*jt) + it.second);
	}

//	cout << node << ": ";
//
//	for(auto it: st) cout << it << " ";
//
//	cout << endl;

	multiset < ll > :: iterator it = st.end();
	it--;

	ans[node] = (*it);
	it--;
	ans[node] += (*it);

}
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(n);

    for(i = 1; i < n; i++)
    {
		ll u, v, w;

		slld(u);
		slld(v);
		slld(w);
		graph[u].pb(make_pair(v,w));
		graph[v].pb(make_pair(u,w));
    }

    dfs(1,0);

    dfs1(1,0);

    slld(m);

    for(i = 1; i <= m; i++)
    {
		slld(input);
		printf("%lld\n", ans[input]);
    }
}



