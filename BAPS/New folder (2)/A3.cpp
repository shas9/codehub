#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long

#define mnlld -LLONG_MAX


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
    if(jump-1!=0)
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

    //cout << 6;
    ans = solve(d,d);
    //cout << 5;

    cout << ans << endl;


}





