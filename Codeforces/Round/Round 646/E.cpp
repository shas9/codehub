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

vector < ll > g[200005];

vector < ll > b, c;

vector < pll > a;

ll par[200005];

void dfs(ll node, ll parr)
{
	par[node] = parr;

	for(auto it: g[node]) if(it != parr) dfs(it,node);
}

pll vis[200005];

ll solve(ll node)
{
	if(vis[node].first != -1) return 0;

	queue < ll > q;

	q.push(node);

	ll ret = 0;

	ll one = 0, zero = 0;

	while(!q.empty())
	{
		ll top = q.front();
		q.pop();

//		cout << top << " ";

		if(b[top - 1] != c[top - 1])
		{
			if(b[top - 1] == 1) one++;
			else zero++;
		}

		for(auto it: g[top])
		{
			if(it == par[top]) continue;

			if(vis[it].first == -1)
			{
				vis[it] = {0,0};
				q.push(it);
			}
			else
			{
				one += vis[it].first;
				zero += vis[it].second;
			}
		}
	}

//	cout << endl;
//	cout << one << " " << zero << endl;

	ret = min(one,zero);

	one -= ret;
	zero -= ret;

//	cout << one << " " << zero << endl;

	vis[node] = {one,zero};
	return ret * 2;
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
		for(i = 0; i <= n; i++) g[i].clear();
		a.clear();
		b.clear();
		c.clear();

		for(i = 1; i <= n; i++)
		{
			slld(input);

			a.push_back({input,i});

			slld(input);
			b.push_back(input);

			slld(input);
			c.push_back(input);
		}

		sort(a.begin(),a.end());

		for(i = 1; i < n; i++)
		{
			ll u, v;

			slld(u);
			slld(v);

			g[u].pb(v);
			g[v].pb(u);
		}

		dfs(1,0);

		ans = 0;

		memset(vis,-1,sizeof vis);

		for(i = 0; i < a.size(); i++)
		{
			ll x = solve(a[i].second);

			ans += x * a[i].first;

//			cout << a[i].second << " ~~ " << x << " " << a[i].first << '\n';
		}

		if(vis[1].first || vis[1].second) ans = -1;

		cout << ans << '\n';
    }


}



