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

ll lft[300005];
ll rgt[300005];
ll arr[300005];

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
		cin >> n;

		lft[1] = lft[n] = rgt[n] = rgt[1] = 0;


		for(ll i = 1; i <= n; i++) cin >> arr[i];

		for(ll i = 2; i < n; i++)
		{
			if(arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) lft[i] = rgt[i] = 1;
			else if(arr[i] < arr[i - 1] && arr[i] < arr[i + 1]) lft[i] = rgt[i] = 1;
			else lft[i] = rgt[i] = 0;
		}

		for(ll i = 2; i <= n; i++) lft[i] += lft[i - 1];
		for(ll i = n - 1; i >= 1; i--) rgt[i] += rgt[i + 1];

		ans = lft[n];

		for(ll i = 2; i < n; i++)
		{
			ll cnt1 = 0;
			ll cnt2 = 0;

			ll x = arr[i];

			arr[i] = arr[i - 1];

			for(ll j = max(2LL, i - 5); j <= min(n - 1, i + 5); j++)
			{
				if(arr[j] > arr[j - 1] && arr[j] > arr[j + 1]) cnt1++;
				else if(arr[j] < arr[j - 1] && arr[j] < arr[j + 1]) cnt1++;
			}

			cnt1 += lft[max(1LL, i - 6)] + rgt[min(n, i + 6)];

			arr[i] = arr[i + 1];

			for(ll j = max(2LL, i - 5); j <= min(n - 1, i + 5); j++)
			{
				if(arr[j] > arr[j - 1] && arr[j] > arr[j + 1]) cnt2++;
				else if(arr[j] < arr[j - 1] && arr[j] < arr[j + 1]) cnt2++;
			}

			cnt2 += lft[max(1LL, i - 6)] + rgt[min(n, i + 6)];

			ans = min(ans, min(cnt1,cnt2));

			arr[i] = x;
		}

		cout << ans << "\n";

    }


}




