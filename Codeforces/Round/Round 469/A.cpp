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

    ll a,r;

    ans = 0;

    cin >> l >> r >> a;;

    if(l == 0 && a == 0)
    {
        ans = 0;
    }
    else if(r == 0 && a == 0)
    {
        ans = 0;
    }
    else if(l == 0 && r >= 1)
    {
        ans = min(r,a);
        ans *= 2;
    }
    else if(r == 0 && l >= 1)
    {
        ans = min(l,a);
        ans *= 2;
    }
    else
    {
        ans = l + r + a;

        if(ans % 2 != 0)
        {
            ans--;
        }

        ans /= 2;

        ans = min(l+a, ans);
        ans = min(ans, r + a);

        ans *= 2;
    }


    cout << ans << endl;
}


