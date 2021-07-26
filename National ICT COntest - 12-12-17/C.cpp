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

#define mxlld 99999999999999999
#define mnlld -99999999999999999

#define mxd 99999999
#define mnd 99999999

#define pi 3.14159265359


using namespace std;

ll arr[100005];

ll cumsum[100005];

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    slld(n);

    for(ll cs = 1; cs <= n; cs++)
    {
        scanf("%lld", &arr[cs]);
    }

    for(ll i = n; i >= 1; i--)
    {
        cumsum[i] = cumsum[i+1] + arr[i];
    }

    ll total = 0;

    for(ll i = 1; i <= n - 1; i++)
    {
        total += (arr[i] * cumsum[i + 1]);
    }

    cout << total << endl;





}


