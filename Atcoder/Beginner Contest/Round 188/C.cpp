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

vector < ll > v1;

pll solve(ll l, ll r)
{
	if(r - l == 1) return {l,r};

	ll mid = (l + r) / 2;

	pll lft = solve(l,mid);
	pll rgt = solve(mid + 1, r);

	ll x, y;

	if(v1[lft.first] < v1[lft.second]) x = lft.second;
	else x = lft.first;

	if(v1[rgt.first] < v1[rgt.second]) y = rgt.second;
	else y = rgt.first;

//	cout << l << " " << r << " " << x << " " << y << endl;

	return {x,y};
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
		n = (1LL << n);
		v1.resize(n);

		for(auto &it: v1) cin >> it;

		pll ans = solve(0,n-1);

		if(v1[ans.first] < v1[ans.second]) cout << ans.first + 1<< "\n";
		else cout << ans.second + 1 << "\n";
    }


}



