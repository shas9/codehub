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

using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

bool mask[(1 << 20)];
ll dp[(1 << 20)];

string str;

ll cnt(ll x)
{
	ll ret = 0;

	for(ll j = 0; j < 20; j++) ret += check(x,j);

	return ret;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> str)
    {
		memset(mask,0,sizeof mask);

		for(ll i = 0; i < str.size(); i++)
		{
			ll nmask = 0;

			for(ll j = i; j < min((int)str.size(), (int)i + 19); j++)
			{
				ll d = str[j] - 'a';

				if(check(nmask,d)) break;

				nmask = Set(nmask,d);

				mask[nmask] = 1;
			}

//			cout << nmask << " " << cnt(nmask) << endl;

		}

		memset(dp,0,sizeof dp);

//		mask[0] = 1;


		for(ll i = (1 << 20) - 1; i >= 0; i--)
		{
			ll offbit = ((1 << 20) - 1) ^ i;

//			if(mask[i] == 0) continue;

			for(ll j = 0; j < 20; j++)
			{
				if(check(i,j) == 0)
				{
					dp[i] = max(dp[i], dp[i ^ (1 << j)]);
				}
			}

			if(mask[offbit]) dp[i] = max(dp[i],cnt(offbit));
		}

		ll mx = 0;

		for(ll i = 0; i < (1 << 20); i++)
		{
			if(mask[i]) mx = max(mx, dp[i] + cnt(i));

//			if(mx == 20)
//			{
//				cout << mx << " " << i << " " << dp[i] << " " << cnt(i) <<endl;
//			}
		}

		printf("%lld\n",mx);

    }


}


