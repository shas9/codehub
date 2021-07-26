// God put a smile upon your face <3

#include <bits/stdc++.h>`

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

struct Line
{
    ll m, c;
};

struct nodes
{
    Line line;
    ll lft, rgt;
};


struct DynamicLichao
{
    vector < nodes > tree;
    vector < ll > nroot;

    ll n;
    ll type;
    ll lft, rgt;
    ll idx;

    void init(ll n, ll _t, ll l, ll r)
    {
        idx = 0;

        nroot.clear();
        nroot.resize(6 * (n + 5));

        fill(nroot.begin(),nroot.end(),-1);

        lft = l;
        rgt = r;

        tree.clear();
        tree.resize(200 * n);

        type = _t; // 1 = maximum, 0 = minimum

        if(type & 1) for(ll i = 0; i < tree.size(); i++) tree[i] = {{0,mnlld}, -1, -1};
        else for(ll i = 0; i < tree.size(); i++) tree[i] = {{0,mxlld}, -1, -1};
    }

    inline ll f(Line &line, ll &x)
    {
        return line.m*x + line.c;
    }

    void add(ll lo, ll hi, Line line, ll node)
    {
        if(lo == hi)
        {
            if(type & 1)
            {
                if(f(line, lo) > f(tree[node].line, lo))
                    tree[node].line = line;
            }
            else
            {
                if(f(line, lo) < f(tree[node].line, lo))
                    tree[node].line = line;
            }

            return;
        }

        ll mid = lo+hi >> 1;

        bool left, m;

        if(type & 1)
        {
            left = f(line, lo) > f(tree[node].line, lo);
            m = f(line, mid) > f(tree[node].line, mid);
        }
        else
        {
            left = f(line, lo) < f(tree[node].line, lo);
            m = f(line, mid) < f(tree[node].line, mid);
        }

        if(m) swap(line, tree[node].line);

        if(left != m)
        {
            if(tree[node].lft == -1) tree[node].lft = ++idx;

            ll left = tree[node].lft;

            add(lo, mid, line, left);
        }
        else
        {
            if(tree[node].rgt == -1) tree[node].rgt = ++idx;

            ll right = tree[node].rgt;

            add(mid+1, hi, line, right);
        }
    }

    void update(Line x, ll nowroot)
    {
        add(lft,rgt,x,nowroot);
    }

    ll query(ll lo, ll hi, ll pos, ll node)
    {
        if(lo == hi)
            return f(tree[node].line, pos);

        ll mid = (lo+hi) >> 1, ret = f(tree[node].line, pos);

        if(pos <= mid)
        {
            ll left = tree[node].lft;

            if(left == -1) return ret;

            if(type & 1)
            {
                return max(ret, query(lo, mid, pos, left));
            }
            else
            {
                return min(ret, query(lo, mid, pos, left));
            }
        }
        else
        {
            ll right = tree[node].rgt;

            if(right == -1) return ret;

            if(type & 1)
            {
                return max(ret, query(mid + 1, hi, pos, right));
            }
            else
            {
                return min(ret, query(mid + 1, hi, pos, right));
            }
        }
    }

    ll ask(ll x, ll nowroot)
    {
        return query(lft,rgt,x,nowroot);
    }
};

DynamicLichao tree;

void update(ll node, ll b, ll e, ll i, Line line)
{
    if(i > e || i < b)
    {
        return;
    }

    if(b == i && e == i)
    {
        if(tree.nroot[node] == -1)
        {
            tree.nroot[node] = ++tree.idx;
        }

        tree.update(line, tree.nroot[node]);
        return;
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    update(left, b, mid, i, line);
    update(right, mid + 1, e, i, line);

    if(tree.nroot[node] == -1)
    {
        tree.nroot[node] = ++tree.idx;
    }

    tree.update(line, tree.nroot[node]);
}

ll sum(ll node, ll b, ll e, ll i, ll j, ll val)
{
	if(tree.nroot[node] == -1)
	{
		return mxlld;
	}

    if(i > e || j < b)
    {
        return mxlld;
    }

    if(b >= i && e <= j)
    {
        return tree.ask(val, tree.nroot[node]);
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    ll p1 = sum(left, b, mid, i, j, val);
    ll p2 = sum(right, mid + 1, e,i, j, val);

    return min(p1,p2);
}

ll pp[300005];
ll hh[300005];
ll aa[300005];
ll dp[300005];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);


    slld(n);

    tree.init(n,0,1,600005);

    for(ll i = 1; i <= n; i++) slld(pp[i]);
    for(ll i = 1; i <= n; i++) slld(aa[i]);
    for(ll i = 1; i <= n; i++) slld(hh[i]);

//    update(1,1,n,1,{0,0});

    for(ll i = 1; i <= n; i++)
    {
		if(i == 1) dp[i] = aa[i];
        else dp[i] = sum(1,1,n,1,pp[i] - 1, hh[i]);

        if(dp[i] == mxlld) continue;

        if(i != 1) dp[i] += (hh[i] * hh[i]) + aa[i];

//        cout << i << " " << dp[i] << endl;

        Line line = {-2*hh[i], dp[i] + (hh[i] * hh[i])};

        update(1,1,n,pp[i], line);
    }

    printf("%lld\n", dp[n]);


}



