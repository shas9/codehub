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

void test()
{
	ll arr[] = {0,9, 8, 7, 4, 5, 8, 1, 6, 8, 2};

	for(ll i = 1; i <= 10; i++)
	{
		cout << arr[i] - i << " " << i << " " << arr[i] + i << endl;
	}
}

map < ll, vector < ll > > g1, g2;
ll m, n;
map < pll, ll > dp1, dp2;

ll solve1(ll x, ll y)
{
	pll xx = {x,y};

	if(dp1.find(xx) != dp1.end()) return dp1[xx];

	auto it = upper_bound(g1[y - x].begin(), g1[y - x].end(), x);

	if(it == g1[y-x].end()) return dp1[xx] = min(n,y + (m - x + 1));

	ll nxtx = *it;
	ll nxty = y + (nxtx - x - 1);

	return dp1[xx] = solve1(nxtx, nxty);
}

ll solve2(ll x, ll y)
{
	pll xx = {x,y};

	if(dp2.find(xx) != dp2.end()) return dp2[xx];

	auto it = upper_bound(g2[y + x].begin(),g2[x + y].end(), x);

	if(it == g2[y + x].end()) return dp2[xx] = max(1LL,y - (m - x + 1));

	ll nxtx = *it;
	ll nxty = y - (nxtx - x - 1);

	return dp2[xx] = solve2(nxtx,nxty);
}

int main()
{
    ll i, j, k, l, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

//	test();

    while(cin >> n >> m)
    {
		dp1.clear();
		dp2.clear();
		g1.clear();
		g2.clear();

		for(i = 1; i <= m; i++)
		{
			slld(input);

			g1[input - i].pb(i);
			g2[input + i].pb(i);
		}

		if(n == 1)
		{
			printf("0\n");
			exit(0);
		}

		ans =0;

		for(i = 1; i <= n; i++)
		{
			ll upor = solve1(0,i);
			ll nich = solve2(0,i);

			assert(nich <= upor);

			ans += (upor - nich + 1);
		}

		printf("%lld\n", ans);
    }


}


