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

#define MAXN 500005
#define SQRSIZE 750

struct info
{
    ll l, r;
    vector < ll > vec;
};
ll arr[MAXN];               // original array
info block[SQRSIZE];          // decomposed array
ll blk_sz;                      // block size

void update(ll idx, ll val)
{
    ll blockNumber = idx / blk_sz;
    ll l = block[blockNumber].l;
    ll r = block[blockNumber].r;

    block[blockNumber].vec.clear();

    arr[idx] = val;

    for(ll i = l; i <= r; i++)
    {
        block[blockNumber].vec.push_back(arr[i]);
    }

    sort(block[blockNumber].vec.begin(), block[blockNumber].vec.end());

}

ll solve(ll ind, ll v)
{
    ll hi = block[ind].vec.size() - 1;
    ll lo = 0;

    ll ans = 0;

    while(lo <= hi)
    {
        ll mid = (lo + hi) / 2;

        if(block[ind].vec[mid] >= v)
        {
            ans = block[ind].vec.size() - mid;
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }

    return ans;
}
ll query(ll l, ll r, ll v)
{
    ll cnt = 0;

//    cout << blk_sz << endl;
    while (l < r && l % blk_sz != 0)
    {
        // traversing first block in range
        if(arr[l] >= v) cnt++;
        l++;

//        bug;
    }

//    bug;
    while (l+blk_sz <= r)
    {
//        bug;
        cnt += solve(l / blk_sz, v);
        l += blk_sz;
//        bug;
    }
    while (l <= r)
    {
        // traversing last block in range
        if(arr[l] >= v) cnt++;
        l++;
    }
    return cnt;
}

// Fills values in input[]
void preprocess(ll n)
{
    // initiating block pointer
    ll blk_idx = 0;

    // calculating size of block
    blk_sz = sqrt(n);


    block[blk_idx].l = 1;
    for (ll i = 1; i <= n; i++)
    {
        if (i%blk_sz == 0)
        {
            sort(block[blk_idx].vec.begin(),block[blk_idx].vec.end());

            block[blk_idx].r = i - 1;

            blk_idx++;

            block[blk_idx].l = i;
        }
        block[blk_idx].vec.push_back(arr[i]);
    }

    if(block[blk_idx].vec.size())
    {
        sort(block[blk_idx].vec.begin(),block[blk_idx].vec.end());

        block[blk_idx].r = n;
    }
}


int main()
{
    ll i, j, k, l, m, n, o, r, q, u;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);
//    slld(testcase);
//
//    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(n);

        for(i = 1; i <= n; i++) slld(arr[i]);

        preprocess(n);

        slld(m);

        for(i = 1; i <= m; i++)
        {
            ll v, p;

            slld(q);
            slld(l);
            slld(r);

            if(q == 0)
            {
                slld(v);
                ans = query(l,r,v);

                printf("%lld\n", ans);
            }
            else
            {
                update(l,r);
            }
        }

    }


}



