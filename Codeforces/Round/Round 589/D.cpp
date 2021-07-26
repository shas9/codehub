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

vector < ll > v[3];

bool vis[100005];
ll tvis[100005];

bool no;

bool bfs(ll st, ll idx)
{
	queue < pll > qq;

	memset(tvis,-1,sizeof tvis);

	qq.push({st,0});

	tvis[st] = 0;

	v[idx].pb(st);

	while(!qq.empty())
	{
		pll top = qq.front();

		qq.pop();

		for(auto it: g[top.first])
		{
			if(tvis[it] == -1)
			{
				tvis[it] = top.second ^ 1;

				if(top.second)
				{
					if(vis[it]) return 0;
					v[idx].push_back(it);
				}

				qq.push({it,tvis[it]});
			}
		}
	}

	for(auto it: v[idx]) vis[it] = 1;

//	for(auto it: v[idx]) cout << it << "-";
//	cout << endl;

	return 1;
}

ll col[100005];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m)
    {
		for(ll i = 0; i <= n; i++) g[i].clear();

		memset(vis,0,sizeof vis);

		for(ll i = 0; i < 3; i++) v[i].clear();

		for(ll i = 1; i <= m; i++)
		{
			ll u, v;

			slld(u);
			slld(v);

			g[u].pb(v);
			g[v].pb(u);
		}

		ll cnt = 0;

		ans = 0;

		for(ll i = 1; i <= n; i++)
		{
			if(vis[i] == 0)
			{
				if(cnt == 3)
				{
					ans = -1;
					break;
				}

				if(bfs(i,cnt) == 0)
				{
					ans = -1;
					break;
				}

				cnt++;
			}
		}

		if(cnt != 3) ans = -1;

		if(ans == -1) printf("-1\n");
		else
		{
			for(ll i = 0; i < 3; i++)
			{
				for(auto it: v[i])
				{
					col[it] = i + 1;
				}
			}

			for(ll i = 1; i <= n; i++)
			{
				printf("%lld ",col[i]);
			}

			printf("\n");
		}


    }

}



