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

ll arr[500005];
ll cdays[500005];
ll cmons[500005];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m)
    {
		for(i = 1; i <= n; i++)
		{
			slld(arr[i]);
			arr[i + n] = arr[i];
		}

		n *= 2;

		for(i = 1; i <= n; i++)
		{
			cmons[i] = cmons[i - 1] + arr[i];
			cdays[i] = cdays[i - 1] + ((arr[i] * (arr[i] + 1)) / 2);
		}

		ans = 0;

		for(i = 1; i <= n; i++)
		{
			if(cmons[i] < m) continue;

			ll lft = cmons[i] - m;

			ll mons = upper_bound(cmons + 1, cmons + 1 + n, lft) - (cmons);

//			cout << lft << " " << mons << " " << i << endl;

			ll cnt = (cdays[i] - cdays[mons - 1]);

			ll x = (cmons[i] - cmons[mons - 1]) - m;

			cnt -= (x * (x + 1) / 2);

//			cout << cnt << endl;
			ans = max(ans,cnt);
		}

		printf("%lld\n", ans);
    }


}


