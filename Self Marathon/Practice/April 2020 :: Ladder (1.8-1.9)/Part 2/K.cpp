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

vector < ll > gr[100005];
ll val[100005];
ll ans = 0;
ll inc[100005];
ll decrement[100005];

void dfs(ll node, ll par)
{
	inc[node] = 0;
	decrement[node] = 0;

	for(auto it: gr[node])
	{
		if(it == par) continue;

		dfs(it,node);

		inc[node] = max(inc[node], inc[it]);
		decrement[node] = max(decrement[node], decrement[it]);
	}

	ll vl = val[node] - decrement[node] + inc[node];

	if(vl >= 0) decrement[node] += vl;
	else inc[node] -= vl;
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
		ll u, v;

		slld(u);
		slld(v);

		gr[u].pb(v);
		gr[v].pb(u);
    }

    for(i = 1; i <= n; i++) slld(val[i]);

    dfs(1,0);

    ans = decrement[1] + inc[1];
    printf("%lld\n", ans);


}


