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

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    ll pos, r;

    slld(n);
    slld(pos);
    slld(l);
    slld(r);

    ll mov = 0;


    if(l == 1 && r == n)
    {
        cout << "0" << endl;
        return 0;
    }

    if(l == 1)
    {
        cout << 1 + abs(pos - r) << endl;
        return 0;
    }

    if(r == n)
    {
        cout << 1 + abs(pos - l) << endl;
        return 0;
    }


    if(pos <= l)
    {
        cout << 2 + (r - l) + (l - pos) << endl;

        return 0;
    }

    if(pos >= r)
    {
        cout << 2 + (pos - r) + (r - l) << endl;

        return 0;
    }

    mov = min(pos - l, r - pos);

    ans = 2 + mov + (r - l);

    cout << ans << endl;

}


