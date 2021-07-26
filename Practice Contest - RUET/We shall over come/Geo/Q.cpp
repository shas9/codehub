#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)
#define plld(longvalue) printf("%lld\n", longvalue)

#define slf(longvalue) scanf("%lf", &longvalue)
#define plf(longvalue) printf("%lf\n", longvalue)
#define sc(letter) scanf("%c", &letter)
#define pc(letter) printf("%c", letter)

#define ss(name) scanf("%s", name)
#define ps(name) printf("%s", name)

#define pnew printf("\n")

#define ll long long

#define pi 3.14159265359

#define mod 1000000009


using namespace std;

ll xp1, xp2, xp3, xp4;
ll yp1, yp2, yp3, yp4;

pair < double, double > solve()
{
    double t = (((xp1 - xp3) * (yp3 - yp4)) - ((yp1- yp3) * (xp3 - xp4)));
    t /= (((xp1 - xp2) * (yp3 - yp4)) - ((yp1- yp2) * (xp3 - xp4)));


    return make_pair(xp1 + (t * (xp2 - xp1)), yp1 + (t * (yp2 - yp1)));
}

int main()
{
//    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
//    ll input, flag, tag, ans;

    // freopen("in.txpt", "r", stdin);
    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        cin >> xp1 >> yp1;
        cin >> xp2 >> yp2;
        cin >> xp3 >> yp3;
        cin >> xp4 >> yp4;

        pair < double, double > ans;

        ans = solve();

        printf("%.10f %.10f\n", ans.first, ans.second);
    }


}



