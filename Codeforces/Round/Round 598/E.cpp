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

struct st
{
	ll id, skill;
} arr[200005];

bool comp(st a, st b)
{
	return a.skill < b.skill;
}

ll team[200005];
ll par[200005];
ll dp[200005];

pll solve(ll n)
{
	for(ll i = 1; i <= n + 2; i++) dp[i] = 1e15;

	dp[1] = 0;

	for(ll i = 1; i <= n; i++)
	{
		for(ll j = 3; j <= 5 && (i + j) <= n + 1; j++)
		{
			ll divers = (arr[i + j - 1].skill - arr[i].skill);

//			cout << i + j << " " << dp[i + j] << " " << divers << " " << dp[i] << endl;

			if(dp[i + j] > (divers + dp[i]))
			{
				dp[i + j] = divers + dp[i];
				par[i + j] = i;
			}
		}
	}

	ll cnt = 0;
	ll now = n + 1;

	while(now > 1)
	{
		cnt++;

//		cout << now << " ~~ " << par[now] << endl;

		for(ll i = now - 1; i >= par[now]; i--)
		{
			team[arr[i].id] = cnt;
		}

		now = par[now];
	}

	return make_pair(dp[n + 1], cnt);

}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll input, flag, tag;
	pll ans;
    ll testcase;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
		for(i = 1; i <= n; i++)
		{
			slld(arr[i].skill);
			arr[i].id = i;
		}

		sort(arr + 1, arr + 1 + n, comp);

		ans = solve(n);

		printf("%lld %lld\n", ans.first, ans.second);

		for(i = 1; i <= n; i++)
		{
			printf("%lld ", team[i]);
		}

		printf("\n");
    }


}



