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

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009


using namespace std;
ll a, b, t, r;

bool check (ll l, ll m, ll mid)
{
    r = mid;
    ll x = a * (r- l + 1);
    ll y = b * (((r * (r - 1)) / 2) - (( (l - 2) * (l - 1))/ 2));

    bool on = 0;

    if(x + y > (t * m)) on = 1;

    ll z = a + ((r - 1) * b);

    if(z > t) on = 1;

    return on;
}
ll solve(ll l, ll m)
{
    ll low = l, high = 2e6 + 10;

    ll ans = -1;

    while(low <= high)
    {
        ll mid = (low + high) / 2;

        //cout << mid << endl;

        if(check(l,m,mid) == 0)
        {
            //bug;
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return ans;
}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);



   cin >> a >> b >> n;

   for(i = 1; i <= n; i++)
   {
       cin >> l >> t >> m;

       r = solve(l, m);

       cout << r << endl;

   }


}


