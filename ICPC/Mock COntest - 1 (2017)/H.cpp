#include <bits/stdc++.h>`

#define scanlld(longvalue) scanf("%lld", &longvalue)
#define printlld(longvalue) printf("%lld\n", longvalue)

#define scanc(letter) scanf("%c", &letter)
#define printc(letter) printf("%c", letter)

#define scans(name) scanf("%s", name)
#define prints(name) printf("%s", name)

#define printnewline printf("\n")

#define ll long long

#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)

#define pb(x) push_back(x)

#define bug printf("BUG\n")


using namespace std;

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

    ll fastexpo[100010];

    fastexpo[1] = 2;
    fastexpo[2] = 3;

    for(i = 3; i < 100009; i++)
    {
        fastexpo[i] = fastexpo[i - 1] + (i - 1);

        //printf("i = %lld, no: %lld\n", i, fastexpo[i]);
    }


    scanlld(testcase);

    ll ans;

    for(i = 1; i <= testcase; i++)
    {
        scanlld(n);
        scanlld(k);
        scanlld(m);

        if(k == m)
        {
           ans = 0;
        }
        else
        {
           ans = power(k,fastexpo[n],m);
        }


        printf("Case %lld: %lld\n", i, ans);
    }





}


