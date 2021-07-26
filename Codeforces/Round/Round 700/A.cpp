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
	ll y;

	cout << "? " << x << endl;
	cin >> y;

	if(y == 1)
	{
		cout << "! " << x << endl;
		exit(0);
	}

	return y;
}

ll n;

ll solve(ll b, ll e, ll v1, ll v2)
{
	if(b == e) return b;

	ll mid = (b + e) / 2;

	ll in;

	if(v1 == -1) v1 = ask(b);
	if(v2 == -1) v2 = ask(e);

	in = ask(mid);

	ll vv1 = mxlld;
	ll vv2 = in;
	ll vv3 = mxlld;

	if(mid > 1) vv1 = ask(mid - 1);
	if(mid < n) vv3 = ask(mid + 1);

	if(vv2 < min(vv1, vv3)) return mid;


	if(v1 < in && b != mid) return solve(b,mid - 1, v1, vv1);
	if(v2 < in) return solve(mid + 1,e,vv3, v2);

	ll lft = (v1 - in + 1);
	ll rgt = (v2 - in + 1);

	ll lftsz = (mid - b + 1);
	ll rgtsz = (e - mid + 1);

	if(lftsz != lft && b != mid) return solve(b,mid,v1,vv1);
	if(rgtsz != rgt) return solve(mid + 1,e,vv3,v2);

	if(vv1 < vv3 && b != mid) return solve(b,mid - 1,v1, vv1);

	return solve(mid + 1, e, vv3, v2);
}

void valid(ll ans, ll n)
{
	ll v1 = mxlld;
	ll v2 = 0;
	ll v3 = mxlld;

	if(ans > 1) v1 = ask(ans - 1);
	if(ans < n) v3 = ask(ans + 1);
	v2 = ask(ans);

	assert((v2 < min(v1, v3)));

	return;
}

int main()
{
    ll i, j, k, l, m, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
		ll lo = 1;
		ll hi = n;

		ans = -1;

		ans = solve(1, n, -1, -1);

		valid(ans,n);

		cout << "! " << ans << endl;

		exit(0);
    }

}


