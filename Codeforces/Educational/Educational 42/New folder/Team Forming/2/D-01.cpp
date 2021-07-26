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

bool x;

void check(ll n, ll l, ll now, ll r)
{
    if(n < 0) return;
    if(x) return;
    if(now > r) return;
    if(n >= l && n <= r)
    {
        x = 1;
        return;
    }

    if(n % now == 0)
    {
        x = 1;
        return;
    }

    if(n == 0)
    {
        x = 1;
        return;
    }

    check(n - now, l, now + 1, r);
    check(n - now, l, now, r);
    check(n,l,now + 1,r);
}

void solve(ll n, ll l, ll r)
{
    x = 0;
    //check(n,l,l,r);

    if(l > n) return;
    if(l == n)
    {
        x = 1;
        return;
    }
    if(l + l > n) return;

    x = 1;

}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);
    slld(testcase);

    ll r;

    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(n);
        slld(l);
        slld(r);

        solve(n,l,r);

        if(x) cout << "Yes" << endl;
        else cout << "No" << endl;
    }


}

