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

ll ask(ll x)
{
	cout << "? " << x << endl;
	cin >> x;

	return x;
}

ll n;

ll solve(ll b, ll e)
{
	if(b == e) return b;

	ll lft = mxlld;
	ll rgt = mxlld;
	ll mid = (b + e) / 2;
	ll val = ask(mid);

	if(mid > 1) lft = ask(mid - 1);
	if(mid < n) rgt = ask(mid + 1);

	if(val < min(lft,rgt)) return mid;

	if(val > rgt) return solve(mid + 1, e);

	return solve(b, mid);
}

int main()
{
    ll i, j, k, l, m, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    cin >> n;

    ans = solve(1,n);

    cout << "! " << ans << endl;

}


