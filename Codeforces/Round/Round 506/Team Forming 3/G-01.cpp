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

int main()
{
    ll i, j, k, l, m, n, o, x;
    ll testcase;
    ll input, flag, tag, ans;

    sieve();

    // freopen("in.txt", "r", stdin);

    ll sz = primes.size();

    slld(testcase);

    ans = 0;
    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(n);

        ll curr = 0;

        ll make = 1;

        flag = n;



        while(make < n)
        {
            ll temp = n / make;
            bool check = 0;

            for(i = 0; i < sz; i++)
            {
                if(temp % primes[i] == 0)
                {
                    check = 1;
                    break;
                }
            }

            if(check == 0)
            {
                make = n;
            }
            else
                make = make * primes[i];
            flag += (n / make);
        }

        ans += flag;
    }

    plld(ans);


}


