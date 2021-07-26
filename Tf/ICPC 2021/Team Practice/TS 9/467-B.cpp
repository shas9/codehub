 // Lights will guide you home

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb push_back

#define bug printf("BUG\n")

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
        vector < ll > vec(m + 1);

        for(auto &it: vec) cin >> it;

        ll ans = 0;
        for(ll i = 0; i < m; i++)
        {
            ll x = vec[i] ^ vec.back();

            ll cnt = 0;
            for(ll i = 0; i < 30; i++) cnt += check(x,i);

            if(cnt <= k) ans++;
        }

        cout << ans << "\n";
    }

}
