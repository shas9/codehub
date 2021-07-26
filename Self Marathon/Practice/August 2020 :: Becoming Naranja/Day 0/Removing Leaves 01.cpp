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

set < ll > g[200005];
vector < ll > leafs[200005];
bool vis[200005];

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
		slld(k);

		for(ll i = 1; i <= n; i++)
		{
			g[i].clear();
			leafs[i].clear();
			vis[i] = 0;
		}

		for(ll i = 1; i < n; i++)
		{
			ll u, v;
			slld(u);
			slld(v);

			g[u].insert(v);
			g[v].insert(u);
		}

		if(k == 1)
		{
			printf("%lld\n", n - 1);
			continue;
		}

		priority_queue < pll > pq;

		for(ll i = 1; i <= n; i++)
		{
			if(g[i].size() == 1)
			{
				vis[i] = 1;
				leafs[*g[i].begin()].push_back(i);

				pq.push({leafs[*g[i].begin()].size(), *g[i].begin()});
			}
		}

		ans = 0;

		while(!pq.empty())
		{
			pll top = pq.top();
			pq.pop();

			if(top.first != leafs[top.second].size()) continue;
			if(top.first < k) break;

			ans++;

			for(ll i = 1; i <= k; i++)
			{
				ll node = leafs[top.second].back();
				leafs[top.second].pop_back();
				g[top.second].erase(node);
			}

			if(g[top.second].size() == 1)
			{
				leafs[*g[top.second].begin()].push_back(top.second);
				pq.push({leafs[*g[top.second].begin()].size(), *g[top.second].begin()});
			}
			else
			{
				pq.push({leafs[top.second].size(),top.second});
			}
		}

		cout << ans << "\n";
    }


}



