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

#define mx 10000000

using namespace std;

vector < ll > prime;
bool check[10000001];

void sieve()
{
    ll i, j;

    memset(check,0,sizeof(check));

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

        ll temp = prime.size();

        ans = 0;

        for(i = 0; 2*prime[i] <= n; i++)
        {
            flag = n - prime[i];

            if(check[flag] == false)
            {
                ans++;
            }
        }

//        if(n == 4)
//        {
//            ans = 1;
//        }

        printcase(cs,ans);
    }


}

