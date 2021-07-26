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

#define mx 100000

using namespace std;

vector < ll > prime;
bool check[mx + 3];

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

void sieve()
{
    ll i, j;

    check[0] = 1;
    check[1] = 1;

    for(i = 4; i <= mx; i += 2)
    {
        check[i] = 1;
    }

    for(i = 3; i * i <= mx; i += 2)
    {
        if(check[i] == false)
        {
            for(j = i * i; j <= mx; j += i)
            {
                check[j] = 1;
            }
        }
    }

    prime.clear();
    for(i = 1; i <= mx; i++)
    {
        if(!check[i])
        {
            prime.pb(i);
        }
    }
}

ll inversemod(ll a, ll m)
{
    return power(a, m - 2, m);
}

ll solve(ll n, ll m)
{
    ll ans =  1;

    ll x1, x2, x;

    ll temp = prime.size();

    for(ll i = 0; prime[i] <= n && i < temp; i++)
    {
        ll cnt = 0;

        if(n % prime[i] == 0)
        {

            while(n % prime[i] == 0)
            {
                n /= prime[i];

                cnt++;
            }

            x1 = power(prime[i], (cnt * m) + 1, mod) - 1;
            x2 = inversemod(prime[i] - 1, mod);
            x = (((x1 + mod) % mod) * ((x2 + mod) % mod)) % mod;
            ans = ((ans % mod) * (x % mod)) % mod;
        }

        if(n == 1)
        {
            break;
        }

    }

    if(n > 1)
    {
        x1 = power(n, m + 1, mod) - 1;
        x2 = inversemod(n - 1, mod);
        x = (((x1 + mod) % mod) * ((x2 + mod) % mod)) % mod;
        ans = ((ans % mod) * (x % mod)) % mod;
    }

    return ans % mod;
}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    sieve();

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(n);
        slld(m);

        ans = solve(n,m);

        printcase(cs,ans);
    }


}


