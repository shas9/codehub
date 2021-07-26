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
        index(right, mid + 1, e, value - tree[left]);
    }
    else
    {
        index(left, b, mid, value);
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
        slld(n);
        slld(q);
        tag = 0;

        memset(tree, 0, sizeof(tree));

        memset(arr, 0, sizeof(arr));

        for(i = 1; i <= n; i++)
        {
            sd(arr[i]);
        }

        init(1,1,n+q);

        printcase(cs);

        for(i = 1; i <= q; i++)
        {
            char c;

//            cout << "Tree:";
//
//            for(j = 1; j <= 25; j++)
//            {
//                cout << " " << tree[j];
//            }
//
//            cout << endl;

            sc(c);
            if(c == 'c')
            {
                slld(input);

                if(input > tree[1])
                {
                    printf("none\n");
                }
                else
                {

                    ll ans = index(1,1,n + q,input);

                    pd(arr[ans]);

                    update(1,1,n+q,ans,0);
                }


            }
            else
            {
                tag++;

                slld(input);

                arr[n + tag] = input;

                update(1,1,n+q,n+tag,1);


            }
        }


    }


}


