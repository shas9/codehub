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

bool solve(ll n, ll m)
{
	if(n >= m) return 1;

	if(n == 2 && m == 3) return 1;

	if(n == 2) return 0;

	if(n == 1) return  0;

	if(n == 3) return 0;

	return 1;
}

void test()
{
	for(ll i = 1; i <= 100; i++)
	{
		ll temp = i;

		for(ll j = 1; j <= 100; j++)
		{
			if(temp % 2) temp--;
			else temp += (temp / 2);
		}

		cout << i << ": " << temp << endl;
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
		cin >> n >> m;

		if(solve(n,m)) printf("Yes\n");
		else printf("No\n");
    }


}


