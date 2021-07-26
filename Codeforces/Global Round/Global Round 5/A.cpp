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

ll arr[20000];
ll dp[20000];
ll ans[20000];
ll testcase;

bool solve(ll pos)
{
    if(pos > testcase)
    {
        if(dp[pos - 1] == 0) return 1;
        else return 0;
    }

    dp[pos] += dp[pos - 1];

    if(arr[pos] % 2 == 0)
    {
        dp[pos] += arr[pos] / 2;
        ans[pos] = arr[pos] / 2;
        return solve(pos + 1);
    }
    else
    {
        dp[pos] += arr[pos] / 2;
        ans[pos] = arr[pos] / 2;

        if(solve(pos + 1))
        {
            return 1;
        }
        else
        {
            if(arr[pos] < 0) dp[pos]--, ans[pos]--;
            else dp[pos]++, ans[pos]++;

            return solve(pos + 1);

        }
    }
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;

    ll input, flag, tag;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    bool on = 0;

    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(arr[cs]);

        solve(1);
    }

    for(ll cs = 1; cs <= testcase; cs++)
    {
        cout << ans[cs] << endl;
    }


}


