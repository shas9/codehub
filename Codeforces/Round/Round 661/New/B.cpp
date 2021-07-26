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
        cin >> n;

        vector < ll > a(n), b(n);

        ll mna = mxlld, mnb = mxlld;

        for(auto &it: a) cin >> it, mna = min(mna, it);
        for(auto &it: b) cin >> it, mnb = min(mnb, it);

        ans = 0;

        for(ll i = 0; i < n; i++)
        {
            ll exa = a[i] - mna;
            ll exb = b[i] - mnb;

            ll mn = min(exa, exb);

            ans += mn;

            exa -= mn;
            exb -= mn;

            ans += exa + exb;
        }

        cout << ans << "\n";
    }


}


