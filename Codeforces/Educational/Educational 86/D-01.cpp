// God put a smile upon your face <3

#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb(x) push_back(x)

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

ll arr[200005];
ll ck[200005];
vector < ll > ans[200005];
ll n;

bool solve(ll sz)
{
	for(ll i = 1; i <= sz; i++) ans[i].clear();

	ll idx = 1;

	for(ll i = 1; i <= n; i++)
	{
		ans[idx].push_back(arr[i]);

		if(ans[idx].size() > ck[arr[i]]) return 0;

		idx = (idx % sz) + 1;
	}

	return 1;
}

int main()
{
    ll i, j, k, l, m, o, r, q;
    ll testcase;
    ll input, flag, tag;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> k)
    {
		for(i = 1; i <= n; i++) slld(arr[i]);
		for(i = 1; i <= k; i++) slld(ck[i]);

		sort(arr + 1, arr + 1 + n);
		reverse(arr + 1, arr + 1 + n);

		ll lo = 1;
		ll hi = n;
		ll sz = n;

		while(lo <= hi)
		{
			ll mid = (lo + hi) / 2;

			if(solve(mid))
			{
				sz = mid;
				hi = mid - 1;
			}
			else lo = mid + 1;
		}

		solve(sz);

		printf("%lld\n", sz);

		for(i = 1; i <= sz; i++)
		{
			cout << ans[i].size() << " ";

			for(auto it: ans[i]) cout << it << " ";

			cout << "\n";
		}
    }


}



