#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)
#define plld(longvalue) printf("%lld\n", longvalue)

#define sd(longvalue) scanf("%d", &longvalue)
#define pd(longvalue) printf("%d\n", longvalue)

#define slf(longvalue) scanf("%lf", &longvalue)
#define plf(longvalue) printf("%lf\n", longvalue)
#define sc(letter) scanf(" %c", &letter)
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
ll tree[mx*3];

void init(ll node, ll b, ll e)
{
//    cout << "Init: " << node << " " << b << " " << e << endl;
    if(b == e)
    {
//        cout << "Check: " << node << " " << arr[b] << endl;
        tree[node] = arr[b];
        return;
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    init(left, b, mid);
    init(right, mid + 1, e);

    tree[node] = max(tree[left],tree[right]);
//    cout << tree[node] << " " << tree[left] << " " << tree[right] << endl;

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

    tree[node] = max(tree[left],tree[right]);
}

ll solve(ll node, ll b, ll e, ll i, ll j)
{
    if(i > e || j < b)
    {
        return -1;
    }

    if(b >= i && e <= j)
    {
        return tree[node];
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    ll p1 = solve(left, b, mid, i, j);
    ll p2 = solve(right, mid + 1, e, i, j);

    //cout << p1 << " " << p2 << endl;

    if(p1 >= 0 && p2 >= 0)
    {
        return max(p1,p2);
    }
    else if(p1 == -1)
    {
        return p2;
    }
    else
    {
        return p1;
    }
}


int main()
{
    ll i, j, k, l, m, n, o, q;
    ll testcase;
    ll input, flag, tag;

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(q);
        tag = 0;

        memset(tree, 0, sizeof(tree));

        memset(arr, 0, sizeof(arr));

        init(1,1,100005);

        printcase(cs);

        ll sz = 0;
        for(i = 1; i <= q; i++)
        {
            char x;

            scanf(" %c", &x);

            if(x == 'A')
            {
                slld(input);

                ++sz;
                update(1,1,100005,sz,input);
            }
            else if(x == 'Q')
            {
                if(sz == 0)
                {
                    printf("Empty\n");
                    continue;
                }
                printf("%lld\n", solve(1,1,100005,1,sz));
            }
            else
            {
                if(sz > 0) --sz;
            }
        }


    }


}

