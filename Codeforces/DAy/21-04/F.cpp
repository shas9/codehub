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

vector < ll > a, b;
ll p1, p2;

ll b_s(ll n, ll m)
{
    ll high = 1000000003;
    ll low = 0;

    ll ans = mnlld;


    while(low <= high)
    {
        ll mid = (low + high) / 2;

        ll t = lower_bound(a.begin(),a.end(),mid) - a.begin();
        ll s = lower_bound(b.begin(),b.end(),mid) - b.begin();

        ll x = (t * 2) + (n - 1 - t) * 3;
        ll y = (t * 2) + (m - 1 - t) * 3;

        ll diff = x - y;

        if(diff >= ans)
        {
            high = mid - 1;
            ans = mid;
        }
        else
        {
            low = mid + 1;
        }

    }

    return ans;
}
void solve(ll n, ll m)
{
    ll mid = b_s(n,m);

    ll t = lower_bound(a.begin(),a.end(),mid) - a.begin();
    ll s = lower_bound(b.begin(),b.end(),mid) - b.begin();

    ll p1 = (t * 2) + (n - 1 - t) * 3;
    ll p2 = (t * 2) + (m - 1 - t) * 3;


}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    slld(n);

    a.clear();
    b.clear();

    for(i = 1; i <= n; i++)
    {
        slld(input);

        a.push_back(input);
    }

    slld(m);

    for(i = 1; i <= m; i++)
    {
        slld(input);

        b.push_back(input);
    }

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    solve(n,m);

    cout << p1 << ":" << p2 << endl;





}


