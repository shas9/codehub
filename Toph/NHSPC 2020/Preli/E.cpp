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

using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

ll calc(ll x, ll c)
{
	ll ret = 0;

	while(x)
	{
		ret += (x / c);
		x /= c;
	}

	return ret;
}

#define mx 100000005

bool check(int n, int pos)
{
	return n & (1 << pos);
}

int Set(int n, int pos)
{
	return n = n | (1 << pos);
}

#define inf (1LL<<50)
#define eps 1e-9

#define MAXL (50000>>5)+1

#define GET(x) (mark[x>>5]>>(x&31)&1)
#define SET(x) (mark[x>>5] |= 1<<(x&31))
int mark[MAXL];
int P[50000], Pt = 0;


void sieve()
{
    register int i, j, k;
    SET(1);
    int n = 46340;
    for (i = 2; i <= n; i++)
    {
        if (!GET(i))
        {
            for (k = n/i, j = i*k; k >= i; k--, j -= i)
                SET(j);
            P[Pt++] = i;
        }
    }
}
long long mul(unsigned long long a, unsigned long long b, unsigned long long mod)
{
    long long ret = 0;
    for (a %= mod, b %= mod; b != 0; b >>= 1, a <<= 1, a = a >= mod ? a - mod : a)
    {
        if (b&1)
        {
            ret += a;
            if (ret >= mod)	ret -= mod;
        }
    }
    return ret;
}
void exgcd(long long x, long long y, long long &g, long long &a, long long &b)
{
    if (y == 0)
        g = x, a = 1, b = 0;
    else
        exgcd(y, x%y, g, b, a), b -= (x/y) * a;
}
long long llgcd(long long x, long long y)
{
    if (x < 0)    x = -x;
    if (y < 0)    y = -y;
    if (!x || !y)    return x + y;
    long long t;
    while (x%y)
        t = x, x = y, y = t%y;
    return y;
}
long long inverse(long long x, long long p)
{
    long long g, b, r;
    exgcd(x, p, g, r, b);
    if (g < 0)	r = -r;
    return (r%p + p)%p;
}
long long mpow(long long x, long long y, long long mod)   // mod < 2^32
{
    long long ret = 1;
    while (y)
    {
        if (y&1)
            ret = (ret * x)%mod;
        y >>= 1, x = (x * x)%mod;
    }
    return ret % mod;
}
long long mpow2(long long x, long long y, long long mod)
{
    long long ret = 1;
    while (y)
    {
        if (y&1)
            ret = mul(ret, x, mod);
        y >>= 1, x = mul(x, x, mod);
    }
    return ret % mod;
}
int isPrime(long long p)   // implements by miller-babin
{
    if (p < 2 || !(p&1))	return 0;
    if (p == 2)				return 1;
    long long q = p-1, a, t;
    int k = 0, b = 0;
    while (!(q&1))	q >>= 1, k++;
    for (int it = 0; it < 2; it++)
    {
        a = rand()%(p-4) + 2;
        t = mpow2(a, q, p);
        b = (t == 1) || (t == p-1);
        for (int i = 1; i < k && !b; i++)
        {
            t = mul(t, t, p);
            if (t == p-1)
                b = 1;
        }
        if (b == 0)
            return 0;
    }
    return 1;
}
long long pollard_rho(long long n, long long c)
{
    long long x = 2, y = 2, i = 1, k = 2, d;
    while (true)
    {
        x = (mul(x, x, n) + c);
        if (x >= n)	x -= n;
        d = llgcd(x - y, n);
        if (d > 1) return d;
        if (++i == k) y = x, k <<= 1;
    }
    return n;
}
void factorize(int n, vector<long long> &f)
{
    for (int i = 0; i < Pt && P[i]*P[i] <= n; i++)
    {
        if (n%P[i] == 0)
        {
            while (n%P[i] == 0)
                f.push_back(P[i]), n /= P[i];
        }
    }
    if (n != 1)	f.push_back(n);
}
void llfactorize(long long n, vector<long long> &f)
{
    if (n == 1)
        return ;
    if (n < 1e+9)
    {
        factorize(n, f);
        return ;
    }
    if (isPrime(n))
    {
        f.push_back(n);
        return ;
    }
    long long d = n;
    for (int i = 2; d == n; i++)
        d = pollard_rho(n, i);
    llfactorize(d, f);
    llfactorize(n/d, f);
}

vector <pll> factors;

void final_factors(ll n) //call this, factors.fr will have the prime factor, and sc will have freq
{
    vector<long long> f;
    map<long long, int> r;

    llfactorize(n, f);
    for (auto &x : f)
        r[x]++;

    for (auto it = r.begin(); it != r.end(); it++)
    {
        factors.pb(pll(it->first, it->second));
    }
}

void brute(ll a, ll b, ll c)
{
	ll lcm = a;

	for(ll i = a; i <= b; i++)
	{
		lcm = (lcm  / __gcd(lcm,i)) * i;
	}

	cout << lcm << endl;

	ll cnt = 0;

	while(lcm % c == 0)
	{
		cnt++;
		lcm /= c;
	}

	cout << cnt << endl;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

	sieve();
    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		ll a, b, c;
		slld(a);
		slld(b);
		slld(c);

//		brute(a,b,c);

		factors.clear();

		final_factors(c);

		ans = mxlld;

		for(auto it: factors)
		{
			ll num = 1;
			ll cnt = 0;
			ll ret = 0;

			while(num <= b / it.first)
			{
				num *= it.first;
				cnt++;

				ll lft = a / num;

				if(a % num) lft++;


				if(lft <= (b / num))
				{
					ret = max(ret, cnt / it.second);
				}
			}

			ans = min(ans,ret);
		}

		printf("%lld\n", ans);
    }


}





