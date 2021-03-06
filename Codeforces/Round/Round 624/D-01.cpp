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
    ll tot, a, b, c;
};

ll x, y, z;

node solve1(ll nn)
{
//    cout << x << " " << y << " " << z << " " << nn << endl;
    if(nn > 3)
    {
        node zz;
        zz.tot = abs(x - a) + abs(y - b) + abs(z - c);

        zz.a = x;
        zz.b = y;
        zz.c = z;

        return zz;
    }

    if(nn == 1)
    {
        return solve1(nn + 1);
    }

    if(nn == 2)
    {
        ll st = b / x;

        st -= 5;

        st = max(st, 1LL);


        node ret;

        ret.tot = mxlld;


        for(ll i = st; i <= st + 10; i++)
        {
            node xx;

            y = i * x;

//            cout << i << endl;

            xx = solve1(nn + 1);

            if(xx.tot < ret.tot) ret = xx;
        }

        return ret;
    }

    if(nn == 3)
    {
        ll st = c / y;

        st -= 5;

        st = max(st, 1LL);


        node ret;

        ret.tot = mxlld;


        for(ll i = st; i <= st + 10; i++)
        {
            node xx;

            z = i * y;

            xx = solve1(nn + 1);

            if(xx.tot < ret.tot) ret = xx;
        }

        return ret;
    }
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
        cin >> a >> b >> c;

        node ans;
        ans.tot = mxlld;

        for(i = 1; i <= 10000; i++)
        {
            x = i;
            node xx = solve1(1);

            if(xx.tot < ans.tot) ans = xx;
        }

        cout << ans.tot << endl;
        cout << ans.a << " " << ans.b << " " << ans.c << endl;
    }


}



