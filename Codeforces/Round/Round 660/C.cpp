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

ll hh[200005];
ll pp[200005];
ll bad[200005];
vector < ll > g[200005];

bool trav(ll node, ll par)
{
	bad[node] = 0;
	ll pep = pp[node];

	for(auto it: g[node])
	{
		if(it != par)
		{
			if(trav(it, node) == 0) return 0;

			pp[node] += pp[it];
		}
	}

	bad[node] = pp[node] - hh[node];

	if(bad[node] & 1 || bad[node] < 0) return 0;

	bad[node] /= 2;

	for(auto it: g[node])
	{
		if(it != par)
			bad[node] -= bad[it];
	}

	if(bad[node] > pep)
	{
//		cout << node << ": " << bad[node] << " " << pep << endl;
		return 0;
	}

	bad[node] = pp[node] - hh[node];

	bad[node] /= 2;

	return 1;
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
		slld(m);

		for(ll i = 1; i <= n; i++) g[i].clear();

		for(ll i = 1; i <= n; i++) slld(pp[i]);
		for(ll i = 1; i <= n; i++) slld(hh[i]);

		for(ll i = 1; i < n; i++)
		{
			ll u, v;
			slld(u);
			slld(v);

			g[u].pb(v);
			g[v].pb(u);
		}

		if(trav(1,-1) == 0)
		{
			printf("NO\n");
			continue;
		}

		printf("YES\n");


    }


}




