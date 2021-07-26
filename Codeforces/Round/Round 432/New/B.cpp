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

ll x1, x2, x3, y_1, y2, y3;

bool solve()
{
    ll up = ((x1 * x1 - x3 * x3) * (y_1 - x2) + (y_1 * y_1 - y3 * y3) * (y_1 - y2) + (x2 * x2 - x1 * x1) * (y_1 - y3) + (y2 * y2 - y_1 * y_1) * (y_1 - y3));
    ll down = (y3 - y_1) * (y_1 - y2) - (x2 - x1) * (y_1 - y3);

    if(down == 0) return 0;
    if(up % down) return 0;

    up = ((x1 * x1 - x3 * x3) * (x1 - x2) + (y_1 * y_1 - y3 * y3) * (x1 - x2) + (x2 * x2 - x1 * x1) * (x1 - x3) + (y2 * y2 - y_1 * y_1) * (x1 - x3));
    down = (y3 - y_1) * (x1 - x2) - (y2 - y_1) * (x1 - x3);


    if(down == 0) return 0;
    if(up % down) return 0;


    return 1;
}

ll dis(ll x1, ll y_1, ll x2, ll y2)
{
    return ((x1 - x2) * (x1 - x2)) + ((y_1 - y2) * (y_1 - y2));
}

bool solve1()
{
    ll ab = dis(x1,y_1,x2,y2);
    ll bc = dis(x2,y2,x3,y3);

    if(ab != bc) return 1;

    ll u1 = (y_1 - y2);
    ll d1 = (x1 - x2);
    ll g1 = __gcd(u1,d1);
    u1 /= g1;
    d1 /= g1;

    ll u2 = (y3 - y2);
    ll d2 = (x3 - x2);
    ll g2 = __gcd(u2,d2);
    u2 /= g2;
    d2 /= g2;

    return u1 == u2 && d1 == d2;

}
int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> x1 >> y_1 >> x2 >> y2 >> x3 >> y3)
    {
        if(!solve1()) cout << "Yes\n";
        else cout << "No\n";
    }

}

