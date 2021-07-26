#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%d", &longvalue)
#define plld(longvalue) printf("%lld\n", longvalue)

#define slf(longvalue) scanf("%lf", &longvalue)
#define plf(longvalue) printf("%lf\n", longvalue)
#define sc(letter) scanf("%c", &letter)
#define pc(letter) printf("%c", letter)

#define ss(name) scanf("%s", name)
#define ps(name) printf("%s", name)

#define pnew printf("\n")

#define ll int

#define printcase(indexing,ans) printf("Case %d: %d\n", indexing, ans)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld 2e18
#define mnlld -2e18

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009

#define maxn 1000001

using namespace std;

ll nextt[maxn][2];
ll sz;

void cle()
{
   memset(nextt,-1,sizeof(nextt));
    sz=0;
}
void insert(ll x)
{
    ll v=0;

    for(ll i = 31; i >= 0; i--)
    {
        bool b = (x & (1 << (i)));
        ll bit = 0;

        if(b)
        {
            bit = 1;
        }

        //cout << bit << " " << x << " " << i << endl;

        if(nextt[v][bit] == -1)
        {
            nextt[v][bit] = ++sz;
        }
        v = nextt[v][bit];
    }

    //cout << sz << endl;
}

ll q1(ll x)
{
    ll v = 0;
    ll ans = 0;

    for(ll i = 31; i >= 0; i--)
    {
        bool b = (x & (1 << (i)));
        ll bit = 0;

        if(b)
        {
            bit = 1;
        }
        bit ^= 1;

        if(nextt[v][bit] != -1)
        {
            ans |= (1 << (i));
        }
        else
        {
            bit ^= 1;
        }

        v = nextt[v][bit];
    }

    return ans;
}

ll q2(ll x)
{
    ll v = 0;
    ll ans = 0;

    for(ll i = 31; i >= 0; i--)
    {
        bool b = (x & (1 << (i)));
        ll bit = 0;

        if(b)
        {
            bit = 1;
        }


        if(nextt[v][bit] == -1)
        {
            ans |= (1 << (i));
            bit ^= 1;
        }

        v = nextt[v][bit];
    }

    return ans;
}


int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag;

    //freopen("in.txt", "r", stdin);
    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        cle();
        slld(n);

        insert(0);

        ll mn = 2e10;
        ll mx = mnlld;
        ll ans = 0;

        for(i = 1; i <= n; i++)
        {
            slld(input);

            ans ^= input;

            mx = max(mx, q1(ans));
            mn = min(mn, q2(ans));

            insert(ans);
        }

        //cout << mx << " " << mn << endl;
        printcase(cs,mx);
    }


}
