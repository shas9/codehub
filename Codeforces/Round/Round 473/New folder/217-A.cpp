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

ll x[500];
ll y[500];
bool vis[500];

void dfs(ll ind, ll n)
{
    if(vis[ind] == true) return;
    vis[ind] = true;
     for(ll i = 1; i <= n; i++)
     {
         if(x[i] == x[ind] || y[i] == y[ind])
         {
             dfs(i,n);
         }
     }
}
ll solve(ll n)
{
    memset(vis,false,sizeof(vis));

    ll ans = 0;

    for(ll i = 1; i <= n; i++)
        //for(ll j = 1 + i; j <= n; j++)
        {
            if(vis[i] == false)
            {
                ans++;
                dfs(i,n);
            }
        }

        return ans - 1;

}
int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);
    slld(testcase);
    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(x[cs]);
        slld(y[cs]);
    }

    ans = solve(testcase);

    cout << ans << endl;


}


