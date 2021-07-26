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

#define maxn 200005

using namespace std;

struct node
{
    ll l, r, id;
};

node que[maxn];
ll arr[maxn];
ll freq[maxn * 6];
ll cnt[maxn];

const int ssq = 450;
bool comp(node a, node b)
{
    ll x = a.l / ssq;
    ll y = b.l / ssq;

    if(x == y)
    {
        return a.r < b.r;
    }
    else
    {
        return a.l < b.l;
    }
}

ll ans;
void add(ll x)
{
    ll c = freq[x];
    ans += x * (c + c + 1);
    freq[x]++;
}

void rem(ll x)
{
    ll c = freq[x];
    ans -= x * (c + c - 1);
    freq[x]--;
}
int main()
{
    ll i, j, k, l, m, n, o;
    ll testcase;
    ll input, flag, tag, q;

    // freopen("in.txt", "r", stdin);

    slld(n);
    slld(q);

    for(i = 1; i <= n; i++) slld(arr[i]);

    for(i = 0; i < q; i++)
    {
        slld(j);
        slld(k);

        que[i].l = j;
        que[i].r = k;
        que[i].id = i + 1;
    }

    sort(que, que + q,comp);

    ll r = 0;
    l = 1;

    ans = 0;
    for(i = 0; i < q; i++)
    {
        //cout << que[i].l << " : " << que[i].r << endl;
        while(l > que[i].l) add(arr[--l]);
        while(r < que[i].r) add(arr[++r]);

        while(l < que[i].l) rem(arr[l++]);
        while(r > que[i].r) rem(arr[r--]);

        //cout << ans << endl;
        cnt[que[i].id] = ans;

        //cout << que[i].id << " " << ans << endl;
    }

    //sort(que.begin(),que.end(),comp2);

    for(i = 1; i <= q; i++)
    {
        plld(cnt[i]);
    }


}


