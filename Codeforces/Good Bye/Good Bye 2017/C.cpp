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

#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld 99999999999999999
#define mnlld -99999999999999999

#define mxd 99999999
#define mnd 99999999

#define pi 3.14159265359


using namespace std;

int main()
{
    ll i, j, k, l, m, n, o, r;
    ll testcase;
    ll input, flag, tag;

    cin >> n >> r;

    double arr[1005];
    double ansarr[1005];

    for(ll cs = 1; cs <= n; cs++)
    {
        cin >> input;

        arr[cs] = input;
    }

    double a, b, c, d;

    for(i = 1; i <= n; i++)
    {
        ansarr[i] = r;

        for(j = 1; j < i; j++)
        {
            b = (arr[i] - arr[j]);
            c = 4*r*r - (b*b);

            ansarr[i] = max(ansarr[i],ansarr[j]+sqrt(c));
        }

        printf("%.10lf ", ansarr[i]);
    }


}


