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

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009


using namespace std;

#define mx 100000000

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



int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    sieve(mx);

    ll sz = primes.size();

    for(i = 0; i < sz; i += 100)
        cout << primes[i] << endl;


}


