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

/*
   Code: Non-deterministic primality testing
   Miller-Rabin Prime Test: up to 3 * 10^18;
*/


vector < ll > primes;
bool vis[mx + 3];

ll mulmod(ll a, ll b, ll c)
{
  ll x = 0, y = a % c;
  while (b) {
    if (b & 1) x = (x + y) % c;
    y = (y << 1) % c;
    b >>= 1;
  }
  return x % c;
}

ll fastPow(ll x, ll n, ll MOD)
{
  ll ret = 1;
  while (n) {
    if (n & 1) ret = mulmod(ret, x, MOD);
    x = mulmod(x, x, MOD);
    n >>= 1;
  }
  return ret;
}

bool isPrime(ll n)
{
    if(n == 2 || n == 3) return true;
    if(n == 1 || !(n & 1)) return false;

    if(n < mx)
    {
        if(vis[n])
        {
            return false;
        }
        else
        {
            return true;
        }
    }


  ll d = n - 1;
  int s = 0;

  while (d % 2 == 0)
  {
    s++;
    d >>= 1;
  }

  // It's guranteed that these values will work for any number smaller than 3*10**18 (3 and 18 zeros)

  int a[9] = {2, 3, 5, 7, 11, 13, 17, 19, 23};

  for(int i = 0; i < 9; i++)
  {
    bool comp = fastPow(a[i], d, n) != 1;

    if(comp)
    {
        for(int j = 0; j < s; j++)
        {
          ll fp = fastPow(a[i], (1LL << (ll)j)*d, n);
          if (fp == n - 1)
          {
            comp = false;
            break;
          }
        }
    }

    if(comp) return false;
  }
  return true;
}

ll makesmall(ll n)
{
    deque<int>dq;
    while(n)
    {
        dq.push_front(n % 10);
        n /= 10;
    }
    ll ret= 0;
    for(i = 0; i < dq.size(); i++)
    {
        if(dq[i] > 7)
        {
            ret = ret * 10 + 7;
            i++;
            while(i < dq.size())
            {
                i++;
                ret = ret * 10 + 7;
            }
        }
        else if(dq[i] == 7)
        {
            ret = ret * 10 + 7;
        }
        else if()
    }
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);
    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(n);

        while(1)
        {
            n = makesmall(n);

            if(isPrime(n))
            {
                printf("Case %lld: %lld\n", cs, n);
                break;
            }
        }
    }


}



