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
	return n & (1 << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1 << pos);
}

ll dp[1 << 16][16];
ll cost[18];
ll arr[18];
ll n;

ll solve(ll mask, ll last, ll pos)
{
    ll &ret = dp[mask][last];

    if(ret != -1) return ret;

    ret = 0;

    bool on = 0;

    ll i;

    for(i = 0; i < n; i++)
    {
        if(!check(mask,i))
        {
            ll flag = solve(Set(mask,i), i, pos + 1) + (abs(arr[i] - arr[last]) * cost[pos]);

//            cout << last << " " << pos << " " << flag << " " << (abs(arr[i] - arr[last]) * cost[pos]) << endl;
            ret = flag;

            on = 1;
        }

        if(on) break;
    }

    for(; i < n; i++)
    {
        if(!check(mask,i))
        {
            ll flag = solve(Set(mask,i), i, pos + 1) + (abs(arr[i] - arr[last]) * cost[pos]);

//            cout << last << " " << pos << " " << flag << " " << (abs(arr[i] - arr[last]) * cost[pos]) << endl;
            ret = min(ret,flag);

//            on = 1;
        }

//        if(on) break;
    }

    return ret;
}

int main()
{
    ll i, j, k, l, m, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);
    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(n);

        memset(dp,-1,sizeof dp);

        for(i = 0; i < n; i++) slld(arr[i]);
        for(i = 0; i < n; i++) slld(cost[i]);

        if(n == 1)
        {
            cout << 0 << endl;
            continue;
        }


        ans = 10000000000000;

        for(i = 0; i < n; i++)
        {
            ll mask = 0;

            mask = Set(mask,i);

            ans = min(ans, solve(mask,i,1));
        }

        plld(ans);

    }


}


