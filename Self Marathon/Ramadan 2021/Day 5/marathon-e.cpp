 // Lights will guide you home

#include <bits/stdc++.h>

#define slld(longvalue) scanf("%d", &longvalue)

#define ll int
#define pll pair < ll, ll >

#define fastio ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define bug(x) printf("BUG %lld\n", x)

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

#define nsz 100010
#define tsz 3000010 //take 4n + qlogn

ll a[nsz];
ll NEXT_FREE;
ll version[nsz];
ll val[tsz], Left[tsz], Right[tsz];

void build(ll node, ll l, ll r)
{
    if(l == r) // leaf node
    {
        val[node] = 0;
        return;
    }
    Left[node] = NEXT_FREE++;
    Right[node] = NEXT_FREE++;
    ll mid = (l + r) >> 1;
    build(Left[node], l, mid);
    build(Right[node], mid+1, r);
    val[node] = val[Left[node]] + val[Right[node]];
}

ll update(ll node, ll l, ll r, ll idx, ll v)
{
    if(idx < l || r < idx)
        return node; // Out of range, use this node.
    ll nnode = NEXT_FREE++; //Creating a new node, as idx is in [l, r]
    if (l == r) // Leaf Node, create new node and return that.
    {
        val[nnode] = val[node]; //cloning current old leaf node's value to new leaf node
        val[nnode] += v; // adding or subtracting or replacing as needed
        return nnode;
    }
    ll mid = (l + r) >> 1;
// Left[nnode] is new node's Left child, it might end up being the old one too
// Left[node] is current old node's Left child.
// So we call to update idx in Left child of old node.
// And use it's return node as new node's Left child. Same for Right.
    Left[nnode] = update(Left[node], l, mid, idx, v);
    Right[nnode] = update(Right[node], mid+1, r, idx, v);
    val[nnode] = val[Left[nnode]] + val[Right[nnode]]; // Update value.
    return nnode; // Return the new node to parent.
}

ll query(ll pnode, ll l, ll r, ll i, ll j)
{
//    cout << pnode << " " << l << " " << r << " " << i << " " << j << '\n';
    assert(pnode != -1);
    if(i > r || j < l) return 0;

    if(i <= l && r <= j)
    {
        return val[pnode];
    }

//    cout << pnode << " DHUKSE " << l << " " << r << " " << i << " " << j << '\n';

    ll p1 = query(Left[pnode], l, (l + r) / 2, i, j);
    ll p2 = query(Right[pnode], ((l + r) / 2) + 1, r, i, j);

    return p1 + p2;
}

map < ll, ll > mp;
vector < pll > pnt;
set < ll > st;


int main()
{
    ll i, j, k, l, m, n, r, q;
    ll testcase;
    ll in, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    memset(Left, -1, sizeof Left);
    memset(Right, -1, sizeof Right);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
        mp.clear();

        slld(n);
        slld(m);

        pnt.resize(n);
        st.clear();

        for(auto &it: pnt)
        {
            slld(it.first);
            slld(it.second);

            mp[it.first] = mp[it.second] = 0;

            st.insert(it.first);
            st.insert(it.second);
        }

        ll cnt = 0;

        for(auto &it: mp)
        {
            it.second = ++cnt;
        }

        for(auto &it: pnt)
        {
            it.first = mp[it.first];
            it.second = mp[it.second];
        }

        sort(pnt.begin(), pnt.end());

        NEXT_FREE = 0;
        version[0] = NEXT_FREE++;
        build(version[0], 1, cnt);

        ll ptr = 0;

        for(ll i = 1; i <= cnt; i++)
        {
            version[i] = update(version[i - 1], 1, cnt, 1, 0);

            while(ptr < n && pnt[ptr].first == i)
            {
                version[i] = update(version[i], 1, cnt, pnt[ptr].second, 1);
                ptr++;
            }
        }

        printf("Case %d:\n", cs);

        while(m--)
        {
            ans = 0;

            ll x1, y1, x2, y2;

            slld(x1);
            slld(y1);
            slld(x2);
            slld(y2);

            auto it = st.upper_bound(x2);

            auto lft = st.lower_bound(y1);
            auto rgt = st.upper_bound(y2);

            if(it != st.begin())
            {
                it--;
                if(lft != st.end() && rgt != st.begin())
                {
                    rgt--;

                    ans = query(version[mp[*it]], 1, cnt, mp[*lft], mp[*rgt]);

                    it = st.lower_bound(x1);

                    if(it != st.begin())
                    {
                        it--;

                        ans -= query(version[mp[*it]], 1, cnt, mp[*lft], mp[*rgt]);
                    }
                }
            }

            printf("%d\n", ans);

        }

    }


}

