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
set < ll > st;

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
        {
            primes.pb(i);
        }
    }

}

bool x[maxn];

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    sieve();
//    bug;

    // freopen("in.txt", "r", stdin);
    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        ans = 0;

        slld(n);
        slld(k);

        memset(x,false,sizeof x);

        for(i = 1; i<= k; i++)
        {
            slld(input);
            x[input] = 1;
        }

        for(i = 0; primes[i] * primes[i] <= n; i++)
        {
            if(x[primes[i]]) continue;
            flag = primes[i] * primes[i];
            while(flag <= n)
            {
                //cout << flag << endl;
                ans++;
                flag *= primes[i];
            }
            for(j = i + 1; primes[j] * primes[j] <= n; j++)
            {
                ll a = primes[i];
                ll b = primes[j];

                if(x[a] || x[b]) continue;

                ll cnt = 1;
                flag = a;
                while(flag * b <= n)
                {
                    ans++;
                    flag *= a;
                }
                flag = b * b;
                while(flag * a <= n)
                {
                    ans++;
                    flag *= b;
                }
            }
        }

        printcase(cs,ans);
    }


}


