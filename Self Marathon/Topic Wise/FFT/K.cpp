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

	const int N = 300000;
	int L = (1 << 20);
	int LG = 20;

	_complex a[N], c[N], b[N];
	_complex _a[N], _c[N], _b[N];

	int res[N], rev[N];
	_complex power[2][20][N];

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

	void fft(_complex *f, int dir) // dir = 0 forward, dir = 1 backward
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

	void init(int n)
	{
		L = 1;
		LG = 0;

		while(L < (n + n))
		{
			L += L;
			LG++;
		}

		process();

		for(ll i = 0; i < L; i++)
		{
			a[i] = _complex(0,0);
			_a[i] = _complex(0,0);
			b[i] = _complex(0,0);
			_b[i] = _complex(0,0);
			c[i] = _complex(0,0);
			_c[i] = _complex(0,0);
		}
	}

	void solve()
	{
		fft(a,0);
		fft(_a,0);
		fft(c,0);
		fft(_c,0);
		fft(b,0);
		fft(_b,0);

		for(ll i = 0; i < L; i++)
		{
			a[i] = a[i] * _a[i];
			b[i] = b[i] * _b[i];
			c[i] = c[i] * _c[i];
		}

		fft(a,1);
		fft(c,1);
		fft(b,1);

		for(ll i = 0; i < L; i++)
		{
			res[i] = (int)(a[i].x + 0.5) + (int)(c[i].x + 0.5) + (int)(b[i].x + 0.5);
		}
	}
}

using namespace fft;

char s[500005];

int main()
{
    ll i, j, k, l, m, n, o, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);


    while(scanf("%s",s) != EOF)
    {
		n = strlen(s);
//
//		bug;
		fft :: init(n);

//		bug;

		for(ll i = 0; i < n; i++)
		{
			if(s[i] == 'a') a[i] = _complex(1,0), _a[n - i - 1] = _complex(1,0);
			if(s[i] == 'c') c[i] = _complex(1,0), _c[n - i - 1] = _complex(1,0);
			if(s[i] == 'b') b[i] = _complex(1,0), _b[n - i - 1] = _complex(1,0);
		}

//		bug;
		fft :: solve();

		ans = 0;

		for(ll i = n; i < fft :: L; i++)
		{
			ans = max((int)ans, res[i]);

//			cout << i << ": " << res[i] << endl;
		}

		printf("%lld\n", ans);

		for(ll i = n; i < fft :: L; i++)
		{
			if(ans == res[i])
			{
				printf("%lld ", i - (n - 1));
			}
		}

		printf("\n");
    }

    return 0;

}

