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

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

ll power(ll x, ll y = 998244353 - 2, ll p = 998244353)
{
    ll res = 1;      // Initialize result

    x = x % p;  // Update x if it is more than or
                // equal to p

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;

        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
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


ll freq[1000006];
ll p;
ll n;

void add(ll x)
{
	ll cnt = 0;

	for(auto it: primes)
	{
		if(it * it > x) break;

		if(x % it == 0)
		{
			ll num = 1;

			while(x % it == 0) x /= it, num *= it;

			for(ll i = it; i <= 1e6; i *= it)
			{
				p += min(num, i) * freq[i];
				cnt += freq[i];
			}

			freq[num]++;
		}
	}

	if(x > 1)
	{
		for(ll i = x; i <= 1e6; i *= x)
		{
			p += x * freq[i];
			cnt += freq[i];
		}

		freq[x]++;
	}

	cout << n << " ~~ " << cnt << endl;
	p += (n - cnt);
}

void rem(ll x)
{
	ll cnt = 0;

	for(auto it: primes)
	{
		if(it * it > x) break;

		if(x % it == 0)
		{
			ll num = 1;

			freq[num]--;

			while(x % it == 0) x /= it, num *= it;

			for(ll i = it; i <= 1e6; i *= it)
			{
				p -= min(num, i) * freq[i];
				cnt += freq[i];
			}

		}
	}

	if(x > 1)
	{
		freq[x]--;

		for(ll i = x; i <= 1e6; i *= x)
		{
			p -= x * freq[i];
			cnt += freq[i];
		}

	}


	p -= (n - cnt);

//	cout << n << " ++ " << cnt << endl;
}

int main()
{
    ll i, j, k, l, m, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

//	fastio;
	sieve();
	while(cin >> m)
	{
		p = 0;
		memset(freq,0,sizeof freq);

		n = 0;

		for(ll i = 1; i <= m; i++)
		{
			cin >> input;

			add(input);
			n++;
		}

		cin >> m;

		for(ll i = 1; i <= m; i++)
		{
			ll t, x;

			cin >> t >> x;

//			cout << i << endl;

			if(t == 1)
			{
				add(x);
				n++;
			}
			else
			{
				n--;
				rem(x);
			}

			ll q = n * (n - 1) / 2;

			cout << p << " " << q << " " << n << endl;

			ll g = __gcd(p,q);

			ans = (((p / g) % 998244353) * power(q / g)) % 998244353;

			cout << ans << "\n";
		}
	}


}



