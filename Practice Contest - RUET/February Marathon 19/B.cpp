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
#define SQRSIZE 320

struct info
{
    ll cnt[MAXN];
    deque < ll > dq;
};


ll arr[MAXN];
info block[SQRSIZE];
ll blk_sz;

void update(ll l, ll r)
{
    ll lb = l / blk_sz, rb = r / blk_sz;
    ll lp = l % blk_sz, rp = r % blk_sz;

    ll val = block[rb].dq[rp];

    block[rb].dq.erase(block[rb].dq.begin() + rp);
    block[lb].dq.insert(block[lb].dq.begin() + lp,val);

    block[rb].cnt[val]--;
    block[lb].cnt[val]++;

//    cout << block[lb].cnt[val] << " && " << val << endl;

    for(ll i = lb + 1; i <= rb; i++)
    {
        val = block[i - 1].dq[block[i - 1].dq.size() - 1];
        block[i - 1].dq.pop_back();
        block[i].dq.push_front(val);

        block[i - 1].cnt[val]--;
        block[i].cnt[val]++;
    }

}


ll query(ll l, ll r, ll k)
{
    ll ans = 0;
    ll i, j;
    while (l < r && l % blk_sz != 0 && l != 0)
    {
        i = l / blk_sz;
        j = l % blk_sz;
        if(k == block[i].dq[j]) ans++;
        l++;
    }

//    cout << l << " " << ans << endl;
    while (l+blk_sz <= r)
    {
        ans += block[l / blk_sz].cnt[k];

//        cout << "BLOCK: " << l / blk_sz << " && " << block[l / blk_sz].cnt[k] << endl;
        l += blk_sz;
    }
    while (l <= r)
    {
        i = l / blk_sz;
        j = l % blk_sz;
        if(k == block[i].dq[j]) ans++;
        l++;
    }

//    cout << l << " " << ans << endl;
    return ans;
}

void preprocess(ll n)
{
    ll blk_idx = -1;

    blk_sz = sqrt(n);

    for (ll i = 0; i < n; i++)
    {
        if (i%blk_sz == 0)
        {
            blk_idx++;
        }
        block[blk_idx].dq.push_back(arr[i]);
        block[blk_idx].cnt[arr[i]]++;
    }
}

void printt(ll n)
{
    ll blk_idx = -1;

    for (ll i = 0, j; i < n; i++)
    {
        if (i%blk_sz == 0)
        {
            blk_idx++;
            j = 0;

            cout << "- ";
        }
        cout << block[blk_idx].dq[j++] << " ";
    }

    cout << endl;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//     freopen("in.txt", "r", stdin);

    slld(n);

    for(i = 0; i < n; i++) slld(arr[i]);

    preprocess(n);
    slld(m);

//    printt(n);

    ans = 0;
    for(i = 1; i <= m; i++)
    {
        slld(q);
        slld(l);
        slld(r);

        l = (l + ans - 1) % n;
        r = (r + ans - 1) % n;

        if(l > r) swap(l,r);

        if(q == 2)
        {
            slld(k);

            k = ((k + ans - 1) % n) + 1;

//            cout << "Start: " << endl;

            ans = query(l,r,k);

            //printt(n);
            printf("%lld\n", ans);
        }
        else
        {
            update(l,r);
//            printt(n);
        }



    }


}



