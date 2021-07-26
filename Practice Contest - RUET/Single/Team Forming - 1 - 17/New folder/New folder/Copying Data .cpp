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

#define num 100000
int a[num+5];
int b[num+5];

int tree[num*4];

void build(ll n, ll b, ll e)
{
    if(b==e)
    {
        tree[n]=0;
        return;
    }

    ll l, r, m;

    l=n<<1;
    r=l+1;
    m=(b+e)>>1;

    build(l, b, m);
    build(r, m+1, e);

    tree[n]=0;
}

void update(ll n, ll b, ll e, ll i, ll j, ll p, ll y)
{
    if(j<b || e<i)
        return;

    if(i<=b && e<=j)
    {
        tree[n]=p;
        return;
    }

    ll l, r, m;

    l=n<<1;
    r=l+1;
    m=(b+e)>>1;

    if(tree[n]>0)
    {
        tree[l]=tree[n];
        tree[r]=tree[n]+(m-b+1);
        tree[n]=0;
    }

//    cout<<"u1 "<<l<<" "<<b<<" "<<m<<" "<<i<<" "<<j<<" "<<p<<endl;

    update(l, b, m, i, j, p, y);
//    cout<<"u2 "<<r<<" "<<m+1<<" "<<e<<" "<<i<<" "<<j<<" "<<p+(m-b+1)<<endl;
    int x=0;
    if(y<=m)
    {
        x=m-y+1;
        y=y+x;
    }

    update(r, m+1, e, i, j, p+x, y);
}

int query(ll n, ll b, ll e, ll pos)
{
    if(b==pos && e==pos)
    {
        return tree[n];
    }

    ll l, r, m;

    l=n<<1;
    r=l+1;
    m=(b+e)>>1;

    if(tree[n]>0)
    {
        tree[l]=tree[n];
        tree[r]=tree[n]+(m-b+1);
        tree[n]=0;
    }
    int x;

    if(pos<=m)
        x=query(l, b, m, pos);
    else
        x=query(r, m+1, e, pos);

//    cout<<"print "<<n<<" "<<x<<" "<<m<<endl;

    return x;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q, x, y;
    ll testcase;
    ll input, flag, tag, ans;

    scanf("%lld %lld", &n, &m);

    for(i=1; i<=n; i++)
    {
        scanf("%d", &a[i]);
    }

    for(i=1; i<=n; i++)
    {
        scanf("%d", &b[i]);
    }

    build(1, 1, n);

    for(i=1; i<=m; i++)
    {
        scanf("%lld", &q);

        if(q==1)
        {
            scanf("%lld %lld %lld", &x, &y, &k);

            update(1, 1, n, y, y+k-1, x, y);
        }
        else
        {
            scanf("%lld", &x);

            flag=query(1, 1, n, x);
//            cout<<"flag= "<<flag<<endl;
            if(flag)
            {
                printf("%d\n", a[flag]);
            }
            else
            {
                printf("%d\n", b[x]);
            }
        }
    }
    return 0;
}



