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

ll m, n, ans;

vector < ll > a, b;

void solve(ll i, ll va, ll j, ll vb)
{
    if(i >= n || j >= m)
    {
        return;
    }

    if(va == vb && va != 0)
    {
        //cout << va << " " << vb << endl;
        ans++;

        solve(i + 1, a[i+1], j + 1, b[j + 1]);
    }

    else if(va < vb)
    {
        solve(i + 1, va + a[i + 1], j, vb);
    }
    else
    {
        solve(i, va, j + 1, vb + b[j + 1]);
    }
}
int main()
{
    ll i, j, k, l, o;
    ll testcase;
    ll input, flag, tag;

    // freopen("in.txt", "r", stdin);

    cin >> n >> m;

    a.clear();
    b.clear();

    for(i = 0; i < n; i++)
    {
        cin >> input;

        a.pb(input);
    }

    for(i = 0; i < m; i++)
    {
        cin >> input;

        b.pb(input);
    }

    ans = 0;

    solve(0, a[0], 0, b[0]);

    cout << ans << endl;


}

