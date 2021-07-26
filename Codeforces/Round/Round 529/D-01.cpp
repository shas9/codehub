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

pll arr[200005];
ll ans[200005];

bool check(ll x, ll y)
{
    if(arr[x].first == y || arr[x].second == y) return 1;
    return 0;
}
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag;

    // freopen("in.txt", "r", stdin);

    while(cin >> n)
    {
        for(i = 1; i <= n; i++)
        {
            slld(arr[i].first);
            slld(arr[i].second);
        }

        ans[1] = 1;

        if(check(arr[1].first, arr[1].second)) ans[2] = arr[1].first, ans[3] = arr[1].second;
        else ans[3] = arr[1].first, ans[2] = arr[1].second;

        i = 2;
        while(i <= n - 2)
        {
            ll x = ans[i];
            ll y = arr[x].first;
            ll z = arr[x].second;

            x = ans[i + 1];

            if(x == y) ans[i + 2] = z;
            else ans[i + 2] = y;

            i++;
        }

        for(i = 1; i <= n; i++) cout << ans[i] << " ";
        cout << endl;
    }


}



