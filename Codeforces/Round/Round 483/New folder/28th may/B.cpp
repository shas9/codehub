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

struct node
{
    ll x, y, r;

    node(ll _x, ll _y, ll _r)
    {
        x = _x;
        y = _y;
        r = _r;
    }
};

bool comp(node a, node b)
{
    return a.r > b.r;
}

vector < node > arr;
bool check(ll k, ll f)
{
    node n = arr[k];
    node m = arr[f];
	ll rad = (n.r - m.r) * (n.r - m.r);
	ll dist = ((n.x  - m.x) * (n.x  - m.x)) + ((n.y  - m.y) - (n.y  - m.y));

	if(dist <= rad) return 1;
	else return 0;
}

vector < ll > tree[1003];

bool vis[1003];

ll par[1003];

void dfs(bool lev, ll num)
{
    vis[num] = lev;

    for(ll i = 0; i < tree[num].size(); i++)
    {
        dfs(lev ^ 1, tree[num][i]);
    }
}

void maketree(ll n)
{
    memset(par,-1,sizeof par);

    ll i, j;

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            if(arr[j].r > arr[i].r && check(i,j))
            {
                if(par[i] == -1 || arr[par[i]].r > arr[j].r) par[i] = j;
            }
        }

        cout << par[i] << " : " << i << endl;
        tree[par[i]].pb(i);
    }

    //memset(vis,true,sizeof vis);

    for(i = 1; i <= n; i++)
    {
        if(par[i] == -1)
        {
            dfs(false,i);
        }
    }
}
double area(ll i)
{
    double x = arr[i].r * arr[i].r;

    return x;
}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag;

    // freopen("in.txt", "r", stdin);

    slld(n);
    ll x, y, r;

    arr.clear();

    for(i = 1; i <= n; i++)
    {
        slld(x);
        slld(y);
        slld(r);

        arr.pb(node(x,y,r));
    }

    //sort(arr.begin(),arr.end()comp());

    maketree(n);

    double ans = 0;

    for(i = 1; i <= n; i++)
    {
        if(vis[i] == true || par[i] == -1)
        {
            ans += area(i);
        }
        else
        {
            ans -= area(i);
        }
    }

    printf("%.10lf\n", ans);

}


