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

vector < ll > g[100005];
ll passage[100005];

bool solve(ll n)
{
	queue < ll > q;

	q.push(1);

	passage[1] = 1;

	while(!q.empty())
	{
		ll top = q.front();
		q.pop();

		for(auto it: g[top])
		{
			if(passage[it] == -1)
			{
				passage[it] = top;
				q.push(it);
			}
		}
	}

	for(ll i = 1; i <= n; i++) if(passage[i] == -1) return 0;

	return 1;
}
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
		for(i = 1; i <= n; i++)
		{
			passage[i] = -1;
			g[i].clear();
		}

		cin >> m;

		for(i = 1; i <= m; i++)
		{
			ll u, v;
			cin >> u >> v;
			g[u].pb(v);
			g[v].pb(u);
		}

		if(solve(n) == 0) printf("No\n");
		else
		{
			printf("Yes\n");
			for(i = 2; i <= n; i++) cout << passage[i] << "\n";
//			cout << '\n';
		}
    }


}



