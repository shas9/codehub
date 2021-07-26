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

        v.assign(n + 2, 0);

        for(ll i = 1; i <= n; i++) cin >> v[i];

        ans = 0;

        for(ll i = 1; i <= n; i++)
        {
            ll mx = max(v[i - 1], v[i + 1]);

            if(v[i] > mx)
            {
                ans += v[i] - mx;
                v[i] = mx;
            }
        }

        for(ll i = 1; i <= n; i++)
        {
            if(v[i - 1] == v[i + 1] && v[i] == v[i - 1]) continue;

            if(v[i] > v[i - 1]) ans += v[i] - v[i - 1];

            if(v[i] > v[i + 1]) ans += v[i] - v[i + 1];
        }

        cout << ans << "\n";
    }


}

