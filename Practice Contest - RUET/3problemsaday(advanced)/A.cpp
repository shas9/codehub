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

void test()
{
	const ll n = 10;

	ll arr[] = {17, 25, 3, 4, 1, 2, 2, 68, 99, 102};
	vector < ll > p;
	for(ll i = 0; i < n; i++) p.push_back(i);

	ll dp[n][n];

	vector < ll > pp;

	ll mnn = mxlld;

//	while(next_permutation(p.begin(),p.end()))
	{
		for(ll i = 0; i < n; i++) for(ll j = 0; j < n; j++) dp[i][j] = mxlld;

		for(ll i = 0, sum = 0; i < n; i++)
		{
			sum += arr[p[i]];
			dp[0][i] = (sum * sum) + n;
		}

		for(ll i = 1; i < n; i++)
		{
			for(ll j = i - 1; j < n; j++)
			{
				for(ll k = j + 1, sum = 0; k < n; k++)
				{
					sum += arr[p[k]];

					dp[i][k] = min(dp[i][k], dp[i - 1][j] + (sum * sum + n));
				}
			}
		}

		ll mn = mxlld;

		for(ll i = 0; i < n; i++) mn = min(mn, dp[i][n - 1]);

		if(mnn > mn)
		{
			pp = p;
			mnn = mn;
		}
	}

	cout << mnn << endl;

	for(auto it: pp) cout << it + 1 << " ";

	cout << endl;
}

ll arr[500005];
ll dp[500005];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

//	test();

    while(cin >> n >> m)
    {
		for(ll i = 1; i <= n; i++) slld(arr[i]);
		for(ll i = 1; i <= n; i++) dp[i] = mxlld;

		dp[0] = 0;

		for(ll i = 1; i <= n; i++)
		{
			ll sum = 0;

			for(ll j = i; j <= min(i + 1000, n); j++)
			{
				sum += arr[j];

				dp[j] = min(dp[j], dp[i - 1] + sum * sum + m);
			}
		}

		cout << dp[n] << '\n';
    }


}


