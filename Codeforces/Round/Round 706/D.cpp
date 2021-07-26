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

ll lft[100005];
ll rgt[100005];

ll arr[100005];

ll lft1[100005];
ll rgt1[100005];

ll lftmx[100005];
ll rgtmx[100005];

void process(ll n)
{
	lft[1] = 1;

	for(ll i = 2; i <= n; i++)
	{
		lft[i] = 1;
		if(arr[i] > arr[i - 1]) lft[i] += lft[i - 1];
	}

	rgt[n] = 1;

	for(ll i = n - 1; i >= 1; i--)
	{
		rgt[i] = 1;
		if(arr[i] > arr[i + 1]) rgt[i] += rgt[i + 1];
	}

	lft1[1] = 1;
	lftmx[1] = 1;

	for(ll i = 2; i <= n; i++)
	{
		lft1[i] = 1;
		if(arr[i] < arr[i - 1]) lft1[i] += lft1[i - 1];

		lftmx[i] = max(lftmx[i - 1], max(lft1[i], lft[i]));
	}

	rgt1[n] = 1;
	rgtmx[n] = 1;

	for(ll i = n - 1; i >= 1; i--)
	{
		rgt1[i] = 1;
		if(arr[i] < arr[i + 1]) rgt1[i] += rgt1[i + 1];

		rgtmx[i] = max(rgtmx[i + 1], max(rgt1[i], rgt[i]));
	}

	lftmx[0] = lftmx[n + 1] = rgtmx[0] = rgtmx[n + 1] = 0;

	return;
}

bool solve(ll idx)
{
	if(lft[idx] == rgt[idx])
	{
		if(lft[idx] == 1) return 0;
		if(lft[idx] & 1)
		{
			ll lmx = lftmx[idx - 1];
			ll rmx = rgtmx[idx + 1];

			return max(lmx,rmx) < lft[idx];
		}
		return 0;
	}

	return 0;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
		for(ll i = 1; i <= n; i++) cin >> arr[i];

		process(n);

		ans = 0;

		for(ll i = 1; i <= n; i++) ans += solve(i);

		cout << ans << "\n";
    }


}



