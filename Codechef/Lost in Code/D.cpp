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

ll cntx[1000006];
ll cnty[1000006];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
		memset(cntx, 0, sizeof cntx);
		memset(cnty, 0, sizeof cnty);

		for(i = 1; i <= n; i++)
		{
			ll mnx = 1e10;
			ll mny = 1e10;
			ll mxx = 0;
			ll mxy = 0;

			for(j = 1; j <= 3; j++)
			{
				ll x, y;
				slld(x);
				slld(y);

//				cout << x << "  && " << y << endl;

				mnx = min(mnx,x);
				mxx = max(mxx,x);
				mny = min(mny,y);
				mxy = max(mxy,y);
			}

			assert(mnx < mxx);
			assert(mny < mxy);

			cntx[mnx + 1]++;
			cntx[mxx]--;

			cnty[mny + 1]++;
			cnty[mxy]--;
//
//			cout << mnx << " - " << mxx << endl;
//			cout << mny << " + " << mxy << endl;
		}

		for(i = 1; i <= 1000000; i++)
		{
			cntx[i] += cntx[i - 1];
			cnty[i] += cnty[i - 1];
		}

		slld(m);

		for(i = 1; i <= m; i++)
		{
			string a, b;

			cin >> a >> b >> input;

			if(a == "x")
			{
				ans = cntx[input];
//				if(input) ans -= cntx[input - 1];
			}
			else
			{
				ans = cnty[input];
//				if(input) ans -= cnty[input - 1];
			}


			printf("%lld\n", ans);
		}

    }


}



