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

long double csum[505];

long double solve(ll n, ll m)
{
    long double ans = 0;

    for(ll i = 1; i <= n; ++i)
    {
        csum[i] = 0;
        long double diff = ((pi * i * 1.0) / m);

        for(ll j = 1; j < m; j++)
        {
            ans += min(j * diff, 2.0 * (long double)i) * 2 * m;

//				cout << i << " = " << ans << " " << 12 + 2 * pi << " " << diff << " " << dist << " --> " << (24 + 4 * pi) / 3 <<"\n";
        }

        for(ll j = 1; j < m; j++)
        {
            csum[i] += min(j * diff, 2.0 * (long double)i) * 2;

//				cout << i << " = " << ans << " " << 12 + 2 * pi << " " << diff << " " << dist << " --> " << (24 + 4 * pi) / 3 <<"\n";
        }

//        cout << i << " : " << ans << endl;

//			cout << csum[i] << "\n";

        ll x = i * 2;

        ans += ((x * (x + 1)) / 2) * m;

        x--;
        ans += ((x * (x + 1)) / 2) * m;

        for(ll j = 1; j < i; j++)
        {
            ans += 2 * m * (csum[j] + (i - j) * (2 * (m - 1)));
        }


//        cout << i << " : " << ans << endl;
    }

    return ans;

}

long double solve1(ll n, ll m)
{
	long double ret = 0;

	for(ll i = 1; i <= n; i++)
	{
		ll x = (i * 2);

		ret += (x * (x + 1)) / 2;

		x--;

		ret += (x * (x + 1)) / 2;

		ret -= (2 * i);
	}

	return ret;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m)
    {
        long double ans = 0;

        if(m == 1) ans = solve1(n,m);
        else ans = solve(n,m);


        cout << setprecision(10) << fixed << ans << "\n";
    }


}



