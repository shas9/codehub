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

vector < pll > g[100005];
vector < ll > can;
set < ll > st;

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> k)
    {
		for(ll i = 1; i <= n; i++) g[i].clear();
		can.clear();
		st.clear();

		for(ll i = 1; i < n; i++)
		{
			ll u, v, w;

			cin >> u >> v >> w;

			g[u].pb({v,w});
			g[v].pb({u,w});
		}

		for(ll i = 0; i < k; i++)
		{
			cin >> input;
			can.push_back(input);
			st.insert(input);
		}

		for(auto it: can)
		{
			ll mn = mxlld;
			ll node = -1;
			ll cnt = 0;

			for(auto jt: g[it])
			{
				if(jt.second < mn)
				{
					mn = jt.second;
					node = jt.first;
				}
			}

			for(auto jt: g[it])
			{
				if(jt.second == mn)
				{
					st.insert(jt.first);
				}
			}
		}

		cout << st.size() << "\n";
    }


}



