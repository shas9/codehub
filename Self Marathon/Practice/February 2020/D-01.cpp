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

struct points
{
    double x, y, z;
};

points sub(points a, points b)
{
    points ret;

    ret.x = a.x - b.x;
    ret.y = a.y - b.y;
    ret.z = a.z - b.z;

    return ret;
}

points cross(points a, points b)
{
    points ret;

    ret.x = (a.y * b.z) - (b.y * a.z);
    ret.y = (b.x * a.z) - (a.x * b.z);
    ret.z = (a.x * b.y) - (b.x * a.y);

    return ret;
}

double dot(points a, points b)
{
    return ((a.x * b.x) + (a.y * b.y) + (a.z * b.z));
}

ll cosine(ll xx)
{
    if(abs(xx) < 0.0000001) return 0;

    if(xx < 0) return -1;

    return 1;
}

double len(points a)
{
    return sqrt(dot(a,a));
}

void print(points a)
{
    cout << a.x << " " << a.y << " " << a.z << endl;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        points a, b, s;

        scanf("%lf %lf %lf", &s.x, &s.y, &s.z);

        scanf("%lf %lf %lf", &a.x, &a.y, &a.z);
        scanf("%lf %lf %lf", &b.x, &b.y, &b.z);

        points sa = sub(a,s);

        points sb = sub(b,s);

        points lombo = cross(sa,sb);

        if(cosine(dot(lombo,s)) > 0)
        {
            lombo.x *= -1;
            lombo.y *= -1;
            lombo.z *= -1;
        }

        points dane_from_a = cross(sa,lombo);

//        print(dane_from_a);

        double len_a = len(sa);
        double len_dane_a = len(dane_from_a);

//        cout << len_dane_a << endl;

        dane_from_a.x *= (len_a / len_dane_a);
        dane_from_a.y *= (len_a / len_dane_a);
        dane_from_a.z *= (len_a / len_dane_a);

        points bame_from_b = cross(lombo,sb);

        double len_b = len(sb);
        double len_bame_b = len(bame_from_b);

        bame_from_b.x *= (len_b / len_bame_b);
        bame_from_b.y *= (len_b / len_bame_b);
        bame_from_b.z *= (len_b / len_bame_b);

        points ans;

//        print(a);
//        print(b);
//        print(s);

//        print(dane_from_a);
//        print(bame_from_b);

        ans.x = (a.x + dane_from_a.x + b.x + bame_from_b.x) / 2.0;
        ans.y = (a.y + dane_from_a.y + b.y + bame_from_b.y) / 2.0;
        ans.z = (a.z + dane_from_a.z + b.z + bame_from_b.z) / 2.0;

        printf("%.9f %.9f %.9f\n", ans.x, ans.y, ans.z);
    }


}


