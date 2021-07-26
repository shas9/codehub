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

    while(cin >> n)
    {
        vector < ll > v(n);

        for(auto &it: v) cin >> it;

        sort(v.begin(), v.end());

        ll ans = 1;
        ll mod = 1e9 + 7;

        for(ll i = 0; i < n; i++)
        {
            ans = (ans * (v[i] - i)) % mod;

            if(ans < 0) ans = 0;
        }

        cout << ans << "\n";
    }


}


