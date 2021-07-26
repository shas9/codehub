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
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);
    slld(testcase);

    ll hh, mm;
    ll hh1, mm1;
    ll d;

    ll t;
    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(hh);
        getchar();
        slld(mm);
        slld(hh1);
        getchar();
        slld(mm1);
        slld(d);

        t = hh - hh1;
        t *= 60;

        if(mm < mm1)
        {
            t -= 60;
            t += (mm - mm1) + 60;
        }
        else
        {
            t += (mm - mm1);
        }

       double p1, p2;


       //cout << t << endl;

        p1 = t + d;
        p2 = d + d;

        if(p2 <= t)
        {
            p2 = t;
        }
        else
        {
            double temp = p2 - t;

            p2 -= temp / 2;

        }

        printf("%.1lf %.1lf\n", p1,p2);


    }


}


