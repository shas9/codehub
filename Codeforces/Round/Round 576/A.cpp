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

ll fnd(ll n, ll k)
{
    ll lo = 0;
    ll hi = 1e10;
    ll ret = 0;

    while(lo <= hi)
    {
        ll mid = (lo + hi) / 2;

        if(mid * n <= k)
        {
            ret = mid;
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }

    return ret;
}

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> k)
    {
        k *= 8;

        ll lim = fnd(n,k);

        vector < ll > v(n);

        for(auto &it: v) cin >> it;

        if(lim >= 20) cout << 0 << "\n";
        else
        {
            lim = 1 << lim;

            map < ll, ll > mp;

            for(auto it: v)
            {
                mp[it]++;
            }

            v.clear();

            ll tot = 0;

            ans = n;

            for(auto it: mp)
            {
                tot += it.second;
                v.push_back(tot);

                if(v.size() <= lim)
                {
                    ans = min(ans, n - tot);
                }
                else
                {
                    ans = min(ans, n - (tot - v[v.size() - lim - 1]));
                }
            }

            cout << ans << "\n";
        }
    }


}
