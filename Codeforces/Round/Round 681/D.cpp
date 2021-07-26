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

ll arr[300005];
ll mn[300005];
bool solve(ll n)
{
	ll pos = 1;

	for(ll i = 2; i <= n; i++)
	{
		if(arr[i] > arr[i - 1]) break;

		pos = i;
	}

	mn[0] = mxlld;

	for(ll i = 1; i <= n; i++) mn[i] = min(mn[i - 1], arr[i]);

	ll mxdiff = 0;

	for(ll i = n - 1; i >= 1; i--)
	{
		arr[i] -= mxdiff;

		if(arr[i] < 0) return 0;

		if(arr[i] <= arr[i + 1]) continue;

		ll diff = arr[i] - arr[i + 1];

		mxdiff += diff;

		arr[i] = arr[i + 1];
	}

	return 1;
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
		cin >> n;

		for(ll i = 1; i <= n; i++) cin >> arr[i];

		if(solve(n)) cout << "YES\n";
		else cout << "NO\n";
    }


}



