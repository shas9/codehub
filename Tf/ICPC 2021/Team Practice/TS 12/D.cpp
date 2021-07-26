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

long double area(long double side, ll n)
{
    long double angle = (180.0 / n) * (acos(-1.0) / 180.0);
    long double ret = (side * side * n) / (4 * tan(angle));

    return ret;
}

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        cin >> n >> m;

        long double tot = area(m,n);

        long double triangle = area(m / 3.0, 3);

//        cout << tot << " " << triangle << "\n";

        long double ans = tot - (n * triangle);

        cout << setprecision(10) << fixed << ans << "\n";
    }


}

