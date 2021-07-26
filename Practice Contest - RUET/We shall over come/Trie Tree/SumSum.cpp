#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)
#define plld(longvalue) printf("%lld\n", longvalue)

#define slf(longvalue) scanf("%lf", &longvalue)
#define plf(longvalue) printf("%lf\n", longvalue)
#define sc(letter) scanf("%c", &letter)
#define pc(letter) printf("%c", letter)

#define ss(name) scanf(" %s", name)
#define ps(name) printf("%s", name)

#define pnew printf("\n")

#define ll long long

#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld 2e18
#define mnlld -2e18

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009

#define mx 100005


using namespace std;

ll arr[mx*3];
ll tree[mx*5][36];
ll one[36];

bool bit(ll num, ll pos)
{
    return (num & (1LL << pos));
}

void init(ll node, ll b, ll e)
{
    if(b == e)
    {
        for(ll i = 29; i >= 0; i--)
        {
            ll X = bit(arr[b],i);
            tree[node][i] = X;
        }
        return;
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    init(left, b, mid);
    init(right, mid + 1, e);

    for(ll j = 0; j <= 29; j++)
    {
        tree[node][j] = tree[left][j] + tree[right][j];
    }

}

void update(ll node, ll b, ll e, ll i, ll val)
{
    if(i > e || i < b)
    {
        return;
    }

    if(b == i && e == i)
    {
        for(ll j = 29; j >= 0; j--)
        {
            ll X = bit(val,i);
            tree[node][j] = X;
        }
        return;
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    update(left, b, mid, i, val);
    update(right, mid + 1, e, i, val);

    for(ll j = 0; j <= 29; j++)
    {
        tree[node][j] = tree[left][j] + tree[right][j];
     }
}

void sum(ll node, ll b, ll e, ll i, ll j)
{
    if(i > e || j < b)
    {
        return;
    }

    if(b >= i && e <= j)
    {
        for(ll ind = 0; ind <= 29; ind++)
        {
            one[ind] += tree[node][ind];
            //cout << ind << " - " << one[ind] << " - " << tree[node][ind] << endl;
        }
        return;
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    sum(left, b, mid, i, j);
    sum(right, mid + 1, e, i, j);


}


int main()
{
    ll i, j, k, l, m, n, o, q;
    ll testcase;
    ll input, flag, tag, ans;

    //freopen("in.txt", "r", stdin);

    slld(n);
    slld(q);

    for(ll i = 1; i <= n; i++)
    {
        slld(arr[i]);
    }

    init(1,1,n);

    ll op, pos, r;
    char str[20];
    for(ll i = 1; i <= q; i++)
    {
        slld(op);

        if(op == 1)
        {
            slld(input);
            slld(pos);

            update(1,1,n,pos,input);
            continue;
        }

        ss(str);

        slld(l);
        slld(r);

        if(l > r)
        {
            swap(l,r);
        }

        if(l == r)
        {
            cout << "0" << endl;
            continue;
        }
        ans = 0;

        memset(one,0,sizeof one);

        sum(1,1,n,l,r);

//        for(j = 0; j <= 29; j++)
//        {
//            cout << one[j] << " ";
//        }
//
//        cout << endl;

        ll range = r - l + 1;

        if(str[0] == 'O')
        {
            for(j = 29; j >= 0; j--)
            {
                ll x1 = (one[j] * (one[j] - 1))/ 2;
                ll x2 = one[j] * (range - one[j]);
                ans += ((x1 + x2) * (1LL << j));
            }
        }
        else if(str[0] == 'X')
        {
            for(j = 29; j >= 0; j--)
            {
                ll x2 = one[j] * (range - one[j]);
                ans += (x2 * (1LL << j));
            }
        }
        else if(str[0] == 'A')
        {
            for(j = 29; j >= 0; j--)
            {
                ll x1 = (one[j] * (one[j] - 1))/ 2;
                ans += (x1 * (1LL << j));
            }
        }

         plld(ans);
    }


}


