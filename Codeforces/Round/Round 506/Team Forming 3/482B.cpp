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
#define mx 100005
using namespace std;

ll Set(ll n, ll pos)
{
	return n = n | (1 << pos);
}

ll arr[mx];
ll tree[mx*3];

void init(ll node, ll b, ll e)
{
    if(b == e)
    {
        tree[node] = arr[b];
        return;
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    init(left, b, mid);
    init(right, mid + 1, e);

    tree[node] = tree[left] & tree[right];


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

    return p1 & p2;


}

struct node
{
    ll l, r, q;

    node(ll _l, ll _r, ll _q)
    {
        l = _l;
        r = _r;
        q = _q;
    }
};

bool comp(node a, node b)
{
    if(a.l == b.l) return a.r < b.r;
    else return a.l < b.l;
}

vector < node > vec;

int main()
{
    ll i, j, k, l, m, n, o, q,r;
    ll testcase;
    ll input, flag, tag, ans;

    while(cin >> n >> m)
    {
        memset(arr,-1,sizeof arr);

        vec.clear();

        for(i = 1; i <= m; i++)
        {
            slld(l);
            slld(r);
            slld(q);

            vec.push_back(node(l,r,q));
        }

        sort(vec.begin(),vec.end(),comp);

        for(i = 0; i < m; i++)
        {
            l = vec[i].l;

            arr[l] |=
        }

        ll nn = 0;

        for(i = 0; i <= 29; i++) nn = Set(nn,i);

        for(i = 1; i <= n; i++)
        {
            if(arr[i] < 0) arr[i] = nn;
        }

        init(1,1,n);

        for(i = 0; i < m; i++)
        {
            l = vec[i].l;
            r = vec[i].r;
            q = vec[i].q;

            ans = sum(1,1,n,l,r);

            if(ans != q)
            {
                cout  << "NO" << endl;
                return 0;
            }
        }

        cout << "YES" << endl;
        for(i = 1; i <= n; i++) cout << arr[i] << " ";

        cout << endl;




    }
}



