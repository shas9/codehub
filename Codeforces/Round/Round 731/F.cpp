 // Lights will guide you home

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define pll pair < ll, ll >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define bug(x) printf("BUG %lld\n", x)
#define pb push_back

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

vector < ll > v;

struct segtree
{

    ll n;
    vector < ll > tree;


    void init(ll _n)
    {
        n = _n;
        tree.assign(4 * n,0);
    }

    void treeupdate(ll node, ll b, ll e, ll i, ll val)
    {
        if(i > e || i < b)
        {
            return;
        }

        if(b == i && e == i)
        {
            tree[node] = val;
            return;
        }

        ll left = node * 2;
        ll right = (node * 2) + 1;
        ll mid = (b + e) / 2;

        treeupdate(left, b, mid, i, val);
        treeupdate(right, mid + 1, e, i, val);

        tree[node] = __gcd(tree[left], tree[right]);
    }

    void update(ll i, ll val)
    {
        treeupdate(1,1,n,i,val);
    }

    ll treequery(ll node, ll b, ll e, ll i, ll j)
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

        ll p1 = treequery(left, b, mid, i, j);
        ll p2 = treequery(right, mid + 1, e,i, j);

        return __gcd(p1,p2);
    }

    ll query(ll x, ll y)
    {
        return treequery(1,1,n,x,y);
    }

} seg;

ll fgcd(ll x, ll y, ll n)
{
    if(y <= n) return seg.query(x, y);
    else
    {
        ll extra = y - n;

        ll r1 = seg.query(x, n);
        ll r2 = seg.query(1,extra);

//        cout << x << " " << y << " " << extra << " == \n";
//        cout << r1 << " -- " << r2 << "\n";

        return __gcd(r1,r2);
    }
}

bool solve(ll mid, ll n)
{
    ll last = 0;

//    cout << mid << " + " << endl;

    for(ll i = 1; i <= n; i++)
    {
        ll x = fgcd(i, i + mid, n);

//        cout << i << " " << x << "\n";

        if(i == 1) last = x;
        else if(last != x) return 0;
    }

    return 1;
}

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    cin >> testcase;

    for(ll cs = 1; cs <= testcase; cs++)
    {
        cin >> n;


        seg.init(n);

        for(ll i = 1; i <= n; i++)
        {
            cin >> in;
            seg.update(i, in);
        }

        ll ret = n;

        ll lo = 0, hi = n - 1;

        while(lo <= hi)
        {
            ll mid = (lo + hi) / 2;

            if(solve(mid, n))
            {
                ret = mid;
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }

        cout << ret << "\n";
    }


}



