#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define nfor(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i, l, r) for (int i = int(l); i < int(r); i++)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define pb(a) push_back(a)
#define mp(x, y) make_pair((x), (y))
#define x first
#define y second

using namespace std;

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

template<typename A, typename B> inline ostream& operator<< (ostream& out, const pair<A, B>& p) { return out << "(" << p.x << ", " << p.y << ")"; }
template<typename T> inline ostream& operator<< (ostream& out, const vector<T>& a) { out << "["; forn(i, sz(a)) { if (i) out << ','; out << ' ' << a[i]; } return out << " ]"; }
template<typename T> inline ostream& operator<< (ostream& out, const set<T>& a) { return out << vector<T>(all(a)); }

inline ld gett() { return ld(clock()) / CLOCKS_PER_SEC; }

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;

int n, k;
vector<int> a;

bool read() {
	if (!(cin >> n >> k)) return false;
	a.resize(n);
	forn(i, n) assert(scanf("%d", &a[i]) == 1);
	return true;
}

const int LOGN = 20, N = (1 << LOGN) + 3;

namespace fftMod {
	typedef int T;
	li mul(li a, li b, li mod) {
		li q = li(ld(a) * b / mod);
		li ans = (a * b - q * mod) % mod;
		return ans < 0 ? ans + mod : ans;
	}
	int mul(int a, int b, int mod) { return int(a * 1ll * b % mod); }
	T add(T a, T b, T mod) { return a + b >= mod ? (a + b - mod) : (a + b); }
	T sub(T a, T b, T mod) { return add(a, mod - b, mod); }
	T gcd(T a, T b, T& x, T& y) {
		if (!a) {
			x = 0, y = 1;
			return b;
		}
		T xx, yy, g = gcd(b % a, a, xx, yy);
		x = yy - b / a * xx;
		y = xx;
		return g;
	}
	T inv(T a, T mod) {
		T x, y;
		assert(gcd(a, mod, x, y) == 1);
		x %= mod;
		(x < 0) && (x += mod);
		return x;
	}
	T binPow(T a, T b, T mod) {
		T ans = 1;
		while (b) {
			if (b & 1) ans = mul(ans, a, mod);
			a = mul(a, a, mod);
			b >>= 1;
		}
		return ans;
	}

	int logn, n;
	T p, g;
	int get(int i) {
		int ans = 0;
		forn(j, logn) if (i & (1 << j)) ans |= 1 << (logn - 1 - j);
		return ans;
	}
	void fft(T *a, bool inverse) {
		forn(i, n) {
			int ni = get(i);
			if (i < ni) swap(a[i], a[ni]);
		}
		assert(binPow(g, n, p) == 1);
		for (int i = 0; i < logn; i++) {
			T cg = binPow(g, 1 << (logn - (i + 1)), p);
			assert(binPow(cg, 1 << (i + 1), p) == 1);
			assert(binPow(cg, 1 << i, p) != 1);
			if (inverse) cg = inv(cg, p);
			for (int j = 0; j < n; j += (1 << (i + 1))) {
				T cur = 1;
				for (int k = 0; k < (1 << i); k++) {
					T u = a[j + k], v = mul(a[j + (1 << i) + k], cur, p);
					a[j + k] = add(u, v, p);
					a[j + (1 << i) + k] = sub(u, v, p);
					cur = mul(cur, cg, p);
				}
			}
		}
		if (inverse) forn(i, n) a[i] = mul(a[i], inv(n, p), p);
	}
	// p                   | deg | g
	// 469762049             26    3
	// 998244353             23    3
	// 1107296257            24    10
	// 10000093151233        26    5
	// 1000000523862017      26    3
	// 1000000000949747713   26    2
	void prepare() {
		p = 469762049; // You can use your own p = c * 2^logn + 1
		g = 3;         // but you should find it's generator
		assert(!((p - 1) & (n - 1)));
		T cs = (p - 1) >> logn;
		g = binPow(g, cs, p);
	}
	void mul(T *a, int na, T *b, int nb, T *ans) {
		while (na && !a[na - 1]) na--;
		while (nb && !b[nb - 1]) nb--;
		logn = 0; while ((1 << logn) < na + nb) logn++;
		n = 1 << logn;

		static T _b[N];
		forn(i, n) ans[i] = a[i], _b[i] = b[i];
		prepare();
		fft(ans, false);
		fft(_b, false);
		forn(i, n) ans[i] = mul(ans[i], _b[i], p);
		fft(ans, true);
	}
};

void mul(int* a, int* b) {
	forn(i, 1 << LOGN) {
		a[i] = !!a[i];
		b[i] = !!b[i];
	}
	fftMod::mul(a, 1 << LOGN, b, 1 << LOGN, a);
}

void binPow(int* a, int b) {
	static int ans[N];
	forn(i, 1 << LOGN) ans[i] = !i;
	while (b) {
		if (b & 1) mul(ans, a);
		mul(a, a);
		b >>= 1;
	}
	forn(i, 1 << LOGN) a[i] = ans[i];
}

void solve() {
	static int ans[N];
	memset(ans, 0, sizeof(ans));
	forn(i, sz(a)) ans[a[i]] = 1;

	binPow(ans, k);

	bool f = true;
	forn(i, 1 << LOGN)
		if (ans[i]) {
			if (f) f = false;
			else putchar(' ');
			printf("%d", i);
		}
	puts("");
}

int main() {
#ifdef SU1
    assert(freopen("input.txt", "rt", stdin));
    //assert(freopen("output.txt", "wt", stdout));
#endif

    cout << setprecision(10) << fixed;
    cerr << setprecision(5) << fixed;

    while (read()) {
		ld stime = gett();
		solve();
		cerr << "Time: " << gett() - stime << endl;
		//break;
	}

    return 0;
}
