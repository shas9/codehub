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

#define mod 1000000007


using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

#define num 1000000

ll tree[num*4];


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

void update(ll n, ll b, ll e, ll i, ll j, ll p)
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

    update(l, b, m, i, j, p);
    update(r, m+1, e, i, j, p);

    tree[n]=(tree[l]+tree[r])%mod;
}

ll query(ll n, ll b, ll e, ll i, ll j)
{
    if(j<b || e<i)
        return 0;
    if(i<=b && e<=j)
    {
        return tree[n];
    }

    ll l, r, m;

    l=n<<1;
    r=l+1;
    m=(b+e)>>1;

    int x, y;

    x=query(l, b, m, i, j);

    y=query(r, m+1, e, i, j);

//    cout<<"print "<<n<<" "<<x<<" "<<m<<endl;

    return (x+y)%mod;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q, x;
    ll testcase;
    ll input, flag, tag, ans, cur;


    scanf("%lld", &n);

    ans = 0;
    build(1, 1, num);

    for(i=1; i<=n; i++)
    {
        scanf("%lld", &x);

        flag=query(1, 1, num, 1, x);

        cur= (((flag+1)%mod)*x)%mod;
        update(1, 1, num, x, x, cur);
    }

    ans=query(1, 1, num, 1, num);

    printf("%lld\n", ans);

    return 0;
}



