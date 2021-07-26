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

#define lim 100005
using namespace std;

struct node
{
    ll l, r, id, blc;
};

node q[lim];
ll ans[lim];
ll arr[lim];
ll freq[lim * 15];
ll cnt, k;
ll cumxor;

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
    ll y = k ^ x;

    cnt += freq[y];

    cumxor ^= x;

    freq[cumxor]++;

//    cout << x << " " << cumxor << " " << y << endl;
}

void rem(ll x)
{
    ll y = k ^ x;
    cnt -= freq[y];

    cumxor ^= x;

    freq[cumxor]--;
}


// q[i].blc = l / ssq;  /// block count


int main()
{
    ll i, j, l, m, n, o, r;
    ll testcase;
    ll input, flag, tag;

    // freopen("in.txt", "r", stdin);


    while(cin >> n >> m >> k)
    {
        memset(freq,0,sizeof freq);

        for(i = 1; i <= n; i++)
        {
            slld(arr[i]);
        }

        ll ssq = (sqrt(n)) + 5;

        for(i = 1; i <= m; i++)
        {
            slld(l);
            slld(r);

            q[i].l = l;
            q[i].r = r;
            q[i].id = i;
            q[i].blc = l / ssq;
        }


        sort(q + 1, q + 1 + m, comp);

        cnt = 0;
        cumxor = 0;

        l = 1;
        r = 0;

        for(i = 1; i <= m; i++)
        {
            while(l > q[i].l) add(arr[--l]);
            while(r < q[i].r) add(arr[++r]);
            while(l < q[i].l) rem(arr[l++]);
            while(r > q[i].r) rem(arr[r--]);

            ans[q[i].id] = cnt;
        }

        for(i = 1; i <= m; i++)
        {
            plld(ans[i]);
        }


    }


}

