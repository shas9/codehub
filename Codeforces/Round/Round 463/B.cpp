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

#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld 99999999999999999
#define mnlld -99999999999999999

#define mxd 99999999
#define mnd 99999999

#define pi 3.14159265359

#define mx 1000005


using namespace std;

ll dp[mx];
ll store[mx];

vector < ll > cnt[100];


ll solve(ll val)
{
    if(dp[val] != -1)
    {
        return dp[val];
    }

    ll temp = val;

    ll ans = 1;

    while(temp != 0)
    {
        ll mod = temp % 10;

        if(mod != 0)
        {
            ans *= mod;
        }

        temp /= 10;
    }

    dp[val] = solve(ans);

}
void precalc()
{
    ll i, j;

    for(i = 1; i <= 9; i++)
    {
        dp[i] = i;
    }

    for(i = 1; i <= mx - 5; i++)
    {
        store[i] = solve(i);
    }
}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    memset(dp,-1,sizeof(dp));
    memset(store,0,sizeof(store));

    precalc();

    for(i = 1; i <= 9; i++)
    {
        cnt[i].clear();
    }

    for(i = 1; i <= 1000000; i++)
    {
        ll x = store[i];
//
//        cout << " - " << x;
        cnt[x].pb(i);
    }

    for(i = 1; i <= 9; i++)
    {
        sort(cnt[i].begin(),cnt[i].end());
    }

    slld(testcase);
    ll r;

    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(l);
        slld(r);
        slld(k);

        vector < ll > :: iterator low, high;

        low = lower_bound(cnt[k].begin(),cnt[k].end(),l);
        high = upper_bound(cnt[k].begin(),cnt[k].end(),r);

        ans = (high - cnt[k].begin()) - (low - cnt[k].begin());

        plld(ans);
    }


}


