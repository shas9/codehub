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

void test()
{
	ll mat[21][21];

	memset(mat,0,sizeof mat);

	ll cnt = 0;

	for(ll i = 1; i <= 20; i++)
	{
		ll x = 1;
		ll y = i;

		while(y >= 1 && x <= 20)
		{
			mat[x][y] = ++cnt;
			x++;
			y--;
		}
	}

//	cout << cnt << endl;
//
	for(ll i = 1; i <= 10; i++)
	{
		for(ll j = 1; j <= 10; j++) cout << mat[i][j] << "\t";
		cout << endl;
	}
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

//	test();

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		ll x1, x2, y1, y2;

		cin >> x1>> y1 >> x2 >> y2;

		ans = (x2 - x1) * (y2 - y1) + 1;

		cout << ans << "\n";
    }


}



