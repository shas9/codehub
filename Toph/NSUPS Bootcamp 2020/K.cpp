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

string str;

bool solve(ll n, ll m)
{
	ll adjn = 0, adjm = 0;

		for(ll i = 1; i < str.size(); i++)
		{
			if(str[i] == str[i - 1])
			{
				if(str[i] == 'W') adjn++;
				else adjm++;
			}
		}

	if(m < adjn) return 0;
	if(n < adjm) return 0;

	m -= adjn;
	n -= adjm;

	if(n == 0 && m == 0) return 1;

	if(str.front() == str.back())
	{
		if(str.front() == 'W') m--;
		else n--;
	}

	if(m < 0 || n < 0) return 0;

//	bug;

	if(abs(n - m) > 1) return 0;

	return 1;
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
		slld(tag);
		cin >> str >> n >> m;


		if(solve(n,m)) printf("YES\n");
		else printf("NO\n");
    }


}



