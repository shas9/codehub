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


void create(ll node, ll b, ll e)
{
    if (b == e) {
        for (ll i = 0; i < 30; i++)
        {
            ll X = bit(arr[b],i);
            tree[node][i] = X;

//            if (i <= 5)
//                cout << b << " " << i << " " << tree[node][i] << endl;
        }
        return ;
    }

    ll left = node* 2;
    ll right = node*2 + 1;
    ll mid = (b+e)/2;

    create(left, b, mid);
    create(right, mid + 1, e);

    for(ll i = 0; i < 30; i++)
        tree[node][i] = tree[left][i] + tree[right][i];
}

void query(ll node, ll b, ll e, ll i, ll j)
{
    if (e < i || j < b)
        return ;

    if (i <= b && e <= j)
    {
        for(ll k = 0; k < 30; k++)
            one[k] += tree[node][k];
        return ;
    }

    ll left = node*2;
    ll right = node * 2 + 1;
    ll mid = (b+e)/2;

    query(left, b, mid, i, j);
    query(right, mid + 1, e, i, j);
}

void update(ll node, ll b, ll e, ll i, ll val)
{
    if (e < i || i < b)
        return;

    if (i <= b && e <= i) {
        for (ll k = 0; k < 30; k++)
        {
            ll X = bit(val,k);
            tree[node][k] = X;
        }

        return;
    }

    ll left = node*2;
    ll right = node*2 + 1;
    ll mid = (b+e)/2;

    update(left, b, mid, i, val);
    update(right, mid + 1, e, i, val);

    for(ll k = 0; k < 30; k++)
        tree[node][k] = tree[left][k] + tree[right][k];
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

//    init(1,1,n);
    create(1,1,n);

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


        memset(one, 0, sizeof(one));

        query(1,1,n,l,r);

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

