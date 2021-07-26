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

    cin >> testcase;

    for(ll cs = 1; cs <= testcase; cs++)
    {
        ll x1, x2, x3, y1, y2, y3;

        cin >> x1 >> y1;
        cin >> x2 >> y2;
        cin >> x3 >> y3;

        ans = abs(x1 - x2) + abs(y1 - y2);

        if(x1 == x2 && x1 == x3 && min(y1,y2) <= y3 && y3 <= max(y1,y2)) ans += 2;
        if(y1 == y2 && y1 == y3 && min(x1,x2) <= x3 && x3 <= max(x1,x2)) ans += 2;

        cout << ans << "\n";
    }


}


