
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

void brute()
{
	for(ll i = 1; i <= 200; i++)
	{
		for(ll j = 1; j <= 200; j++)
		{
			double s = sqrt(i) + j;

//			cout << s << " ";

			if(abs(s - 127.321336469) < 0.001) cout << i << " " << j << endl;

			s = sqrt(i) + sqrt(j);


			if(abs(s - 127.321336469) < 0.001) cout << i << " " << j << endl;

//			cout << s << " " << i << " " << j << endl;

		}
	}
}
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);
//
//	brute();

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		slld(n);

		double ans = tan(acos(-1.0) / (n * 2));

		ans = (0.5) / ans;

		printf("%.10f\n", ans * 2);
    }


}



