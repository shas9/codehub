// God put a smile upon your face <3

#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb push_back

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 958585860497

#define base 2001487

using namespace std;

bool check(ll n, ll pos)
{
    return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
    return n = n | (1LL << pos);
}


double calc(double h, double m)
{
    double hh = 0.5 * (h * 60 + m);
    double mm = (6 * m);

    double ang = abs(hh - mm);

    ang = min(ang,360-ang);

    ang = (acos(-1.0) * ang) / 180;

    return ang;
}

double calcAngle(double h, double m)
{

    double hour_angle = 0.5 * (h * 60 + m);
    double minute_angle = 6 * m;


    double angle = abs(hour_angle - minute_angle);

    angle = min(360 - angle, angle);

    angle = (angle / 180) * pi;
    return angle;
}
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m >> l >> r)
    {
        double ang = calc(l,r);

//        cout << ang << " " << cos(ang) << endl;

        double c = (n * n) + (m * m) - (2 * n * m * cos(ang));

        printf("%.10f\n", sqrt(c));
    }
}




