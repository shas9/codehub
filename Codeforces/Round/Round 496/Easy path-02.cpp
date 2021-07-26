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

#define mod 1000000007


using namespace std;

bool check(ll n, ll pos)
{
	return n & (1 << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1 << pos);
}

map < pair < ll, ll > , char > grid;
map < pair < ll, ll >, ll > dp, dp2;

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    //freopen("in.txt", "r", stdin);

    slld(n);
    slld(m);

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= m; j++)
        {
            char ch;

            scanf(" %c", &ch);

            grid[make_pair(i,j)] = ch;
        }
    }

    for(i = 1; i <= n; i++)
    {
        if(grid[make_pair(i,1)] == '.') break;

        dp[make_pair(i,1)] = 1;
    }

    for(i = 1; i <= m; i++)
    {
        if(grid[make_pair(1,i)] == '.') break;

        dp[make_pair(1,i)] = 1;
    }

    for(i = 2; i <= n; i++)
    {
        for(j = 2; j <= m; j++)
        {
            dp[make_pair(i,j)] = dp[make_pair(i - 1, j)] + dp[make_pair(i, j - 1)];
        }
    }

    for(i = n; i >= 1; i--)
    {
        if(grid[make_pair(i,m)] == '.') break;

        dp2[make_pair(i,m)] = 1;
    }

    for(i = m; i >= 1; i--)
    {
        if(grid[make_pair(n,i)] == '.') break;

        dp2[make_pair(n,i)] = 1;
    }

    for(i = n - 1; i >= 1; i--)
    {
        for(j = m - 1; j >= 1; j--)
        {
            dp2[make_pair(i,j)] = dp2[make_pair(i + 1, j)] + dp2[make_pair(i, j + 1)];
        }
    }

//    for(i = 1; i <= n; i++)
//    {
//        for(j = 1; j <= m; j++)
//        {
//            cout << dp[i][j] << ":" << dp2[i][j] << " ";
//        }
//
//        cout << endl;
//    }

    ll q;

    slld(q);

    ll x, y;

    for(i = 1; i <= q; i++)
    {
        slld(k);

        ans = 0;
        for(j = 1; j <= k; j++)
        {
            slld(x);
            slld(y);

            ans += (dp[make_pair(x,y)] % mod) * (dp2[make_pair(x,y)] % mod);

            ans %= mod;
        }

        plld(ans);
    }


}


