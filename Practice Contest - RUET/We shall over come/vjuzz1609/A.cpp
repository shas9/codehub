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

    tree[node] = min(tree[left],tree[right]);
//    cout << tree[node] << " " << tree[left] << " " << tree[right] << endl;

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
        return min(p1,p2);
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
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;

    slld(m);

    for(k = 1; k <= m; k++)
    {
        slld(n);
        slld(testcase);

        for(ll cs = 1; cs <= n; cs++)
        {
            slld(arr[cs]);
        }

//        for(i = 1; i <= n; i++)
//        {
//            cout << arr[i] << " ";
//        }

        init(1,1,n);

//        for(i = 0; i <= 10; i++)
//        {
//            cout << tree[i] << endl;
//        }

        printcase(k);

        for(ll cs = 1; cs <= testcase; cs++)
        {
            slld(i);
            slld(j);

            ans = solve(1,1,n,i,j);
            plld(ans);

        }
    }


}


