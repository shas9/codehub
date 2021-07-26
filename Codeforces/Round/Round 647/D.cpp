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

vector < ll > g[500005];
vector < ll > t[500005];
vector < ll > order;
ll vis[500005];

void clr(ll n)
{
	order.clear();

	for(ll i = 0; i <= (n + 2); i++)
	{
		vis[i] = 0;
		g[i].clear();
		t[i].clear();
	}
}

bool imposs(ll node, ll num)
{
	set < ll > st;

	for(auto it: g[node])
	{
		if(vis[it]) st.insert(vis[it]);

		if(vis[it] == num) return 1;
	}

	if(st.size() != (num - 1)) return  1;

	vis[node] = num;
	return 0;
}
bool solve(ll n)
{
	for(ll i = 1; i <= n; i++)
	{
//		cout << i << endl;
		for(auto it: t[i])
		{
			if(imposs(it,i)) return 0;

			order.push_back(it);
		}
	}

	return 1;
}
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m)
    {
		clr(n);

		for(ll i = 1; i <= m; i++)
		{
			ll u, v;

			slld(u);
			slld(v);

			g[u].pb(v);
			g[v].pb(u);

		}

		for(ll i = 1; i <= n; i++)
		{
			slld(input);

			t[input].pb(i);
		}

		if(solve(n) == 0) printf("-1");
		else
		{
			for(auto it: order) cout << it << " ";
			cout << '\n';
		}
    }



}


