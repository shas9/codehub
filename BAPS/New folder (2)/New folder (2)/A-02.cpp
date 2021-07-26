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

ll dp[30005][550];
ll mp[30005];
ll d;

ll solve(ll cur, ll jump)
{

    if(cur > 30000 || jump == 0) return 0;

    ll flag = jump - d;
    flag += 250;

    if(dp[cur][flag] != -1) return dp[cur][flag];

    ll cnt = 0;

    cnt = max(cnt, solve(cur + jump-1, jump - 1));
    cnt = max(cnt, solve(cur + jump+1, jump + 1));
    cnt = max(cnt, solve(cur + jump, jump));

    cnt += mp[cur];

    return dp[cur][flag] = cnt;
}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("in.txt", "r", stdin);

    memset(dp,-1,sizeof dp);
    memset(mp,0,sizeof mp);

    slld(n);
    slld(d);

    for(i = 1; i <= n; i++)
    {
        slld(input);

        mp[input]++;
    }

    ans = solve(d,d);

    cout << ans << endl;


}




