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

char grid1[55][55];
char grid2[55][55];
char grid3[55][55];

bool match1(ll n, ll m)
{
    for(ll i = 1; i <= n; i++)
    {
        for(ll j = 1; j <= m; j++)
        {
            if(grid3[i][j] == '.') continue;

            if(grid3[i][j] != grid1[i][j]) return 0;
        }
    }

    cout << "YES\n";

    for(ll i = 1; i <= n; i++)
    {
        for(ll j = 1; j <= m; j++) cout << grid1[i][j];
        cout << "\n";
    }

    return 1;
}

bool match2(ll n, ll m)
{
    for(ll i = 1; i <= n; i++)
    {
        for(ll j = 1; j <= m; j++)
        {
            if(grid3[i][j] == '.') continue;

            if(grid3[i][j] != grid2[i][j]) return 0;
        }
    }

    cout << "YES\n";

    for(ll i = 1; i <= n; i++)
    {
        for(ll j = 1; j <= m; j++) cout << grid2[i][j];
        cout << "\n";
    }

    return 1;
}

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    for(ll i = 1; i <= 50; i++)
        for(ll j = 1; j <= 50; j++)
            if((i + j) & 1) grid1[i][j] = 'R', grid2[i][j] = 'W';
            else grid1[i][j] = 'W', grid2[i][j] = 'R';

    cin >> testcase;

    for(ll cs = 1; cs <= testcase; cs++)
    {
        cin >> n >> m;

        for(ll i = 1; i <= n; i++) cin >> grid3[i] + 1;

        if(match1(n,m));
        else if(match2(n,m));
        else cout << "NO\n";
    }


}

