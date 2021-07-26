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


int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    slld(n);
    slld(flag);

    ll cnt = 0;
    ll mx = mnlld;
    ll mn = mxlld;
    ll first;
    ll mnx = mxlld;
    bool on = 0;
    for(i = 1; i<= n; i++)
    {
        slld(input);

        cnt += input;

        if(cnt < 0) on = 1;

        mx = max(mx,cnt);
        mn = min(mn,cnt);
        mnx = min(mnx,input);
    }

    ans = flag - mx + 1;

    //mn = min(mn,mnx);


    if(mn < 0)
    {
        ans = min(flag + mn, ans);
    }

    //if(on) ans--;

    cout << ans << endl;



}


