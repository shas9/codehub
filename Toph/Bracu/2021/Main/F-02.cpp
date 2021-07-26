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

ll arr[1000005];
ll dp[1000006][27];
ll dp2[1000006];

string str;

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> str)
    {
		ll n = str.size();

		for(ll i = 0; i < n; i++)
		{
			arr[i + 1] = str[i] - 'a';
		}

		for(ll i = 1; i <= n; i++)
		{
			dp[i][arr[i]]++;
			dp2[i] = dp2[i - 1];

			for(ll j = arr[i] + 1; j < 26; j++)
			{
				dp2[i] += dp[i - 1][j];

//				cout << i - 1 << " " << j << " : " << dp[i - 1][j] << endl;
			}
			for(ll j = 0; j < 26; j++)
			{
				dp[i][j] += dp[i - 1][j];
			}
		}

		cin >> m;

		for(ll i = 1; i <= m; i++)
		{
			cin >> l >> r;

			ll ans = dp2[r] - dp2[l - 1];

			ll cnt1[30] = {0}, cnt2[30] = {0};

			for(ll j = 0; j < 26; j++) cnt1[j] = dp[r][j] - dp[l - 1][j];
			for(ll j = 0; j < 26; j++) cnt2[j] = dp[l - 1][j];

//			for(ll j = 0; j < 26; j++) cout << j << " : " << cnt1[i] << " " << cnt2[j] << "\n";

			for(ll j = 25; j >= 0; j--) cnt2[j] += cnt2[j + 1];

			for(ll j = 0; j < 26; j++)
			{
				ans -= (cnt1[j] * cnt2[j + 1]);
			}

			cout << ans << "\n";
		}
    }


}

