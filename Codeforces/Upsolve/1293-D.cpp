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


using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

vector < pair < ll, ll > > vec;

/*

The first line contains integers x0, y0, ax, ay, bx, by (1≤x0,y0≤1016, 2≤ax,ay≤100, 0≤bx,by≤1016), which define the coordinates of the data nodes.

The second line contains integers xs, ys, t (1≤xs,ys,t≤1016) – the initial Aroma's coordinates and the amount of time available.

*/

// (ax⋅xi−1+bx, ay⋅yi−1+by)

    ll x0, y0, ax, ay, bx, by;
    ll xs, ys, t;

bool vis[100];

ll start(ll pos)
{
    memset(vis,0,sizeof vis);

    ll dist = abs(vec[pos].first - xs) + abs(vec[pos].second - ys);

    ll tt = t;

    tt = t - dist;

    vis[pos] = 1;

    ll xx = vec[pos].first;
    ll yy = vec[pos].second;

    ll cnt = 0;

    while(1)
    {
        if(tt < 0) return cnt;

        cnt++;

        ll mndist = mxlld;

        for(ll i = 0; i < vec.size(); i++)
        {
            if(vis[i]) continue;

            dist = abs(xx - vec[i].first) + abs(yy - vec[i].second);

            if(dist < mndist)
            {
                mndist = dist;
                pos = i;
            }
        }

        tt -= mndist;
        vis[pos] = 1;
        xx = vec[pos].first;
        yy = vec[pos].second;
    }
}
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);



    while(cin >> x0 >> y0 >> ax >> ay >> bx >> by >> xs >> ys >> t)
    {
        vec.clear();

        for(i = 0; i < 60; i++)
        {
            vec.push_back(make_pair(x0, y0));

            ll x = (ax * x0) + bx;
            ll y = (ay * y0) + by;

            x0 = x;
            y0 = y;

            if(x0 < 0 || y0 < 0) break;
        }

        ll sz = vec.size();

        ll mx = 0;

        for(i = 0; i < sz; i++)
        {
            mx = max(mx, start(i));
        }

        cout << mx << endl;
    }

}

