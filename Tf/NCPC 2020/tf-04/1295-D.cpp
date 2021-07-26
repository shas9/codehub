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

#define mxlld 2e18
#define mnlld -2e18

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009

#define maxn 1000002

using namespace std;

vector < ll > primes;
bool vis[maxn+10];

void sieve()
{
    vis[0] = 1;
    vis[1] = 1;

    for(ll i = 4; i <= maxn; i += 2)
    {
        vis[i] = 1;
    }

    for(ll i = 3; i * i <= maxn; i += 2)
    {
        if(vis[i] == 0)
        for(ll j = i * i; j <= maxn; j += i)
        {
            vis[j] = 1;
        }
    }

    for(ll i = 2; i <= maxn; i++)
    {
        if(vis[i] == false)
        primes.pb(i);
    }

}

ll phi(ll n)
{
    double res = n;

    for(ll i = 0; primes[i] * primes[i] <= n; i++)
    {
        if(n % primes[i]) continue;

        while(n % primes[i] == 0)
        {
            n /= primes[i];
        }

        res *= (1 - (1.0 / primes[i]));
    }

    if(n > 1)
    {
        res *= (1 - (1.0 / n));
    }

    return res;
}

ll phi2(ll n)
{
    ll res = n;

    for(ll i = 0; primes[i] * primes[i] <= n; i++)
    {
        if(n % primes[i]) continue;

        while(n % primes[i] == 0)
        {
            n /= primes[i];
        }

        res -= (res / primes[i]);
    }

    if(n > 1)
    {
        res -= res / n;
    }

    return res;
}
int main()
{
    ll i, j, k, l, m, n, o, x;
    ll testcase;
    ll input, flag, tag, ans;

    sieve();

    // freopen("in.txt", "r", stdin);
    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(n);
        slld(m);

        ll ephi = phi2(m / __gcd(n,m));

        cout << ephi << endl;
    }


}



