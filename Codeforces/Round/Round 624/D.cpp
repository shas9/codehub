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

ll a, b, c;


struct node{
    ll a, b, c, tot;
};

node solve1(ll ind)
{
    node ret;

    ret.a = ind;

    ll p1, p2, p3, p4, p5, p6, p7, p8, p9;

    p1 = p2 = p3 = p4 =  p5 = p6 = p7 = p8 = p9 = mxlld;

    ll x1 = (b / ind) * ind;

    ll y11,y12, y13;

    if(x1)
    {
        y11 = (c / x1) * x1;
        y12 = ((c / x1) + 1) * x1;
        y13 = ((c / x1) - 1) * x1;

        p1 = abs(a - ind) + abs(b - x1) + abs(c - y11);
        p2 = abs(a - ind) + abs(b - x1) + abs(c - y12);
        p5 = abs(a - ind) + abs(b - x1) + abs(c - y13);
    }

    ll x2 = ((b / ind) + 1) * ind;
    ll y21 = (c / x2) * x2;
    ll y22 = ((c / x2) + 1) * x2;
    ll y23 = ((c / x2) - 1) * x2;

    p3 = abs(a - ind) + abs(b - x2) + abs(c - y21);
    p4 = abs(a - ind) + abs(b - x2) + abs(c - y22);
    p6 = abs(a - ind) + abs(b - x2) + abs(c - y23);

    ll x3 = ((b / ind) - 1) * ind;

    ll y31, y32, y33;

    if(x3)
    {
        y31 = (c / x3) * x3;
        y32 = ((c / x3) + 1) * x3;
        y33 = ((c / x3) - 1) * x3;

        p7 = abs(a - ind) + abs(b - x3) + abs(c - y31);
        p8 = abs(a - ind) + abs(b - x3) + abs(c - y32);
        p9 = abs(a - ind) + abs(b - x3) + abs(c - y33);
    }

    ret.tot = min(p1, min(p2,min(p3,min(p4,min(p5,min(p6,min(p7,min(p8,p9))))))));

    if(ret.tot == p1) ret.b = x1, ret.c = y11;
    else if(ret.tot == p2) ret.b = x1, ret.c = y12;
    else if(ret.tot == p3) ret.b = x2, ret.c = y21;
    else if(ret.tot == p4) ret.b = x2, ret.c = y22;
    else if(ret.tot == p5) ret.b = x1, ret.c = y13;
    else if(ret.tot == p6) ret.b = x2, ret.c = y32;
    else if(ret.tot == p7) ret.b = x3, ret.c = y31;
    else if(ret.tot == p8) ret.b = x3, ret.c = y32;
    else if(ret.tot == p9) ret.b = x3, ret.c = y33;

    return ret;

}

node solve2(ll ind)
{
    node ret;

    ret.b = ind;

    ll p1, p2, p3, p4, p5, p6, p7, p8, p9;

    p1 = p2 = p3 = p4 =  p5 = p6 = p7 = p8 = p9 = mxlld;

    ll x1 = (ind / a) * a;

    ll y11,y12, y13;

    {
        y11 = (c / ind) * ind;
        y12 = ((c / ind) + 1) * ind;
        y13 = ((c / ind) - 1) * ind;

        p1 = abs(a - x1) + abs(b - x1) + abs(c - y11);
        p2 = abs(a - x1) + abs(b - x1) + abs(c - y12);
        p5 = abs(a - ind) + abs(b - x1) + abs(c - y13);
    }

    ll x2 = ((b / ind) + 1) * ind;
    ll y21 = (c / x2) * x2;
    ll y22 = ((c / x2) + 1) * x2;
    ll y23 = ((c / x2) - 1) * x2;

    p3 = abs(a - ind) + abs(b - x2) + abs(c - y21);
    p4 = abs(a - ind) + abs(b - x2) + abs(c - y22);
    p6 = abs(a - ind) + abs(b - x2) + abs(c - y23);

    ll x3 = ((b / ind) - 1) * ind;

    ll y31, y32, y33;

    if(x3)
    {
        y31 = (c / x3) * x3;
        y32 = ((c / x3) + 1) * x3;
        y33 = ((c / x3) - 1) * x3;

        p7 = abs(a - ind) + abs(b - x3) + abs(c - y31);
        p8 = abs(a - ind) + abs(b - x3) + abs(c - y32);
        p9 = abs(a - ind) + abs(b - x3) + abs(c - y33);
    }

    ret.tot = min(p1, min(p2,min(p3,min(p4,min(p5,min(p6,min(p7,min(p8,p9))))))));

    if(ret.tot == p1) ret.b = x1, ret.c = y11;
    else if(ret.tot == p2) ret.b = x1, ret.c = y12;
    else if(ret.tot == p3) ret.b = x2, ret.c = y21;
    else if(ret.tot == p4) ret.b = x2, ret.c = y22;
    else if(ret.tot == p5) ret.b = x1, ret.c = y13;
    else if(ret.tot == p6) ret.b = x2, ret.c = y32;
    else if(ret.tot == p7) ret.b = x3, ret.c = y31;
    else if(ret.tot == p8) ret.b = x3, ret.c = y32;
    else if(ret.tot == p9) ret.b = x3, ret.c = y33;

    return ret;

}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag;

    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(a);
        slld(b);
        slld(c);

//        cout << a << " " << b << " " << c << endl;

        node ans;
        ans.tot = mxlld;

        for(i = 1; i <= 10000; i++)
        {
            node xx = solve1(i);
            if(xx.tot < ans.tot)
            {
                ans = xx;
            }
        }

        for(i = 1; i <= 10000; i++)
        {
            node xx = solve2(i);
            if(xx.tot < ans.tot)
            {
                ans = xx;
            }
        }



        cout << ans.tot << endl;

        cout << ans.a << " " << ans.b << " " << ans.c << endl;
    }


}



