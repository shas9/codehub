// Lights will guide you home

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define bug(x) printf("BUG %lld\n", x
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

        bool on = 0;

        for(auto &it: v) cin >> it;

        for(ll i = 0; i < n; i++)
        {
            ll sq = sqrt(v[i]);

            if(sq * sq != v[i]) on = 1;

            for(ll j = 0; j < n; j++)
            {
                if(i == j) continue;

                ll gun = v[i] * v[j];
                ll sq = sqrt(gun);

                if(sq * sq != gun) on = 1;

                for(ll k = 0; k < n; k++)
                {
                    if(k == i || k == j) continue;

                    ll egun = gun * v[k];
                    ll sq = sqrt(egun);

                    if(sq * sq != egun) on = 1;

                }
            }
        }

        if(on) cout << "YES\n";
        else cout << "NO\n";
    }


}


