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

vector < ll > vec;

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
		cin >> n;
		vec.resize(n);

		for(auto &it: vec) cin >> it;

		ll ans = 0;
		ll lim = (n / 3);

		ll c0 = 0, c1 = 0, c2 = 0;

		for(auto it: vec)
		{
			if(it % 3 == 0) c0++;
			else if(it % 3 == 1) c1++;
			else c2++;
		}

//				cout << c0 << " " << c1 << " " << c2 << endl;
		if(max(c0,max(c1,c2)) == c1)
		{
			swap(c0,c1);
			swap(c1,c2);
		}
		else if(max(c0,max(c1,c2)) == c2)
		{
			swap(c0,c2);
			swap(c2,c1);
		}

//		cout << c0 << " " << c1 << " " << c2 << endl;


		ans = abs(lim - c0);

		c1 += abs(lim - c0);

		if(c1 > lim) ans += c1 - lim;
		else ans += (2 * (lim - c1));

		cout << ans << "\n";
    }


}



