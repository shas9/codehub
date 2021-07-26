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

vector < ll > g[100005];
bool vis[100005];
ll cnt;
vector < ll > vec;

void dfs(ll node)
{
	cnt++;
	vis[node] = 1;

	for(auto it: g[node])
	{
		if(vis[it] == 0) dfs(it);
	}
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m >> k)
    {
		vec.clear();

		for(ll i = 1; i <= m; i++)
		{
			ll u, v;

			slld(u);
			slld(v);

			g[u].pb(v);
			g[v].pb(u);
		}

		memset(vis,0,sizeof vis);

		for(ll i = 1; i <= n; i++)
		{
			if(vis[i]) continue;

			cnt = 0;

			dfs(i);

			vec.push_back(cnt);
		}

		ans = 1;


		if(n == 1 && m == 0) cout << vec.size() << endl;

		for(auto it: vec)
		{
			ans = (ans * it) % k;
		}

		if(n == 1 && m == 0) cout << vec.size() << endl;
		ll sz = vec.size() - 2;


		if(n == 1 && m == 0) cout << vec.size() << endl;

		for(ll i = 1; i <= sz; i++) ans = (ans * n) % k;

		if(n == 1 && m == 0) cout << vec.size() << endl;

		if(vec.size() == 1) ans = min(ans,1LL);

		if(n == 1 && m == 0) cout << vec.size() << endl;

		printf("%lld\n", ans);
    }


}



