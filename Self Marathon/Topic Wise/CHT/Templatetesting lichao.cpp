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

struct Lichao
{
    vector < Line > tree;
    vector < ll > pnt;
    ll n;
    ll type;

    Lichao (): pnt(0,0) {}

    void init(ll _t)
    {
		sort(pnt.begin(),pnt.end());

        pnt.erase(unique(pnt.begin(),pnt.end()), pnt.end());

        n = pnt.size() - 1;

        tree.clear();
        tree.resize(4 * (n + 5));

        type = _t; // 1 = maximum, 2 = minimum

        if(type & 1) for(ll i = 0; i < tree.size(); i++) tree[i] = {0,mnlld};
        else for(ll i = 0; i < tree.size(); i++) tree[i] = {0,mxlld};
    }

    inline ll f(Line &line, ll &x)
    {
        return line.m*x + line.c;
    }

    void add1(ll lo, ll hi, Line line, ll node)
    {
        if(lo == hi)
        {
            if(f(line, pnt[lo]) > f(tree[node], pnt[lo]))
                tree[node] = line;
            return;
        }

        ll mid = lo+hi >> 1;

        bool left = f(line, pnt[lo]) > f(tree[node], pnt[lo]);
        bool m = f(line, pnt[mid]) > f(tree[node], pnt[mid]);

        if(m) swap(line, tree[node]);

        if(left != m) add1(lo, mid, line, node<<1);
        else add1(mid+1, hi, line, node<<1|1);
    }

    void add2(ll lo, ll hi, Line line, ll node)
    {
        if(lo == hi)
        {
            if(f(line, pnt[lo]) < f(tree[node], pnt[lo]))
                tree[node] = line;
            return;
        }

        ll mid = lo+hi >> 1;

        bool left = f(line, pnt[lo]) < f(tree[node], pnt[lo]);
        bool m = f(line, pnt[mid]) < f(tree[node], pnt[mid]);

        if(m) swap(line, tree[node]);

        if(left != m) add2(lo, mid, line, node<<1);
        else add2(mid+1, hi, line, node<<1|1);
    }

    void update(ll m, ll c)
    {
        Line x;
        x.m = m;
        x.c = c;

        if(type & 1) add1(0,n,x,1);
        else add2(0,n,x,1);
    }

    ll query1(ll lo, ll hi, ll idx, ll node)
    {
        if(lo == hi)
            return f(tree[node], pnt[idx]);

        ll mid = (lo+hi) >> 1, ret = f(tree[node], pnt[idx]);

        if(idx <= mid) return max(ret, query1(lo, mid, idx, node<<1));
        else return max(ret, query1(mid+1, hi, idx, node<<1 | 1));
    }

    ll query2(ll lo, ll hi, ll idx, ll node)
    {
        if(lo == hi)
            return f(tree[node], pnt[idx]);

        ll mid = (lo+hi) >> 1, ret = f(tree[node], pnt[idx]);

        if(idx <= mid) return min(ret, query2(lo, mid, idx, node<<1));
        else return min(ret, query2(mid+1, hi, idx, node<<1 | 1));
    }

    ll ask(ll x)
    {
        if(type & 1) return query1(0,n,x,1);
        else return query2(0,n,x,1);
    }
};

struct qq
{
	ll t, x, y;
} query[100005];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m)
    {
        Lichao tree;

        for(ll i = 1; i <= n; i++)
        {
			slld(query[i].t);

			if(query[i].t == 1)
			{
				slld(query[i].x);
				slld(query[i].y);
			}
			else
			{
				slld(query[i].x);

				tree.pnt.push_back(query[i].x);
			}
        }

        tree.init((m + 1) % 2);

        for(ll i = 1; i <= n; i++)
        {
			if(query[i].t == 1)
			{
				tree.update(query[i].x, query[i].y);
			}
			else
			{
				ll pos = lower_bound(tree.pnt.begin(),tree.pnt.end(), query[i].x) - tree.pnt.begin();

				ans = tree.ask(pos);

				printf("%lld\n", ans);
			}
        }
    }


}


