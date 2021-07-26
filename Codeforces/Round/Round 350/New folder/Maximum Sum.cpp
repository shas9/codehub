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
#define mx 100005
using namespace std;

ll arr[mx];
pair < ll, ll > tree[mx*3];
vector < ll > ch;
void init(ll node, ll b, ll e)
{
    if(b == e)
    {
        tree[node].first = arr[b];
        tree[node].second = 0;
        return;
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    init(left, b, mid);
    init(right, mid + 1, e);

    ch.clear();

    ch.pb(tree[left].first);
    ch.pb(tree[left].second);
    ch.pb(tree[right].first);
    ch.pb(tree[right].second);

    sort(ch.begin(),ch.end());

    tree[node].first = ch[3];
    tree[node].second = ch[2];

}

void update(ll node, ll b, ll e, ll i, ll val)
{
    if(i > e || i < b)
    {
        return;
    }

    if(b == i && e == i)
    {
        tree[node].first = val;
        return;
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    update(left, b, mid, i, val);
    update(right, mid + 1, e, i, val);

    ch.clear();

    ch.pb(tree[left].first);
    ch.pb(tree[left].second);
    ch.pb(tree[right].first);
    ch.pb(tree[right].second);

    sort(ch.begin(),ch.end());

    tree[node].first = ch[3];
    tree[node].second = ch[2];
}

pair < ll, ll > maxi(ll node, ll b, ll e, ll i, ll j)
{
    if(i > e || j < b)
    {
        return make_pair(0,0);
    }

    if(b >= i && e <= j)
    {
        return tree[node];
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    pair < ll, ll > p1 = maxi(left, b, mid, i, j);
    pair < ll, ll > p2 = maxi(right, mid + 1, e,i, j);

    ch.clear();

    ch.pb(p1.first);
    ch.pb(p2.first);
    ch.pb(p1.second);
    ch.pb(p2.second);

    sort(ch.begin(),ch.end());

    return make_pair(ch[3],ch[2]);
}

int main()
{
    ll i, j, k, l, m, n, o, q;
    ll testcase;
    ll input, flag, tag;

    slld(n);

    for(i = 1; i <= n; i++) slld(arr[i]);

    init(1,1,n);

    slld(m);

    for(i = 1; i <= m; i++)
    {
        char c;
        ll x, y;

        scanf(" %c %lld %lld", &c, &x, &y);

        if(c == 'U')
        {
            update(1,1,n,x,y);
            continue;
        }

        pair < ll, ll > ans = maxi(1,1,n,x,y);

        plld(ans.first + ans.second);
    }
}



