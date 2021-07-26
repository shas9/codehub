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

#define mod 958585860497

#define base 2001487

using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

namespace fft
{
	// DFS Style

	typedef complex < long double > Complex;
	typedef valarray < Complex > ValComplex;

	const long double PI = 2 * acos(0.0);

	ll res[(1 << 17)];
	ll processed[(1 << 17)];
	ll current[(1 << 17)];
	ValComplex x(1 << 17);


	void init()
	{
		memset(processed,0,sizeof processed);
		memset(current,0,sizeof current);
	}

	void fft(ValComplex &p, bool inverse = 0)
	{
		ll n = p.size();

		if(n <= 1) return;

		ValComplex f = p[slice(0, n/ 2, 2)];
		ValComplex g = p[slice(1, n/ 2, 2)];

		fft(f, inverse);
		fft(g, inverse);

		Complex omega_n = exp(Complex(0, 2 * (PI / n))), w = 1;

		if(inverse) omega_n = Complex(1,0) / omega_n;

		for(ll k = 0; k < (n / 2); k++)
		{
			Complex add = w * g[k];  // Now w = omega_n^k;

			p[k] = f[k] + add; // This is p(x)
			p[k + (n / 2)] = f[k] - add; //Note: p(-x) should be at x + (n / 2) th position

			w *= omega_n; // Increasing the power of w.
		}
	}

	void ifft(ValComplex &p)
	{
		fft(p,1);

		p /= p.size(); // Divide each element by p.size()
	}

	void solve()
	{
		ll sz = (1 << 17);

		for(ll i = 0; i < sz; i++) x[i] = Complex(processed[i], 0);

		fft(x);

		for(ll i = 0; i < sz; i++) x[i] = x[i] * x[i]; ///Multiplying in point-value form

		ifft(x); // Inverse to restore the data

//		for(ll i = 0; i < sz; i++) res[i] = x[i].real() + 0.5; // Flooring up incase 3 becomes 2.9999999999

	}

	void square()
	{
		solve();
	}
}

using namespace fft;

ll arr[100005];
const ll sq = 400;

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		fft :: init();

		slld(n);

		for(i = 1; i <= n; i++) slld(arr[i]);

		ans = 0;

		for(i = 1; i <= n; i += sq)
		{
			ll lft = i, rgt = min(n, i + sq - 1);

			for(j = lft; j <= rgt; j++)
			{
				for(k = j + 1; k <= rgt; k++)
				{
					if(arr[k] > arr[j]) ans += current[arr[k] - arr[j]] + processed[arr[k] - arr[j]];
				}

				current[arr[j]]++;
			}

			fft :: square();

			for(j = lft; j <= rgt; j++)
			{
				ans += fft :: x[arr[j]].real() + 0.5;
			}

			for(j = lft; j <= rgt; j++)
			{
				processed[arr[j]]++;
				current[arr[j]]--;
			}

			printf("%lld\n", ans);
		}
    }


}


