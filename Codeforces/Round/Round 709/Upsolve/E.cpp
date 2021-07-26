 // God put a smile upon your face <3

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define pb push_back

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}


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

        tree[node] = max(tree[left], tree[right]);
    }

    void update(ll i, ll val)
    {
        treeupdate(1,1,n,i,val);
    }

    ll treequery(ll node, ll b, ll e, ll i, ll j)
    {
        if(i > e || j < b)
        {
            return -1e10;
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

        return max(p1, p2);
    }

    ll query(ll x, ll y)
    {
        return treequery(1,1,n,x,y);
    }

};

vector < ll > dp;
stack < ll > st;
vector < pll > arr;

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
        while(!st.empty()) st.pop();
        n++;

        dp.assign(n + 1, 0);
        arr.resize(n + 1);

        for(ll i = 2; i <= n; ++i) cin >> arr[i].first;
        for(ll i = 2; i <= n; ++i) cin >> arr[i].second;

        segtree seg;
        seg.init(n);

        for(ll i = 2; i <= n; i++)
        {
            while(!st.empty() && arr[st.top()].first > arr[i].first) st.pop();

            ll pos = 1;

            if(!st.empty()) pos = st.top();

            if(st.empty()) dp[i] = seg.query(1,i - 1) + arr[i].second;
            else dp[i] = max(dp[pos], max(dp[pos], seg.query(pos + 1, i - 1)) + arr[i].second);

//            cout << i << " " << pos << " " << dp[i] << "\n";

            seg.update(i,dp[i]);
            st.push(i);
        }

        cout << dp[n] << "\n";
    }


}

