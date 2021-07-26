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

#define maxn 1500005

using namespace std;

bool grid[maxn];
ll dp1[maxn];
ll dp2[maxn];

void solve(ll n, ll m)
{
    ll i, j, ind;

    for(i = 1; i <= m; i++)
    {
        if(grid[i] == 0) break;

        dp1[i] = 1;
    }

    for(i = 1; i <= n; i++)
    {
        ind = (i - 1) * m;
        ind += 1;

        if(grid[ind] == 0) break;

        dp1[ind] = 1;
    }

    for(i = 2; i <= n; i++)
    {
        for(j = 2; j <= m; j++)
        {
            ind = (i - 1) * m;
            ind += j;

            if(grid[ind] == 0) continue;

            dp1[ind] = dp1[ind - 1] + dp1[ind - m];
            dp1[ind] %= mod;
        }
    }

    for(i = m; i >= 1; i--)
    {
        ind = (n - 1) * m;
        ind += i;

        if(grid[ind] == 0) break;

        dp2[ind] = 1;
    }

    for(i = n; i >= 1; i--)
    {
        ind = i * m;

        if(grid[ind] == 0) break;

        dp2[ind] = 1;
    }

    for(i = n - 1; i >= 1; i--)
    {
        for(j = m - 1; j >= 1; j--)
        {
            ind = (i - 1) * m;
            ind += j;

            if(grid[ind] == 0) continue;

            dp2[ind] = dp2[ind + 1] + dp2[ind + m];

            dp2[ind] %= mod;
        }
    }
}
int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    slld(n);
    slld(m);

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= m; j++)
        {
            char c;
            ll ind = (i - 1) * m;
            ind += j;

            scanf(" %c", &c);

            if(c == '#') grid[ind] = 1;
        }
    }

    solve(n,m);

//    for(i = 1; i <= n; i++)
//    {
//        for(j = 1; j <= m; j++)
//        {
//            ll ind = (i - 1) * m;
//            ind += j;
//
//            cout << ind << ":" << grid[ind] << ":" << dp1[ind] << ":" << dp2[ind] << " ";
//        }
//
//        cout << endl;
//    }

    slld(testcase);

    ll stones, x, y;

    ll ind;
    for(ll cs = 1; cs <= testcase; cs++)
    {
        ans = 0;

        slld(stones);

        for(i = 1; i <= stones; i++)
        {
            slld(x);
            slld(y);

            ind = (x - 1) * m;
            ind += y;

            //cout << ind << endl;

            if(grid[ind] == 0) continue;

            ans += ((dp1[ind] % 1000000007) * (dp2[ind] % 1000000007));
            ans %= 1000000007;
        }

        plld(ans);
    }


}


