// God put a smile upon your face <3

#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long

using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

ll par[200005];
ll mnn[200005];
ll mxx[200005];
ll sz[200005];
vector < ll > graph[200005];
bool vis[200005];

ll fnd(ll node)
{
	if(par[node] == node) return node;

	return par[node] = fnd(par[node]);
}

void add(ll a, ll b)
{
	ll pa = fnd(a);
	ll pb = fnd(b);

	par[pa] = pb;

	mnn[pb] = min(mnn[pb],mnn[pa]);
	mxx[pb] = max(mxx[pb],mxx[pa]);
	sz[pb] += sz[pa];
}

ll solve(ll node)
{
	ll pnode = fnd(node);

	vis[pnode] = 1;

	ll cnt = 0;

//	cout << node << " " << pnode << " " << mnn[pnode] << " " << mxx[pnode] << endl;

	for(ll i = mnn[pnode]; i <= mxx[pnode]; i++)
	{
		ll pi = fnd(i);

		if(pi != pnode)
		{
			add(i,pnode);

			cnt++;
		}
	}

//	cout << cnt << endl;

	return cnt;
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
		for(i = 1; i <= n; i++) par[i] = mnn[i] = mxx[i] = i, sz[i] = 1, vis[i] = 0;
		for(i = 1; i <= n; i++) graph[i].clear();

		for(i = 1; i <= m; i++)
		{
			ll u, v;

			slld(u);
			slld(v);

			graph[u].push_back(v);
			graph[v].push_back(u);
			add(u,v);
		}

		ans = 0;

		for(i = 1; i <= n; i++)
		{
			if(vis[fnd(i)]) continue;

			ans += solve(i);
		}

		printf("%lld\n", ans);
    }


}


