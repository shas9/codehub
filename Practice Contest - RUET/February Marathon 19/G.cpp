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
#define pll pair < int, int >
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

#define mx 100005
using namespace std;

ll arr[mx], nxt[mx], cnt[mx];
ll blk_sz;
ll n;
void build(ll block)
{
    ll l = block * blk_sz;
    ll r = min(n - 1, (blk_sz * (block + 1)) - 1);

    for(ll i = r; i >= l; i--)
    {
        ll x = i;

        if(x + arr[x] > r)
        {
            nxt[x] = x;
            cnt[x] = 1;
        }
        else
        {
            nxt[x] = nxt[x + arr[x]];
            cnt[x] = 1 + cnt[x + arr[x]];
        }
    }
}

pll solve(ll ind)
{
    ll cntt = 0;
    ll last = ind;

    while(ind < n)
    {
        cntt += cnt[ind];
        last = nxt[ind];
        ind = last + arr[last];
    }

    return make_pair(last + 1,cntt);
}

void update(ll i, ll b)
{
    arr[i] = b;

    build(i / blk_sz);
}


int main()
{
    ll i, j, k, l, m, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//     freopen("in.txt", "r", stdin);

    slld(n);
    slld(m);

    for(i = 0; i < n; i++) slld(arr[i]);

    blk_sz = 320;

    for(i = 0; i < n; i += blk_sz) build(i / blk_sz);

//    printt();

    while(m--)
    {
        slld(q);

        if(q == 1)
        {
            slld(k);

            k--;

            pll x = solve(k);

            printf("%d %d\n", x.first, x.second);
        }
        else
        {
            slld(l);
            slld(r);

            l--;

            update(l,r);

//            printt();
        }
    }


}



