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

#define pi acos(-1.0)

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

double area(double a, double b, double c)
{
    double s = a + b + c;
    s *= 0.5;

//    cout << a << " " << b << " " << c << endl;
//    cout << s << endl;

    return sqrt((s * (s - a) * (s - b) * (s - c)));
}

double incircle(double a, double b, double c)
{
    return area(a, b, c) / (0.5 * (a + b + c));
}

double outcircle(double a, double b, double c)
{
    return a * b * c / (4.0 * area(a,b,c));
}

double circlearea(double r)
{
    return pi * r * r;
}


int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("in.txt", "r", stdin);

    double a, b, c;

    while(cin >> a >> b >> c)
    {

        double tri_area = area(a,b,c);

//        cout << tri_area << endl;
        double big = outcircle(a,b,c);
        double small = incircle(a,b,c);

//        cout << big << " " << tri_area << " " << small << endl;
        big = circlearea(big);
        small = circlearea(small);



        big -= tri_area;
        tri_area -= small;



        printf("%.4f %.4f %.4f\n", big, tri_area, small);
    }


    return 0;
}



