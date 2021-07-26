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
#define ull unsigned long long
#define pll pair < long long, long long >
#define pii pair < int, int >

#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009


using namespace std;

#define mx 100000005

bool check(int n, int pos)
{
	return n & (1 << pos);
}

int Set(int n, int pos)
{
	return n = n | (1 << pos);
}

int status[(mx / 32) + 5];

vector < int > primes;
vector < ll > oddprime;

void sieve(int n)
{
    int i, j, sq;

    sq = int( sqrt(n) );

    for(i = 3; i <= sq; i += 2)
    {
        if(check(status[i >> 5], i & 31) == 0)
        {
            for(j = i * i; j <= n; j += (i << 1))
            {
                status[j >> 5] = Set(status[j >> 5], j & 31);
            }
        }
    }

    primes.clear();

    primes.pb(2);

    for(i = 3; i <= n; i += 2)
    {
        if(check(status[i >> 5], i & 31) == 0)
        {
            primes.pb(i);
        }
    }


}

void solve()
{
    oddprime.clear();

    ll sz = primes.size();

    for(ll i = 0; i < sz; i++)
    {
        ll num = primes[i];

        while(num > 0)
        {
            ll dig = num % 10;

            if(dig % 2 == 0) break;

            num /= 10;
        }

        if(num == 0) oddprime.push_back(primes[i]);
    }
}

ll solve1(ll num)
{
    ll lo = 0;
    ll hi = oddprime.size();

    ll ret = 0;


    while(lo <= hi)
    {
        ll mid = (lo + hi) / 2;

        if(oddprime[mid] <= num)
        {
            ret = mid + 1;
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }

    return ret;
}


int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    sieve(100000000);

    solve();
    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {

        slld(l);
        slld(r);

        printf("%lld\n", solve1(r) - solve1(l - 1));
    }


}



