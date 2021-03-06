#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%d", &longvalue)
#define plld(longvalue) printf("%lld\n", longvalue)

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

#define lim 400005

using namespace std;

struct node
{
    ll l, r, num, blc;
};

node q[lim * 2];
ll mx[lim];
ll mn[lim];
ll arr[lim * 2];
ll freq[lim];
ll cnt;
ll curr[lim];

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

void add(ll x)
{
    x = arr[x];
    freq[x]++;

    if(freq[x] == 1) cnt++;
}

void rem(ll x)
{
    x = arr[x];

    freq[x]--;

    if(freq[x]==0) cnt--;
}




/*

    while(l > q[i].l) add(--l);
    while(r < q[i].r) add(++r);
    while(l < q[i].l) remove(l++);
    while(r > q[i].r) remove(r--);

*/

int main()
{
    ll i, j, k, l, m, n, o, r;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(n);
    slld(m);

    for(i = 1; i <= n; i++)
    {
        arr[i + m] = i;

        curr[i] = i + m;
    }

    for(i = 1; i <= n; i++)
    {
        mn[i] = mx[i] = i;
    }

    ll ssq = sqrt(n + m) + 10;

    for(i = 1, j = 0; i <= m; i++, j++)
    {
        slld(arr[m - j]);

        ll xx = arr[m - j];

        mn[xx] = 1;

        q[i].l = m - j + 1;
        q[i].r = curr[xx];
        q[i].num = xx;
        q[i].blc = l / ssq;  /// block count
        curr[xx] = m - j;
    }

    for(i = 1; i <= n; i++)
    {
        ll x = i + m;

        q[x].l = 1;
        q[x].r = curr[i];
        q[x].num = i;
        q[x].blc = q[x].l / ssq;
    }

    sort(q + 1, q + 1 + m + n, comp);

    cnt = 0;
    l = 1;
    r = 0;

//    for(i = 1; i <= n + m; i++)
//    {
//        cout << arr[i] << " ";
//    }
//
//    cout << endl;

    for(i = 1; i <= m + n; i++)
    {
        while(l > q[i].l) add(--l);
        while(r < q[i].r) add(++r);
        while(l < q[i].l) rem(l++);
        while(r > q[i].r) rem(r--);

//        cout << q[i].l << " " << q[i].r << " " << q[i].num << " " << cnt << endl;
        mx[q[i].num] = max(mx[q[i].num],cnt);
    }

    for(i = 1; i <= n; i++)
    {
        printf("%d %d\n", mn[i], mx[i]);
    }



}



