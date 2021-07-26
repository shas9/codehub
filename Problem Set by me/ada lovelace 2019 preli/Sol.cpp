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

ll arr[mx];
ll tree[mx*5];

void init(ll node, ll b, ll e)
{
    if(b == e)
    {
        tree[node] = arr[b];
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
        tree[node] = val;
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
    ll i, j, k, l, m, n, o, q;
    ll testcase;
    ll input, flag, tag, ans;

    freopen("rtecase.txt", "r", stdin);

    freopen("output-rtecase.txt", "w", stdout);

    cin >> n >> q;

    assert(1 <= n && n <= 200000);
    assert(1 <= q && q <= 200000);

    for(i = 1; i <= n; i++)
    {
        slld(arr[i]);

        assert(0 <= arr[i] && arr[i] <= 100000);
        if(arr[i])
        {
            update(1,1,n,i,1);
        }
    }

//    cout << tree[1] << endl;
    for(i = 1; i <= q; i++)
    {
        ll type;
        slld(type);
        slld(input);

        assert(1 <= type && type <= 2);
        assert(input <= n && input >= 1);

        if(type == 1)
        {
            arr[input]--;

            if(arr[input] == 0) update(1,1,n,input,0);
        }
        else
        {
            arr[input]++;

            if(arr[input] == 1) update(1,1,n,input,1);
        }

        assert(0 <= arr[input] && arr[input] <= 100000);

        cout << tree[1] << endl;
    }


}



