#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pb push_back
#define ff first
#define ss second
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define nn "\n"
#define sci(x) scanf("%d", &x)
#define LL_INF (1LL << 62)
#define INF (1 << 30)
#define SetBit(x, k) (x |= (1LL << k))
#define ClearBit(x, k) (x &= ~(1LL << k))
#define CheckBit(x, k) (x & (1LL << k))
#define mod 1000000007
#define N 300005

#define T long double

struct pt
{
    T x, y;
    pt operator+(pt p) { return {x + p.x, y + p.y}; }
    pt operator-(pt p) { return {x - p.x, y - p.y}; }
    pt operator*(T d) { return {x * d, y * d}; }
    pt operator/(T d) { return {x / d, y / d}; }
};

bool operator==(pt a, pt b) { return a.x == b.x && a.y == b.y; }
bool operator!=(pt a, pt b) { return !(a == b); }
T sq(pt p) { return p.x * p.x + p.y * p.y; }
double abs(pt p) { return sqrt(sq(p)); }
pt translate(pt v, pt p) { return p + v; }
pt scale(pt c, double factor, pt p) { return c + (p - c) * factor; }

ostream &operator<<(ostream &os, pt p)
{
    return os << "(" << p.x << ", " << p.y << ")";
}



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    pt p1, p2;
    T r1, r2;
    cin >> p1.x >> p1.y >> r1;
    cin >> p2.x >> p2.y >> r2;

    T d = abs(p1-p2);

    if(d>=r1+r2){
        cout << 0 << nn;
        return 0;
    }

    if(d+min(r1, r2) <= max(r1, r2)){
        T ans = acos(-1.0)*min(r1, r2)*min(r1, r2);
        cout << fixed << setprecision(10) << ans << nn;
        return 0;
    }

    T d1, d2;

    d1 = (sq(p1-p2)+r1*r1-r2*r2)/(2.0 * d);
    d2 = (sq(p1-p2)-r1*r1+r2*r2)/(2.0 * d);

    T ans = r1*r1*acos(d1/r1) + r2*r2*acos(d2/r2) - d1*r1*sin(acos(d1/r1)) - d2*r2*sin(acos(d2/r2));

    cout << fixed << setprecision(10) << ans << nn;

    return 0;
}
