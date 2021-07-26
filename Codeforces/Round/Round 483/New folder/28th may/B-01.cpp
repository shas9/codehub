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

#define maxn 1005

using namespace std;

struct circle
{
    ll x, y, r;

    circle(ll _x, ll _y, ll _r)
    {
        x = _x;
        y = _y;
        r = _r;
    }
};

vector < circle > arr;
vector < ll > tree[maxn];
ll par[maxn];
bool vis[maxn];

//bool check(ll i, ll j)
//{
//    circle n = arr[i];
//    circle m = arr[j];
//
//    ll rad = (n.r + m.r);
//    rad *= rad;
//
//    ll d = ((n.x - m. x) * (n.x - m. x)) + ((n.y - m.y) * (n.y - m.y));
//
////    if(i == 2)
////    {
////        cout << j << endl;
////        cout << rad << " " << d << endl;
////    }
//
//    if(d > rad) return 0;
//    return 1;
//}

bool check(ll i, ll j)
{
    circle n = arr[i];
    circle m = arr[j];

    ll rad = (n.r - m.r);
    rad *= rad;

    ll d = ((n.x - m. x) * (n.x - m. x)) + ((n.y - m.y) * (n.y - m.y));

//    if(i == 2)
//    {
//        cout << j << endl;
//        cout << rad << " " << d << endl;
//    }

    if(d > rad) return 0;
    return 1;
}

void dfs(ll num, bool lev)
{
    vis[num] = lev;

    for(ll i = 0; i < tree[num].size(); i++)
    {
        dfs(tree[num][i],lev ^ 1);
    }
}
int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag;

    // freopen("in.txt", "r", stdin);

    slld(n);

    arr.pb(circle(0,0,0));
    for(i = 1; i <= n; i++)
    {
        cin >> j >> k >> l;

        arr.pb(circle(j,k,l));
    }

    memset(par,-1,sizeof par);
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            //if(i == j) continue;

            if(arr[j].r > arr[i].r && check(i,j))
            {
//                if(i == 4 || i == 5)
//                {
//                    cout << i << " " <<
//                }
////                cout << j << " -- " << i << endl;
////                cout << arr[j].r << " && " << arr[i].r << endl;
//
//                if(i != 2) continue;

                //cout << i << " " << j << endl;
                if(par[i] == -1 || arr[par[i]].r > arr[j].r)
                {
                    //bug;
                    par[i] = j;
                }
            }
        }

        if(par[i] != -1)
        tree[par[i]].pb(i);

//        cout << i << " " << par[i] << endl;
    }

    for(i = 1; i <= n; i++)
    {
        if(par[i] == -1) dfs(i,0);
    }

    long long ans = 0;

    for(i = 1; i <= n; i++)
    {
        if(vis[i] == true || par[i] == -1)
        {
            //cout << i << endl;
            ans += (arr[i].r * arr[i].r);
        }
        else
        {
            ans -= (arr[i].r * arr[i].r);
        }
    }

    printf("%.10lf\n", (double)ans * acos(-1.0));



}

/*
15
-848 0 848
-758 0 758
-442 0 442
-372 0 372
-358 0 358
-355 0 355
-325 0 325
-216 0 216
-74 0 74
-14 0 14
-13 0 13
51 0 51
225 0 225
272 0 272
664 0 664
*/

