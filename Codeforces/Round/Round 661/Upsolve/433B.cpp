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

    while(cin >> n)
    {
        vector < ll > v(n), u;

        for(auto &it: v) cin >> it;

        u = v;

        sort(u.begin(), u.end());

        for(ll i = 1; i < n; i++) v[i] += v[i - 1];
        for(ll i = 1; i < n; i++) u[i] += u[i - 1];

        cin >> m;

        for(ll i = 1; i <= m; i++)
        {
            ll t;

            cin >> t >> l >> r;

            if(t == 1)
            {
                ans = v[r - 1];
                if(l >= 2) ans -= v[l - 2];
            }
            else
            {
                ans = u[r - 1];
                if(l >= 2) ans -= u[l - 2];
            }

            cout << ans << "\n";
        }
    }


}

