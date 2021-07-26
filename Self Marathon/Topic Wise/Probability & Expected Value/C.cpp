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

double exp_val[100005];

double solve(ll node)
{
	if(exp_val[node] != -1) return exp_val[node];

	ll tot = 0;

	double texp_val = 0;


	for(ll i = 1; i * i <= node; i++)
	{
		if(node % i) continue;

		ll x = i;

		tot++;

		texp_val += solve(x);

		if(i == (node / i)) continue;

		x = node / i;

		if(x == node) continue;

		tot++;

		texp_val += solve(x);
	}

	tot++;

//	if(node == 50) cout << texp_val << " " << tot << endl;

	return exp_val[node] = ((1 + (texp_val / tot)) * tot) / (tot - 1);
}

void precalc()
{
	for(int i = 2; i <= 100000; i++) exp_val[i] = -1;

	exp_val[1] = 0;

	for(int i = 2; i <= 100000; i++)
	{
		solve(i);
	}
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
		slld(n);

		printf("Case %lld: %.10f\n", cs, exp_val[n]);
    }


}


