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
    ll i, j, k, l, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    slld(n);
    ll s;
    slld(s);

    ll ph, pm, h, m;
    ll ah = 0, am = 0;
    bool on = 0;

    ph = 0;
    pm = 0;
    for(i = 1; i <= n; i++)
    {
        cin >> h >> m;

        if(on) continue;

        ll diff = ((h - ph) * 60) + (m - pm);

        if(i == 1 && diff >= (s + 1))
        {
            am = 0;
            ah = 0;
            on = 1;
        }
        else if(diff >= (s + 1) * 2)
        {
            //cout << i << endl;
            am = (pm + s + 1);
            ah = ph;

            if(am >= 60)
            {
                ah++;
                am %= 60;
                on = 1;;
            }
        }
        ph = h;
        pm = m;
    }

    if(on == 0)
    {
        am = (pm + s + 1);
        ah = ph;

            if(am >= 60)
            {
                ah++;
                am %= 60;
            }
    }

    cout << ah << " " << am << endl;


}


