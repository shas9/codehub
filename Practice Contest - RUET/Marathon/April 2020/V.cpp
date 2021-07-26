#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000007


using namespace std;

bool check(ll n, ll pos)
{
    return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
    return n = n | (1LL << pos);
}

const ll maxn = 100002;
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
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);
//
//    freopen("output.txt", "w", stdout);

    sieve();

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(n);
        slld(m);



        ans = 0;

        ans += n;

        ll cnt = 0;

        if(m >= 2)
        {
            for(i = 0; primes[i] < n; i++)
            {
                ans += ((n - primes[i]) * (m - 1));
                ans %= mod;

            }
        }


        if(m >= 3)
        {
            for(i = 0; primes[i] + 2 < n; i++)
            {
                if(vis[primes[i] + 2]) continue;

                ll dx = (m - 1) * (m - 2);
                dx %= mod;

                ans += ( dx * (n - primes[i] - 2));
                ans %= mod;
            }
        }

        if(m >= 4)
        {
			for(i = 0; primes[i] + 4 < n; i++)
            {
                if(vis[primes[i] + 4] || vis[primes[i] + 2]) continue;

                ll dx = (m - 1) * (m - 2) * (m - 3);

                dx /= 6;

                dx %= mod;

                ans += (dx * (n - primes[i] - 4));
                ans %= mod;
            }
        }

//        if(cs == 214) cout << n << " " << m << endl;
//
//        if(cs == 214)
        printf("Case %lld: %lld\n", cs, ans);

    }


}



