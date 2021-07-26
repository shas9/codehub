#include <bits/stdc++.h>

#define ld double

using namespace std;

const ld pi = acos(-1.0);

ld r, l, w;
ld ans, A, B;

struct points
{
    ld x, y;

    points() {}
    points(ld x, ld y) : x(x), y(y) {}

    friend points operator +(const points &a, const points &b)
    {
        return points(a.x + b.x, a.y + b.y);
    }

    friend points operator -(const points &a, const points &b)
    {
        return points(a.x - b.x, a.y - b.y);
    }
};


struct line
{
    points a, b;

    line() {}
    line(points a, points b) : a(a), b(b) {}

};

ld dot(points a, points b)
{
    return a.x * b.x + a.y * b.y;
}

ld det(points a, points b)
{
    return a.x * b.y - a.y * b.x;
}

ld dist(points a, points b)
{
    ld x = a.x - b.x;
    ld y = a.y - b.y;

    return sqrt(x*x + y*y);
}

ld perpdist(points a, line b)
{
    ld x = (a.x * (b.b.y - b.a.y)) + (b.a.x * (a.y - b.b.y)) + (b.b.x * (b.a.y - a.y));
    ld y = dist(b.a, b.b);

    return abs(x) / y;
}

bool check(points a, line b)
{
    return dot(a - b.a, b.b - b.a) >= 0 && dot(a-b.b, b.a - b.b) >= 0;
}

int main()
{
//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);


    int testcase;

    cin >> r >> l >> w >> testcase;

    while(testcase--)
    {
        cin >> A >> B;

        line L1 = line(points(l,w), points(l + 100,w));
        line L2 = line(points(l,w), points(l - l*cos(A), l*sin(A) + w));
        line L3 = line(points(l,0), points(l - l*cos(B), l*sin(B)));

        ans = min(r * 2, min(w,l));

        ans = min(ans, dist(L3.b,L1.a));


        if(A <= pi / 2) ans = min(ans,perpdist(points(0,w), L2));

        if(check(L3.b, L1)) ans = min(ans, perpdist(L3.b, L1));

        if(check(L3.b, L2)) ans = min(ans, perpdist(L3.b, L2));

        if(check(L1.a, L3)) ans = min(ans, perpdist(L1.a, L3));

        ans /= 2;
        printf("%.10f\n", (double)ans);

    }

    return 0;


}


