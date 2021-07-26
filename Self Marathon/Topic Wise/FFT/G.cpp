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

namespace fft
{
	// bfs style

	struct _complex
	{
		double x, y;

		_complex () : x(0.0), y(0.0) {}
		_complex (double _x, double _y) : x(_x), y(_y) {}

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

	const double PI = acos(-1);

	const int N = 1500000;
	int L = (1 << 17);
	int LG = 17;

	_complex f[N];
	int a[N], b[N], res[N], rev[N];
	_complex power[2][21][N];

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
				double theta = 2 * PI / l * (dir ? -1 : 1);
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

	ll n;

	void init(ll _n)
	{
		L = 1;
		LG = 0;

		n = _n;

		while(L < n) L += L, LG++;

		L += L;
		LG++;

//		cout << L << " " << LG <<endl;

		for(ll i = 0; i < n; i++) a[i] = 0, b[i] = 0;

		for(ll i = 1; i < n; i++)
		{
			ll x = (i * i) % n;
//			cout << i << " = " << i * i << " &init& " << x << endl;

			a[x]++;
			b[(x + x) % n]++;
		}

		process();
	}

	void solve()
	{

		for(ll i = 0; i < n; i++)
		{
			f[i] = _complex(a[i],0);
		}
		for(ll i = n; i < L; i++) f[i] = _complex(0,0);

//		for(ll i = 0; i < L; i++) cout << f[i].x << " ";
//		cout << endl;

		fft(0);

//		for(ll i = 0; i < L; i++) cout << f[i].x << " ";
//		cout << endl;

		for(ll i = 0; i < L; i++) f[i] = f[i] * f[i];

		fft(1);

//		for(ll i = 0; i < L; i++) cout << (int)(f[i].x + 0.5) << " ";
//		cout << endl;

	}

	void run()
	{
		for(ll i = 0; i < n; i++)
		{
			cout << a[i] << " ";
		}

		cout << endl;
	}
}

using namespace fft;

void test(ll n)
{
	ll ans = 0;

	for(ll i = 1; i < n; i++)
	{
		for(ll j = i; j < n; j++)
		{
			for(ll k = 1; k < n; k++)
			{
				ll x = i * i + j * j;
				ll y = k * k;

				x %= n;
				y %= n;

				if(x == y)
				{
					cout << i << " " << j << " " << k << endl;
					ans++;
				}
			}

		}
	}

	cout << ans << endl;


}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

//	while(cin >> input)
//	{
//		test(input);
//	}

    while(cin >> n)
    {
		fft :: init(n);

		ans = 0;

//		fft :: run();

		fft :: solve();

//		test(n);

//		for(ll i = 0; i < fft :: L; i++)
//		{
//			cout << i << " = " << fft :: f[i].x << endl;
//		}

		ll cnt = 0;

		for(ll i = 1; i < n; i++)
		{
			ll need = (i * i) % n;

//			cout << need << endl;

			ll tot = 0;

			tot += fft :: f[need].x + 0.5;
			tot -= fft :: b[need];
			cnt += fft :: b[need];


			while(need + n < fft :: L)
			{
				need += n;

				tot += fft :: f[need].x + 0.5;
			}

			ans += tot / 2;

		}

		printf("%lld\n", ans + cnt);
    }


}


