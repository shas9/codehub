#include <bits/stdc++.h>`

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
#define ull unsigned long long
#define pll pair < long long, long long >
#define pii pair < int, int >

#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009


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
    ll i, j, k, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag;

    // freopen("in.txt", "r", stdin);

    double l, w, h, thita;

    while(cin >> l >> w >> h >> thita)
    {
        double red = thita * pi;
        red /= 180.0;

        double oti = l / cos(red);
        double lombo = oti * sin(red);

        double ans = 0;

        if(lombo < h)
        {
            double s = oti + l + lombo;
            s /= 2;
            double area = sqrt(s * (s - l) * (s - oti) * (s - lombo));
            area *= w;
            ans = (l * w * h) - area;

        }
        else
        {
            oti = h / sin(red);
            lombo = oti * cos(red);

            double s = oti + h + lombo;
            s /= 2;
            double area = sqrt(s * (s - h) * (s - oti) * (s - lombo));
            area *= w;
            ans = area;



        }


        printf("%.3f mL\n", ans);

    }


}
