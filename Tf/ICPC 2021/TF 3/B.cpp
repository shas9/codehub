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

vector < ll > g[30];
string a, b;

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m)
    {
		for(ll i = 0; i < 30; i++) g[i].clear();

		cin >> a;

		for(ll i = 0; i < m; i++)
		{
			g[a[i] - 'a'].pb(i);
		}

		for(ll i = 1; i <= n; i++)
		{
			cin >> b;

			ans = 0;

			for(ll j = 0; j < b.size(); j++)
			{
				ll ch = b[j] - 'a';

				if(g[ch].empty()) ans += b.size();
				else
				{
					auto it = upper_bound(g[ch].begin(), g[ch].end(), j);

					ll pos = mxlld;

					if(it != g[ch].end())
					{
						pos = min(pos, *it - j);
					}

					if(it != g[ch].begin())
					{
						it--;

						pos = min(pos, j - *it);
					}

					ans += pos;
				}
			}

			cout << ans << "\n";
		}
    }


}



