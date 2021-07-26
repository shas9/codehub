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

#define mod 1000000009


using namespace std;

ll arr[300005];

int main()
{
    ll i, j, k, l, m, n, o;
    ll input, flag, tag, ans;

    slld(n);

    arr[0] = 0;
    for(ll cs = 1; cs <= n; cs++)
    {
        slld(arr[cs]);
        arr[cs+n] = arr[cs];
    }

    for(i = 1; i <= n * 2; i++)
    {
        arr[i] += arr[i - 1];
    }

    ll f, s;

    cin >> s >> f;

    ll mx = mnlld, pos;
    f--;
    k = f - s;

    for(i = 1; i <= n; i++)
    {
        ll temp = arr[i + k ] - arr[i - 1];

        if(temp > mx)
        {
            mx = temp;
            pos = (s + n - i + 1) % n;
            if(pos==0) pos = n;
        }

        if(temp == mx)
        {
            tag = (s + n - i + 1) % n;;

            if(tag == 0 ) tag = n;

            pos = min(pos,tag);
        }
    }

    cout << pos <<endl;
}
