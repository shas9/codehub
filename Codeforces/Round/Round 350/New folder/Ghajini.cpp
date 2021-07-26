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

#define printcase(indexing, ans) printf("Case %d: %d\n", indexing, ans)

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

void init(ll node, ll b, ll e)
{
    if(b == e)
    {
        tree[node].first = arr[b];
        tree[node].second = arr[b];
        return;
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    init(left, b, mid);
    init(right, mid + 1, e);

    tree[node].first = max(tree[left].first, tree[right].first);
    tree[node].second = min(min(tree[left].first, tree[right].first), min(tree[left].second, tree[right].second));


}

//void update(ll node, ll b, ll e, ll i, ll val)
//{
//    if(i > e || i < b)
//    {
//        return;
//    }
//
//    if(b == i && e == i)
//    {
//        tree[node] = val;
//        return;
//    }
//
//    ll left = node * 2;
//    ll right = (node * 2) + 1;
//    ll mid = (b + e) / 2;
//
//    update(left, b, mid, i, val);
//    update(right, mid + 1, e, i, val);
//
//    tree[node] = tree[left] + tree[right];
//}

pair <ll, ll> sum(ll node, ll b, ll e, ll i, ll j)
{
    if(i > e || j < b)
    {
        return make_pair(-1,INT_MAX);
    }

    if(b >= i && e <= j)
    {
        return tree[node];
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    pair < ll, ll > p1 = sum(left, b, mid, i, j);
    pair < ll, ll > p2 = sum(right, mid + 1, e,i, j);

    return make_pair(max(p1.first,p2.first),min(p1.second,p2.second));


}

int main()
{
    ll i, j, k, l, m, n, o, q, d;
    ll testcase;
    ll input, flag, tag, ans;

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(n);
        slld(d);

        ans = -1;

        for(i = 1; i <= n; i++) slld(arr[i]);

        init(1,1,n);

        for(i = d; i <= n; i++)
        {
            pair < ll, ll > chk = sum(1,1,n,i - d + 1, i);

            //cout << i - d + 1 << " " << i << " " << chk.first << " " << chk.second << endl;

            ans = max(ans,abs(chk.first - chk.second));
        }

        printcase(cs,ans);
    }


}




