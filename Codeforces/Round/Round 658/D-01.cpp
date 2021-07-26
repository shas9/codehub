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

ll arr[5003];
vector < ll > subset;
ll dp[5003][5003];

ll solve(ll pos, ll sum)
{
	if(sum < 0) return 0;

	ll &ret = dp[pos][sum];

	if(ret != -1) return ret;

	if(sum == 0) return ret = 1;

	if(pos == subset.size()) return ret = 0;

	ret = solve(pos + 1, sum - subset[pos]) | solve(pos + 1, sum);

	return  ret;
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
		slld(n);

		for(ll i = 1; i <= 2 * n; i++) slld(arr[i]);

		subset.clear();

		for(ll i = 2 * n; i >= 1; i--)
		{
			ll idx = i;
			ll mx = arr[i];

			for(ll j = i; j >= 1; j--)
			{
				if(mx < arr[j])
				{
					mx = arr[j];
					idx = j;
				}
			}

			subset.push_back(i - idx + 1);

			i = idx;
		}

		ll sz = subset.size();

		for(ll i = 0; i <= sz; i++)
		{
			for(ll j = 0; j <= n; j++) dp[i][j] = -1;
		}

		ans = solve(0,n);

		if(ans == 1) printf("YES\n");
		else printf("NO\n");
    }


}



