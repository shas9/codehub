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

double dist(double x1, double y1, double x2, double y2)
{
    double a = (x1 - x2) * (x1 - x2);
    double b = (y1 - y2) * (y1 - y2);

    return (double)sqrt(a + b);
}


//Corner point if Door is Less than 90 degree
pair < double, double > solve(double angle, double d, double y1, double x1)
{
    pair < double, double > ret = {0,0};

    ret.first = d - (d * cos(angle));
    ret.second = y1 + (d * sin(angle));

    return ret;
}

// Corner point if Door is More than 90 degree
pair < double, double > solve2(double angle, double d, double y1, double x1)
{
    pair < double, double > ret = {0,0};

    angle = pi - angle;

    ret.first = d + (d * cos(angle));
    ret.second = (d * sin(angle));

    return ret;
}

int main()
{
    ll i, j, k, m, n, o, r, q;
    ll testcase;


    freopen("input.txt", "r", stdin);

    double R, l, w;

    cin >> R >> l >> w;

    slld(testcase);

    double ang90 = pi / 2; //radian angle for 90 degree

    for(ll cs = 1; cs <= testcase; cs++)
    {
        double A, B;
        double mA = 0, mB = 0;
        double cA = 0, cB = 0;

        pair < double, double > point1, point2;
        point1 = {-1,-1};
        point2 = {-1,-1};

        double ans = (R * 2);
        ans = min(ans,l);
        ans = min(ans,w);

        bool ok1 = 1, ok2 = 1;


        cin >> A >> B;


        if(abs(A - 0.00000000000) < 0.00001) //if A is 0 degree. The answer should always be 0
        {
            cout << "0.0000000000" << endl;
            continue;
        }

        if(abs(B - ang90) < 0.00001) // if B is 90 degree. R should be shrunked to (w - l) if he is not shruked that much yet.
        {
            ans = min(w - l,ans);
            ok2 = 0;
        }

        if(A >= ang90 || abs(A - ang90) <= 0.00001) ok1 = 0; // if angle of A is greater or equal than 90 degree Door A is useless :P


        if(ok1) // If Door A is useful
            mA = tan(pi - A);

        if(ok2) // If Door B is useful
            mB = tan(pi - B);


        if(abs(mA - 0) < 0.000001) mA = 0;

        if(abs(mB - 0) < 0.000001) mB = 0;

        if(ok1)
        {
            point1 = solve(A, l, w, l);
        }
        if(ok2)
        {
            if(B < ang90) point2 = solve(B, l, 0, l);
            else point2 = solve2(B, l, 0, l);
        }

        if(ok1) cA = (-1.0 * mA * l) + w; // if mx + y + c = 0 is the equation. Here cA is c of equation of Door A

        if(ok1)
        {
            double perp = abs(- w + cA) / sqrt((mA*mA) + 1); //perpendicular distance from Door A to (0,W)

            ans = min(ans,perp);
        }

        if(A < ang90 && B < ang90) //perpendicular distance from corner point of Door B to the Door A
        {
            double perpendiculardist = abs((mA * point2.first) - point2.second + cA) / sqrt((mA*mA) + 1);

            ans = min(ans,perpendiculardist);
        }
        else if(B < ang90) // if angle of A is greater than 90 degree. we should calculate the distance from corner of Door B to (L,W)
        {
            double zz = dist(point2.first,point2.second,l,w);

            ans = min(ans,zz);
        }
        else if(ok2) // if angle of B is greater than 90 degree. ans can be shrunked to the distance between upper wall and corner of Door B
        {
            double perpend = w - point2.second;
            ans = min(ans,perpend);
        }

        ans /= 2; //Convertion from diameter to radius


        printf("%.10f\n", ans);

    }


}



