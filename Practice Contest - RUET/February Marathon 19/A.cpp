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

#define MAXN 1000000
#define SQRSIZE 1000

ll arr[MAXN];               // original array
ll block[SQRSIZE];          // decomposed array
ll blk_sz;                      // block size

// Time Complexity : O(sqrt(n))
ll query(ll l, ll r)
{
    ll sum = mxlld;
    while (l<r && l%blk_sz!=0)
    {
        // traversing first block in range
        sum = min(sum,arr[l]);
        l++;
    }
    while (l+blk_sz <= r)
    {
        // traversing completely overlapped blocks in range
        sum = min(sum,block[l/blk_sz]);
        l += blk_sz;
    }
    while (l <= r)
    {
        // traversing last block in range
        sum = min(sum,arr[l]);
        l++;
    }
    return sum;
}

// Fills values in input[]
void preprocess(ll n)
{
    // initiating block pointer
    ll blk_idx = 0;

    // calculating size of block
    blk_sz = sqrt(n);

    // building the decomposed array

    for(ll i = 0; i < SQRSIZE; i++) block[i] = mxlld;

    for (ll i = 1; i <= n; i++)
    {
        if (i%blk_sz == 0)
        {
            blk_idx++;
        }
        block[blk_idx] = min(block[blk_idx],arr[i]);
    }
}


int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

    // freopen("in.txt", "r", stdin);
    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(n);
        slld(m);

        for(i = 1; i <= n; i++) slld(arr[i]);


        preprocess(n);

        printf("Case %lld:\n", cs);

        for(i = 1; i <= m; i++)
        {
            slld(l);
            slld(r);

            ans = query(l,r);

            printf("%lld\n", ans);
        }


    }


}



