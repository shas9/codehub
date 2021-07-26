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

void brute(ll st)
{

	for(ll i = 1; i <= 1000; i++)
	{
		cout << st << " ";

		ll mx = 0;
		ll mn = 20;
		ll tmp = st;

		while(tmp)
		{
			mx = max(mx, tmp % 10);
			mn = min(mn, tmp % 10);

			tmp /= 10;
		}

		st += (mn * mx);
	}

	cout << endl;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

//	while(cin >> n)
//	{
//		brute(n);
//	}

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		slld(n);
		slld(k);

		m = -1;

		while(--k)
		{
			if(m == n) break;

			ll mx = 0;
			ll mn = 10;

			ll tmp = n;

			m = n;
			while(tmp)
			{
				mx = max(mx, tmp % 10);
				mn = min(mn, tmp % 10);

				tmp /= 10;
			}

			n += (mx * mn);
		}

		cout << n << "\n";
    }


}


