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

vector < pll > g[200005];
ll n;
ll subtree[200005];

ll solvemax(ll node, ll par = -1, ll upor = 0)
{
	subtree[node] = 0;
	ll ret = 0;

	for(auto it: g[node])
	{
		if(it.first != par)
		{
			ret += solvemax(it.first,node);
			subtree[node] += subtree[it.first];
		}
	}

	subtree[node]++;

	for(auto it: g[node])
	{
		if(it.first == par)
		{
			ll x = it.second * min(n / 2, min(subtree[node], n - subtree[node]));
			ret += x;

//			cout << node << " " << par << " " << x << endl;
		}
	}

	return ret;
}

ll solvemin(ll node, ll par = -1, ll upor = 0)
{
	subtree[node] = 0;
	ll ret = 0;

	for(auto it: g[node])
	{
		if(it.first != par)
		{
			ret += solvemin(it.first,node);
			subtree[node] += subtree[it.first];
		}
	}

	subtree[node]++;

	for(auto it: g[node])
	{
		if(it.first == par)
		{
			ll x = it.second * (subtree[node] % 2);
			ret += x;

//			cout << node << " " << par << " " << x << endl;
		}
	}

	return ret;
}

int main()
{
    ll i, j, k, l, m, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		slld(n);

		n *= 2;

		for(ll i = 0; i <= n; i++) g[i].clear();

		for(ll i = 1; i < n; i++)
		{
			ll u, v, w;

			slld(u);
			slld(v);
			slld(w);

			g[u].pb({v,w});
			g[v].pb({u,w});
		}


		for(ll i = 1; i <= n; i++) if(g[i].size() == 1) {

			cout << solvemin(i) << " " << solvemax(i) << '\n';

//			cout << i << endl;
			break;
		}
    }

}


