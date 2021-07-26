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

#define maxn 500005


using namespace std;

unordered_map < ll , ll > indx;
ll arr[maxn], sorted[maxn];
ll tree[maxn*3];

void init(ll node, ll b, ll e)
{
    if(b == e)
    {
        tree[node] = 0;
        return;
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    init(left, b, mid);
    init(right, mid + 1, e);

    tree[node] = tree[left] + tree[right];


}

void update(ll node, ll b, ll e, ll i, ll val)
{
    if(i > e || i < b)
    {
        return;
    }

    if(b == i && e == i)
    {
        if(val)
        tree[node]++;
        else tree[node]--;

        return;
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    update(left, b, mid, i, val);
    update(right, mid + 1, e, i, val);

    tree[node] = tree[left] + tree[right];
}

ll sum(ll node, ll b, ll e, ll i, ll j)
{
    if(i > e || j < b)
    {
        return 0;
    }

    if(b >= i && e <= j)
    {
        return tree[node];
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    ll p1 = sum(left, b, mid, i, j);
    ll p2 = sum(right, mid + 1, e,i, j);

    return p1 + p2;


}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    slld(n);
    slld(m);

    ll sz = 0;

    for(i = 1;  i <= n; i++) slld(arr[i]), sorted[i] = arr[i];

    sort(sorted + 1, sorted + 1 + n);

    for(i = 1; i <= n; i++)
    {
        if(sorted[i] != sorted[i - 1]) indx[sorted[i]] = ++sz;
    }

//    init(1,1,sz);

    ll cnt = 0;

    for(i = 1; i <= m; i++)
    {
        ll ind = indx[arr[i]];

        cnt += sum(1,1,sz,ind + 1, sz);

        update(1,1,sz,ind,1);
    }

    ll mx = cnt;
    ll pos = 1;

    ll a = 1;

    for(i = m + 1; i <= n; i++)
    {
        ll ind = indx[arr[i]];
        ll ind2 = indx[arr[a]];

        cnt -= sum(1,1,sz, 1, ind2 - 1);
        update(1,1,sz,ind2,0);
        cnt += sum(1,1,sz, ind + 1, sz);
        update(1,1,sz,ind,1);

        a++;

        if(cnt > mx)
        {
            mx = cnt;
            pos = a;
        }
    }

    cout << pos << " " << mx << endl;






}


