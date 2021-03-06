#include <bits/stdc++.h>

#define ll long long

#define sl(n) scanf("%lld", &n)
#define ss(n) scanf("%s", n)
#define sf(n) scanf("%lf", &n)

#define INF (1LL<<62)

#define pll pair<ll,ll>

#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define srt(v) sort(v.begin(), v.end())
using namespace std;

#define PI acos(-1.00)

void findCornerPoint(double A, double l, double *Ax, double *Ay)
{

        *Ax = l - l*cos(A);
        *Ay = l*sin(A);

}

#define EPS 0.000000001
#define varTyp double
struct point
{
    varTyp x, y;
    point()
    {
        x = y = 0;
    }
    point(varTyp _x, varTyp _y)
    {
        x = _x, y = _y;
    }
    bool operator < (point other)
    {
        if (fabs(x - other.x) > EPS)
            return x < other.x;
        return y < other.y;
    }
    bool operator == (point other)
    {
        return ( fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS) );
    }
} root;
struct line
{
    varTyp a, b, c; //ax + by + c = 0
};
void pointsToLine(point p1, point p2, line &l)
{
    if (fabs(p1.x - p2.x) < EPS) // for vertical line
    {
        l.a = 1.0;
        l.b = 0.0;
        l.c = -p1.x;
    }
    else
    {
        l.a = - (varTyp) (p1.y - p2.y) / (p1.x - p2.x);
        l.b = 1.0; // to check equality/parallelgiri etc of lines easier
        l.c = -(varTyp)(l.a * p1.x) - p1.y;
    }
}
varTyp dist(point p1, point p2, ll sq = 0)
{
    //sq = 1 returns squared version, useful for int calc
    if (sq)
        return (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y);
    return hypot(p1.x - p2.x, p1.y - p2.y);
}
bool areParallel(line l1, line l2)
{
    return (fabs(l1.a-l2.a) < EPS) && (fabs(l1.b-l2.b) < EPS); //checking if a and b of both lines are
}
bool areSame(line l1, line l2)
{
    return areParallel(l1,l2) && (fabs(l1.c - l2.c) < EPS); //checking if both lines are parallel and c is
}

bool areIntersect(line l1, line l2, point &p) //returns true if the lines intersect
{
    if (areParallel(l1, l2))
        return false; // no intersectionp.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
    if (fabs(l1.b) > EPS)
        p.y = -(l1.a * p.x + l1.c)/l1.b;
    else
        p.y = -(l2.a * p.x + l2.c)/l2.b;
    return true;
}
struct vec
{
    varTyp x, y;
    vec()
    {
        x = y = 0;
    }
    vec(varTyp _x, varTyp _y)
    {
        x = _x, y = _y;
    }
};
vec toVec(point a, point b) // convert a and b points to vector a->b
{
    return vec(b.x - a.x, b.y - a.y);
}
vec scale(vec v, varTyp s) // nonnegative s = [<1 .. 1 .. >1]
{
    return vec(v.x * s, v.y * s);
}
point translate(point p, vec v) // translate p according to v
{
    return point(p.x + v.x, p.y + v.y);
}
varTyp dot(vec a, vec b)
{
    return (a.x * b.x + a.y * b.y);
}
varTyp vec_magni(vec v) // magnitude
{
    return sqrt(v.x * v.x + v.y * v.y);
}
varTyp norm_sq(vec v) // square of magnitude
{
    return (v.x * v.x + v.y * v.y);
}
varTyp distToLine(point p, point a, point b, point &c) //also creates closest point c, distance
{
    vec ap = toVec(a, p), ab = toVec(a, b);
    varTyp u = dot(ap, ab) / norm_sq(ab);
    c = translate(a, scale(ab, u)); // u = ap.ab/|ab| * ab/|ab|
    return dist(p, c);
}
varTyp distToLineSeg(point p, point a, point b, point &c) //also creates closest point c, distance
{
    vec ap = toVec(a, p), ab = toVec(a, b);
    varTyp u = dot(ap, ab) / norm_sq(ab);
    if (u < 0.0)
    {
        c = point(a.x, a.y); // closer to a
        return dist(p, a);
    }
    if (u > 1.0)
    {
        c = point(b.x, b.y); // closer to b
        return dist(p, b);
    }
    c = translate(a, scale(ab, u));
    return dist(p, c);
}

int main()
{
    //  freopen("input.txt", "r", stdin);

    ll n, i, j, k, x, y, z, cs, ts;

    double R, l, w, A, B, Ax, Ay, Bx, By;

    cin >> R >> l >> w >> ts;

    while(ts--)
    {
        sf(A);
        sf(B);

        findCornerPoint(A, l, &Ax, &Ay);
        Ay += w;
        findCornerPoint(B, l, &Bx, &By);

//        cout << Ax << " " << Ay << " " << Bx << " " << By << endl;

        point A1(Ax, Ay), B1(Bx, By), Z(0, 0), A3(0, w), A2(l,w), B2(l,0), G;

        double ans = l;

        ans = min(ans, distToLineSeg(A3, A1, A2, G)); // (0,w) to door A
        ans = min(ans, distToLineSeg(B1, A1, A2, G)); // door B corner to door A
        ans = min(ans, distToLineSeg(A2, B1, B2, G)); // (l,w) to door B
        if (2*B >= PI)
        {
            ans = min(ans, w - l*sin(B)); // door B corner to upper wall
        }

//        double zx = (Bx - l) * (Bx - l);
//        double zy = (By - w) * (By - w);
//
//        ans = min(ans, sqrt(zx + zy));
        ans /= 2;

        ans = min(ans, R);

        printf("%0.9f\n", ans);
    }

    return 0;
}
