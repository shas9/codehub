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

#define mod 1000000009


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

void gen()
{
    ll mx = 0;
    ll i, j;

    for(i = 1; i <= 100000; i++)
    {
        ll cnt = 0;

        for(j = 1; j * j <= i; j++)
        {
            if(i % j) continue;

            ll x = j;
            ll y = i / j;

            if(x == y) cnt++;
            else cnt += 2;
        }

        mx = max(mx,cnt);
    }

    cout << mx << endl;
}

void genp()
{
    ll mx = 0;
    ll i, j;

    for(i = 1; i <= 100000; i++)
    {
        ll cnt = 0;

        ll num = i;

        for(j = 0; primes[j] * primes[j] <= num; j++)
        {
            if(num % primes[j]) continue;

            cnt++;

            while(num % primes[j] == 0) num /= primes[j];
        }

        if(num > 1) cnt++;

        mx = max(mx,cnt);
    }

    cout << mx << endl;
}

ll arr[100005];
set < ll > divv;

bool solve(ll jump, ll n)
{
    if((n / jump) < 3) return 0;

    ll i, j;
    for(i = 1; i < (1 + jump); i++)
    {
        ll cnt = (n / jump);

//        if(n == 1001 && jump == 7 )cout << cnt << " " << n << " " << jump << " " << i << endl;

        for(j = i; cnt--; j += jump)
        {
            if(j > n) j-=n;

            if(arr[j] == 0) break;
        }

        if(cnt == -1) return 1;
    }

    return 0;
}

void solveprime(ll n)
{
    divv.clear();

    ll num = n;

    for(ll i = 0; primes[i] * primes[i] <= num; i++)
    {
        while(num % primes[i] == 0)
        {
            divv.insert(primes[i]);
            num /= primes[i];
        }
    }

    if(num > 1) divv.insert(num);

    bool ok = 0;

    for(auto it: divv)
    {
        if(solve(it,n))
        {
            ok = 1;
            break;
        }

        if(solve(n / it, n))
        {
			ok = 1;
            break;
        }
    }

    if(ok) printf("YES\n");
    else printf("NO\n");
}

void solvebrute(ll n)
{
    bool ok = 0;

    for(ll i = 3; i <= n; i++)
    {
        if(n % i) continue;

        if(solve(n/i,n))
        {
			if(n == 1001 )cout << n / i << endl;
            ok = 1;
            break;
        }
    }

    if(ok) printf("YES\n");
    else printf("NO\n");
}
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    sieve();

//	gen();

//	genp();

    while(cin >> n)
    {
        bool allone = 1;

        for(i = 1; i <= n; i++)
        {
            slld(arr[i]);

            if(arr[i] == 0) allone = 0;
        }

        if(allone)
        {
            printf("YES\n");
            continue;
        }

        solveprime(n);
//        solvebrute(n);
    }

}


