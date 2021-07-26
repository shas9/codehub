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

		while(!res.empty() && res.back() == 0) res.pop_back(); // Removing Trailing zero
	}
}

using namespace fft;
