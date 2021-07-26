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

ll freq[100005];
ll arr[100005];
bool solve(ll mid, ll n)
{
	ll mx = 0;
	ll cnt = 0;

	for(ll i = 1; i <= n; i++)
	{
		if(mx < freq[i])
		{
			mx = freq[i];
			cnt = 0;
		}

		if(mx == freq[i]) cnt++;
	}

	ll space = max(mid + 1, cnt);

//	cout << mid << " " << space << " " << space * mx << endl;

	return space * (mx - 1) + cnt <= n;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

//	fastio;
    cin >> testcase;

    for(ll cs = 1; cs <= testcase; cs++)
    {
		cin >> n;

		for(ll i = 1; i <= n; i++) freq[i] = 0;

		for(ll i = 1; i <= n; i++)
		{
			cin >> input;

			freq[input]++;
		}

		ll lo = 0;
		ll hi = n;
		ans = 0;

		while(lo <= hi)
		{
			ll mid = (lo + hi) / 2;

			if(solve(mid,n))
			{
				ans = mid;
				lo = mid + 1;
			}
			else
			{
				hi = mid - 1;
			}
		}

		cout << ans << "\n";
    }


}





