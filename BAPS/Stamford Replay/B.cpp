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

#define mod 1000000005721


using namespace std;


ll arr[100005];
ll x___1, y__1, x___2, y__2;
ull basepow[100005];

ull tree[500005];

void init(ll node, ll b, ll e)
{
    if(b == e)
    {
        tree[node] = basepow[arr[b]];
        return;
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    init(left, b, mid);
    init(right, mid + 1, e);

    tree[node] = tree[left] + tree[right];


}


ll sum(ll node, ll b, ll e, ll i, ll j)
{
    if(i > e || j < b)
    {
        return 0;
    }

    if(b >= i && e <= j)
    {
        return tree[node];
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    ll p1 = sum(left, b, mid, i, j);
    ll p2 = sum(right, mid + 1, e,i, j);

    return p1 + p2;


}


bool solve(ll n)
{
    ll a = sum(1,1,n,x___1,y__1);


    ll b = sum(1,1,n,x___2,y__2);

    if(a == b) return 1;

    return 0;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.tx___t", "r", stdin);

    slld(n);

    for(i = 1; i <= n; i++) slld(arr[i]);

    ll base = 1069;

    basepow[0] = 1;

    for(i = 1; i <= n; i++)
    {
        basepow[i] = (basepow[i - 1] * base);
    }

    init(1,1,n);
    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(x___1);
        slld(y__1);

        slld(x___2);
        slld(y__2);

        if(solve(n)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }


}


