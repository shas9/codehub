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

vector < ll > vec;

bool solve(ll n, ll m)
{
	vec.clear();

	if(n % 2)
	{
		if(m % 2 == 0) return 0;

		if(n < m) return 0;

		for(ll i = 1; i < m; i++) vec.push_back(1);

		vec.push_back(n - (m - 1));
	}
	else
	{

		if(n < m) return 0;

		if(m % 2 == 0)
		{
			for(ll i = 1; i < m; i++) vec.push_back(1);

			vec.push_back(n - (m - 1));
		}
		else
		{
			if(n < m * 2) return 0;

			for(ll i = 1; i < m; i++) vec.push_back(2);

			vec.push_back(n - ((m - 1) * 2));
		}

	}

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
		slld(n);
		slld(m);

		if(solve(n,m) == 0) printf("NO\n");
		else
		{
			printf("YES\n");
			for(auto it: vec) cout << it << " ";

			cout << "\n";
		}
    }


}



