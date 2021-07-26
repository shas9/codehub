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

ll val[200005];
ll par[200005];
vector < ll > root;
ll ans;
vector < ll > seq;
vector < ll > g[200005];
vector < pll > last;

void dfs(ll node)
{
	for(auto it: g[node])
	{
		dfs(it);

		if(val[it] >= 0) val[node] += val[it];
		else
		{
			last.push_back({it,val[it]});
		}
	}

	if(val[node] >= 0)
	{
		seq.push_back(node);
		ans += val[node];
	}
}


int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
		root.clear();
		seq.clear();
		last.clear();
		ans = 0;

		for(ll i = 1; i <= n; i++) g[i].clear();

		for(ll i = 1; i <= n; i++) slld(val[i]);
		for(ll i = 1; i <= n; i++)
		{
			slld(par[i]);

			if(par[i] != -1)
			{
				g[par[i]].pb(i);
			}
			else
			{
				root.push_back(i);
			}
		}

		for(auto it: root)
		{
			dfs(it);

			if(val[it] < 0) last.push_back({it,val[it]});
		}

		reverse(last.begin(),last.end());

		for(auto it: last)
		{
			seq.push_back(it.first);

			ans += it.second;
		}

		cout << ans << "\n";

		for(auto it: seq) cout << it << " ";
		cout << "\n";

    }

}




