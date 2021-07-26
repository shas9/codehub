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


#define mx 150005

struct info
{
    ll prop, summ;
} tree[mx*5];

ll points[mx];
pll range[mx];
map < ll, ll > mp;
vector < ll > vec;

void update(ll node, ll b, ll e, ll i, ll j, ll val)
{
    if(i > e || j < b)
    {
        return;
    }

    if(b >= i && e <= j)
    {
        tree[node].summ += (e - b + 1) * val;
        tree[node].prop += val;
        return;
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    update(left, b, mid, i, j, val);
    update(right, mid + 1, e, i, j, val);

    tree[node].summ = tree[left].summ + tree[right].summ + (e - b + 1) * tree[node].prop;
}

ll sum(ll node, ll b, ll e, ll i, ll j, ll carry = 0)
{
    if(i > e || j < b)
    {
        return 0;
    }

    if(b >= i && e <= j)
    {
        return tree[node].summ + carry * (e - b + 1);
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    ll p1 = sum(left, b, mid, i, j, carry + tree[node].prop);
    ll p2 = sum(right, mid + 1, e,i, j, carry + tree[node].prop);

    return p1 + p2;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        slld(n);
        slld(q);

        mp.clear();
        vec.clear();

        ll ind = 0;

        for(i = 1; i <= n; i++)
        {
            slld(range[i].first);
            slld(range[i].second);

            vec.push_back(range[i].first);
            vec.push_back(range[i].second);
        }

        for(i = 1; i <= q; i++)
        {
            slld(points[i]);

            vec.push_back(points[i]);
        }

        sort(vec.begin(),vec.end());

        for(i = 0; i < vec.size(); i++)
        {
            if(mp.find(vec[i]) == mp.end())
            {
                mp[vec[i]] = ++ind;
            }
        }

        for(i = 0; i < mx * 5; i++) tree[i].summ = tree[i].prop = 0;

        for(i = 1; i <= n; i++)
        {
            ll xx = mp[range[i].first];
            ll yy = mp[range[i].second];

            update(1,1,ind,xx,yy,1);
        }

        printf("Case %lld:\n", cs);

        for(i = 1; i <= q; i++)
        {
            ll xx = mp[points[i]];

            ans = sum(1,1,ind,xx,xx);

            printf("%lld\n", ans);
        }
    }


}

