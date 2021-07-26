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
#define ull unsigned long long
#define pll pair < long long, long long >
#define pii pair < int, int >

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


#define mx 100005

ll inn;

struct info
{
    ll prop, summ;
} tree[mx*3];

void update(ll node, ll b, ll e, ll i, ll j, ll val)
{
    if(i > e || j < b)
    {
        return;
    }

    if(b >= i && e <= j)
    {
        tree[node].summ |= val;
        tree[node].prop |= val;
        return;
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    update(left, b, mid, i, j, val);
    update(right, mid + 1, e, i, j, val);

    tree[node].summ = (tree[left].summ & tree[right].summ) | tree[node].prop;
}

ll sum(ll node, ll b, ll e, ll i, ll j, ll carry = 0)
{
    if(i > e || j < b)
    {
        return inn;
    }

    if(b >= i && e <= j)
    {
        return tree[node].summ | carry;
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    ll p1 = sum(left, b, mid, i, j, carry | tree[node].prop);
    ll p2 = sum(right, mid + 1, e,i, j, carry | tree[node].prop);

    return p1 & p2;
}

struct node
{
    ll l, r, q;

    node(ll _l, ll _r, ll _q)
    {
        l = _l;
        r = _r;
        q = _q;
    }
};

vector < node > vec;
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    slld(n);
    slld(m);

    inn = 0;

    for(i = 0; i < 40; i++)
    {
        inn += (1LL << i);
    }
    for(i = 1; i <= m; i++)
    {
        slld(l);
        slld(r);
        slld(q);

        vec.push_back(node(l,r,q));

        update(1,1,n,l,r,q);
    }

    for(i = 0; i < m; i++)
    {
        l = vec[i].l;
        r = vec[i].r;
        q = vec[i].q;

        if(sum(1,1,n,l,r) != q)
        {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;

    for(i = 1; i <= n; i++)
    {
        flag = sum(1,1,n,i,i);

        printf("%lld ", flag);
    }

    pnew;

}


