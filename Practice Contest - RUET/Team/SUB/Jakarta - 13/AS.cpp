#include <bits/stdc++.h>

using namespace std;

#define ll long long
ll n, ara[150];
ll dp[110][110];

ll solve(ll stop, ll m)

{
    if(dp[stop + 1][m] != -1)
        return dp[stop + 1][m];
    if(m == 1) {
        //cout << "uguwfu  " << stop << endl;
        return ara[n] - ara[stop + 1];
    }
    ll range = n - m + 1;
    ll start = stop + 1;
    ll mn = 1000000000000000;
    for(ll i = start; i <= range; i++) {
        ll dif = ara[i] - ara[start];
        ll dif2 = solve(i, m - 1);
        ll tmp = dif + dif2;
        mn = min(mn, tmp);
    }

    return dp[stop + 1][m] = mn;

}
int main()

{

    ll t, caseno = 0;
    scanf("%lld", &t);
    while(t--) {
        ll m;
        memset(dp, -1, sizeof(dp));
        scanf("%lld %lld", &n, &m);
        for(ll i = 1; i <= n; i++)
            scanf("%lld", &ara[i]);

        sort(ara + 1, ara + n + 1);
        ll ans = solve(0, m);

        printf("Case #%lld: %lld\n", ++caseno, ans);
    }
    return 0;
}
