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

#define mx 100005

using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}


ll tree[mx * 4];
ll lazy[mx * 4];
ll arr[mx];

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

    tree[lft] += (lft_r - lft_l + 1) * lazy[node];
    tree[rgt] += (rgt_r - rgt_l + 1) * lazy[node];

    lazy[node] = 0;
}

void update(ll node, ll L, ll R, ll l, ll r, ll val)
{

    if(r < L || R < l) return;

    if(l <= L && R <= r)
    {
        lazy[node] += val;
        tree[node] += (R - L + 1) * val;

        return;
    }

    propagate(node,L,R);

    ll mid = (L + R) / 2;

    update(node * 2, L, mid, l, r, val);
    update((node * 2) + 1, mid +1, R, l, r, val);

    tree[node] = tree[node * 2] + tree[(node * 2) + 1];
}

ll query(ll node, ll L, ll R,  ll l, ll r)
{
//        cout << node << " " << L << " " << R << " "<< l << " " << r << endl;

    if(r < L || R < l) return 0;

    if(l <= L && R <= r)
    {
        return tree[node];
    }

    propagate(node, L, R);

    ll mid = (L + R) / 2;
    ll x = query(node * 2, L, mid, l, r);
    ll y = query((node * 2) + 1, mid + 1, R, l, r);

    return x + y;
}



int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    cin >> n;

    for(i = 1; i <= n; i++)
    {
        cin >> arr[i];

        update(1,1,n,i,i,arr[i]);
    }

    for(i = 1; i <= n; i++)
    {
        ll a, b, c;

        cin >> a >> b;

        if(i % 2)
        {
            cout << query(1,1,n,a,b) << endl;
        }
        else
        {
            cin >> c;

            update(1,1,n,a,b,c);
        }
    }


}


