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

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

#define mx 30000005

int status[(mx / 32) + 5];

vector < int > primes;

void sieve()
{
    ll n = mx;
    ll i, j, sq;

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




ll power(ll x, ll y)
{
    ll res = 1;      // Initialize result
  // Update x if it is more than or
                // equal to p

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) ;

        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x);
    }
    return res;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    sieve();
    while(1)
    {
        slld(input);

        if(input == -1) return 0;

        ll a = 1, b = input;

        ll sz = primes.size();

        ll sq = int(sqrt(input));

        if(sq * sq == input) a = sq;
        else
        for(i = 0; primes[i] * primes[i] <= input && i < sz; i++)
        {
            ll cnt = 0;
            while(input % primes[i] == 0)
            {
                input /= primes[i];
                cnt++;
            }

                a *= power(primes[i],cnt / 2);

//            cout << i << endl;
        }

        cout << a << " " << b / (a * a) << endl;
    }


}



