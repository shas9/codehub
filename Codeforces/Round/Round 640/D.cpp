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

ll arr[1003];

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
		ll a = 0, b = 0;
		ll pa = 0, pb = 0;

		slld(n);

		for(i = 1; i <= n; i++) slld(arr[i]);

		i = 1;
		j = n;

		for(k = 1; k <= n; k++)
		{
			if(k % 2)
			{
				pa = 0;

				while(pa <= pb && i <= j)
				{
					pa += arr[i];
					i++;
				}

				a += pa;
			}
			else
			{
				pb = 0;

				while(pb <= pa && i <= j)
				{
					pb += arr[j];
					j--;
				}

				b += pb;
			}

			if(i > j) break;
		}

		cout << k << " " << a << " " << b << "\n";
     }


}



