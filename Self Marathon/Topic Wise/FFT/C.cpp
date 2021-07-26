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

	const int N = 1e6;
	const int L = (1 << 16);
	const int LG = 16;

	_complex f[N];
	_complex r[N];
	int a[N], rev[N];
	int pref[N], active[N];
	_complex power[2][20][N];
	int proL[L];
	int proR[L];
	int activeL[L];

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

	void init()
	{
		process();

		memset(proL, 0, sizeof proL);
		memset(proR, 0, sizeof proR);
		memset(activeL, 0, sizeof activeL);
	}

	void solve()
	{
		for(ll i = 0; i < L; i++)
		{
			f[i] = _complex(proL[i],0);
		}

		fft(0);

		for(ll i = 0; i < L; i++)
		{
			r[i] = f[i];
		}

		for(ll i = 0; i < L; i++)
		{
			f[i] = _complex(proR[i],0);
		}

		fft(0);

		for(ll i = 0; i < L; i++)
		{
			f[i] = r[i] * f[i];
		}

		fft(1);
	}
}

using namespace fft;

ll arr[100005];

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
		ans = 0;

//		ll sq = sqrt(n) + 1;
		ll sq = (n / 40) + 1;

		for(i = 1; i <= n; i++) slld(arr[i]), fft :: proR[arr[i]]++;

//		bug;

		for(i = 1; i <= n; i += sq)
		{
			ll lft = i, rgt = min(n, i + sq - 1);

			for(j = lft; j <= rgt; j++) assert(proR[arr[j]]), fft :: proR[arr[j]]--;

			for(j = lft; j <= rgt; j++)
			{
				for(k = j + 1; k <= rgt; k++)
				{
					if(arr[j] * 2 > arr[k])
					{
						ans += fft :: proL[arr[j] * 2 - arr[k]] + fft :: activeL[arr[j] * 2 - arr[k]];
					}
				}
				fft :: activeL[arr[j]]++;
			}

			for(j = rgt; j >= lft; j--)
			{
				for(k = j - 1; k >= lft; k--)
				{
					if(arr[j] * 2 > arr[k])
					{
						ans += fft :: proR[arr[j] * 2 - arr[k]];
					}
				}
			}


			fft :: solve();

			ll x = 0;

			for(j = lft; j <= rgt; j++)
			{
				x += fft :: f[arr[j] * 2].x + 0.5;
			}

			ans += x;

			for(j = lft; j <= rgt; j++)
			{
				fft :: activeL[arr[j]]--;
				fft :: proL[arr[j]]++;
			}
		}

		printf("%lld\n", ans);
    }


}



