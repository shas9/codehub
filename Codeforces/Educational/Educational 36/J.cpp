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

#define mxlld 99999999999999999
#define mnlld -99999999999999999

#define mxd 99999999
#define mnd 99999999

#define pi 3.14159265359

#define mod 1000000009

#define mx 10000000


using namespace std;


vector < ll > primes;
bool vis[mx + 3];


ll mulmod(ll a, ll b, ll c) {
  ll x = 0, y = a % c;
  while (b) {
    if (b & 1) x = (x + y) % c;
    y = (y << 1) % c;
    b >>= 1;
  }
  return x % c;
}

ll fastPow(ll x, ll n, ll MOD) {
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
  while (d % 2 == 0) {
    s++;
    d >>= 1;
  }

  // It's guranteed that these values will work for any number smaller than 3*10**18 (3 and 18 zeros)
  int a[9] = {2, 3, 5, 7, 11, 13, 17, 19, 23};
  for(int i = 0; i < 9; i++) {
    bool comp = fastPow(a[i], d, n) != 1;
    if(comp) for(int j = 0; j < s; j++) {
      ll fp = fastPow(a[i], (1LL << (ll)j)*d, n);
      if (fp == n - 1) {
        comp = false;
        break;
      }
    }
    if(comp) return false;
  }
  return true;
}

void prime()
{
    vis[0] = true;
    vis[1] = true;

    for(ll i = 4; i <= mx; i += 2)
    {
        vis[i] = true;
    }

    for(ll i = 3; i * i <= mx; i += 2)
    {
        if(vis[i] == false)
        {
            for(ll j = i * i; j <= mx; j += i)
            {
                vis[j] = true;
            }
        }
    }

    for(ll i = 2; i <= mx; i++)
    {
        if(!vis[i])
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

    prime();

    slld(n);

    if(isPrime(n))
    {
        ans =1;
    }
    else if(n % 2 == 0)
    {
        ans = 2;
    }
    else
    {
        if(isPrime(n - 2))
        {
            ans = 2;
        }
        else
        {
            ans = 3;
        }
    }


    cout << ans << endl;


}

