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

#define mxlld 100000000000
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009

#define maxn 100005

using namespace std;

ll arr[maxn];

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    slld(n);

    for(i = 1; i <= n; i++)
    {
        slld(arr[i]);
    }

    if(n == 1 || n == 2)
    {
        cout << 0 << endl;
        exit(0);
    }
    bool on;

    if(arr[1] > arr[2]) on = 1;
    else on = 0;

    for(i = 2; i <= n; i++)
    {
        if((arr[i] > arr[i - 1] && on) || (arr[i] < arr[i - 1] && !on))
        {
            cout << -1 << endl;
            return 0;
        }
    }

    ll diff = -1;
    for(i = 2; i <= n; i++)
    {
        diff = max(diff,abs(arr[i] - arr[i - 1]));
    }

    if(ans == mxlld) ans = -1;

    cout << ans << endl;



}



