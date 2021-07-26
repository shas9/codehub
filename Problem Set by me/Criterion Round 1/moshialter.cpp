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

ll dp[1000006];

void solve(ll num)
{
    for(ll i = 2; i <= 1000000; i++)
    {
        ll xx = i;

        dp[xx] = min(dp[xx], dp[xx - 1] + 1);

        if(xx % 2 == 0)
        {
            dp[xx] = min(dp[xx], dp[xx / 2] + 1);
        }
        else
        {
            dp[xx] = min(dp[xx], dp[xx + 1] + 1);
        }

        if(xx * 2 <= 1000000)
        {
            dp[xx * 2] = min(dp[xx * 2], dp[xx] + 1);
        }
    }
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

    slld(testcase);


    for(i = 1; i <= 1000000; i++)
    {
        dp[i] = mxlld;
    }

    dp[1] = 0;

    solve(2);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(n);

        ans = dp[n];

        cout << ans << endl;
    }


}



