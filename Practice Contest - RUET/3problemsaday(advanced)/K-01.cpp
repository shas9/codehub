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

vector < ll > g[1000];
ll vis[1000];
vector < pll > vec;

bool inside(ll x, ll y)
{
	if(vec[x].first < vec[y].first && vec[y].first < vec[x].second && vec[x].second < vec[y].second) return 1;

	if(vec[x].first < vec[y].second && vec[y].second < vec[x].second && vec[y].first < vec[x].first) return 1;

	return 0;
}

bool solve(ll node, ll col)
{
	if(vis[node] != -1)
	{
		return vis[node] == col;
	}

	vis[node] = col;

	for(auto it: g[node])
	{
		if(solve(it, col ^ 1) == 0) return 0;
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

	fastio;
    while(cin >> n >> m)
    {
		vec.clear();
		memset(vis,-1,sizeof vis);

		vec.push_back({0,0});

		for(ll i = 1; i <= m; i++)
		{
			ll u, v;
			cin >> u >> v;
			if(u > v) swap(u,v);

			vec.push_back({u,v});

			for(ll j = 1; j < i; j++)
			{
				if(inside(i,j) || inside(j,i))
				{
					g[i].pb(j);
					g[j].pb(i);
				}
			}
		}

		bool no = 0;

		for(ll i = 1; i <= m; i++)
		{
			if(vis[i] == -1)
			{
				if(solve(i,0) == 0)
				{
					no = 1;
					break;
				}
			}
		}

		if(no) cout << "Impossible\n";
		else
		{
			string s = "";

			for(ll i = 1; i <= m; i++)
			{
				if(vis[i] == 0) s += 'i';
				else s += 'o';
			}

			cout << s << "\n";
		}
    }


}




