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

    while(cin >> n >> m >> k)
    {
        vector < ll > v(n);

        for(auto &it: v) cin >> it;

        ans = -1;

        for(ll i = 0; i < n; i++)
        {
            bool on = 1;

            for(ll j = i - 1; j >= max(0LL, (i - m)); j--)
            {
                if(v[i] > v[j]) on = 0;
            }

            for(ll j = i + 1; j <= min(n - 1, (i + k)); j++)
            {
                if(v[i] > v[j]) on = 0;
            }

            if(on)
            {
                ans = i + 1;
                break;
            }
        }

        assert(ans != -1);

        cout << ans << "\n";

    }


}

