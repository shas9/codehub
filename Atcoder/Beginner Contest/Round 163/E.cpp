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

vector < pll > vec;
ll dp[2003][2003];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
		vec.clear();

		for(ll i = 0; i <= n; i++) for(ll j = 0; j <= n; j++) dp[i][j] = mnlld;

		ans = mnlld;

		for(ll i = 0; i < n; i++)
		{
			cin >> input;

			vec.push_back({input,i + 1});
		}

		sort(vec.rbegin(),vec.rend());

		dp[i][j] = 0;
		for(ll i = 0; i <= n; i++)
		{
			for(ll j = 0; j <= n; j++)
			{
				ll tot = i + j;

				if(tot == n)
				{
					ans = max(ans, dp[i][j]);
					break;
				}

				dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + vec[tot].first * (vec[tot].second - (i + 1)));
				dp[i][j + 1] = max(dp[i][j + 1], dp[i][j] + vec[tot].first * (n - j - vec[tot].second));
			}
		}

		cout << ans << "\n";
    }


}



