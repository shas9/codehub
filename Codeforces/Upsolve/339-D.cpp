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

#define printcase(indexing) printf("Case %lld:\n", indexing)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld 99999999999999999
#define mnlld -99999999999999999

#define mxd 99999999
#define mnd 99999999

#define pi 3.14159265359

#define mod 1000000009
#define mx 200005
using namespace std;

struct base
{
    ll lv, val;
};

ll arr[mx];
base tree[mx*4];

void init(ll node, ll b, ll e)
{
    if(b == e)
    {
        tree[node].val = arr[b];
        tree[node].lv = 1;
        return;
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    init(left, b, mid);
    init(right, mid + 1, e);

    tree[node].lv = tree[left].lv + 1;

    if(tree[node].lv % 2 == 0)
    {
        tree[node].val = tree[left].val | tree[right].val;
    }
    else
    {
        tree[node].val = tree[left].val ^ tree[right].val;
    }

}

void update(ll node, ll b, ll e, ll i, ll val)
{
    if(i > e || i < b)
    {
        return;
    }

    if(b == i && e == i)
    {
        tree[node].val = val;
        return;
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    update(left, b, mid, i, val);
    update(right, mid + 1, e, i, val);

    if(tree[node].lv % 2 == 0)
    {
        tree[node].val = tree[left].val | tree[right].val;
    }
    else
    {
        tree[node].val = tree[left].val ^ tree[right].val;
    }
}

int main()
{
    ll i, j, k, l, m, n, o, q;
    ll testcase;
    ll input, flag, tag, ans;

    slld(n);
    slld(m);

    n = (1 << n);
    for(i = 1; i <= n; i++)
    {
        slld(arr[i]);
    }

    init(1,1,n);

//    cout << " --- " << endl;

    for(ll ii = 1; ii <= m; ii++)
    {
        ll p, b;

        slld(p);
        slld(b);

        update(1,1,n,p,b);

//        for(i = 1; i <= 7; i++)
//        {
//            cout << tree[i].val << " " << tree[i].lv << endl;
//        }

        cout << tree[1].val << endl;
    }


}



