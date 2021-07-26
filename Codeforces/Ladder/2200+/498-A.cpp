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

    ll x1, x2, y1, y2;

    while(cin >> x1 >> y1 >> x2 >> y2)
    {
        cin >> n;

        ans = 0;

        while(n--)
        {
            ll a, b, c;

            cin >> a >> b >> c;

            ll s1 = a * x1 + b * y1 + c;
            ll s2 = a * x2 + b * y2 + c;

            if(s1 > s2) swap(s1, s2);

            if(s1 < 0 && s2 > 0) ans++;
        }

        cout << ans << "\n";
    }


}


