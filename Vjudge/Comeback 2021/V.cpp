// God put a smile upon your face <3

#include <bits/stdc++.h>

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

char str[55][55];
ll vis[55][55];

bool check(ll px, ll py, ll x, ll y, ll cnt, ll n, ll m)
{
    if(vis[x][y] == cnt) return 1;

    if(vis[x][y] != -1) return 0;

    vis[x][y] = cnt;

    bool ret = 0;

    ll nx = x + 1;
    ll ny = y + 1;

    if(nx <= n && str[x][y] == str[nx][y] && (nx != px || y != py)) ret |= check(x, y, nx, y, cnt, n, m);
    if(ny <= m && str[x][y] == str[x][ny] && (x != px || ny != py)) ret |= check(x, y, x, ny, cnt, n, m);

    nx = x - 1;
    ny = y - 1;

    if(nx >= 1 && str[x][y] == str[nx][y] && (nx != px || y != py)) ret |= check(x, y, nx, y, cnt, n, m);
    if(ny >= 1 && str[x][y] == str[x][ny] && (x != px || ny != py)) ret |= check(x, y, x, ny, cnt, n, m);


    return ret;
}

bool solve(ll n, ll m)
{
    ll cnt = 0;

    for(ll i = 1; i <= n; i++)
    {
        for(ll j = 1; j <= m; j++)
        {
            if(check(-1, -1, i, j, ++cnt, n, m)) return 1;
        }
    }

    return 0;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m)
    {
        for(ll i = 1; i <= n; i++) cin >> str[i] + 1;

        memset(vis,-1,sizeof vis);

        if(solve(n,m)) cout << "Yes\n";
        else cout << "No\n";

    }


}


