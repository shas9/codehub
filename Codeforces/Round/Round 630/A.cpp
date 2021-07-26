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

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        ll a, b, c, d;
        ll x1, y1, x2, y2, x, y;

        cin >> a >> b >> c >> d;
        cin >> x >> y >> x1 >> y1 >> x2 >> y2;

        if((x == x1 && x == x2 && (a || b)) || (y == y1 && y == y2 && (c || d)))
        {
            cout << "NO" << endl;
            continue;
        }


        ll xx = min(a,b);
        a -= xx;
        b -= xx;

        ll yy = min(c,d);

        c -= yy;
        d -= yy;

        if(a > abs(x - x1) || b > abs(x - x2) || c > abs(y - y1) || d > abs(y - y2))
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }

    }


}


