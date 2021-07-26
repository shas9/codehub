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

ll arr[100005];

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
		ll z;

		cin >> n >> k >> z;

		for(ll i = 1; i <= n; i++) cin >> arr[i];

		ll mx = 0;

		ans = 0;
		ll sum = 0;

		for(ll i = 1; i <= k; i++)
		{
			sum += arr[i];

			mx = max(mx, arr[i] + arr[i + 1]);

			ll baki = k + 1 - i;

//			cout << i << ": " << baki << " " << mx << endl;

			if(baki % 2 == 0 && baki / 2 <= z)
			{
				ans = max(ans, sum + (baki / 2) * mx);
			}
		}

		sum += arr[k + 1];

		ans = max(ans, sum);

		cout << ans << "\n";
    }


}



