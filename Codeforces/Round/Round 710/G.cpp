 // Lights will guide you home

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb push_back

#define bug printf("BUG\n")

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

struct segtreemin
{

    ll n;
    vector < pll > tree;


    void init(ll _n)
    {
        n = _n;
        tree.assign(4 * n,{0,0});
    }

    void treeupdate(ll node, ll b, ll e, ll i, ll val)
    {
        if(i > e || i < b)
        {
            return;
        }

        if(b == i && e == i)
        {
            tree[node] = {val,b};
            return;
        }

        ll left = node * 2;
        ll right = (node * 2) + 1;
        ll mid = (b + e) / 2;

        treeupdate(left, b, mid, i, val);
        treeupdate(right, mid + 1, e, i, val);

        tree[node] = min(tree[left], tree[right]);
    }

    void update(ll i, ll val)
    {
        treeupdate(1,1,n,i,val);
    }

    pll treequery(ll node, ll b, ll e, ll i, ll j)
    {
        if(i > e || j < b)
        {
            return {mxlld,mxlld};
        }

        if(b >= i && e <= j)
        {
            return tree[node];
        }

        ll left = node * 2;
        ll right = (node * 2) + 1;
        ll mid = (b + e) / 2;

        pll p1 = treequery(left, b, mid, i, j);
        pll p2 = treequery(right, mid + 1, e,i, j);

        return min(p1, p2);
    }

    pll query(ll x, ll y)
    {
        return treequery(1,1,n,x,y);
    }
};

struct segtreemax
{

    ll n;
    vector < pll > tree;


    void init(ll _n)
    {
        n = _n;
        tree.assign(4 * n,{0,0});
    }

    void treeupdate(ll node, ll b, ll e, ll i, ll val)
    {
        if(i > e || i < b)
        {
            return;
        }

        if(b == i && e == i)
        {
            tree[node] = {val,b};
            return;
        }

        ll left = node * 2;
        ll right = (node * 2) + 1;
        ll mid = (b + e) / 2;

        treeupdate(left, b, mid, i, val);
        treeupdate(right, mid + 1, e, i, val);

        tree[node] = max(tree[left], tree[right]);
    }

    void update(ll i, ll val)
    {
        treeupdate(1,1,n,i,val);
    }

    pll treequery(ll node, ll b, ll e, ll i, ll j)
    {
        if(i > e || j < b)
        {
            return {mnlld, mnlld};
        }

        if(b >= i && e <= j)
        {
            return tree[node];
        }

        ll left = node * 2;
        ll right = (node * 2) + 1;
        ll mid = (b + e) / 2;

        pll p1 = treequery(left, b, mid, i, j);
        pll p2 = treequery(right, mid + 1, e,i, j);

        return max(p1, p2);
    }

    pll query(ll x, ll y)
    {
        return treequery(1,1,n,x,y);
    }
};

string str;
vector < ll > vec[30];

void solve()
{
    cin >> str;
    ll n = str.size();

    for(ll i = 0; i < 30; i++) vec[i].clear();

    segtreemax s1;
    segtreemin s2;

    s1.init(n);
    s2.init(n);

    for(ll i = n - 1; i >= 0; i--)
    {
        ll c = str[i] - 'a';
        vec[c].push_back(i + 1);

        s1.update(i + 1, c);
        s2.update(i + 1, vec[c].size());
    }

    for(ll i = 0; i < n; i++)
    {
        pll ask = s2.query(i + 1, n);

//        cout << ask.first << " ++ " << ask.second << "\n";

        if(ask.first == mxlld)
        {
            break;
        }

        pll ask2 = s1.query(i + 1, ask.second);

//        cout << ask2.first << " && " << ask2.second << "\n";

        cout << (char)(ask2.first + 'a');

        for(auto it: vec[ask2.first])
        {
            s2.update(it,mxlld);
            s1.update(it,-1);
        }

        i = ask2.second - 1;
    }

    cout << '\n';
    return;
}

int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        solve();
    }


}

