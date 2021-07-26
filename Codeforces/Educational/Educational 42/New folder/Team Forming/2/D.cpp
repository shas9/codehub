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

bool tr;

map < ll, ll > dp;

void dfs(ll n, ll l, ll r)
{
    //bug;
    if(n < 0) return;
    if(l > r) return;
    if(tr) return;

    if(n == 0)
    {
        tr = 1;
        return;
    }

    if(n % l == 0)
    {
        tr = 1;
        return;
    }

    dfs(n - l, l, r);
    dfs(n - l, l + 1, r);
    dfs(n, l + 1, r);
}
void solve(ll n, ll l, ll r)
{
    tr = 0;
    dp.clear();

    dfs(n,l,r);
}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    ll r;
    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        cin >> n >> l >> r;
        solve(n,l,r);

        if(tr)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }


}


