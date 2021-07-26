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

ll lft[200005];
ll rgt[200005];

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

        for(ll i = 1; i <= n; i++) lft[i] = rgt[i] = 0;

        for(ll i = 1; i <= l; i++)
        {
            cin >> in;
            lft[in]++;
        }

        for(ll i = 1; i <= r; i++)
        {
            cin >> in;
            rgt[in]++;
        }

        ans = abs(r - l) / 2;

        if(l < r)
        {
            for(ll i = 1; i <= n && l < r; i++)
            {
                ll cantake = min(rgt[i], (lft[i] + rgt[i]) / 2 - (lft[i]));
                cantake = max(cantake, 0LL);

                ll diff = (r - l) / 2;

//                cout << i << " " << cantake << " " << diff << "\n";

                lft[i] += min(cantake, diff);
                rgt[i] -= min(cantake, diff);

                l += min(cantake, diff);
                r -= min(cantake, diff);
            }

            assert(r >= l);

            for(ll i = 1; i <= n; i++)
            {
                while(l < r && rgt[i] > lft[i])
                {
                    lft[i]++;
                    rgt[i]--;
                    r--;
                    l++;
                }
            }

            assert(l == r);
        }
        else
        {
            for(ll i = 1; i <= n && l > r; i++)
            {
                ll cantake = min(lft[i], (lft[i] + rgt[i]) / 2 - rgt[i]);
                cantake = max(cantake, 0LL);

                ll diff = (l - r) / 2;

                rgt[i] += min(cantake, diff);
                lft[i] -= min(cantake, diff);

                l -= min(cantake, diff);
                r += min(cantake, diff);
            }

            assert(r <= l);

            for(ll i = 1; i <= n; i++)
            {
                while(l > r && lft[i] > rgt[i])
                {
                    lft[i]--;
                    rgt[i]++;
                    r++;
                    l--;
                }
            }

            assert(l == r);
        }


        for(ll i = 1; i <= n; i++)
        {
//            cout << i << " : " << lft[i] << " " << rgt[i] << "\n";
            ll mn = min(lft[i], rgt[i]);

            lft[i] -= mn;
            rgt[i] -= mn;

            ans += lft[i];
        }

        cout << ans << "\n";
    }


}

