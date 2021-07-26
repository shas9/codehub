#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)
#define plld(longvalue) printf("%lld\n", longvalue)

#define slf(longvalue) scanf("%lf", &longvalue)
#define plf(longvalue) printf("%.8lf ", longvalue)
#define sc(letter) scanf("%c", &letter)
#define pc(letter) printf("%c", letter)

#define ss(name) scanf("%s", name)
#define ps(name) printf("%s", name)

#define pnew printf("\n")

#define ll long long

#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld 99999999999999999
#define mnlld -99999999999999999

#define mxd 99999999
#define mnd 99999999

#define pi 3.14159265359

#define mod 1000000009


using namespace std;

bool outside(double R, double x1, double y1, double x2, double y2)
{
    double temp;

    temp = ((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1));
    R = R * R;

    if(temp >= R)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    double R, x1, y1, x2, y2, r, x, y;

    cin >> R >> x1 >> y1 >> x2 >> y2;

    if(outside(R, x1, y1, x2, y2))
    {
        plf(x1);
        plf(y1);
        plf(R);

        return 0;
    }


    r = sqrt(((x2 - x) * (x2 - x)) + ((y2 - y) * (y2 - y)));

        plf(x);
        plf(y);
        plf(r);

        return 0;


}


