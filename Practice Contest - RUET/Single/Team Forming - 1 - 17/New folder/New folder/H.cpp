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

ll solve(ll x)
{
    for(ll i = x - 1; i >= 1; i--)
    {
        if(__gcd(x,i) == 1 && __gcd(x + 1, i) == 1) return i;
    }
}
int main()
{
    ll i, j, k, l, m, n, o, x;
    ll testcase;
    ll input, flag, tag, ans, ans2;

    sieve();

    // freopen("in.txt", "r", stdin);

    slld(n);

    if(n == 1) ans = 1;
    else if(n == 2) ans = 2;
    else if(n == 3) ans = 6;
    else if(n == 4) ans = 12;
    else if(n==5) ans = 60;
    else
    {
        ans = n * (n - 1);

        ans *= solve(n - 1);

        ans2 = (n-1)*(n-2);

        ans2 *= solve(n-2);

        ans = max(ans, ans2);
    }

    cout << ans << endl;
}



