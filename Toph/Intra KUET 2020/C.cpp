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

ll suffix[1000006];
ll arr[1000006];
ll rarr[1000006];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m)
    {
		for(ll i = 1; i <= n; i++) slld(arr[i]);

		for(ll i = 1; i <= n; i++)
		{
			if(arr[i] > m)
			{
				cout << -1 << '\n';
				return 0;
			}
		}

		memset(suffix,-1,sizeof suffix);

		suffix[n + 1] = 0;
		rarr[n + 1] = -1;

		for(ll i = n; i >= 1; i--)
		{
			rarr[i] = max(arr[i], rarr[i + 1] + 1);

			if(rarr[i] >= m) break;

			suffix[i] = suffix[i + 1] + abs(rarr[i] - arr[i]);
		}

		ans = mxlld;

		ll cost = 0;
		ll prv = -1;

		for(ll i = 1; i <= n; i++)
		{
			ll tot = cost + abs(m - arr[i]) + suffix[i + 1];

			if(suffix[i + 1] != -1 && 1 < i && i < n) ans = min(ans, tot);

			ll now = max(prv + 1, arr[i]);

			if(now >= m) break;

			prv = now;

			cost += abs(now - arr[i]);
		}

		if(ans == mxlld) ans = -1;

		printf("%lld\n", ans);
	}


}



