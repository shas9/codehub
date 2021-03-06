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

char grid[105][105];

bool solve(ll n)
{
    ll i, j;
    for(i = 2; i < n; i++)
    {
        for(j = 2; j < n; j++)
        {
            if(grid[i][j] == '.') continue;

            if(grid[i - 1][j] == '#' && grid[i + 1][j] == '#' && grid[i][j - 1] == '#' && grid[i][j+1] == '#')
            {
                grid[i + 1][j] = '.';
                grid[i - 1][j] = '.';
                grid[i][j] = '.';
                grid[i][j + 1] = '.';
                grid[i][j - 1] = '.';
            }
        }
    }

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            if(grid[i][j] == '#') return 0;
        }
    }

    return 1;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
        for(i = 1; i <= n; i++)
        {
            scanf("%s", grid[i] + 1);
        }

        if(solve(n)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }


}

