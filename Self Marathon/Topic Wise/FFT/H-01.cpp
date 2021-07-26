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

//#define mod 958585860497

//#define base 2001487

using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

namespace ntt
{
	const int G = 3;
	const int MOD = 998244353;
	const int N = (1 << 21) + 5;

	int rev[N], w[N], inv_n;
	int a[N];

	void init()
	{
		memset(a,0,sizeof a);
	}

	int bigMod (int a, int e, int mod)
	{
		if (e == -1) e = mod - 2;
		int ret = 1;
		while (e)
		{
			if (e & 1) ret = (ll) ret * a % mod;
			a = (ll) a * a % mod;
			e >>= 1;
		}
		return ret;
	}

	void prepare (int &n)
	{
		int sz = abs(31 - __builtin_clz(n));
		int r = bigMod(G, (MOD - 1) / n, MOD);
		inv_n = bigMod(n, MOD - 2, MOD), w[0] = w[n] = 1;
		for (int i = 1; i < n; ++i) w[i] = (ll) w[i - 1] * r % MOD;
		for (int i = 1; i < n; ++i) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (sz - 1));
	}

	void ntt (int n, int dir)
	{
		for (int i = 1; i < n - 1; ++i)
		{
			if (i < rev[i]) swap(a[i], a[rev[i]]);
		}
		for (int m = 2; m <= n; m <<= 1)
		{
			for (int i = 0; i < n; i += m)
			{
				for (int j = 0; j < (m >> 1); ++j)
				{
					int &u = a[i + j], &v = a[i + j + (m >> 1)];
					int t = (ll) v * w[dir ? n - n / m * j : n / m * j] % MOD;
					v = u - t < 0 ? u - t + MOD : u - t;
					u = u + t >= MOD ? u + t - MOD : u + t;
				}
			}
		}
		if (dir) for (int i = 0; i < n; ++i) a[i] = (ll) a[i] * inv_n % MOD;
	}

	void solve(ll k)
	{
		ll sz = 1;

		while(sz <= (k * 1000)) sz += sz;

		ntt(sz, 0);

		for(ll i = 0; i < sz; i++)
		{
			a[i] = bigMod(a[i],k,MOD);
		}

		ntt(sz, 1);
	}
}

using namespace ntt;


int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m)
    {
		ntt :: init();

		for(i = 1; i <= n; i++)
		{
			slld(input);

			ntt :: a[input] = 1;
		}

		ntt :: solve(m);

		for(i = 0; i < (m * 1000); i++)
		{
			if(a[i] > 0) printf("%lld ", i);
		}

		printf("\n");
    }


}



