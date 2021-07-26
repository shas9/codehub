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

#define maxn 100005

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

map < ll, ll > a, b;
bool on;

ll power(ll x, ll y, ll p)
{
    ll res = 1;      // Initialize result

    if(x >= p)
    x = x % p, on = 1;  // Update x if it is more than or
                // equal to p

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x);

        if(res >= p)
            res %= p, on = 1;

        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x);

        if(x >= p)
            x = x % p, on = 1;
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

    slld(n);

    on = 0;

    for(i = 1; i <= n; i++)
    {
        slld(input);

        ll ssq = sqrt(input) + 1;

        j = 0;
        while(input > 1 && primes[j] <= ssq)
        {
            while(input % primes[j] == 0)
            {
                input /= primes[j];

                a[primes[j]]++;
            }

            j++;
        }

        if(input > 1)
        {
            a[input]++;
        }
    }

    slld(n);

    on = 0;

    for(i = 1; i <= n; i++)
    {
        slld(input);

        ll ssq = sqrt(input) + 1;

        j = 0;
        while(input > 1 && primes[j] <= ssq)
        {
            while(input % primes[j] == 0)
            {
                input /= primes[j];

                b[primes[j]]++;
            }

            j++;
        }

        if(input > 1)
        {
            b[input]++;
        }
    }

    ans = 1;

    for(map < ll, ll > :: iterator it = a.begin(); it != a.end(); it++)
    {
        ll ff = it -> first;
        ll ss = it -> second;

        if(b.find(ff) != b.end())
        {
            ans *= power(ff,min(a[ff],b[ff]), 1000000000);
        }

        if(ans >= 1000000000)
        {
            ans %= 1000000000;
            on = 1;
        }
    }

    if(on == 0) plld(ans);
    else
    {
        string x = "";

        while(ans > 0)
        {
            x += (ans % 10) + '0';
            ans /= 10;
        }

        reverse(x.begin(),x.end());

        flag = 9 - x.size();

        for(i = 1; i <= flag; i++) cout << 0;
        if(x.size())cout << x;

        cout << endl;
    }



}


