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

	const ll N = 1500000;
	ll L = (1 << 17);
	ll LG = 17;

	_complex f[N];
	ll a[N], res[N], rev[N];
	_complex power[2][21][N];

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
				double theta = 2 * PI / l * (dir ? -1 : 1);
				_complex base(cos(theta), sin(theta));

//				cout << cos(theta) << " " << sin(theta) << '\n';
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

	void init()
	{
		memset(a,0,sizeof a);

		L = (1 << 20);
		LG = 20;

		process();
	}

	void solve()
	{
		for(ll i = 0; i < L; i++) f[i] = _complex(a[i],i);

		fft(0);

		for(ll i = 0; i < L; i++) res[i] = f[i].x + 0.5;
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

		for(ll i = 0; i <= n; i++) slld(fft :: a[i]);

		fft :: solve();

		slld(m);

		for(ll i = 0; i < m; i++)
		{
			slld(input);

			ans = (fft :: res[input]) % 786433;

			printf("%lld\n", ans);
		}
    }

    return 0;

}


