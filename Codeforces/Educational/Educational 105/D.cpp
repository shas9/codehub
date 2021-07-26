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

ll mat[505][505];
ll arr[200005];
vector < ll > g[200005];
vector < pll > money[5005];
bool vis[5005];
bool vis2[505];

ll n;
vector < ll > sup[5005];

ll solve(ll node, ll salary)
{
	arr[node] = salary;

	for(ll i = node; i >= 1; i--)
	{
		if(money[i].empty()) continue;

		if(vis[i] == 1) continue;

		solve(node + 1, i);
	}

	for(auto it: money[salary])
	{

	}
}

int main()
{
    ll i, j, k, l, m, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
		ll mx = 0;

		memset(vis,0,sizeof vis);
		memset(vis2,0,sizeof vis2);

		for(ll i = 1; i <= n; i++)
		{
			for(ll j = 1; j <= n; j++)
			{
				cin >> mat[i][j];
				mx = max(mx, mat[i][j]);

				if(i == j) arr[i] =  mat[i][j];

				if(i < j)
				{
					money[mat[i][j]].push_back({i,j});
				}
			}
		}

		for(ll i = 1; i <= n * n; i++) g[i].clear();

		ll tot = solve(n + 1, mx);

		cout << tot << "\n";
		for(ll i = 1; i <= n; i++)
		{
			cout << arr[i] << " ";
		}

		cout << n + 1 << "\n";

		ans = 0;

		for(ll i = 1; i <= tot; i++)
		{
			for(auto it: g[i]) cout << it << " " << i << "\n";
		}

		cout << "\n";

    }


}



