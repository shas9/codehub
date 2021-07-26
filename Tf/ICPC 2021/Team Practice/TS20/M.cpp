// Lights will guide you home

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define pll pair < ll, ll >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define bug(x) printf("BUG %lld\n", x)
#define pb push_back

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

char grid[1003][1003];
ll vis[1003][1003];

ll dx[] = {1,-1,0,0};
ll dy[] = {0,0,1,-1};

vector < vector < pll > > v;

ll n, m;

void bfs(ll l, ll r, ll cnt)
{
    queue < pll > q;

    q.push({l,r});
    vis[l][r] = cnt;

    v.push_back({});

    while(!q.empty())
    {
        pll top = q.front();
        q.pop();

        v.back().push_back(top);

        for(ll i = 0; i < 4; i++)
        {
            ll nx = top.first + dx[i];
            ll ny = top.second + dy[i];

            if(nx < 1 || nx > n) continue;
            if(ny < 1 || ny > m) continue;

            if(grid[nx][ny] == '#') continue;
            if(vis[nx][ny]) continue;

            vis[nx][ny] = cnt;

            q.push({nx,ny});
        }
    }

}

#define for1(i, stop) for(ll i = 1; i <= stop; ++i)

int main()
{
    ll i, j, k, l, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m >> k)
    {
        for(ll i = 1; i <= n; i++) cin >> grid[i] + 1;
        v.clear();

        memset(vis,0,sizeof vis);

        ll lim = 0;

        for1(j, m) {
            if(vis[1][j]) continue;
            bfs(1,j,1);
        }
        for1(j, m) {
            if(vis[n][j]) continue;
            bfs(n,j,1);
        }
        for1(i, n) {
            if(vis[i][1]) continue;
            bfs(i, 1,1);
        }
        for1(i, n) {
            if(vis[i][m]) continue;
            bfs(i, m,1);
        }
        lim = v.size();

        for(ll i = 1; i <= n; i++)
        {
            for(ll j = 1; j <= m; j++)
            {
                if(grid[i][j] == '#') continue;
                if(vis[i][j]) continue;

                bfs(i,j,1);
            }
        }

        ll sz = v.size();

        for(ll i = lim; i < sz; i++)
        {
            if(v[i].size() < k)
            {
                for(auto it: v[i]) grid[it.first][it.second] = '#';

                //k -= v[i].size();
            }
        }

        for(ll i = 1; i <= n; i++)
        {
            for(ll j = 1; j <= m; j++) cout << grid[i][j];
            cout << "\n";
        }


}


}
