 // God put a smile upon your face <3

#include <bits/stdc++.h>

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

#define mx 50000005

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


ll solve(ll p, ll q)
{
	ll gc = __gcd(p,q);

	if(gc != q) return p;

	vector < pll > v;

	for(auto it: primes)
	{
		if(it * it > gc) break;

		if(gc % it == 0)
		{
			ll cnt = 0;

			while(gc % it == 0)
			{
				cnt++;
				gc /= it;
			}

			v.push_back({it,cnt});
		}
	}

	if(gc != 1) v.pb({gc,1});

	ll mn = mxlld;

	for(auto it: v)
	{
//		cout << it.first << " " << it.second << endl;
		ll cnt = 0;

		ll x = p;

		while(x % it.first == 0) cnt++, x /= it.first;

		ll del = cnt - it.second + 1;

		ll num = 1;

		while(del--) num *= it.first;

		mn = min(mn, num);

//		cout << num << endl;
	}

	return p / mn;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

	sieve(5e7);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		ll p, q;

		cin >> p >> q;

		ans = solve(p,q);

		cout << ans << "\n";

		assert(p % ans == 0 && ans % q != 0);
    }


}



