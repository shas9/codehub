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

#define maxn 500005
#define sq 750
using namespace std;

ll arr[maxn];
ll ans[maxn];
ll cnt[maxn];
ll sqd[sq];
ll sum;

struct node
{
    ll l, r, id, blc;


};

node vec[maxn];

bool comp(node a, node b)
{
    if(a.blc != b.blc)
    {
        return a.blc < b.blc;
    }

    return a.r < b.r;
}

bool add(ll x)
{
    cnt[x]++;
    if(cnt[x] == 1)
    {
        sqd[x/sq]++;
        sum++;
    }
    else if(cnt[x] == 2)
    {
        sqd[x/sq]--;
        sum--;
    }
}

bool rem(ll x)
{
    cnt[x]--;
    if(cnt[x] == 1)
    {
        sqd[x/sq]++;
        sum++;
    }
    else if(cnt[x] == 0)
    {
        sqd[x/sq]--;
        sum--;
    }
}

ll solve()
{
    if(sum == 0) return 0;

    for(ll i = 0; i <= sq; i++)
    {
        if(sqd[i] == 0) continue;

        for(ll j = i * sq; ; j++)
        {
            if(cnt[j] == 1) return j;
        }
    }
}
int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag;

    // freopen("in.txt", "r", stdin);

    slld(n);

    for(i = 1; i <= n; i++)
    {
        slld(arr[i]);
    }

    ll q;

    slld(q);

    for(i = 1; i <= q; i++)
    {
        ll r;

        slld(l);
        slld(r);

        vec[i].l = l;
        vec[i].r = r;
        vec[i].id = i;
        vec[i].blc = l / sq;
    }

    sort(vec + 1, vec + 1 + q, comp);

    l = 1;
    ll r = 0;
    sum = 0;

    for(i = 1; i <= q; i++)
    {
        while(r < vec[i].r) add(arr[++r]);
        while(r > vec[i].r) rem(arr[r--]);

        while(l < vec[i].l) rem(arr[l++]);
        while(l > vec[i].l) add(arr[--l]);

        ans[vec[i].id] = solve();
    }

    for(i = 1; i <= q; i++)
    {
        plld(ans[i]);
    }



}
