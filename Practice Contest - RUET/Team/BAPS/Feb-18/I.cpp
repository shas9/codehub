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

ll cx[100005];
ll cy[100005];
ll testcase;

bool check(ll x, ll y, ll qx, ll qy, ll pos)
{
    for(ll i = pos + 1; i <= testcase; i++)
    {
        if((x == cx[i] && qx == cx[i]) || (y == cy[i] && qy == cy[i]))
        {
            return 0;
        }
    }
    if(x == qx || y == qy)
    {
        return 1;
    }

    if(abs(x - qx) == abs(y - qy))
    {
        return 1;
    }

    return 0;


}

int main()
{
//    freopen("queen2.in", "r", stdin);
//    freopen("queen2.out", "w", stdout);
    ll i, j, k, l, m, n, o;
    ll input, flag, tag, ans;

    slld(testcase);

    ll x, y;
    ll qx = 0, qy = 0;
    ans = 0;
    flag = 1;
    ll tempx, tempy;

    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(cx[cs]);
        slld(cy[cs]);
    }

    for(ll cs = 1; cs <= testcase; cs++)
    {
        x = cx[cs];
        y = cy[cs];
        if(check(x,y,qx,qy, cs) && flag)
        {
            ans++;
        }
        else
        {
            break;
        }

        qx = x;
        qy = y;
    }

    plld(ans);


}


