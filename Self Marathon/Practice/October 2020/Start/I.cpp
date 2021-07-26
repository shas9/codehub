// God put a smile upon your face <3

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll int
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

ll mat[101][101];
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m >> k)
    {
		ans = (1 << 30);

		for(ll i = 1; i <= n; i++) for(ll j = 1; j <= m; j++) cin >> mat[i][j];

		for(ll i = 1; i <= 10000; i++)
		{
			ll cnt = 0;

			for(ll j = 1; j <= n && cnt != (1 << 30); j++)
			{
				for(ll x = 1; x <= m; x++)
				{
					if(abs(mat[j][x] - i) % k)
					{
						cnt = (1 << 30);
						break;
					}

					cnt += abs(mat[j][x] - i) / k;
				}
			}

			ans = min(ans, cnt);

		}
		if(ans == (1 << 30)) ans = -1;

		cout << ans << "\n";
	}


}


