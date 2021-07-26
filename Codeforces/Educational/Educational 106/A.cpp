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
        ll k1, k2, w, b;
        cin >> n >> k1 >> k2 >> w >> b;

        ll wcell = min(k1, k2);
        ll bcell = n - max(k1, k2);

        w -= wcell;
        b -= bcell;

        bool on = 1;

        if(w > 0)
        {
            ll space = max(k1, k2) - min(k1, k2);

            if(space < w * 2) on = 0;
        }

        if(b > 0)
        {
            ll space = max(k1, k2) - min(k1, k2);

            if(space < b * 2) on = 0;
        }

        if(on) cout << "YES\n";
        else cout << "NO\n";
    }


}

