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

vector < ll > v;

ll fnd(ll val)
{
    ll lo = 0;
    ll hi = v.size() - 1;
    ll ret = -1;

    while(lo <= hi)
    {
        ll mid = (lo + hi) / 2;

        if(v[mid] <= val)
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

    cin >> testcase;

    for(ll cs = 1; cs <= testcase; cs++)
    {
        cin >> n >> l >> r;

        v.resize(n);

        for(auto &it: v) cin >> it;

        sort(v.begin(), v.end());

        ans = 0;

        for(ll i = 0; i < n; i++)
        {
            ll lft = fnd(l - v[i] - 1) + 1;
            ll rgt = fnd(r - v[i]);

            if(lft < i)
            {
                ans += max(0LL, min(rgt, i - 1) - lft + 1);
            }
        }

        cout << ans << "\n";
    }


}

