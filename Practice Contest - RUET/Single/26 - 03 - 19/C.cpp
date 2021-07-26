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

#define maxn 200002

using namespace std;

vector < ll > primes;
bool vis[maxn+10];

ll arr[505][505];

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

bool _isprime(ll x)
{
    ll lo = 0;
    ll hi = primes.size() - 1;
    ll mid = -1;

    while(lo <= hi)
    {
        ll mid = (lo + hi) / 2;

        if(primes[mid] == x) return 1;

        if(primes[mid] < x)
        {
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }

    return 0;

}

ll _getprime(ll x)
{
    ll lo = 0;
    ll hi = primes.size() - 1;
    ll mid = -1;
    ll ans = 0;

    while(lo <= hi)
    {
        ll mid = (lo + hi) / 2;

        if(primes[mid] < x)
        {
            lo = mid + 1;
        }
        else
        {
            ans = mid;
            hi = mid - 1;
        }
    }

    return primes[ans];

}

int main()
{
    ll i, j, k, l, m, n, o, x;
    ll testcase;
    ll input, flag, tag, ans;

    sieve();



    while(cin >> n >> m)
    {
        ans = mxlld;

        for(i = 1; i <= n; i++)
            for(j = 1; j <= m; j++)
                cin >> arr[i][j];

        for(i = 1; i <= n; i++)
        {
            ll cnt = 0;
            for(j = 1; j <= m; j++)
            {
                if(!_isprime(arr[i][j]))
                {
                    cnt += abs(_getprime(arr[i][j]) - arr[i][j]);
                }
            }

            ans = min(ans,cnt);
        }

        for(i = 1; i <= m; i++)
        {
            ll cnt = 0;
            for(j = 1; j <= n; j++)
            {
                if(!_isprime(arr[j][i]))
                {
                    cnt += abs(_getprime(arr[j][i]) - arr[j][i]);
                }
            }

            ans = min(ans,cnt);
        }

        cout << ans << endl;
    }


}


