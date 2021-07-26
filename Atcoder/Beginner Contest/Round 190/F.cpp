 // God put a smile upon your face <3

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb push_back

#define bug printf("BUG\n")

#define mxlld 1e12
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

ll distk[20][20];
ll ck[20];
ll dist[100005];
vector < ll > g[100005];
ll dp[20][(1 << 17)];

void bfs(ll st, ll en)
{
	memset(dist,-1,sizeof dist);

	queue < ll > qq;

	qq.push(ck[st]);

	dist[ck[st]] = 0;

	while(!qq.empty())
	{
		ll top = qq.front();
		qq.pop();

		if(top == ck[en])
		{
			distk[st][en] = dist[top];
			return;
		}

		for(auto it: g[top])
		{
			if(dist[it] == -1)
			{
				dist[it] = dist[top] + 1;
				qq.push(it);
			}
		}
	}

	distk[st][en] = -1;
}

ll solve(ll last, ll mask, ll k)
{
	ll &ret = dp[last][mask];

	if(ret != -1) return ret;

	ll lim = (1 << k) - 1;

	if(mask == lim) return ret = 0;

	ret = mxlld;

	for(ll i = 0; i < k; i++)
	{
		if(check(mask, i) == 0)
		{
			if(distk[last][i] != -1)
			{
				ret = min(ret, solve(i, Set(mask, i), k) + distk[last][i]);
			}
		}
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

    while(cin >> n >> m)
    {
		for(ll i = 1; i <= n; i++) g[i].clear();

		for(ll i = 1; i <= m; i++)
		{
			ll u, v;

			cin >> u >> v;

			g[u].pb(v);
			g[v].pb(u);
		}

		cin >> k;

		for(ll i = 0; i < k; i++) cin >> ck[i];

		memset(dp,-1,sizeof dp);

		for(ll i = 0; i < k; i++)
		{
			for(ll j = i + 1; j < k; j++)
			{
				bfs(i,j);

				distk[j][i] = distk[i][j];

//				cout << i << " : " << j << " " << distk[i][j] << "\n";
			}
		}

		ans = mxlld;

		for(ll i = 0; i < k; i++) ans = min(ans, solve(i, (1 << i), k));

		if(ans >= (9e11)) ans = -2;

		cout << ans + 1 << "\n";
    }


}



