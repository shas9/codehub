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
        double lo = 0;
        double hi = 1e9;
        double ans = 1e10;

        vector < pair < double, double > > v;

        v.resize(n);

        for(auto &it: v) cin >> it.first >> it.second;

        ll cnt = 100;

        while(cnt--)
        {
            double mid = (lo + hi) / 2;

            double killed = 0;

            for(auto it: v)
            {
                if(it.second < mid) killed += 1;
                else if(it.first > mid);
                else
                {
                    killed += (mid - it.first) / (it.second - it.first);
                }
            }

//            cout << killed << " " << mid << "\n";

            if(killed < m)
            {
                lo = mid;
            }
            else
            {
                ans = mid;
                hi = mid;
            }
        }

        cout << setprecision(10) << fixed << ans << "\n";
    }


}

