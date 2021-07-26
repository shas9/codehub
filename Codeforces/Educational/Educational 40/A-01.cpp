
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

#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld 2e18
#define mnlld -2e18

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009


using namespace std;

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag;

    // freopen("in.txt", "r", stdin);

    ll hh, mm, h, d;
    double c;

    cin >> hh >> mm >> h >> d >> c >> n;

    double dis, nor;

     ll t = ((20 - (hh + 1)) * 60) + (60 - mm);

     //cout << t << endl;

     //cout << t << endl;

    ll h_n = h / n;

    if(h % n != 0)
    {
        h_n++;
    }

    ll h_n_1 = ((t * d) + h) / n;

    if(((t * d) + h)  % n != 0)
    {
        h_n_1++;
    }

    dis = ( c * 80 * 1.0) / (100 * 1.0);
    dis *= h_n_1;
    nor = ( 1.0 * c)* h_n;

    //cout << dis << " " << nor << endl;

    double ans;

    if(hh >= 20 && hh <= 23)
    {
        ans = nor * (8.0/10.0);
    }
    else
    {
        ans = min(dis,nor);
    }

    printf("%.6lf\n", ans);


}

