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
map < string, ll > mp;
ll anto[maxn];
bool vis[maxn];

ll fnd(ll x)
{
    if(par[x] == x) return x;

    return par[x] = fnd(par[x]);
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//     freopen("in.txt", "r", stdin);

    while(cin >> n >> m >> q)
    {
        mp.clear();
        memset(anto, 0, sizeof anto);
        memset(vis, 1, sizeof vis);

        for(i = 1; i <= n; i++) par[i] = i;

        ll idx = 0;
        string x, y;
        for(i = 1; i <= n; i++)
        {
            cin >> x;

            mp[x] = ++idx;
        }

        for(i = 1; i <= m; i++)
        {
            cin >> k >> x >> y;

            ll indx = mp[x];
            ll indy = mp[y];
            ll parx = fnd(indx);
            ll pary = fnd(indy);

            if(vis[indx] && vis[indy])
            {
                vis[indx] = vis[indy] = 0;

                if(k == 2)
                {
                    anto[indx] = indy;
                    anto[indy] = indx;
                }
                else
                {
                    par[indy] = indx;
                }

                cout << "YES" << endl;
            }
            else if(vis[indx])
            {
                ll p = fnd(indy);
                vis[indx] = 0;

                if(k == 1)
                {
                    par[indx] = p;
                }
                else
                {
                    ll temp = anto[p];
                    if(temp == 0) anto[p] = indx;
                    else par[indy] = fnd(temp);
                }

                cout << "YES" << endl;
            }
            else if(vis[indy])
            {
                ll p = fnd(indx);
                vis[indy] = 0;

                if(k == 1)
                {
                    par[indy] = p;
                }
                else
                {
                    ll temp = anto[p];

                    if(temp == 0) anto[p] = indy;
                    else par[indy] = fnd(temp);
                }

                cout << "YES" << endl;
            }
            else
            {
                if(k == 1)
                {
                    if(parx == pary)
                    {
                        cout << "YES" << endl;
                    }
                    else if(parx == fnd(anto[pary]) || pary == fnd(anto[parx]))
                    {
                        cout << "NO" << endl;
                    }
                    else
                    {
                        par[parx] = pary;
                        cout << "YES" << endl;
                    }
                }
                else
                {
                    if(parx == pary)
                    {
                        cout << "NO" << endl;
                    }
                    else if(parx == fnd(anto[pary]) || pary == fnd(anto[parx]))
                    {
                        cout << "YES" << endl;
                    }
                    else
                    {
                        ll p = fnd(indy);
                        ll temp = anto[p];
                        if(temp == 0) anto[p] = indx;
                        else par[indy] = fnd(temp);
                        cout << "YES" << endl;
                    }
                }
            }

            cout << fnd(indx) << " " << fnd(indy) << endl;
        }

        for(i = 1; i <= q; i++)
        {
            cin >> x >> y;

            ll indx = mp[x];
            ll indy = mp[y];
            ll parx = fnd(indx);
            ll pary = fnd(indy);

            if(parx == pary) cout << 1 << endl;
            else if(anto[parx] == pary) cout << 2 << endl;
            else cout << 3 << endl;

        }


    }


}


