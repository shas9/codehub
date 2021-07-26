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
	// bfs style

	struct _complex
	{
		long double x, y;

		_complex () : x(0.0), y(0.0) {}
		_complex (long double _x, long double _y) : x(_x), y(_y) {}

		const _complex operator + (const _complex &z)
		{
			return _complex(x + z.x, y + z.y);
		}

		const _complex operator - (const _complex &z)
		{
			return _complex(x - z.x, y - z.y);
		}

		const _complex operator * (const _complex &z)
		{
			return _complex(x * z.x - y * z.y, x * z.y + y * z.x);
		}
	};

	const long double PI = acos(-1);

	const int N = 1e6;
	int L = (1 << 15);
	int LG = 15;

	_complex f[N], r[N];
	int a[N], b[N], res[N], rev[N];
	_complex power[2][20][N];
	int n, m;

	void process (void)
	{
		for (int i = 0; i < L; ++i)
		{
			rev[i] = 0;
			for (int j = 0; j < LG; ++j)
			{
				if (i & 1 << j)
				{
					rev[i] |= 1 << (LG - 1 - j);
				}
			}
		}

		for (int dir = 0; dir < 2; ++dir)
		{
			for (int i = 1; i <= LG; ++i)
			{
				int l = 1 << i;
				long double theta = 2 * PI / l * (dir ? -1 : 1);
				_complex base(cos(theta), sin(theta));
				power[dir][i][0] = _complex(1, 0);
				for (int j = 1; j < (l >> 1); ++j)
				{
					power[dir][i][j] = base * power[dir][i][j - 1];
				}
			}
		}
	}

	void fft (int dir) // dir = 0 forward, dir = 1 backward
	{
		for (int i = 0; i < L; ++i)
		{
			if (i < rev[i])
			{
				swap(f[i], f[rev[i]]);
			}
		}

		for (int i = 1; i <= LG; ++i)
		{
			int l = 1 << i;
			for (int j = 0; j < L; j += l)
			{
				_complex z, *w = power[dir][i];
				_complex *u = f + j, *v = f + j + (l >> 1);
				_complex *lim = f + j + (l >> 1);
				while (u != lim)
				{
					z = *v * *w;
					*v = *u - z;
					*u = *u + z;
					++u, ++v, ++w;
				}
			}
		}

		if (dir == 1)
		{
			for (int i = 0; i < L; ++i)
			{
				f[i].x /= L;
				f[i].y /= L;
			}
		}
	}

	void init()
	{
		process();
	}

	void check()
	{
		for(ll i = 0; i <= 20; i++) cout << i << ": " << rev[i] << endl;
	}

	void solve()
	{

		L = 1;
		LG = 0;

		while(L < (n + m - 1)) L = L << 1, LG++;

		init();

		for(ll i = 0; i < n; i++) f[i] = _complex(a[i],0);
		for(ll i = n; i < L; i++) f[i] = _complex(0,0);

		fft(0);

		for(ll i = 0; i < L; i++) r[i] = f[i];

//		for(ll i = 0; i < n; i++) cout << a[i] << " ";
//		cout << endl;
//
//		for(ll j = 0; j < m; j++) cout << b[j] << " ";
//		cout << endl;

		for(ll i = 0; i < m; i++) f[i] = _complex(b[i],0);
		for(ll i = m; i < L; i++) f[i] = _complex(0,0);

		fft(0);

		for(ll i = 0; i < L; i++) f[i] = r[i] * f[i];

		fft(1);

		for(ll i = 0; i < L; i++) res[i] = f[i].x + 0.5;

//		for(ll i = 0; i < 5; i++) cout << res[i] << " " << f[i].x << endl;

	}
}

using namespace fft;
string s, t, out;

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);


//	fft :: init();
//	fft :: check();

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		cin >> s >> t;

		fft :: n = s.size();
		fft :: m = t.size();


		for(i = 0; i < s.size(); i++) a[i] = s[s.size() - i - 1] - '0';
		for(i = 0; i < t.size(); i++) b[i] = t[t.size() - i - 1] - '0';

		fft :: solve();

		ll carry = 0;

		out = "";

		for(ll i = 0; i < (fft :: n + fft :: m - 1); i++)
		{
//			cout << res[i] << " ";
			carry += res[i];

			out += (carry % 10) + '0';

			carry /= 10;
		}

//		cout << endl;

		while(carry)
		{
			out += (carry % 10) + '0';

			carry /= 10;
		}

		while(out.back() == '0') out.pop_back();

		if(out.empty()) out = '0';

		reverse(out.begin(),out.end());

		cout << out << '\n';
	}


}


