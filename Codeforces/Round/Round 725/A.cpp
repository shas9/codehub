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
        vector < ll > v(n);

        for(auto &it: v) cin >> it;

        ll mn = mxlld, mnpos = -1;
        ll mx = mnlld, mxpos = -1;

        for(ll i = 0; i < n; i++)
        {
            mn = min(mn, v[i]);
            mx = max(mx, v[i]);

            if(mn == v[i]) mnpos = i;
            if(mx == v[i]) mxpos = i;
        }

        if(mnpos > mxpos) swap(mnpos, mxpos);

        ans = mnpos + 1 + (n - mxpos);
        ans = min(ans, mxpos + 1);
        ans = min(ans, n - mnpos);

        cout << ans << "\n";
    }


}

