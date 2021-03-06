#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

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

struct segTree
{
    ll n;
    vector<ll> tree;

    segTree(ll n): n(n), tree(4*n, 0) {}

    void treeUpdate(ll node, ll l, ll r, ll u, ll val)
    {
        ll mid = (l+r)>>1;

        if(l > u || r < u) return;
        if(l == u && r == u)
        {
            tree[node] = val;
            return;
        }

        treeUpdate(2*node, l, mid, u,  val);
        treeUpdate(2*node+1, mid+1, r, u, val);

        tree[node] = max(tree[2*node], tree[2*node+1]);
    }

    void update(ll idx, ll val) { treeUpdate(1, 1, n, idx, val); }

    ll treeQuery(ll node, ll l, ll r, ll u, ll v)
    {
        ll mid = (l+r)>>1;

        if(l > v || r < u) return 0;
        if(l >= u && r <= v) return tree[node];

        return max(treeQuery(2*node, l, mid, u, v), treeQuery(2*node+1, mid+1, r, u, v));
    }

    ll query(ll l, ll r) { return treeQuery(1, 1, n, l, r); }
};

ll arr[100005];
ll track[100005];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n)
    {
        for(i = 1; i <= n; i++)
        {
            slld(arr[i]);

            track[arr[i]] = i;
        }

        ans = 0;

        segTree tree(n);
        stack < ll > st;

        for(i = 1; i <= n; i++)
        {
            ll lf = 0;

            ll lo = 1;
            ll hi = i - 1;

            while(!st.empty())
            {
                if(st.top() <= arr[i]) st.pop();
                else break;
            }


            if(st.size() == 0) lf = 0;
            else
            {
                lf = track[st.top()];
            }

            st.push(arr[i]);

            if(lf == 0) continue;

            ll mx = tree.query(lf + 1, i - 1);

//            cout << mx << " " << lf << " " << i - 1 << endl;

            ans = max(ans, mx + 1);

            tree.update(i,mx + 1);
        }

        cout << ans << endl;

    }


}

