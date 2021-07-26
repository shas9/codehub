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


ll vis[5003];
vector < ll > graph[5003];
ll dp[5003][5003];
vector < pair < ll, pll >  > ccomp;
ll lev;
ll odd;
ll a, b, c;
ll col[5003];

ll dfs(ll node, ll par, ll lv)
{
	lev++;

	if(lv % 2) odd++;

	vis[node] = (lv % 2) + 2;

	ll ret = 0;

	for(auto it: graph[node])
	{
		if(it == par) continue;

		if(vis[it])
		{
			if((vis[it] + vis[node]) % 2 == 0) return -1;
		}
		else
		{
			ret = min(ret, dfs(it,node,lv + 1));
		}
	}

	return ret;
}

void docol(ll node, ll par, ll st)
{
	if(st % 2 == 0) col[node] = 2;
	else
	{
		if(a)
		{
			col[node] = 1;
			a--;
		}
		else
		{
			col[node] = 3;
			c--;
		}
	}


	for(auto it: graph[node])
	{
		if(it == par) continue;

		if(col[it] == 0)
		{
			docol(it,node,st ^ 1);
		}
	}
}

ll solve(ll pos, ll taken)
{
	if(pos == ccomp.size())
	{
//		cout << pos << " " << taken << endl;
		if(taken == b) return dp[pos][taken] = 1;

		return dp[pos][taken] = 0;
	}

	ll &ret = dp[pos][taken];

	if(ret != -1) return ret;

	ll p1 = solve(pos + 1, taken + ccomp[pos].second.first);

	if(p1 == 1)
	{
//		bug;
		docol(ccomp[pos].first,0,0);

		return ret = p1;
	}

	p1 = solve(pos + 1, taken + ccomp[pos].second.second);

	if(p1 == 1)
	{
//		bug;
		docol(ccomp[pos].first,0,1);

		return ret = p1;
	}

	return ret = 0;
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
		for(i = 1; i <= n; i++) vis[i] = 0, col[i] = 0, graph[i].clear();
		ccomp.clear();
		memset(dp,-1,sizeof dp);



		cin >> a >> b >> c;

		for(i = 1; i <= m; i++)
		{
			ll u, v;
			slld(u);
			slld(v);

			graph[u].pb(v);
			graph[v].pb(u);
		}

		for(i = 1; i <= n; i++)
		{
			lev = 0;
			odd = 0;

			if(vis[i]) continue;

			ll x = dfs(i,0,1);

			if(x == -1)
			{
				printf("NO\n");
				exit(0);
			}

//			cout << i << " " << odd << " " << lev - odd << endl;

			ccomp.push_back({i,{odd,lev-odd}});
		}

		solve(0,0);

		if(dp[ccomp.size()][b] == 0 || dp[ccomp.size()][b] == -1) printf("NO\n");
		else
		{
			printf("YES\n");

//			cout << col[444] << " " << col[789] << endl;
			for(i = 1; i <= n; i++)
			{
				if(col[i] == 0)
				{
					if(a) col[i] = 1, a--;
					else if(c) col[i] = 3, c--;
				}
			}

			for(i = 1; i <= n; i++) printf("%lld", col[i]);

			printf("\n");
		}
    }


}

/*

5000 1
1000 1 4000
444 789

*/

