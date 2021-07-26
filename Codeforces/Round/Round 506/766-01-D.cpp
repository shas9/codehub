#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)
#define plld(longvalue) printf("%lld\n", longvalue)

#define slf(longvalue) scanf("%lf", &longvalue)
#define plf(longvalue) printf("%lf\n", longvalue)
#define sc(letter) scanf("%c", &letter)
#define pc(letter) printf("%c", letter)

#define ss(name) scanf("%s", name)
#define ps(name) printf("%s", name)

#define pnew printf("\n")

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >
#define pii pair < int, int >

#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009

#define maxn 100005
using namespace std;

bool check(ll n, ll pos)
{
	return n & (1 << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1 << pos);
}

ll par[maxn];
ll anto[maxn];
map < string, ll > mp;

ll fnd(ll x)
{
    if(par[x] == x) return x;

    return par[x] = fnd(par[x]);
}

ll tree(ll u, ll v)
{
    if(u == 0) return v;
    if(v == 0) return u;

    ll px = fnd(u);
    ll py = fnd(v);

    if(px != py) par[px] = py;

    return py;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    while(cin >> n >> m >> q)
    {
        mp.clear();
        string x, y;


        for(i = 1; i <= n; i++)
        {
            cin >> x;

            mp[x] = i;

            par[i] = i;

            anto[i] = 0;
        }

        ll idx, idy, px, py, ax, ay;
        for(i = 1; i <= m; i++)
        {
            cin >> k >> x >> y;

            idx = mp[x];
            idy = mp[y];

            px = fnd(idx);
            py = fnd(idy);

            ax = fnd(anto[px]);
            ay = fnd(anto[py]);

            if(k == 1)
            {
                if(px == ay) cout << "NO" << endl;
                else
                {
                    cout << "YES" << endl;
                    ll p = tree(px,py);
                    ll p1 = tree(ax,ay);

                    anto[p] = p1;
                    anto[p1] = p;
                }
            }
            else
            {
                if(px == py) cout << "NO" << endl;
                else
                {
                    cout << "YES" << endl;
                    ll p = tree(px,ay);
                    ll p1 = tree(py,ax);

                    anto[p] = p1;
                    anto[p1] = p;
                }
            }
        }

        for(i = 1; i <= q; i++)
        {
            cin >> x >> y;

            idx = mp[x];
            idy = mp[y];

            px = fnd(idx);
            py = fnd(idy);

            ax = fnd(anto[px]);
            ay = fnd(anto[py]);

            if(px == py) cout << 1 << endl;
            else if(px == ay) cout << 2 << endl;
            else cout << 3 << endl;
        }
    }

}


