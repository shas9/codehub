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
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);
    slld(testcase);

    double D, d, h;

    for(ll cs = 1; cs <= testcase; cs++)
    {
        cin >> D >> d >> h;

        double x, r, area1, area2;

        double pi = acos(-1.0);

        r = D / 2.0;

        x = sin((double)acos((d - r) / r)) * r;

        area1 = pi * x * x * h;
        area2 = (4 / 3.0) * pi * r * r * r;

//        cout << area1 << " " << area2 << endl;

        if(abs(area1 - area2) < 0.01)
        {
            printf("Case %lld: Yes\n", cs);
        }
        else
        {
            printf("Case %lld: No\n", cs);
        }



    }


}



