// God put a smile upon your face <3

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll int
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

ll conv(string &s)
{
	ll ret = 0;

	for(ll i = 0; i < s.size(); i++)
	{
		if(s[i] == '1') ret = Set(ret, i);
	}

	return ret;
}

ll arr[20];
ll cost[1 << 13];
ll val[1 << 13][101];
ll freq[1 << 13];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

	fastio;

    while(cin >> n >> m >> q)
    {
		memset(cost,0,sizeof cost);
		memset(val,0,sizeof val);
		memset(freq,0,sizeof freq);

		for(ll i = 0; i < n; i++) cin >> arr[i];

		for(ll mask = 0; mask < (1 << n); mask++)
		{
			for(ll j = 0; j < n; j++)
			{
				if(check(mask, j))
				{
					cost[mask] += arr[j];
				}
			}
		}

		for(ll i = 0; i < m; i++)
		{
			string str;

			cin >> str;

			ll num = conv(str);

			freq[num]++;
		}

		ll mx = (1 << n) - 1;

		for(ll mask1 = 0; mask1 < (1 << n); mask1++)
		{
			for(ll mask2 = 0; mask2 < (1 << n); mask2++)
			{
				ll xxor = (~(mask1 ^ mask2)) & mx;

//				cout << xxor << ": " << cost[xxor] << " " << freq[mask2] << endl;

				if(cost[xxor] <= 100) val[mask1][cost[xxor]] += freq[mask2];
			}

			for(ll i = 1; i <= 100; i++) val[mask1][i] += val[mask1][i - 1];

//			cout << mask1 << ": ";
//			for(ll i = 0; i < 70; i++) cout << val[mask1][i] << " ";
//
//			cout << endl;
		}

		for(ll i = 0; i < q; i++)
		{
			string str;
			cin >> str >> k;

			ll num = conv(str);

			cout << val[num][k] << "\n";
		}

    }


}


