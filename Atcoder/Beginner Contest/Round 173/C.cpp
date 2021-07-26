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

using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

char grid[10][10];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m >> k)
    {
		for(ll i = 0; i < n; i++) scanf("%s", grid[i]);

		ans = 0;

		for(ll i = 0; i < (1 << n); i++)
		{
			for(ll j = 0; j < (1 << m); j++)
			{
				ll cnt = 0;
				for(ll ii = 0; ii < n; ii++)
				{
					if(check(i,ii)) continue;

					for(ll jj = 0; jj < m; jj++)
					{
						if(check(j,jj)) continue;

						cnt += grid[ii][jj] == '#';
					}
				}

				if(cnt == k) ans++;
			}
		}

		cout << ans << '\n';
    }


}




