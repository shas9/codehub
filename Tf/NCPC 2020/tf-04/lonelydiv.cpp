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

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

ll div1[100005];
ll div2[100005][130];

pll tree[400005];
struct qq
{
    ll l, r, k, id;
};

bool comp(qq a, qq b)
{
    return a.k <= b.k;
}

qq query[1000006];
pll ans[1000006];

void process()
{
    memset(div1,0,sizeof div1);
    memset(div2,0,sizeof div2);

    div1[1] = 1;
    div2[1][1] = 1;

    for(ll i = 2; i <= 100000; i++)
    {
        for(ll j = 1; j * j <= i; j++)
        {
            if(i % j) continue;

            ll xx = j;
            ll yy = i / j;

            div1[i]++;

            if(div1[xx] <= 128)
            {
                ll &ch = div2[i][div1[xx]];

                if(ch != 0) ch = -1;
                else ch = xx;

            }
            if(xx == yy) continue;

            if(xx == i || yy == i) continue;

            div1[i]++;

            if(div1[yy] <= 128)
            {
                ll &chh = div2[i][div1[yy]];

                if(chh != 0) chh = -1;
                else chh = yy;
            }
        }

        div1[i]++;

        if(div1[i] > 128) continue;

        ll &ch = div2[i][div1[i]];

        if(ch != 0) ch = -1;
        else ch = i;
    }
}

void init(ll node, ll b, ll e, ll k)
{
    if(b == e)
    {
        tree[node] = {div2[b][k],b};
        return;
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    init(left, b, mid, k);
    init(right, mid + 1, e, k);

    tree[node] = max(tree[left],tree[right]);
}

pll sum(ll node, ll b, ll e, ll i, ll j)
{
    if(i > e || j < b)
    {
        return {-1,-1};
    }

    if(b >= i && e <= j)
    {
        return tree[node];
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    pll p1 = sum(left, b, mid, i, j);
    pll p2 = sum(right, mid + 1, e,i, j);

    return max(p1,p2);


}


int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(query[cs].l);
        slld(query[cs].r);
        slld(query[cs].k);

        query[cs].id = cs;
    }

    sort(query + 1, query + 1 + testcase, comp);

    process();

    ll prevk = -1;

    for(ll cs = 1; cs <= testcase; cs++)
    {
//        cout << query[cs].k << endl;
        if(prevk != query[cs].k)
        {
//            bug;
            prevk = query[cs].k;

            init(1,1,100000,prevk);
        }

        ans[query[cs].id] = sum(1,1,100000,query[cs].l,query[cs].r);
    }

    for(ll i = 1; i <= testcase; i++)
    {
        if(ans[i].first <= 0)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << ans[i].second << " " << ans[i].first << endl;
        }
    }


}


