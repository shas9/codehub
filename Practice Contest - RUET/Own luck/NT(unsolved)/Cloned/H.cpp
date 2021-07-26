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

#define mod 1000000009

#define mx 1000000


using namespace std;

vector < ll > primes;
bool vis[mx + 3];

void prime()
{
    vis[0] = true;
    vis[1] = true;

    for(ll i = 4; i <= mx; i += 2)
    {
        vis[i] = true;
    }

    for(ll i = 3; i * i <= mx; i += 2)
    {
        if(vis[i] == false)
        {
            for(ll j = i * i; j <= mx; j += i)
            {
                vis[j] = true;
            }
        }
    }

    for(ll i = 2; i <= mx; i++)
    {
        if(!vis[i])
        {
            primes.pb(i);
        }
    }

}

ll solve(ll n)
{
    ll ans = 1;

    ll temp = primes.size();

    ll cnt;

    for(ll i = 0; i < temp && primes[i] * primes[i] <= n; i++)
    {
        cnt = 0;
        if(n % primes[i] == 0)
        {
            while(n % primes[i] == 0)
            {
                cnt++;

                n /= primes[i];
            }

            cnt++;

            ans *= cnt;
        }
    }

    if(n != 1)
    {
        ans *= 2;
    }

    return ans - 1;
}

/*
1
1000000000000
*/



int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    slld(testcase);

    primes.clear();

    prime();

    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(n);

        ans = solve(n);

        printcase(cs,ans);
    }


}


