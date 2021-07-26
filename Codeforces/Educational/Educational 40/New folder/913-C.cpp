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

#define mxlld 4e18
#define mnlld -4e18

#define mxd 2e10
#define mnd -2e10

#define pi 3.14159265359

#define mod 1000000009


using namespace std;

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    slld(n);
    slld(l);

    ll arr[50];
    memset(arr,mxlld,sizeof arr);

    for(i = 0; i < n; i++)
    {
        slld(arr[i]);
    }

    ll p[50];
    p[0] = 1;

    for(i = 0; i < 45; i++)
    {
        arr[i + 1] = min(arr[i+1], 2 * arr[i]);
        p[i+1] = 2 * p[i];
    }
    ans = mxlld;
    ll sum = 0;

    for(i = n - 1; i >= 0; i--)
    {
        ll temp = l / p[i];

        sum += (temp * arr[i]);

        l -= (temp * p[i]);

        if(l > 0)
        ans = min(ans, sum + arr[i]);
        else ans = min(ans, sum);

       /// cout << temp << " " << sum << " " << l << " " << ans << " " << sum + (l > 0) * arr[i] << endl;
    }

    cout << ans << endl;


}

