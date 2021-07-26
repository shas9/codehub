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

ll solve(ll vp, ll vd, ll f, ll t, ll c)
{
    ll ans = 0;
    double np = t * vp;
    double nd = 0;

    while(np + vp < c)
    {
        if(np + vp == nd + vd)
        {
            ans++;
            np += vp;
            nd += vd;

            //cout << np << " " << nd << endl;
            np += ((nd / vd) * vp * 2) + (f * vp);
        }
        else if(np + vp < nd + vd)
        {
            ans++;

            double temp = np - nd;
            temp /= vd;
            nd = np;
            np += temp;
            np += ((nd / vd) * vp * 2) + (f * vp);
        }
        else
        {
            np += vp;
            nd += vd;
        }
    }

    return ans;
}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    ll vp, vd, f, t, c;

    cin >> vp >> vd >> t >> f >> c;


    ans = solve(vp, vd, f, t, c);

    cout << ans << endl;


}


