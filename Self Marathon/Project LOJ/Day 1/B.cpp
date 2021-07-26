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

ll xx[3], yy[3], zz[3];

double solve(double mid)
{
    double dist = sqrt((xx[0] - xx[1]) * (xx[0] - xx[1]) +  (yy[0] - yy[1]) * (yy[0] - yy[1]) + (zz[0] - zz[1]) * (zz[0] - zz[1]));

    double x1;
    double y1;
    double z1;

    if(xx[0] == xx[1] && yy[0] == yy[1] && zz[0] == zz[1])
    {
        x1 = xx[0];
        y1 = yy[0];
        z1 = zz[0];
    }
    else
    {
        x1 = (xx[0] * (dist - mid) + xx[1] * mid) / dist;
        y1 = (yy[0] * (dist - mid) + yy[1] * mid) / dist;
        z1 = (zz[0] * (dist - mid) + zz[1] * mid) / dist;

    }


    double ret = sqrt((x1 - xx[2]) * (x1 - xx[2]) +  (y1 - yy[2]) * (y1 - yy[2]) +  (z1 - zz[2]) * (z1 - zz[2]));

    return ret;
}
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        for(i = 0; i < 3; i++)
        {
            slld(xx[i]);
            slld(yy[i]);
            slld(zz[i]);
        }

        double lo = 0;
        double hi = sqrt((xx[0] - xx[1]) * (xx[0] - xx[1]) +  (yy[0] - yy[1]) * (yy[0] - yy[1]) + (zz[0] - zz[1]) * (zz[0] - zz[1]));
        double ans = sqrt((xx[0] - xx[2]) * (xx[0] - xx[2]) +  (yy[0] - yy[2]) * (yy[0] - yy[2]) +  (zz[0] - zz[2]) * (zz[0] - zz[2]));

        while(abs(lo - hi) > 0.0000001)
        {
            double mid1 = ((lo + lo + hi) / 3);
            double mid2 = ((hi + hi + lo) / 3);

            double x = solve(mid1);
            double y = solve(mid2);

            if(x <= y) hi = mid2, ans = x;
            else lo = mid1, ans = y;
        }

        printf("Case %lld: %.10f\n", cs, ans);
    }


}


