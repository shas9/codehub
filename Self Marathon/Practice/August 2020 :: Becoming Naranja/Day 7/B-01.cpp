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

vector < vector < ll > > vec;
vector < ll > g[1000];
bool vis[1003];

void trav(ll node)
{
//	cout << node << endl;
	vis[node] = 1;

	for(auto it: g[node])
	{
		for(auto jt: vec[it])
		{
			if(vis[jt] == 0)
			{
				trav(jt);
			}
		}
	}
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
		for(ll i = 1; i <= m; i++) g[i].clear(), vis[i] = 0;

		vec.clear();

		ans = 0;

		for(ll i = 0; i < n; i++)
		{
			vec.push_back({});

			ll sz;

			cin >> sz;

			ans += sz == 0;

			for(ll j = 0; j < sz; j++)
			{
				cin >> input;

				g[input].push_back(i);

				vec.back().push_back(input);
			}
		}

		ll cc = 0;
		for(ll i = 1; i <= m; i++)
		{
//			cout << i  << endl;
			if(g[i].empty()) continue;

//			bug;
			if(vis[i] == 0)
			{
				cc++;

				trav(i);
			}

//			bug;
		}

		cout << ans + max(0LL, cc - 1) << "\n";
    }


}



