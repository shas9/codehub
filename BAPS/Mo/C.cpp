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

unordered_map < ll, ll > mp;

struct node
{
    ll l, r, id, blc;
};

node q[100005];
ll arr[100005];
ll ans[100005];
ll sum;

void add(ll x)
{
    x = arr[x];

    if(mp[x] == x)
    {
        sum--;
    }

    mp[x]++;

    if(mp[x] == x)
    {
        sum++;
    }
}

void rem(ll x)
{
    x = arr[x];

    if(mp[x] == x) sum--;

    mp[x]--;

    if(mp[x] == x)
    {
        sum++;
    }
}

bool comp(node a, node b)
{
    if(a.blc != b.blc)
    {
        return a.blc < b.blc;
    }

    if(a.blc % 2 == 0)
    {
        return a.r < b.r;
    }
    else
    {
        return a.r > b.r;
    }
}
int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag;

    // freopen("in.txt", "r", stdin);

    slld(n);
    slld(m);

    for(i = 1; i <= n; i++) slld(arr[i]);

    ll ssq = sqrt(n) + 5;
    for(i = 1; i <= m; i++)
    {
        slld(j);
        slld(k);

        q[i].l = j;
        q[i].r = k;
        q[i].id = i;
        q[i].blc = j / ssq;
    }

    sort(q + 1, q + 1 + m, comp);

   l = 1;
   ll r = 0;
   sum = 0;

   for(i = 1; i <= m; i++)
   {
       while(l > q[i].l) add(--l);
       while(r < q[i].r) add(++r);

        while(l < q[i].l) rem(l++);
        while(r > q[i].r) rem(r--);
        ans[q[i].id] = sum;
   }

   for(i = 1; i <= m; i++)
   {
       plld(ans[i]);
   }


}


