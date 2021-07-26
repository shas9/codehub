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
ll cnt[3][15000];

bool on;

ll power(ll x, ll y, ll p)
{
    ll res = 1;      // Initialize result

        if(x > p)
        {
            x %= p;
            on = 1;
        }  // Update x if it is more than or
                // equal to p

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x);

            if(res >= p)
            {
                on = 1;
                res %= p;
            }

        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x);

        if(x > p)
        {
            x %= p;
            on = 1;
        }
    }
    return res;
}

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

int main()
{
    ll i, j, k, l, m, n, o, x;
    ll testcase;
    ll input, flag, tag, ans;

    sieve();

//    cout << primes.size() << endl;

    slld(n);

    for(i = 1; i <= n; i++)
    {
        slld(input);

        j = 0;
        while(input > 1 && j < primes.size())
        {
            while(input % primes[j] == 0)
            {
                input /= primes[j];
                cnt[1][j]++;
            }
            j++;
        }
    }

    slld(m);

    for(i = 1; i <= m; i++)
    {
        slld(input);

        j = 0;
        while(input > 1 && j < primes.size())
        {
            while(input % primes[j] == 0)
            {
                input /= primes[j];
                cnt[2][j]++;
            }

            j++;
        }
    }

    on = 0;

    ll sz = primes.size();

    ans = 1;
    for(i = 0; i < sz; i++)
    {
        ans *= power(primes[i], min(cnt[1][i], cnt[2][i]), 1000000000);

        if(ans >= 1000000000)
        {
            on = 1;
            ans %= 1000000000;
        }
    }

    string xx = "";

    while(ans > 0)
    {
        ll id = ans % 10;

        xx += id + '0';

        ans /= 10;
    }

    reverse(xx.begin(),xx.end());

    if(on == 0) cout << xx << endl;
    else
    {
        ll sz = xx.size();

        ll temp = 10 - sz;

        for(i = 1; i < temp; i++)
        {
            cout << 0;
        }

        if(xx.size())
        cout << xx;

        cout << endl;
    }
}


