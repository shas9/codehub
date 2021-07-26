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

ll store[11][1000005];
ll primes[mx + 5];

void sieve()
{
    ll i, j, k, l, m;

    primes[2] = 1;

    for(i = 4; i <= mx; i += 2)
    {
        primes[i]++;
    }

    for(i = 3; i <= mx; i += 2)
    {
        if(primes[i] == 0)
        {
            for(j = i; j <= mx; j += i)
            {
                primes[j]++;
            }
        }
    }

//    for(i = 0; i <= 20; i++)
//    {
//        cout << primes[i] << " " << i <<  endl;
//    }

    for(i = 1; i <= mx; i++)
    {
//        if(primes[i] <= 10)
//        {
            store[primes[i]][i]++;
//        }

        for(j = 0; j <= 10; j++)
        {
            store[j][i] += store[j][i - 1];
        }
    }
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
        slld(i);
        slld(j);
        slld(n);

        ans = store[n][j] - store[n][i - 1];

        plld(ans);
    }

    return 0;


}


