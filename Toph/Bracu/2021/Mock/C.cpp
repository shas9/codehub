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

ll dp[2000000];
ll ans[200];
ll arr[2000000];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
		memset(dp,0,sizeof dp);

		for(ll i = 1; i <= n; i++)
		{
			cin >> arr[i];
		}

		for(ll i = n - 1; i >= 1; i--)
		{
			if(abs(arr[i] - arr[i + 1]) < 2) continue;
			if(arr[i] > arr[i + 1]) continue;

			dp[i] = dp[i + 1] + 1;

			if(dp[i] == 1) dp[i] = 2;

//			cout << dp[arr[i]] << " " << arr[i] << endl;
		}

		for(ll i = 1; i <= n; i++)
		{
			cout << dp[i] << "\n";
		}

    }


}

