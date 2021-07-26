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

ll fib[55];

void precalc()
{
	fib[1] = fib[2] = 1;

	for(ll i = 3; i <= 50; i++)
	{
		fib[i] = fib[i - 1] + fib[i - 2];

//		cout << fib[i] << " ";
	}
}

string solve(ll n)
{
	string str = "";

	for(int i = 50; i >= 2; i--)
	{
		if(n >= fib[i]) str += '1', n -= fib[i];
		else if(str.size()) str += '0';
	}

	return str;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

	precalc();

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		slld(input);

		cout << "Case " << cs << ": " << solve(input) << '\n';
    }


}



