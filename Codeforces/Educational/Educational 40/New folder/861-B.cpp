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

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    slld(n);
    slld(m);



    ll mn = mxlld;
    ll mx = mnlld;

    if(n == 1)
    {
        cout << 1 << endl;
        return 0;
    }

    if(m == 0)
    {
        cout <<-1<<endl;

        return 0;
    }

    for(i = 1; i <= m; i++)
    {
        ll u, v;

        slld(u);
        slld(v);

        ll fl = u / v;

        if(u % v)
        {
            fl++;
        }

        mx = max(fl,mx);

        if(v != 1 && u != 1)
        {
            fl = --u / --v;

            mn = min(fl,mn);
        }
    }
            ll ans1 = n / mx;

            if(n % mx)
            {
                ans1++;
            }

            ll ans2 = n / mn;

            if(n % mn)
            {
                ans2++;
            }

            //cout << ans1 << " " << ans2 << endl;
        if(ans1 == ans2)
        {
            cout << ans1 << endl;
        }
        else
        {
            cout << -1 << endl;
        }

}

