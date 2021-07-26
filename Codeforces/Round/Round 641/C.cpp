// God put a smile upon your face <3

#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb push_back

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 958585860497

#define base 2001487

using namespace std;

bool check(ll n, ll pos)
{
    return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
    return n = n | (1LL << pos);
}

const ll maxn  = 1000002;
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

ll arr[100005];

void brute(ll n)
{
    ll i, j;

    for(i = 1; i <= n; i++)
    {
        ll tmp = arr[i];

        cout << tmp << "\n";

        for(ll j = 0; primes[j] * primes[j] <= tmp; j++)
        {
            if(tmp % primes[j]) continue;

            ll x = 0;

            while(tmp % primes[j] == 0) x++, tmp /= primes[j];

            cout << primes[j] << ": " << x << endl;
        }

        if(tmp > 1) cout << tmp << ": " << 1  << endl;
    }
}

vector < ll > app[1000006];

ll solve(ll n)
{
    ll i, j;
    for(i = 1; i <= n; i++)
    {
        ll tmp = arr[i];

        for(j = 0; primes[j] * primes[j] <= tmp; j++)
        {
            ll x = 0;

            while(tmp % primes[j] == 0) x++, tmp /= primes[j];

            if(x) app[primes[j]].push_back(x);
        }

        if(tmp > 1) app[tmp].pb(1);
    }

    ll res = 1;

    for(i = 2; i <= 1000000; i++)
    {
        if(app[i].size() == n)
        {
            sort(app[i].begin(),app[i].end());

            for(j = 1; j <= app[i][1]; j++)
            {
                res *= i;
            }
        }
        else if(app[i].size() + 1 == n)
        {
            sort(app[i].begin(),app[i].end());

            for(j = 1; j <= app[i][0]; j++)
            {
                res *= i;
            }
        }
    }

    return res;
}
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    sieve();

    while(cin >> n)
    {
        for(i = 1; i <= n; i++) slld(arr[i]);

//        brute(n);

        for(i = 1; i <= 1000000; i++) app[i].clear();

        ans = solve(n);

        cout << ans << "\n";
    }
}



