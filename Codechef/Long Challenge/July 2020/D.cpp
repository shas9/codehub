// God put a smile upon your face <3

#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%d", &longvalue)

#define ll int
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

unordered_map < ll, ll > xx, yy;

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
		xx.clear();
		yy.clear();

		xx.reserve(1<<15);
		xx.max_load_factor(0.25);

		yy.reserve(1<<15);
		yy.max_load_factor(0.25);

		slld(n);

		for(ll i = 1; i < (4 * n); i++)
		{
			ll x, y;
			slld(x);
			slld(y);

			xx[x]++;
			yy[y]++;
		}

		ll mark = 1e10;
		ll ax = mark, ay = mark;

		for(auto it: xx)
		{
			if(it.second & 1)
			{
				if(ax != mark) assert(0);
				ax = it.first;
			}
		}

		for(auto it: yy)
		{
			if(it.second & 1)
			{
				if(ay != mark) assert(0);

				ay = it.first;
			}
		}

		printf("%d %d\n", ax, ay);
    }


}



