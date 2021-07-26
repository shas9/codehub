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

map < ll, ll > mp;

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m)
    {
		mp.clear();

		for(ll i = 1; i <= n; i++)
		{
			cin >> l >> r >> q;

			mp[l] += q;
			mp[r + 1] -= q;
		}

		ans = 0;

		ll last = 0, val = 0;

		for(auto it: mp)
		{
			ll dur = (it.first - last);

			ans += dur * min(val,m);

//			cout << dur << " " << ans << "\n";

			last = it.first;
			val += it.second;
		}

		cout << ans << "\n";
    }


}



