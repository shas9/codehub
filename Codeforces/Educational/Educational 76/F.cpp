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

map < vector < ll >, ll > vec;

ll arr[103];
ll lft[103];
ll rgt[103];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
		vec.clear();

		for(i = 1; i <= n; i++)
		{
			slld(arr[i]);

			lft[i] = arr[i] >> 15;
			rgt[i] = arr[i] & ((1 << 15) - 1);
		}

		for(i = 0; i < (1 << 15); i++)
		{
			ll prv = 0;
			vector < ll > v;

			for(j = 1; j <= n; j++)
			{
				ll x = lft[j] ^ i;
				ll o = __builtin_popcount(x);

				if(j != 1) v.push_back(prv - o);
				prv = o;
			}

			vec[v] = i;
		}

		ll ans = -1;

		for(i = 0; i < (1 << 15); i++)
		{
			ll prv = 0;
			vector < ll > v;

			for(j = 1; j <= n; j++)
			{
				ll x = rgt[j] ^ i;
				ll o = __builtin_popcount(x);

				if(j != 1) v.push_back(o - prv);
				prv = o;
			}

//			if(i == 1)
//			{
//				for(auto it: v) cout << it << " ";
//				cout << endl;
//			}

			if(vec.find(v) != vec.end())
			{
//				cout << vec[v] << " " << i << endl;
//				for(auto it: v) cout << it << " ";
//				cout << endl;

				ans = (vec[v] << 15) + i;
				break;
			}
		}

		printf("%lld\n", ans);

//		if(ans != -1)
//		{
//			for(i = 1; i <= n; i++)
//			{
//				ll y = arr[i] ^ ans;
//
//				cout << __builtin_popcount(y) << " ";
//			}
//
//			cout << endl;
//		}

    }


}


