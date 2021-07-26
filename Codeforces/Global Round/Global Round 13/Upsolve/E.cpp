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

vector < ll > g[200005];
ll subnode[200005];

bool isfib(ll x)
{
	ll fn1 = 1, fn2 = 0;

	while(fn1 < x)
	{
		ll fn = fn1 + fn2;
		fn2 = fn1;
		fn1 = fn;
	}

	return fn1 == x;
}

bool solve(ll node, ll par)
{
	bool ret = 1;
	ll child = 0;
	subnode[node] = 1;
	ll totfib = 0;

	for(auto it: g[node])
	{
		if(it != par)
		{
			child++;
			ret &= solve(it, node);
			subnode[node] += subnode[it];
		}
	}

	if(child >= 3)
	{
		bool on = 0;
		for(auto it: g[node])
		{
			if(it != par)
			{
				subnode[node] -= subnode[it];

				if(isfib(subnode[node]) && isfib(subnode[it])) on = 1;

				subnode[node] += subnode[it];

			}
		}

		ret &= on && isfib(subnode[node]);
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

    while(cin >> n)
    {
//		cout << isfib(n) << endl;

		for(ll i = 1; i <= n; i++)
		{
			g[i].clear();
		}

		for(ll i = 1; i < n; i++)
		{
			ll u, v;

			cin >> u >> v;

			g[u].pb(v);
			g[v].pb(u);
		}

		if(solve(1,-1) && isfib(n)) cout << "Yes\n";
		else cout << "No\n";
    }


}


