 // God put a smile upon your face <3

#include <bits/stdc++.h>

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

using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

string a, b;

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
		cin >> n >> b;

		a = "";
		ll last = -1;

		for(ll i = 0; i < n; i++)
		{
			ll now = b[i] - '0';

			if(now == 0)
			{
				if(last == 1)
				{
					a += '0';
					last = 0;
				}
				else
				{
					a += '1';
					last = 1;
				}
			}
			else
			{
				if(last == 2)
				{
					a += '0';
					last = 1;
				}
				else
				{
					a += '1';
					last = 2;
				}
			}
		}

		cout << a << "\n";
    }


}


