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

#define mx 30005

#define pll pair<ll,ll>

using namespace std;

ll hist[mx];
pll tree[mx * 3];
ll n;

void maketree(ll node, ll b, ll e)
{
    if(b > e)
    {
        return;
    }

    if(b == e)
    {
        tree[node] = make_pair(hist[b], b);
        return;
    }

    ll left = node * 2;
    ll right = node * 2 + 1;
    ll mid = (b + e) / 2;

    maketree(left,b, mid);
    maketree(right, mid + 1, e);

    tree[node] = min(tree[left],tree[right]);
}

pll index(ll node, ll b, ll e, ll i, ll j)
{
    pll x;
    if(j < b || i > e)
    {
        x = make_pair(mxlld,mxlld);

        return x;
    }

    if(b >= i && j >= e)
    {
        return tree[node];
    }

    ll left = node * 2;
    ll right = node * 2 + 1;
    ll mid = (b + e) / 2;

    pll p1 = index(left, b, mid, i, j);
    pll p2 = index(right,  mid + 1,  e,  i, j);

    return min(p1,p2);
}

ll solve(ll i, ll j)
{
    if(i > j)
    {
        return 0;
    }

    pll flag = index(1,1,n,i,j);

    //cout << flag << " " << i << " " << j <<  endl;

    ll a1 = flag.first * (j - i + 1);

    ll a2 = max(solve(i, flag.second - 1), solve(flag.second + 1, j));

    //cout << a1 << " " << a2 << endl;

    return max(a1,a2);
}


int main()
{
    ll i, j, k, l, m, o;
    ll testcase;
    ll input, flag, tag, ans;

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(n);

        for(i = 1; i <= n; i++)
        {
            slld(hist[i]);
        }

        maketree(1,1,n);

        ans = solve(1,n);

        printcase(cs,ans);
    }


}


