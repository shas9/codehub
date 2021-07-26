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

ll arr[1000];
ll out[1000];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    ll d, s;

    while(cin >> n >> m >> s >> d)
    {
		for(i = 1; i <= s; i++) slld(arr[i]), out[i] = arr[i];

		while(n)
		{
			ll mn = mxlld;
			ll mnpos = 0;

			for(i = 1; i <= s; i++)
			{
				if(out[i] < mn)
				{
					mn = out[i];
					mnpos = i;
				}
			}

			if(mn == d) break;

			ll x = min(d - out[mnpos], n);
			out[mnpos] += x;
			n -= x;
		}


		ll tot = 0;

		for(i = 1; i <= s; i++)
		{
			if(out[i] == arr[i]) tot += arr[i];
		}

		if(n || tot < m) printf("Impossible\n");
		else
		{
			for(i = 1; i <= s; i++)
			{
				printf("%lld ", out[i] - arr[i]);
			}

			printf("\n");
		}
    }


}



