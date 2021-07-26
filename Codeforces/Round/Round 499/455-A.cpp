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

ll freq[100005];
ll dp[100005];

ll solve(ll pos)
{
    if(pos > 100000) return 0;


//    cout << pos << endl;

    if(dp[pos] != -1) return dp[pos];

    return dp[pos] = max(solve(pos + 1) , freq[pos] + solve(pos + 2));
}


int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    slld(n);

    for(i = 1; i <= n; i++)
    {
        slld(input);

        freq[input] += input;
    }

    memset(dp,-1,sizeof dp);

    ans = solve(1);

    cout << ans << endl;


}






