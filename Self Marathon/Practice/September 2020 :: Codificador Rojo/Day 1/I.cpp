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

ll segment[200005];
ll arr[200005];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

	fastio;

    while(cin >> n >> k)
    {
		for(ll i = 1; i <= n; i++) cin >> arr[i];

		memset(segment,0,sizeof segment);

		for(ll j = n; j >= 1; j--)
		{
			if(arr[j] == 1)
			{
				segment[j] = segment[j + 1] + 1;
			}
		}

		ans = 0;

		for(ll i = 1; i <= n; i++)
		{
			__int128 gun = 1;
			ll sum = 0;
			ll logg = 0;

			for(ll j = i; j <= n; j++)
			{

				logg++;

				assert(logg <= 200);
				if(gun > (1e13)) break;

				if(arr[j] == 1)
				{
					if(gun % k == 0)
					{
						ll need = (gun / k) - sum;

						if(need > 0 && need <= segment[j])
						{
							ans++;
						}
					}

					sum += segment[j];
					j += segment[j] - 1;
				}
				else
				{
					sum += arr[j];
					gun *= arr[j];

					if(gun == (sum * k)) ans++;
				}
			}
		}

		cout << ans << endl;
    }


}



