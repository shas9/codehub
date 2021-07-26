// God put a smile upon your face <3

#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%d", &longvalue)

#define ll int
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

const int N = (1 << 18);
int L = (1 << 17);
int LG = 17;

vector < _complex > f[5][5];

vector < _complex > a;

_complex power[2][19][N];
int rev[N];

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

void fft (vector < _complex > &f, int dir = 0) // dir = 0 forward, dir = 1 backward
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

void init(string &s, string &t)
{
    ll x = s.size() + t.size();

    L = 1;
    LG = 0;

    while(L < x) L += L, LG++;

    process();

    a.resize(L);

    for(ll i = 0; i < 5; i++)
    {
        for(ll j = 0; j < s.size(); j++)
        {
            if(s[j] == (i + 'A'))
            {
                a[j] = {1,0};
            }
            else a[j] = {0,0};
        }

        for(ll j = s.size(); j < L; j++)
        {
            a[j] = {0,0};
        }

        fft(a);

        for(ll j = 0; j < 5; j++)
        {

			f[i][j] = a[k];
        }
    }


    for(ll i = 0; i < 5; i++)
    {
        for(ll j = 0; j < t.size(); j++)
        {
            if(t[j] == (i + 'a'))
            {
                a[j] = {1,0};
            }
            else a[j] = {0,0};
        }

        for(ll j = t.size(); j < L; j++)
        {
            a[j] = {0,0};
        }

        fft(a);

        for(ll j = 0; j < 5; j++)
        {
            for(ll k = 0; k < L; k++)
            {
                f[j][i][k] = f[j][i][k] * a[k];
            }

            fft(f[j][i],1);
        }
    }
}

ll solve(ll n, ll m)
{
    ll ret = 0;

    vector < ll > prp;

    prp.resize(5);
    iota(prp.begin(),prp.end(),0);

    ll cnt = 0;

//		for(auto it: prp) cout << it << " ";
//		cout << endl;

    while(next_permutation(prp.begin(),prp.end()))
    {
        for(ll j = m; j < n; j++)
        {

            ll tmp = 0;


            for(ll i = 0; i < 5; i++)
            {
                tmp += f[i][prp[i]][j].x + 0.5;
            }

            ret = max(ret,tmp);
        }

    }

//    cout << ret << endl;
    ret = m - ret;

    return ret;
}

}

using namespace fft;

string s, t;

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> s >> t)
    {
        s += s;

        fft :: init(s,t);

        ans = fft :: solve(s.size(), t.size());

        printf("%d\n", ans);
    }


}


