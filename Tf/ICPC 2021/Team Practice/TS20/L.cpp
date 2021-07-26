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

vector < vector < pll > > v;

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m)
    {
        ans = 0;

        for(ll i = 0; i < n; i++)
        {
            long double mx1 = 1e10;
            ll mx2 = mxlld;

            for(ll j = 0; j < m; j++)
            {
                ll s, p;
                cin >> s >> p;

                long double pp = (p / (s * 1.0));

                if(abs(mx1 - pp) < 0.000001)
                {
                    mx2 = min(mx2, p);
                }
                else if(mx1 > pp)
                {
                    mx1 = pp;
                    mx2 = p;
                }
            }

            cout << mx1 << " " << mx2 << "\n";

            ans += mx2;
        }

        cout << ans << "\n";

    }


}


