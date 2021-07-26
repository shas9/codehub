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

vector < ll > g[1005];
vector < ll > qq;

pll ask()
{
	cout << "? " << qq.size() << " ";

	for(auto it: qq) cout << it << " ";

	cout << endl;

	pll ret;

	cin >> ret.first >> ret.second;

	assert(ret.first != -1);

	qq.clear();

	return ret;
}

ll depth[1003];

void build(ll node, ll par)
{
	depth[node] = depth[par] + 1;

	for(auto it: g[node]) if(it != par) build(it,node);

	return;
}

void solve(ll n)
{
	for(ll i = 0; i <= n; i++) g[i].clear();

	for(ll i = 1; i < n; i++)
	{
		ll u, v;

		slld(u);
		slld(v);

		g[u].pb(v);
		g[v].pb(u);
	}


	for(ll i = 1; i <= n; i++)
	{
		qq.push_back(i);
	}

	pll root = ask();

	depth[0] = -1;

	build(root.first, 0);

	ll lo = root.second / 2;
	ll hi = 0;
	for(ll i = 1; i <= n; i++) hi = max(hi, depth[i]);
	hi = min(hi,root.second);

	ll nodef = root.first;

	while(lo <= hi)
	{
		ll mid = (lo + hi) / 2;

		for(ll i = 1; i <= n; i++) if(depth[i] == mid) qq.push_back(i);

		pll x = ask();

		if(x.second == root.second)
		{
			nodef = x.first;
			lo = mid + 1;
		}
		else
		{
			hi = mid - 1;
		}
	}

	build(nodef, 0);

	ll nodes = 0;

	for(ll i = 1; i <= n; i++) if(depth[i] == root.second) qq.push_back(i);

	pll x = ask();

	nodes = x.first;

	cout << "! " << nodef << " " << nodes << endl;

	string str;
	cin >> str;

	assert(str == "Correct");

	return;
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

		solve(n);
    }


}

