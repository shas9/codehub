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

	const ll N = (1 << 18);
	 ll L = (1 << 18);
	 ll LG = 18;

	_complex f[N];
	_complex r[N];
	ll a[N], b[N], c[N], d[N], res[N], rev[N];
	_complex power[2][20][N];
	ll nn, mm, cc;

	void process (void)
	{
		for (ll i = 0; i < L; ++i)
		{
			rev[i] = 0;
			for (ll j = 0; j < LG; ++j)
			{
				if (i & 1 << j)
				{
					rev[i] |= 1 << (LG - 1 - j);
				}
			}
		}

		for (ll dir = 0; dir < 2; ++dir)
		{
			for (ll i = 1; i <= LG; ++i)
			{
				ll l = 1 << i;
				long double theta = 2 * PI / l * (dir ? -1 : 1);
				_complex base(cos(theta), sin(theta));
				power[dir][i][0] = _complex(1, 0);
				for (ll j = 1; j < (l >> 1); ++j)
				{
					power[dir][i][j] = base * power[dir][i][j - 1];
				}
			}
		}
	}

	void fft (ll dir) // dir = 0 forward, dir = 1 backward
	{
		for (ll i = 0; i < L; ++i)
		{
			if (i < rev[i])
			{
				swap(f[i], f[rev[i]]);
			}
		}

		for (ll i = 1; i <= LG; ++i)
		{
			ll l = 1 << i;
			for (ll j = 0; j < L; j += l)
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
			for (ll i = 0; i < L; ++i)
			{
				f[i].x /= L;
				f[i].y /= L;
			}
		}
	}

	void prn()
	{
		for(ll i = 0; i <= mm; i++) cout << a[i] << " ";
		cout << endl;

		for(ll i = 0; i <= mm; i++) cout << b[i] << " ";
		cout << endl;

		for(ll i = 0; i <= mm; i++) cout << c[i] << " ";
		cout << endl;

		for(ll i = 0; i <= mm; i++) cout << d[i] << " ";
		cout << endl;
	}

	void init()
	{
		L = 1;
		LG = 0;

		scanf("%lld%lld%lld", &nn, &mm, &cc);

		if(nn == 0 && mm == 0 && cc == 0)
		{
			exit(0);
		}

		while(L < (mm * 4)) L = L << 1, LG++;

		memset(a,0,sizeof a);

		for(ll i = 2; i * i <= mm; i++)
		{
			if(a[i] == 0)
			{
				a[i] = b[i] = c[i] = d[i] = 0;
				for(ll j = i * i; j <= mm; j += i)
				{
					a[j] = b[j] = c[j] = d[j] = 1;
				}
			}
		}

		process();
	}

	void rem()
	{
		for(ll i = 1; i <= cc; i++)
		{
			string s;

			cin >> s;

			ll num = 0;

			for(ll j = 0; j + 1 < s.size(); j++)
			{
				num *= 10;

				num += (s[j] - '0');
			}

			if(s.back() == 'S' && num <= mm) a[num] = 0;
			if(s.back() == 'H' && num <= mm) b[num] = 0;
			if(s.back() == 'C' && num <= mm) c[num] = 0;
			if(s.back() == 'D' && num <= mm) d[num] = 0;
		}
	}

	void solve()
	{
//		prn();
//		a[0] = b[0] = c[0] = d[0] = 1;

		for(ll i = 0; i < mm; i++) f[i] = _complex(a[i],0);
		for(ll i = mm; i < L; i++) f[i] = _complex(0,0);

		fft(0);

		for(ll i = 0; i < L; i++) r[i] = f[i];

		for(ll i = 0; i < mm; i++) f[i] = _complex(b[i],0);
		for(ll i = mm; i < L; i++) f[i] = _complex(0,0);

		fft(0);

		for(ll i = 0; i < L; i++) r[i] = r[i] * f[i];

		for(ll i = 0; i < mm; i++) f[i] = _complex(c[i],0);
		for(ll i = mm; i < L; i++) f[i] = _complex(0,0);

		fft(0);

		for(ll i = 0; i < L; i++) r[i] = r[i] * f[i];

		for(ll i = 0; i < mm; i++) f[i] = _complex(d[i],0);
		for(ll i = mm; i < L; i++) f[i] = _complex(0,0);

		fft(0);

		for(ll i = 0; i < L; i++) f[i] = f[i] * r[i];

		fft(1);
	}

	void solve1()
	{
//		a[0] = b[0] = c[0] = d[0] = 1;
//		prn();

		for(ll i = 0; i < mm; i++) f[i] = _complex(a[i],0);
		for(ll i = mm; i < L; i++) f[i] = _complex(0,0);

		fft(0);

		for(ll i = 0; i < L; i++) r[i] = f[i];

		for(ll i = 0; i < mm; i++) f[i] = _complex(b[i],0);
		for(ll i = mm; i < L; i++) f[i] = _complex(0,0);

		fft(0);

		for(ll i = 0; i < L; i++) f[i] = r[i] * f[i];

		fft(1);

		for(ll i = 0; i < L; i++) r[i] = f[i];

		for(ll i = 0; i < mm; i++) f[i] = _complex(c[i],0);
		for(ll i = mm; i < L; i++) f[i] = _complex(0,0);

		fft(0);


		for(ll i = 0; i < L; i++) f[i] = r[i] * f[i];

		fft(1);

		for(ll i = 0; i < L; i++) r[i] = f[i];

		for(ll i = 0; i < mm; i++) f[i] = _complex(d[i],0);
		for(ll i = mm; i < L; i++) f[i] = _complex(0,0);

		fft(0);

		for(ll i = 0; i < L; i++) f[i] = f[i] * r[i];

		fft(1);
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

    while(1)
    {
		fft :: init();

		fft :: rem();

		fft :: solve();

		ans = 0;
		for(ll i = fft :: nn; i <= fft :: mm; i++)
		{
			ans = fft :: f[i].x + 0.5;

			printf("%lld\n", ans);
		}

		puts("");
    }


}

