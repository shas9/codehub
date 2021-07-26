#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%d", &longvalue)
#define plld(longvalue) printf("%d\n", longvalue)

#define slf(longvalue) scanf("%lf", &longvalue)
#define plf(longvalue) printf("%lf\n", longvalue)
#define sc(letter) scanf("%c", &letter)
#define pc(letter) printf("%c", letter)

#define ss(name) scanf("%s", name)
#define ps(name) printf("%s", name)

#define pnew printf("\n")

#define ll int

#define printcase(indexing) printf("Case %d:\n", indexing)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000009


using namespace std;

#define mx 200005

char mp[mx];


#define mx 1000005

struct info
{
    ll prop, summ;
} tree[mx*3];

void update(ll node, ll b, ll e, ll i, ll j)
{
    if(i > e || j < b)
    {
        return;
    }

    if(b >= i && e <= j)
    {
        tree[node].prop ^= 1;

        if(tree[node].prop == 1) tree[node].summ += (e - b + 1);
        else tree[node].summ -= (e - b + 1);

        return;
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    update(left, b, mid, i, j);
    update(right, mid + 1, e, i, j);

    tree[node].summ = tree[left].summ + tree[right].summ + (e - b + 1) * tree[node].prop;
}

ll sum(ll node, ll b, ll e, ll i, ll j, ll carry = 0)
{
    if(i > e || j < b)
    {
        return 0;
    }

    if(b >= i && e <= j)
    {
        return tree[node].summ + carry * (e - b + 1);
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    ll p1 = sum(left, b, mid, i, j, carry + tree[node].prop);
    ll p2 = sum(right, mid + 1, e,i, j, carry + tree[node].prop);

    return p1 + p2;
}

void cle(ll n)
{
    for(ll i = 0; i <= n; i++)
    {
        tree[i].prop = 0;
        tree[i].summ = 0;
    }
}

int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, ans;


        ll len;
        slld(len);

        ll q;

        scanf("%d", &q);


        char c;
        for(i = 1; i <= q; i++)
        {
            scanf(" %c", &c);

            if(c == '0')
            {
                slld(j);
                slld(k);

                update(1,1,len,j,k);

                continue;
            }

            slld(j);
            slld(k);

            ans = sum(1,1,len,j,k);

            plld(ans);
        }


}

