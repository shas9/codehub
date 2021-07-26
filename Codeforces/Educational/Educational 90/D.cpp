
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

ll arr[200005];
ll even[200005];
ll odd[200005];

ll solve1(ll i, ll j, ll lo, ll hi, ll n)
{
	ll ret = 0;

	if(i % 2 == j % 2)
	{
		if(lo < j) ret = solve1(i,j - 1, lo, hi, n);

		if(j < hi) ret = max(solve1(i, j + 1, lo, hi, n), ret);

		return ret;
	}

	ret += odd[j] - odd[i - 1];
	ret -= even[j] - even[i - 1];

	return ret;
}


ll solve(ll st, ll n)
{
	ll ret = 0;

	ll lo = st + 1;
	ll hi = n - 1;

	while(lo <= hi)
	{
		ll mid1 = (lo + (hi - lo) / 3);
		ll mid2 = (hi - (hi - lo) / 3);

		ll ans1 = 0, ans2 = 0;

		ans2 = solve1(st,mid2,lo,hi,n);

		ans1 = solve1(st,mid1,lo,hi,n);

		if(ans1 > ans2)
		{
			ret = max(ans1, ret);
			hi = mid2 - 1;
		}
		else
		{
			ret = max(ans2, ret);
			lo = mid1 + 1;

		}
	}

	return ret;
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

		for(i = 0; i < n; i++) even[i] = odd[i] = 0;

		for(i = 0; i < n; i++) slld(arr[i]);

		for(i = 0; i < n; i++)
		{
			if(i & 1) even[i] = even[i - 1];
			else
			{
				even[i] = arr[i];
				if(i) even[i] += even[i - 1];
			}
		}

		for(i = 0; i < n; i++)
		{
			if(i & 1) odd[i] = odd[i - 1] + arr[i];
			else if(i) odd[i] = odd[i - 1];
		}

		for(i = 0; i < n; i++) cout << odd[i] << " ";
		cout << endl;
		for(i = 0; i < n; i++) cout << even[i] << " ";
		cout << endl;

		ll cnt = 0;
		for(i = 0; i < n; i++)
		{
			cout << i << ":: ";
			for(j = i + 1; j < n; j += 2)
			{
				cnt++;
				ll sum = odd[j] - odd[i - 1] - even[j] + even[i - 1] + even[n - 1];

				cout << sum << " ";
			}

			cout << endl;
		}

		cout << cnt << endl;

		ans = 0;

		for(ll i = 0; i < n; i++)
		{
			ans = max(ans, solve(i,n));
		}

		printf("%lld\n", ans + even[n - 1]);
    }


}



