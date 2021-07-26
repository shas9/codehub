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

bool bit(ll x, ll i)
{
    return x & (1LL << i);
}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    vector < ll > arr;

    arr.clear();

    ll x, d;

    cin >> x >> d;

    n = 1;

    for(i = 0; i <= 50; i++)
    {
        if(bit(x,i))
        {
            //cout << i << " - " << endl;
            for(j = 1; j <= i; j++)
            {
                arr.pb(n);
            }

            arr.pb(n + d + 1);

            n += 2 * (d + 1);
        }
    }

    m = arr.size();

    cout << m << endl;

    for(i = 0; i < m; i++) cout << arr[i] << " ";




}

