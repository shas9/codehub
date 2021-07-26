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

#define mod 1000000007

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

vector < ll > g[500005];
bool vis[500005];

ll power(ll x, ll y, ll p)
{
    ll res = 1;      // Initialize result

    x = x % p;  // Update x if it is more than or
                // equal to p

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;

        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}

ll dfs(ll node, ll par = 0)
{
	vis[node] = 1;
	ll ret = 0;

	for(auto it: g[node])
	{
		if(it != par)
		{
			ret += dfs(it,node);
		}
	}

	return ret + 1;
}

ll dfs1(ll node, ll par = 0)
{
	vis[node] = 1;
	ll ret = g[node].size();

	for(auto it: g[node])
	{
		if(it != par)
		{
			ret = max(dfs1(it,node),ret);
		}
	}

	return ret;
}
vector < pll > vec;

ll fact[500005];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(n);
    slld(m);

    for(i = 1; i <= m; i++)
    {
		ll u, v;

		slld(u);
		slld(v);

		g[u].pb(v);
		g[v].pb(u);
    }

    slld(m);

    for(i = 1; i <= n; i++)
    {
		if(vis[i] == 0)
		{
			ll nodes = dfs1(i) - 1;
//			cout << nodes << endl;
			vec.push_back({nodes,dfs(i)});
		}
    }

    for(i = 1; i <= m; i++)
    {
		slld(k);

		ans = 0;

		for(auto it: vec)
		{
			ll add = (k * power(k - it.first, it.second - 1, mod)) % mod;
			ans = (ans + add) % mod;
		}

		printf("%lld\n", ans);
    }


}



