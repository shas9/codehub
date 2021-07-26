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

    freopen("input.txt", "a", stdout);

    input = 10;

    while(input--)
    {
		vector < ll > v;

		ll n = rand() % 10 + 1;

		v.resize(n + 1);

		for(ll i = 1; i <= n; i++) v[i] = rand() + 1;

		ans = 0;

		for(ll i = 1; i <= n; ++i)
		{
			for(ll j = i + 1; j <= n; j++)
			{
				ans = max(ans, (v[i] + v[j]) * (j - i));
			}
		}

		cout << n << "\n";

		for(ll i = 1; i <= n; ++i) cout << v[i] << " ";

		cout << "\n" << ans << "\n\n";


    }


}



