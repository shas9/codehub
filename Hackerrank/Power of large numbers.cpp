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

#define mod 1000000007



using namespace std;
char A[100005];
char B[100005];

ll power(ll x, ll y, ll p)
{
    ll res = 1;      // Initialize result

    x = x % p;  // Update x if it is more than or
                // equal to p

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;

        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans, temp;

    slld(testcase);

    ll a, b;

    for(ll cs = 1; cs <= testcase; cs++)
    {
        ss(A);
        ss(B);

        temp = strlen(A);

        a = 0;

        for(i = 0; i < temp; i++)
        {
            a = (a * 10 + (A[i] - 48)) % mod;
        }

        temp = strlen(B);

        b = 0;

        flag = mod - 1;

        for(i = 0; i < temp; i++)
        {
            b = (b * 10 + (B[i] - 48)) % flag;
        }

        if(b == 0)
        {
            ans = 1;
        }
        else
        {
            ans = power(a,b,mod);
        }

        plld(ans);
    }
}

