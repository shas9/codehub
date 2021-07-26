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

ll brute(ll a, ll b, ll c, ll d)
{
	ll ret = 0;

	for(ll i = a; i <= b; i++)
	{
		for(ll j = b; j <= c; j++)
		{
			for(ll k = c; k <= d; k++)
			{
				if(i + j > k)
				{
					cout << i << " " << j << " ~~ " << k << endl;
					ret++;
				}
			}
		}
	}

	return ret;
}
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    ll a, b, c, d;

    while(cin >> a >> b >> c >> d)
    {
		ans = 0;

		cout << brute(a,b,c,d) << endl;

		for(i = b; i <= c; i++)
		{
			ll bam = b - (c - i);
			ll dan = d - c + 1;

			if(bam <= dan)
			{
				ans += (bam * (bam + 1)) / 2;
				ll biyog = (a - 1);

				ans -= (biyog * (biyog + 1)) / 2;
			}
			else if(bam > dan)
			{
				ll extra = bam - dan;

				ans += (dan * (dan + 1)) / 2;
				ans += (extra * dan);


			}
		}



		cout << ans << "\n";
    }


}



