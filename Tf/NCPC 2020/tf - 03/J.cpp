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

double x1, y1, r1;
double x2, y2, r2;
double x3, y3, r3;
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2)
    {
        double distxy = sqrt(((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2)));

        double xx1 = (distxy - r1);
        double xx2 = (distxy - r2);

        double covarea = distxy - (xx1 + xx2);

        covarea /= 2;

        r3  = covarea;

        double rat1 = r1 - covarea;
        double rat2 = r2 - covarea;

        x3 = ((rat2 * x1) + (rat1 * x2)) / (rat1 + rat2);

        y3 = ((rat2 * y1) + (rat1 * y2)) / (rat1 + rat2);

        printf("%.10f %.10f %.10f\n", x3 ,y3, r3);
    }


}


