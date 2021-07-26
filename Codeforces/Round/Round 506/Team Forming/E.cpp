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
	return n & (1 << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1 << pos);
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    ll a, b;
    double area;
    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        a = 0;
        b = 0;
        area = 0;

        slld(n);
        char c;
        flag = 0;
        tag = 1;
        for(i = 1; i <= n; i++)
        {
            scanf(" %c", &c);
            slld(input);
            flag += input;

            if(c == 'S')
            {
                area += input * input;
            }
            else if(c == 'T')
            {
                double s = (input * 3.0) / 2;

                double p = s * (s - input) * (s - input) * (s - input);
                p = sqrt(p);

//                cout << p << endl;

                area += p;
            }
            else
            {
                area += input * input;
                if(tag == 1) tag = 0;
                else if(a == 0) a = flag;
                else if(b == 0) b = flag;

                flag = input;
            }
        }

        double x = (a * b * 1.0) - area;

        printf("%.4f\n", x);
    }


}

//

