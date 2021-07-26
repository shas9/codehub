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

double a, b, c, xx, yy, zz;

struct p
{
    double x, y, z;
};

p solve(double ang)
{
    double aa = (acos(-1.0) / 180.0) * ang;

    double dv = sqrt(a * a + b * b + c * c);

    a /= dv;
    b /= dv;
    c /= dv;

    p term1 = {xx * cos(aa), yy * cos(aa), zz * cos(aa)};
    p term2 = {((b * zz) - (yy * c)) * sin(aa), ((c * xx) - (a * zz)) * sin(aa), ((a * yy) - (b * xx)) * sin(aa)};
    double add = (1 - cos(aa)) * (a * xx + b * yy + c * zz);
    p term3 = {a * add, b * add, c * add};

    p ret = {term1.x + term2.x + term3.x, term1.y + term2.y + term3.y, term1.z + term2.z + term3.z};

    return ret;
}
int main()
{
    ll testcase;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    cin >> testcase;

    for(ll cs = 1; cs <= testcase; cs++)
    {
        double r;
        cin >> a >> b >> c >> xx >> yy >> zz >> r;

        p p1 = solve(r);
        p p2 = solve(360 - r);

        if(p1.z > p2.z) cout << setprecision(10) << fixed << p1.x << " " << p1.y << " " << p1.z << "\n";
        else cout << setprecision(10) << fixed << p2.x << " " << p2.y << " " << p2.z << "\n";
    }


}

