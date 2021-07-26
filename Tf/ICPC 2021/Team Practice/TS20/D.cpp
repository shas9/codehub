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

char grid[2][101][101];
ll dx[] = {1,1,1,0,0,-1,-1,-1};
ll dy[] = {-1,0,1,-1,1,1,-1,0};

void tranform(ll x, ll n, ll m, ll l, ll r)
{
    for(ll i = 1; i <= n; i++)
    {
        for(ll j = 1; j <= m; j++)
        {
            ll cnt = 0;

            for(ll k = 0; k < 8; k++)
            {
                ll nx = i + dx[k];
                ll ny = j + dy[k];

                if(nx < 1 || nx > n) continue;
                if(ny < 1 || ny > m) continue;
                if(grid[x ^ 1][nx][ny] == '*') cnt++;
            }

            if(cnt >= l && cnt <= r)
            {
                grid[x][i][j] = '*';
            }
            else grid[x][i][j] = '.';
        }
    }

    return;
}

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m)
    {
        cin >> l >> r >> k;

        for(ll i = 1; i <= n; i++) cin >> grid[1][i] + 1;

        for(ll ii = 2; ii <= k; ii++)
        {
            tranform(ii % 2,n,m,l,r);
        }

        for(ll i = 1; i <= n; i++)
        {
            for(ll j = 1; j <= m; j++) cout << grid[k % 2][i][j];

            cout << "\n";
        }

    }


}

