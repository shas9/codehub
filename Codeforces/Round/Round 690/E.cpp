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


// when mod is prime

const ll mod = 1000000007;
const ll sz = 300000;

ll fact[sz + 10];

ll power(ll x, ll y, ll p)
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


ll nCr(ll n, ll r)
{
    if(r > n) return 0;

    if(n < mod)
    {
        ll z = ((power(fact[r], mod - 2, mod)) * (power(fact[n - r], mod - 2, mod))) % mod;
        return (fact[n] * z) % mod;
    }

    /// Lucas Theorem
    vector < ll > N, K;

    while(n) N.push_back(n % mod), n /= mod;

    while(r) K.push_back(r % mod), r /= mod;

    ll ret = 1;

    for(ll i = 0; i < K.size(); i++)
    {
        ret = (ret * nCr(N[i],K[i])) % mod;
    }

    return ret;
}

void precalc()
{
    fact[0] = 1;

    for(ll i = 1; i <= sz; i++)
    {
        fact[i] = (i * fact[i - 1]) % mod;
    }
}

map < ll, ll > mp;
vector < ll > v;

ll calc(ll x, ll n)
{
	ll lo = 0;
	ll hi = n - 1;
	ll ret = 0;

	while(lo <= hi)
	{
		ll mid = (hi + lo) / 2;

		if(v[mid] <= x)
		{
			ret = mid;
			lo = mid + 1;
		}
		else
		{
			hi = mid - 1;
		}
	}

	return ret;
}

ll solve(ll n, ll m, ll k)
{
	sort(v.begin(), v.end());

	ll ret = 0;

	if(m == 1)
	{
		return v.size();
	}

	for(ll i = 0; i < n; i++)
	{
		ll num = k + v[i];

		ll lim = calc(num, n) - i;

		ret = (ret + (lim * (lim - 1) / 2));
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

	precalc();

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		v.clear();
		mp.clear();

		cin >> n;

		m = 3;
		k = 2;

		v.resize(n);

		for(auto &it: v)
		{
			cin >> it;
			mp[it]++;
		}

		ans = solve(n,m,k);

		cout << ans << "\n";
    }


}



