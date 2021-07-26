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

namespace fft
{
	// DFS Style

	typedef complex < long double > Complex;
	typedef valarray < Complex > ValComplex;

	const long double PI = 2 * acos(0.0);

	vector < ll > a, b, res;

	void init()
	{
		a.clear();
		b.clear();
		a.resize(60001);
		b.resize(60001);
		res.clear();
	}

	void adda(ll x) { a.push_back(x); }
	void addb(ll x) { b.push_back(x); }

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
		ll n = a.size(), m = b.size();
		ll t = n + m - 1, sz = 1;

		while(sz < t) sz = (sz << 1);

		ValComplex x(sz), y(sz), z(sz);

		for(ll i = 0; i < n; i++) x[i] = Complex(a[i], 0);
		for(ll i = n; i < sz; i++) x[i] = Complex(0, 0); //Resizing first polynomial by inserting 0;

		for(ll i = 0; i < m; i++) y[i] = Complex(b[i], 0);
		for(ll i = m; i < sz; i++) y[i] = Complex(0, 0); //Resizing first polynomial by inserting 0;

		fft(x);
		fft(y);	// Doing fft on both polynomial

		for(ll i = 0; i < sz; i++) z[i] = x[i] * y[i]; ///Multiplying in point-value form

		ifft(z); // Inverse to restore the data

		res.resize(sz);

		for(ll i = 0; i < sz; i++) res[i] = z[i].real() + 0.5; // Flooring up incase 3 becomes 2.9999999999

//		while(!res.empty() && res.back() == 0) res.pop_back(); // Removing Trailing zero
	}
}

using namespace fft;

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

	while(cin >> n)
    {
		fft :: init();

		vector < ll > v;

//		cin >> n;

		for(ll i = 1; i <= n; i++)
		{
			cin >> input;
			fft :: a[input + 30000] = 1;
		}

		cin >> n;

		for(ll i = 1; i <= n; i++)
		{
			cin >> input;
			v.push_back(input);
		}

		cin >> n;

		for(ll i = 1; i <= n; i++)
		{
			cin >> input;
			fft :: b[input + 30000] = 1;
		}

		fft :: solve();

//		for(ll i = 0; i < 10; i++)
//		{
//			cout << i << " : " << fft :: res[i] << endl;
//		}

		ans = 0;

		for(auto it: v)
		{
			ans += fft :: res[(it + 30000) * 2];
		}

		cout << ans << "\n";

    }


}



