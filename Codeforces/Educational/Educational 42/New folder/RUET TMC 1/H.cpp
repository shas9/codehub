#include <bits/stdc++.h>

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

int arr[mx];
int tree[mx * 4];

void init(ll node, ll b, ll e)
{
    if(b == e)
    {
        if(arr[b] != 0)
        {
            tree[node] = 1;
        }
        else
        {
            tree[node] = 0;
        }
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
        tree[node]++;
        return;
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    update(left, b, mid, i, val);
    update(right, mid + 1, e, i, val);

    tree[node] = tree[left] + tree[right];
}

ll index(ll node, ll b, ll e, ll value)
{
    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    if(b == e)
    {
        return b;
    }

    if(value > tree[left])
    {
        return index(right, mid + 1, e, value - tree[left]);
    }
    else
    {
        return index(left, b, mid, value);
    }
}

int main()
{
    ll i, j, k, l, m, n, o, q;
    ll testcase;
    ll input, flag, tag;

//    slld(testcase);
//
//    for(ll cs = 1; cs <= testcase; cs++)
//    {
        slld(n);
////        slld(q);
//        tag = 0;

        memset(tree, 0, sizeof(tree));

        memset(arr, 0, sizeof(arr));

        init(1,0,100005);

        for(i = 1; i <= n; i++)
        {
            //slld(n);

            slld(input);

            update(1,0,100005,input,1);

            ll temp1, temp2;
            double ans;

            if(i % 2 == 0)
            {
                temp1 = index(1,0,100005, i / 2);
                temp2 = index(1,0,100005, (i / 2) + 1);

                ans = temp1 + temp2;

                ans /= 2.0;
            }
            else
            {
                temp1 = 0;
                temp2 = index(1,0,100005, (i / 2) + 1);

                ans = temp1 + temp2;

                ans /= 1.0;
            }

            printf("%.1lf\n", ans);

        }


//    }


}
