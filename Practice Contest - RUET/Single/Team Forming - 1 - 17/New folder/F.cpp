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


using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}


#define mx 100005

struct dd
{
    ll t, tt, f;
};

ll solve(ll x, dd div)
{
    //while(div > 1)
    {
        while(div.t)
        {
            div.t--;

            if(x % 2 == 0) x/= 2;
            else break;

            if(x == 1) return 1;
        }

        while(div.tt)
        {
            div.tt--;

            if(x % 3 == 0) x/= 3;
            else break;

            if(x == 1) return 1;
        }

        while(div.f)
        {
            div.f--;

            if(x % 5 == 0) x/= 5;
            else break;

            if(x == 1) return 1;
        }
    }

    return x;
}

struct info
{
    dd prop;
    ll val;
} tree[mx*3];

ll arr[mx];

void init(ll node, ll b, ll e)
{
    if(b == e)
    {
        tree[node].val = arr[b];
        return;
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    init(left, b, mid);
    init(right, mid + 1, e);

}

void update(ll node, ll b, ll e, ll i, ll j, ll val)
{
    if(i > e || j < b)
    {
        return;
    }

    if(b >= i && e <= j)
    {
        if(val == 2) tree[node].prop.t++;
        else if(val == 3) tree[node].prop.tt++;
        else if(val == 5) tree[node].prop.f++;
        return;
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    update(left, b, mid, i, j, val);
    update(right, mid + 1, e, i, j, val);
}

void update_2(ll node, ll b, ll e, ll i, ll val, dd carry)
{
    tree[node].prop.t += carry.t;
    tree[node].prop.f += carry.f;
    tree[node].prop.tt += carry.tt;

    if(i > e || i < b)
    {
        return;
    }

    if(b == i && e == i)
    {
        tree[node].val = val;
        tree[node].prop.t = tree[node].prop.f = tree[node].prop.tt = 0;
        return;
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    dd x;
        x.t = carry.t + tree[node].prop.t;
        x.f = carry.f + tree[node].prop.f;
        x.tt = carry.tt + tree[node].prop.tt;

    update_2(left, b, mid, i, val, x);
    update_2(right, mid + 1, e, i, val, x);

    tree[node].prop.t = tree[node].prop.f = tree[node].prop.tt = 0;
}

ll sum(ll node, ll b, ll e, ll i, dd carry)
{
    if(i > e || i < b)
    {
        return 1;
    }

    if(b == i && e == i)
    {

    dd x;
        x.t = carry.t + tree[node].prop.t;
        x.f = carry.f + tree[node].prop.f;
        x.tt = carry.tt + tree[node].prop.tt;

        return solve(tree[node].val, x);
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;


    dd x;
        x.t = carry.t + tree[node].prop.t;
        x.f = carry.f + tree[node].prop.f;
        x.tt = carry.tt + tree[node].prop.tt;

    ll p1 = sum(left, b, mid, i, x);
    ll p2 = sum(right, mid + 1, e,i, x);

    return p1 * p2;
}


void prrr(ll n)
{
    for(ll i = 1; i <= 5; i++)
    {
        cout << tree[i].prop.t << " -- ";
    }

    cout << endl;

    for(ll i = 1; i <= 3; i++)
    {
        dd x;
        cout << sum(1,1,n,i,x) << " - ";
    }

    cout << endl;
}



int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);

    slld(n);

    for(i = 1; i <= n; i++)
    {
        slld(arr[i]);
    }

    init(1,1,n);

    slld(m);

//    bug;
    for(i = 1; i <= m; i++)
    {
        slld(flag);

        slld(l);
        slld(r);

        dd d;
        d.t = 0;
        d.f = 0;
        d.tt = 0;

        if(flag == 1)
        {
            slld(q);

            update(1,1,n,l,r,q);
        }
        else
        {
            update_2(1,1,n,l,r,d);
        }

//        prrr(n);
    }

    for(i = 1; i <= n; i++)
    {
        dd d;
        d.t = 0;
        d.f = 0;
        d.tt = 0;
        ll x = sum(1,1,n,i,d);

        if(i != 1) printf(" ");

        printf("%lld", x);
    }

    printf("\n");


}



