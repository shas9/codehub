// Lights will guide you home

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define bug(x) printf("BUG %lld\n")
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

vector < ll > a, b;

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
        cin >> n >> m;
        a.resize(n);
        b.resize(n - 1);

        for(auto &it: a) cin >> it;
        for(auto &it: b) cin >> it;

        ll days = 0;
        ll now = 0;
        ans = mxlld;

        for(ll i = 0; i < n; i++)
        {
            ll baki = (m - now);

            if(baki <= 0)
            {
                ans = min(ans, days);
            }
            else
            {
                ll needhere = (baki / a[i]);

                if(baki % a[i]) needhere++;

                ans = min(ans, days + needhere);
            }

            if(i + 1 < n)
            {
                ll promotion = (b[i] - now);

                if(promotion <= 0)
                {
                    days++;
                    now -= b[i];
                    continue;
                }

                ll needtop = promotion / a[i];
                if(promotion % a[i]) needtop++;

                now = now + (needtop * a[i]) - b[i];
                days += needtop + 1;
            }
        }

        cout << ans << "\n";
    }


}

