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

#define MAXN 100005
#define SQRSIZE 400

ll arr[MAXN];
ll block[SQRSIZE];
ll blk_sz;
bool is_possible[SQRSIZE];

void update(ll idx, ll val, ll n)
{
    idx--;

    ll blockNumber = idx / blk_sz;

    arr[idx] = val;

    is_possible[blockNumber] = 0;

    ll mn = min(block[blockNumber + 1], n - 1);

    for(ll j = min((blk_sz * (blockNumber + 1)) - 1, n - 1); j >= blk_sz * blockNumber; j--)
    {
        cout << " -- " << j << " < ";
        if(j + arr[j] >= mn)
        {
            mn = j;
            is_possible[blockNumber] = 1;
        }
    }

    cout << endl;

    block[blockNumber] = mn;

}


ll query(ll s, ll n)
{
    s--;

    ll blockNumber = s / blk_sz;

    for(ll i = 0; i < blockNumber; i++)
    {
        if(is_possible[i]) return 1;
    }

    ll mn = min(block[blockNumber + 1], n - 1);

    for(ll j = min((blk_sz * (blockNumber + 1)) - 1, n - 1); j >= blk_sz * blockNumber; j--)
    {
        if(j + arr[j] >= mn)
        {
            mn = j;

            if(j <= s) return 1;
        }
    }


    return 0;

}

void preprocess(ll n)
{
    memset(block, mxlld, sizeof block);
    memset(is_possible, 0, sizeof is_possible);

    ll blk_idx = -1;

    blk_sz = sqrt(n);

    for(ll i = 0; i < SQRSIZE; i++) block[i] = 0;

    for (ll i = 0; i < n; i++)
    {
        if (i%blk_sz == 0)
        {
            blk_idx++;
        }
    }

    ll mn = n;

    for (ll i = n - 1; i >= 0; i--)
    {
        if (i%blk_sz == 0)
        {
            for(ll j = min(i + blk_sz, n - 1); j >= i; j--)
            {
                if(j + arr[j] >= mn)
                {
                    mn = j;

                    is_possible[blk_idx] = 1;
                }
            }

            block[blk_idx] = mn;

            blk_idx--;
        }
    }
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

     freopen("in.txt", "r", stdin);
    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(n);
        slld(m);

        for(i = 0; i < n; i++) slld(arr[i]);

        preprocess(n);

        printf("Case %lld:\n", cs);

        for(i = 0; i < m; i++)
        {
            ll type;

            slld(type);

            for(j = 0; j < n; j++) cout << arr[j] << " ";
            cout << endl;

            for(j = 0; j <= blk_sz; j++) cout << block[j] << " ";
            cout << endl;

            if(type == 2)
            {
                slld(input);

                if(query(input, n)) printf("yes\n");
                else printf("no\n");
            }
            else
            {
                slld(input);
                slld(flag);

                update(input,flag, n);
            }
        }
    }


}


