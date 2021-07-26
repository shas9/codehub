 // Lights will guide you home

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define pll pair < ll, ll >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define bug(x) printf("BUG %lld\n", x)
#define pb push_back

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

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
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m)
    {
        ll ans1 = 0;
        ll ans2 = 0;

        ll permove = (n / m);

        ans1 = (permove * (permove - 1)) / 2;

        ans1 *= m;

        if(n % m)
        {
            ll extra = n - permove * m;

            ans1 = extra * (permove * (permove + 1)) / 2;
            ans1 += (m - extra) * (permove * (permove - 1)) / 2;
        }

        ans2 = (n - m + 1) * (n - m) / 2;

        cout << ans1 << " " << ans2 << "\n";

    }


}


