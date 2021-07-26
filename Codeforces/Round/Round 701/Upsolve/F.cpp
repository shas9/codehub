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

void test1()
{
	ll n;
    cin >> n;

    ll dp[200005][2];


    dp[1][0] = 1;
    dp[1][1] = 0;

    ll sum;

    cin >> sum;

    for(ll i = 2; i <= n; i++)
    {
		ll input;

        cin >> input;

        dp[i][0] = dp[i - 1][0] + dp[i - 1][1];

        if(sum) dp[i][1] = dp[i - 1][0] + dp[i - 1][1];
        else dp[i][1] = dp[i - 1][1];

        sum += input;
    }

    cout << dp[n][0] + dp[n][1] << endl;
}

map < ll, ll > dp_test2[200005];
ll arr[200005];
ll n;
ll solve_test2(ll pos, ll sum)
{
	if(pos > n) return 1;

	if(dp_test2[pos].find(sum) != dp_test2[pos].end()) return dp_test2[pos][sum];

	dp_test2[pos][sum] = solve_test2(pos + 1, arr[pos]);
	if(sum) dp_test2[pos][sum] += solve_test2(pos + 1, sum + arr[pos]);

	return dp_test2[pos][sum];
}

void test2()
{
	cin >> n;

	for(ll i = 1; i <= n; i++) slld(arr[i]), dp_test2[i].clear();

	cout << solve_test2(1,0) << "\n";
}

void solve()
{
	ll n;
	cin >> n;
	vector < ll > b(n);

	for(auto &it: b) cin >> it;

	map < ll, ll > dp;

	ll sum = 0;
	ll ans = 1;
	dp[0] = 1;
	const ll mod = (1e9) + 7;

	for(auto it: b)
	{
		ll x = dp[sum];
		dp[sum] = ans;
		sum += it;

		ans = (2 * ans - x) % mod;
	}

	if(ans < 0) ans += mod;

	cout << ans << "\n";
}


int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		solve();
    }


}


