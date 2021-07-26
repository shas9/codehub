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




using namespace std;

long long int power(long long int x, long long int y, long long int p)
{
    long long int res = 1;      // Initialize resulto

    x = x % p;  // Update x if it is more than or
                // equal to p

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;

        // y must be even now
        y = y >> 1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;

    scanlld(testcase);

    ll num, prime;
    ll ans;
    ll flag;

    for(i = 1; i <= testcase; i++)
    {
        scanlld(num);
        scanlld(prime);

        ans = (prime - 1) % prime;

        flag = prime - 2;

        if(prime <= num)
        {
            ans = 0;
        }

        else
        {
             for(j = num + 1; j < prime; j++)
            {
                ans = ((ans % prime) * (power(j, flag, prime) % prime)) % prime;
            }

        }

        printlld(ans);
    }


}

