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

ll pw5[5003];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    for(i = 0; i <= 5000; i++)
    {
		pw5[i] = 1;

		for(j = 1; j <= 5; j++)
		{
			pw5[i] *= i;
		}
    }

    ll x, y, a, b;

    while(cin >> x)
    {
		a = b = -1;


		for(i = 0; i <= 5000; i++)
		{
			for(j = 0; j <= i; j++)
			{
				y = pw5[i];

				if(y >= x)
				{
					y -= pw5[j];

					b = j;
				}
				else y += pw5[j], b = -j;

				if(y == x)
				{
					a = i;
					break;
				}
			}

			if(a != -1) break;
		}

		printf("%lld %lld\n", a, b);
    }

}



