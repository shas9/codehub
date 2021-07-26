 // Lights will guide you home

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb push_back

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
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

struct info
{
    ll x, y, r;
};

vector < info > v;
ll vis[1003];
vector < ll > g[1003];

bool dfs(ll node, ll par, bool col)
{
    if(vis[node] != -1)
    {
        return vis[node] == col;
    }

    vis[node] = col ^ 1;

    bool ret = 0;

    for(auto it: g[node])
    {
        if(it != par) ret |= dfs(it,node, col ^ 1);
    }

    return ret;
}

bool connected(ll x, ll y)
{
    ll dist = ((v[x].x - v[y].x) * (v[x].x - v[y].x)) + ((v[x].y - v[y].y) * (v[x].y - v[y].y));
    ll dist2 = (v[x].r + v[y].r) * (v[x].r + v[y].r);

    assert(dist2 <= dist);

    return dist2 == dist;
}

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
        memset(vis,-1,sizeof vis);
        v.resize(n);
        for(ll i = 1; i <= n; i++) g[i].clear();

        for(auto &it: v) cin >> it.x >> it.y >> it.r;

        for(ll i = 0; i < n; i++)
        {
            for(ll j = i + 1; j < n; j++)
            {
                if(connected(i,j))
                {
                    g[i + 1].pb(j + 1);
                    g[j + 1].pb(i + 1);
                }
            }
        }

        if(dfs(1,-1,0)) cout << "The input gear cannot move.\n";
        else if(vis[n] == -1) cout << "The input gear is not connected to the output gear.\n";
        else
        {
            ll x = v[0].r;
            ll y = v[n - 1].r;
            ll g = __gcd(x,y);

            x /= g;
            y /= g;

            if(vis[1] == vis[n]) cout << x << ":" << y << "\n";
            else cout << -x << ":" << y << "\n";
        }

    }


}


