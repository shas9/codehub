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


using namespace std;

bool check(ll n, ll pos)
{
	return n & (1 << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1 << pos);
}
ll dp[2000006];
ll dp2[2000006];

string grid[1000006];

void solve(ll n, ll m)
{
    ll i, j;

    for(i = 0; i < m; i++)
    {
        if(grid[0][i] == '.') break;

        dp[i] = 1;
    }

    for(i = 0; i < n; i++)
    {
        if(grid[i][0] == '.') break;

        //cout << i << " " << 0 << " " << i * m << endl;
        dp[i * m] = 1;
    }

    for(i = 1; i < n; i++)
    {
        for(j = 1; j < m; j++)
        {
            if(grid[i][j] == '.') break;

            ll ind = (i * m) + j;
            dp[ind] = dp[ind - 1] + dp[ind - m];
        }
    }

    for(i = m - 1; i >= 0; i--)
    {
        if(grid[n - 1][i] == '.') break;

        ll ind = (n - 1) * m;

//        cout << n - 1 << " " << i << " " << ind + i << endl;
        dp2[ind + i] = 1;
    }

    for(i = n - 1; i >= 0; i--)
    {
        if(grid[i][m - 1] == '.') break;
        dp2[(i + 1) * m - 1] = 1;
    }

    for(i = n - 2; i >= 0; i--)
    {
        for(j = m - 2; j >= 0; j--)
        {
            if(grid[i][j] == '.') break;

            ll ind = (i * m) + j;
            dp2[ind] = dp2[ind + 1] + dp2[ind + m];
        }
    }
}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

//    while(1)
//    {


    slld(n);
    slld(m);

    for(i = 1; i <= n; i++) cin >> grid[i - 1];

    solve(n,m);

//    for(i = 0; i < n; i++)
//    {
//        for(j = 0; j < m; j++)
//        {
//            ll ind = (i * m) + j;
//            cout << dp[ind] << ":" << dp2[ind] << " ";
//        }
//        cout << endl;
//    }

//    }

    ll q;
    ll stones;
    slld(q);

    ll x, y;
    for(i = 1; i <= q; i++)
    {
        ans = 0;

        slld(stones);

        for(j = 1; j <= stones; j++)
        {
            slld(x);
            slld(y);

            x--;
            y--;

            ans += (dp[x * n + y] % 1000000007) * (dp2[x * n + y] % 1000000007);
            ans %= 1000000007;
        }

        //ans--;
        plld(ans);
    }
}


