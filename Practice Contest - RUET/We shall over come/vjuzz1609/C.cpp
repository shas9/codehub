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

#define printcase(indexing) printf("Case %lld:\n", indexing)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld 99999999999999999
#define mnlld -99999999999999999

#define mxd 99999999
#define mnd 99999999

#define pi 3.14159265359

#define mod 1000000007
#define mx 100005
using namespace std;

ll arr[mx];
ll tree[mx*3];
map < ll, ll > mp;
vector < ll > vec;

void init(ll node, ll b, ll e)
{
    if(b == e)
    {
        tree[node] = 0;
        return;
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    init(left, b, mid);
    init(right, mid + 1, e);

    tree[node] = tree[left] + tree[right];


}

void update(ll node, ll b, ll e, ll i, ll val)
{
    if(i > e || i < b)
    {
        return;
    }

    if(b == i && e == i)
    {
        tree[node] = (tree[node] + val) % mod;
        return;
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    update(left, b, mid, i, val);
    update(right, mid + 1, e, i, val);

    tree[node] = tree[left] + tree[right];
}

ll sum(ll node, ll b, ll e, ll i, ll j)
{
    if(i > e || j < b)
    {
        return 0;
    }

    if(b >= i && e <= j)
    {
        return tree[node];
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    ll p1 = sum(left, b, mid, i, j);
    ll p2 = sum(right, mid + 1, e,i, j);

    return p1 + p2;


}

int main()
{
    ll i, j, k, l, m, n, o, q;
    ll testcase;
    ll input, flag, tag, ans;

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {

        mp.clear();
        vec.clear();

        ll ind = 0;

        slld(n);

        for(i = 0; i < n; i++)
        {
            slld(arr[i]);
            vec.push_back(arr[i]);
        }

        sort(vec.begin(),vec.end());

        for(i = 0; i < n; i++)
        {
            if(mp.find(vec[i]) == mp.end())
            {
                mp[vec[i]] = ++ind;
            }
        }

        init(1,1,ind);

        ans = 0;

        for(i = 0; i < n; i++)
        {
            ll xx = mp[arr[i]];
            ll cnt = 1;

            if(xx > 1)
            {
                cnt += sum(1,1,ind,1,xx - 1);
            }

            ans = (ans + cnt) % mod;

            update(1,1,ind,xx,cnt);
        }

        printf("Case %lld: %lld\n", cs, ans);
    }


}



