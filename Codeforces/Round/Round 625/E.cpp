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

#define mod 1000000009
#define mx 200005

#define pll pair < ll, ll >
using namespace std;

pll aa[mx];
pll bb[mx];

struct node
{
    ll x, y, z;
};

node mons[mx];

ll tree[mx * 4];
ll lazy[mx * 4];

void propagate(ll node, ll i, ll j)
{
    ll mid = (i + j) / 2;
    ll lft = node * 2;
    ll rgt = lft + 1;

    lazy[lft] += lazy[node];
    lazy[rgt] += lazy[node];

    ll lft_l = i;
    ll lft_r = mid;

    ll rgt_l = mid + 1;
    ll rgt_r = j;

    tree[lft] += lazy[node];
    tree[rgt] += lazy[node];

    lazy[node] = 0;
}

void update(ll node, ll L, ll R, ll l, ll r, ll val)
{

    if(r < L || R < l) return;

    if(l <= L && R <= r)
    {
        lazy[node] += val;
        tree[node] += val;

        return;
    }

    propagate(node,L,R);

    ll mid = (L + R) / 2;

    update(node * 2, L, mid, l, r, val);
    update((node * 2) + 1, mid +1, R, l, r, val);

    tree[node] = max(tree[node * 2], tree[(node * 2) + 1]);
}

ll query(ll node, ll L, ll R,  ll l, ll r)
{
//        cout << node << " " << L << " " << R << " "<< l << " " << r << endl;

    if(r < L || R < l) return mnlld;

    if(l <= L && R <= r)
    {
        return tree[node];
    }

    propagate(node, L, R);

    ll mid = (L + R) / 2;
    ll x = query(node * 2, L, mid, l, r);
    ll y = query((node * 2) + 1, mid + 1, R, l, r);

    return max(x,y);
}

void print(ll node, ll a, ll b)
{
    ll mid = (a + b) / 2;

    cout << a << " " << b << ": " << tree[node] << endl;

    if(a == b) return;

    print(node * 2, a, mid);
    print((node * 2) + 1, mid + 1, b);
}


bool comp(node a, node b)
{
    return a.x < b.x;
}

int main()
{
    ll i, j, k, l, m, n, o, q;
    ll testcase;
    ll input, flag, tag, ans;

        freopen("input.txt", "r", stdin);

    slld(n);
    slld(m);
    slld(k);

    for(i = 1; i <= n; i++)
    {
        slld(aa[i].first);
        slld(aa[i].second);
    }

    for(i = 1; i <= m; i++)
    {
        slld(bb[i].first);
        slld(bb[i].second);
    }

    for(i = 1; i <= k; i++)
    {
        slld(mons[i].x);
        slld(mons[i].y);
        slld(mons[i].z);
    }



    sort(aa + 1, aa + 1 + n);
    sort(bb + 1, bb + 1 + m);
    sort(mons + 1, mons + 1 + k, comp);

    for(i = n - 1; i >= 1; i--)
    {
        aa[i].second = min(aa[i].second, aa[i + 1].second);
    }

    for(i = m - 1; i >= 1; i--)
    {
        bb[i].second = min(bb[i].second, bb[i + 1].second);
    }

//    for(i = 1; i <= n; i++)
//    {
//        cout << aa[i].first << " " << aa[i].second << endl;
//    }
//
//    for(i = 1; i <= m; i++)
//    {
//        cout << bb[i].first << " " << bb[i].second << endl;
//    }


    for(i = 1; i <= m; i++)
    {
        update(1,1,m,i,i,-bb[i].second);
    }

//    print(1,1,m);
//
//    cout << " ~~ " << query(1,1,m,2,3) << endl;

    i = 1;
    j = 1;

    ans = mnlld;

    while(i <= n && j <= k)
    {
        while((mons[j].x < aa[i].first) && j <= k)
        {
            ll lo = 1;
            ll hi = m;
            ll pos = m;

            while(lo <= hi)
            {
                ll mid = (lo + hi) / 2;

                if(bb[mid].first > mons[j].y)
                {
                    pos = mid;
                    hi = mid - 1;
                }
                else
                {
                    lo = mid + 1;
                }

//                cout << " -- " << mid << endl;
            }

//            cout << mons[j].y << " ~~ " << pos << " " << bb[pos].first << endl;

            update(1,1,m,pos,m,mons[j].z);

            ll p = query(1,1,m,1,m);

//            cout << p << endl;

            ans = max(ans, p - aa[i].second);
            j++;
        }

        i++;


    }

    cout << ans << endl;



}



