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

void test(ll d, ll k)
{
	d *= d;

	for(ll i = 1; i <= d; i++)
	{
		if(d < i * i * k * k) break;

		ll x = (sqrt(d - i * i * k * k) / k);

		cout << i << " = " << x << " : " << i << " == " << i * i * k * k << " " << x * x * k * k << " ++ " << i + x <<  "\n";
	}
}

bool solve(ll n, ll k)
{
	for(ll i = 1; i <= n + 5; i++)
	{
		ll x = 2 * (i * i * k * k);

		if(x <= n * n) continue;

		if(i * i * k * k + (i - 1) * (i - 1) * k * k > (n * n)) return 1;

		return 0;
	}

	assert(0);
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
		cin >> n >> m;

		if(solve(n,m)) cout << "Utkarsh\n";
		else cout << "Ashish\n";
    }


}




