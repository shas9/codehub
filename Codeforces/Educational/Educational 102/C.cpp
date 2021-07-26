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

		ll cnt = 0;

		cin >> n >> k;

		m = k;

		ll diff = (n - k);

		ll lim = (k - diff - 1);

		for(ll i = 1; i <= lim; i++)
		{
			cout << i << " ";

			cnt++;
		}

		for(ll i = lim + 2; i <= k; i += 2) cout << i << " ", cnt++;

		if((lim + k) % 2 == 0) k--;

		for(ll i = k; i > lim; i -= 2)
		{
			cout << i << " ";

			cnt++;
		}

		assert(cnt == m);

		cout << "\n";
    }


}


