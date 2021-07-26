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

ll edge[505][505];
ll arr[594];
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m)
    {
		memset(edge,0,sizeof edge);

		for(ll i = 1; i <= n; i++) cin >> arr[i];

		for(ll i = 0; i < m; i++)
		{
			ll u, v;

			cin >> u >> v;
			cin >> edge[u][v];

			edge[v][u] = edge[u][v];

			assert(u != v);
		}

		double ans = 0;

		for(ll i = 1; i <= n; i++)
		{
			for(ll j = i + 1; j <= n; j++)
			{
				double up = arr[i] + arr[j];

				if(edge[i][j]) ans = max(ans, up / edge[i][j]);
			}
		}

		cout << setprecision(10) << fixed << ans << "\n";
    }


}



