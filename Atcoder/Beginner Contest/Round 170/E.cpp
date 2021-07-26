// God put a smile upon your face <3

#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb push_back

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 958585860497

#define base 2001487

using namespace std;

bool check(ll n, ll pos)
{
    return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
    return n = n | (1LL << pos);
}

ll tree[1000000];

void init(ll node, ll b, ll e)
{
    if(b == e)
    {
        tree[node] = mxlld;
        return;
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    init(left, b, mid);
    init(right, mid + 1, e);

    tree[node] = min(tree[left], tree[right]);


}

void update(ll node, ll b, ll e, ll i, ll val)
{
    if(i > e || i < b)
    {
        return;
    }

    if(b == i && e == i)
    {
        tree[node] = val;
        return;
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    update(left, b, mid, i, val);
    update(right, mid + 1, e, i, val);

    tree[node] = min(tree[left], tree[right]);
}

ll sum(ll node, ll b, ll e, ll i, ll j)
{
    if(i > e || j < b)
    {
        return mxlld;
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

    return min(p1,p2);


}

multiset < ll > mset[200005];
ll arr[200005];
ll pos[200005];

void pr()
{
    for(ll i = 1; i <= 5; i++)
    {
        cout << i << ": ";

        for(auto it: mset[i]) cout << it << " ";

        cout << endl;
    }
    for(ll i = 1; i <= 5; i++)
    {
        cout << sum(1,1,200000,i,i) << " ";
    }

    cout << endl;
}
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m)
    {
        ll lm = 200000;
        for(i = 1; i <= lm; i++) mset[i].clear();
        init(1,1,lm);

        for(i = 1; i <= n; i++)
        {
            slld(arr[i]);
            slld(pos[i]);

            mset[pos[i]].insert(arr[i]);

            auto it = mset[pos[i]].end();
            it--;

            update(1,1,lm,pos[i],*it);
        }

//		pr();

        for(i = 1; i <= m; i++)
        {
            ll u, v;

            slld(u);
            slld(v);

            mset[pos[u]].erase(arr[u]);

            if(!mset[pos[u]].empty())
            {
                auto it = mset[pos[u]].end();
                it--;
                update(1,1,lm,pos[u],*it);
            }
            else update(1,1,lm,pos[u],mxlld);

//			pr();

            pos[u] = v;

            mset[pos[u]].insert(arr[u]);
            auto it = mset[pos[u]].end();
            it--;
            update(1,1,lm,pos[u],*it);


//			pr();

            printf("%lld\n", sum(1,1,lm,1,lm));
        }
    }


}



