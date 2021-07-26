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

    cin >> testcase;

    for(ll cs = 1; cs <= testcase; cs++)
    {
        ll x, y;
        ll a, b;

        cin >> x >> y;
        cin >> a >> b;

        if(x > y) swap(x, y);
        if(a > b) swap(a, b);

        ll lo = 0;
        ll hi = 1e9;
        ll mov = 0;

        while(lo <= hi)
        {
            ll mid = (lo + hi) / 2;

            ll cnta = x - (mid * a);
            ll cntb = y - (mid * b);

            if(cnta < 0 || cnta < 0)
            {
                hi = mid - 1;
            }
            else if(cnta <= cntb)
            {
                lo = mid + 1;
                mov = mid;
            }
            else
            {
                hi = mid - 1;
            }
        }

        ll c = a + b;

//        cout << mov << "\n";

        ans = mov + 2 * min((x - (mov * a)) / c, (y - (mov * b)) / c);
        mov++;
//         ans = max(ans, mov + 2 * min((x - (mov * a)) / c, (y - (mov * b)) / c));

        cout << ans << "\n";

    }


}

