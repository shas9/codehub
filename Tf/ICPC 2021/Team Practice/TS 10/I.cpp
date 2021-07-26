
 // Lights will guide you home

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb push_back

#define bug printf("BUG\n")

#define mxlld 1e15
#define mnlld -LLONG_MAX

using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

ll a[501][501];
ll b[501][501];
ll c[501][501];
ll w[501][501];
ll dist[501][501];
ll xs, ys, xe, ye;

ll solve(ll n, ll m)
{
    priority_queue < pair < ll, pll > > pq;

    pq.push({0,{xs,ys}});
    dist[xs][ys] = 0;

    while(!pq.empty())
    {
        pair < ll, pll > top = pq.top();
        pq.pop();

        ll t = top.first * -1;
        pll pos = top.second;
        ll x = pos.first;
        ll y = pos.second;

//        cout << x << " " << y << " " << t << "\n";

////        if(dist[x][y] < t) contCinue;
        if(x == xe && y == ye) return dist[x][y];

        if(x < n)
        {
            ll k = (t % (a[x][y] + b[x][y]));
            ll val = mxlld;

//            cout << val << " + ";

            if(k < a[x][y])
            {
                val = min(val,t);
            }
            else
            {
                val = min(val, t + (a[x][y] + b[x][y] - k));
            }

            val += w[x][y];

            if(dist[x + 1][y] > val)
            {
                dist[x + 1][y] = val;
                pq.push({-val, {x + 1,y}});
            }

//            cout << val << "\n";
        }

        if(x > 1)
        {
            ll k = (t % (a[x][y] + b[x][y]));
            ll val = mxlld;

            if(k < a[x][y])
            {
                val = min(val,t);
            }
            else
            {
                val = min(val, t + (a[x][y] + b[x][y] - k));
            }

            val += w[x - 1][y];

            if(dist[x - 1][y] > val)
            {
                dist[x - 1][y] = val;
                pq.push({-val, {x - 1,y}});
            }
        }

        if(y < m)
        {
            ll k = (t % (a[x][y] + b[x][y]));
            ll val = mxlld;

            if(k >= a[x][y])
            {
                val = min(val,t);
            }
            else
            {
                val = min(val, t + (a[x][y] - k));
            }

            val += c[x][y];

            if(dist[x][y + 1] > val)
            {
                dist[x][y + 1] = val;
                pq.push({-val, {x, y + 1}});
            }
        }

        if(y > 1)
        {
            ll k = (t % (a[x][y] + b[x][y]));
            ll val = mxlld;

            if(k >= a[x][y])
            {
                val = min(val,t);
            }
            else
            {
                val = min(val, t + (a[x][y] - k));
            }

            val += c[x][y - 1];

            if(dist[x][y - 1] > val)
            {
                dist[x][y - 1] = val;
                pq.push({-val, {x,y - 1}});
            }
        }
    }

    assert(0);
}
int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    fastio;

    while(cin >> n >> m >> xs >> ys >> xe >> ye)
    {
        for(ll i = 1; i <= n; i++) for(ll j = 1; j <= m; j++) cin >> a[i][j];
        for(ll i = 1; i <= n; i++) for(ll j = 1; j <= m; j++) cin >> b[i][j];
        for(ll i = 1; i <= n; i++) for(ll j = 1; j < m; j++) cin >> c[i][j];
        for(ll i = 1; i < n; i++) for(ll j = 1; j <= m; j++) cin >> w[i][j];

        for(ll i = 1; i <= n; i++) for(ll j = 1; j <= m; j++) dist[i][j] = mxlld;


        ans = solve(n,m);

        cout << ans << "\n";
    }


}

