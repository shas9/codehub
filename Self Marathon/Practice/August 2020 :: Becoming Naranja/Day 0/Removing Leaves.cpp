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
priority_queue < pll > pq;
ll par[200005];
ll leaf[200005];

void dfs(ll node, ll p)
{
	ll cnt = 0;
	par[node] = p;

	for(auto it: g[node])
	{
		if(it != p)
		{
			if(g[it].size() == 1) cnt++;

			dfs(it,node);
		}
	}

	leaf[node] = cnt;
	pq.push({cnt,node});
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

		for(ll i = 1; i <= n; i++) g[i].clear(), leaf[i] = par[i] = 0;
		while(!pq.empty()) pq.pop();

		ll mx = 0;
		ll node = -1;

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
			mx = max((int)mx, (int)g[i].size());

			if(mx == g[i].size())
			{
				node = i;
			}
		}

		cout << "! " << node << endl;

		dfs(node,-1);

		ans = 0;

		while(!pq.empty())
		{
			pll top = pq.top();
			pq.pop();

			cout << top.first << " ~ " << top.second << endl;

			if(top.first < m || leaf[top.second] != top.first) continue;

			bug;

			leaf[top.second] -= m;

			ans++;

			if(leaf[top.second] == 0)
			{
				if(par[top.second] != -1)
				{
					leaf[par[top.second]]++;
					pq.push({leaf[par[top.second]], par[top.second]});
				}
			}
			else
			{
				pq.push({leaf[top.second], top.second});
			}
		}

		cout << ans << "\n";
    }


}



