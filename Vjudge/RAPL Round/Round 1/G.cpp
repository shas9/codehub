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

bool subtree[50004];
vector < ll > g[50004];
bool uptree[50004];


void clr(ll n)
{
	for(ll i = 0; i <= n; i++)
	{
		subtree[i] = 0;
		uptree[i] = 0;
		g[i].clear();
	}
}

void dfs(ll node, ll par)
{
	subtree[node] = 0;

	for(auto it: g[node])
	{
		 if(it != par)
		 {
			dfs(it,node);
			subtree[node] |= subtree[it];
		 }
	}

	subtree[node] ^= 1;
}

bool alice;

void solve(ll node, ll par)
{
	bool ret = uptree[par];

	uptree[node] = 0;

	ll tot = 0;

	if(uptree[par]) tot++;

	for(auto it: g[node]) if(it != par) if(subtree[it]) tot++;

	for(auto it: g[node])
	{
		if(it == par) continue;

		if(subtree[it]) tot--;

		if(tot) uptree[node] = 0;
		else uptree[node] = 1;

		ret |= subtree[it];

		solve(it,node);

		if(subtree[it]) tot++;
	}

	ret ^= 1;

	alice |= ret;
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

		clr(n);

		for(i = 1; i < n; i++)
		{
			ll u, v;

			slld(u);
			slld(v);

			g[u].pb(v);
			g[v].pb(u);
		}

		if(n == 1) cout << "Alice" << '\n';
		else if(n == 0) cout << "Bob" << '\n';
		else
		{
			dfs(1,0);

			alice = 0;

			solve(1,0);

			if(alice) printf("Alice\n");
			else printf("Bob\n");
		}
    }


}


