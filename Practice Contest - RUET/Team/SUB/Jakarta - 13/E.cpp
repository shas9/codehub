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

#define printcase(indexing) printf("Case %lld:\n", indexing)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld 99999999999999999
#define mnlld -99999999999999999

#define mxd 99999999
#define mnd 99999999

#define pi 3.14159265359

#define mod 1000000009


using namespace std;
vector < ll > start;
vector < ll > stop;
int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    slld(testcase);
    ll a, b;

    for(ll cs = 1; cs <= testcase; cs++)
    {
        start.clear();
        stop.clear();

        ll q;

        slld(n);
        slld(q);

        ll mna = mxlld, mxb = mnlld;

        for(i = 1; i <= n; i++)
        {
            slld(a);
            slld(b);

            start.pb(a);
            stop.pb(b);

            mna = min(a,mna);
            mxb = max(b,mxb);
        }

        sort(start.begin(),start.end());
        sort(stop.begin(),stop.end());

        printcase(cs);

        for(i = 1; i <= q; i++)
        {
            vector < ll > :: iterator low, high;

            slld(input);

            low = lower_bound(stop.begin(),stop.end(), input);
            high = lower_bound(start.begin(),start.end(),input);

            ll x, y;

            x = low - stop.begin();
            y = high - start.begin();

            ans = y - x;

            ans = abs(ans);

            if(mna == input && mxb == input)
            {
                ans = n;
            }

            if(input < stop[0] && binary_search(start.begin(),start.end(),input))
            {
                ans += 1;
            }

            plld(ans);
        }
    }


}
