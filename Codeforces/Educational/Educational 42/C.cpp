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

#define mxlld 2e18
#define mnlld -2e18

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009


using namespace std;

string num;

map < ll, ll > mp;

bool vis[100];

map < ll, ll > dp;

ll makenum()
{
    ll flag = 0;

    for(ll i = 0; i < num.size(); i++)
    {
        if(vis[i] == false) continue;

        flag *= 10;
        flag += num[i] - '0';
    }

    return flag;
}
bool check;
ll dfs(ll off)
{
    vis[off] = false;

    ll n = makenum();

    if(n == 0) return  0;

    if(dp[n] != 0) return dp[n];

    cout << n << endl;

    ll sq = (int)sqrt(n);
    if(sq * sq == n)
    {
        check = 1;
        bug;
        return 1;
    }
    //bug;

    ll ans = mxlld;

    for(ll i = 0; i < num.size(); i++)
    {
        if(vis[i] == true)
        {
            ans = min(ans,dfs(i));
            vis[i] = true;
        }
    }

    dp[n] = 1  + ans;
    return dp[n];
}

ll solve()
{
    ll ans = mxlld;

    memset(vis,true,sizeof vis);
    for(ll i = 0; i < num.size(); i--)
    {
        ans = min(ans,dfs(i));
        vis[i] = true;
    }

    return ans;
}
int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    mp.clear();
    dp.clear();

    check = 0;

//    for(i = 1; i <= 100000; i++)
//    {
//        mp[i * i] = i;
//    }

    cin >> num;

    ans = solve();

    if(check == 0)
    {
        cout << -1 << endl;
        return 0;
    }

    cout << ans << endl;


}


