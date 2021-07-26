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

ll fndbit(ll x)
{
	for(ll i = 40; i >= 0; i--)
	{
		if(check(x,i)) return i;
	}

	assert(0);
}

ll solve(ll n)
{
	for(ll i = 2; i < n; i++)
	{
		if(fndbit(arr[i - 1]) == fndbit(arr[i]) && fndbit(arr[i]) == fndbit(arr[i + 1])) return 1;
	}

	ll ans = mxlld;

	for(ll i = 1; i <= n; i++)
	{
		ll cx = 0;

		for(ll j = i; j <= n; j++)
		{
			cx ^= arr[j];

			ll cx2 = 0;

			for(ll k = j + 1; k <= n; k++)
			{
				cx2 ^= arr[k];

//				cout << i << " " << j << " " << k << " " << cx << " " << cx2 << endl;

				if(cx > cx2)
				{
					ll cnt = (k - j - 1) + (j - i);
					ans = min(ans, cnt);
				}
			}
		}
	}

	if(ans == mxlld) ans = -1;

	return ans;
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

		for(ll i = 1; i <= n; i++) slld(arr[i]);

		ans = solve(n);

		cout << ans << "\n";
    }


}


