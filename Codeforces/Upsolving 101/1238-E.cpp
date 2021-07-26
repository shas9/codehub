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

ll dp[(1 << 21)];
ll cnt[21][21];
string str;

void solve(ll m)
{
	dp[0] = 0;

	for(ll i = 0; i < m; i++)
	{
		for(ll mask = 0; mask < (1 << m); mask++)
		{
			if(check(mask,i))
			{
				ll pos = __builtin_popcount(mask);

				ll sum1 = 0, sum2 = 0;

				for(ll j = 0; j < m; j++)
				{
					if(check(mask,j)) sum1 += cnt[i][j];
					else sum2 += cnt[i][j];
				}

//				cout << sum1 << " " << sum2 << endl;

				dp[mask] = min(dp[mask], dp[mask ^ (1 << i)] + (sum1 - sum2) * pos);
			}
		}
	}
}
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m >> str)
    {
		memset(cnt,0,sizeof cnt);

		for(i = 0; i < (1 << m); i++) dp[i] = mxlld;

		for(i = 1; i < n; i++)
		{
			ll x = str[i] - 'a';
			ll y = str[i - 1]  -'a';

			if(x == y) continue;

			cnt[x][y]++;
			cnt[y][x]++;
		}

		solve(m);

		printf("%lld\n", dp[(1 << m) - 1]);
    }


}


