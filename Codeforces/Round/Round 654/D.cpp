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

ll mat[305][305];

void calc(ll n)
{
	ll mxr = 0;
	ll mnr = mxlld;
	ll mxc = 0;
	ll mnc = mxlld;

	for(ll i = 1; i <= n; i++)
	{
		ll cnt = 0;

		for(ll j = 1; j <= n; j++)
		{
			cnt += mat[i][j];
		}

		mxr= max(mxr,cnt);
		mnr = min(mnr,cnt);
	}

	for(ll i = 1; i <= n; i++)
	{
		ll cnt = 0;

		for(ll j = 1; j <= n; j++)
		{
			cnt += mat[j][i];
		}

		mxc = max(mxc,cnt);
		mnc = min(mnc,cnt);
	}

	cout << (mxr - mnr) * (mxr - mnr) + (mxc - mnc) * (mxc - mnc) << '\n';
}
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
		slld(n);
		slld(m);

		ll perrow = (m / n);
		ll extra = (m % n);

		ll st = 1;
		ll en = n;

		memset(mat,0,sizeof mat);

//		cout << perrow << " " << extra << endl;

		for(ll i = 1; i <= n; i++)
		{
			ll need = (perrow + (extra > 0));

			extra--;

			st = i;
			if(i > 1) en = i - 1;
			else en = n;

			while(need)
			{
				if(need >= 2) mat[i][st] = mat[i][en] = 1, need -= 2;
				else mat[i][st] = 1, need--;

				st++, en--;

				if(en <= 0) en = n;
				if(st > n) st = 1;
			}

		}

		calc(n);

		for(i = 1; i <= n; i++)
		{
			for(j = 1; j <= n; j++) cout << mat[i][j];

			cout << '\n';
		}
    }


}



