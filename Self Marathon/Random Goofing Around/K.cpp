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

vector < pair < ll, pll > > edge;
ll par[105];

ll fnd(ll node)
{
	if(par[node] == node) return node;

	return par[node] = fnd(par[node]);
}

ll best(ll n)
{
	for(ll i = 0; i <= n; i++)
	{
		par[i] = i;
	}

	sort(edge.begin(),edge.end());

	ll ret = 0;

	for(auto it: edge)
	{
		ll u = it.second.first;
		ll v = it.second.second;

		ll pu = fnd(u);
		ll pv = fnd(v);

		if(pu == pv) continue;

		ret += it.first;

		par[pu] = pv;
	}

	return ret;
}

ll worst(ll n)
{
	for(ll i = 0; i <= n; i++)
	{
		par[i] = i;
	}

	sort(edge.rbegin(),edge.rend());

	ll ret = 0;

	for(auto it: edge)
	{
		ll u = it.second.first;
		ll v = it.second.second;

		ll pu = fnd(u);
		ll pv = fnd(v);

		if(pu == pv) continue;

		ret += it.first;

		par[pu] = pv;
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

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		slld(n);

		edge.clear();

		ll u, v, w;

		while(cin >> u >> v >> w)
		{
			if(u == 0 && v == 0 && w == 0) break;

			edge.push_back({w,{u,v}});
		}

		ans = worst(n);
		ans += best(n);

		if(ans & 1) printf("Case %lld: %lld/2\n", cs, ans);
		else printf("Case %lld: %lld\n", cs, ans / 2);
    }


}


