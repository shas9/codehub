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

ll arr[200005];

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    cin >> n >> k;

    arr[0] = 0;
    for(i = 1; i <= n; i++)
    {
        slld(arr[i]);

        arr[i] += arr[i - 1];
    }

    ll mn = mxlld;
    ll pos = 0;

    for(i = 1; i <= n; i++)
    {
        l = i;
        ll r = i + k - 1;

        if(r > n) break;

        ll sum = arr[r] - arr[l - 1];

        if(sum < mn)
        {
            mn = sum;
            pos = i;
        }
    }

    cout << pos << endl;


}


