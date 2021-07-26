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

ll cnt[2000];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
		memset(cnt,0,sizeof cnt);

		for(ll i = 1; i <= n; i++)
		{
			cin >> input;
			ll mask = 0;

			while(input)
			{
				ll x = input % 10;
				input /= 10;

				mask = Set(mask,x);
			}

			cnt[mask]++;
		}

		ans = 0;

		for(ll i = 1; i < (1 << 10); i++)
		{
			for(ll j = i + 1; j < (1 << 10); j++)
			{
				if(i & j) ans += cnt[i] * cnt[j];
			}

			ans += (cnt[i] * (cnt[i] - 1)) / 2;
		}

		cout << ans << "\n";
    }

}


