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

bool solve()
{
	ll n, u, d, r, l;

	cin >> n >> u >> r >> d >> l;

	bool on = 1;

	if(r == n && l == n) on &= (u >= 2 && d >= 2);
	if(u == n && d == n) on &= (l >= 2 && r >= 2);
	if(r == n && u == n) on &= (l && d);
	if(r == n && d == n) on &= (l && u);
	if(l == n && u == n) on &= (r && d);
	if(l == n && d == n) on &= (r && u);

	if(r == n || l == n) on &= (u && d);
	if(u == n || d == n) on &= (l && r);

	if(r == n && l == (n - 1)) on &= (u && d && (u + d >= 3));
	if(u == n && d == (n - 1)) on &= (l && r && (r + l >= 3));

	if(l == n && r == (n - 1)) on &= (u && d && (u + d >= 3));
	if(d == n && u == (n - 1)) on &= (l && r && (r + l >= 3));

	n--;

	if(r == n && l == n) on &= (u + d >= 2);
	if(u == n && d == n) on &= (l + r >= 2);

	if(r == n || l == n) on &= (u || d);
	if(u == n || d == n) on &= (l || r);

	return on;


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
		if(solve()) cout << "Yes\n";
		else cout << "No\n";
    }


}



