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
		ll pos = lower_bound(pnt.begin(),pnt.end(),x) - pnt.begin();

        if(type & 1) return query1(0,n,pos,1);
        else return query2(0,n,pos,1);
    }
};

struct qq
{
	ll type, t, cyc, speed;
} query[100005];


vector < ll > g[50004];
ll val[50004];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    while(cin >> n >> m)
    {
		for(ll i = 1; i <= n; i++)
		{
			g[i].clear();
			val[i] = 0;
		}

		Lichao tree;

		for(ll i = 1; i <= m; i++)
		{
			slld(query[i].type);

			if(query[i].type == 1)
			{
				slld(query[i].t);
				slld(query[i].cyc);
				slld(query[i].speed);
			}
			else
			{
				slld(query[i].t);
				tree.pnt.push_back(query[i].t);
			}
		}

		tree.init(1);

		for(ll i = 1; i <= m; i++)
		{
			if(query[i].type == 1)
			{

				if(g[query[i].cyc].empty()) val[query[i].cyc] -= query[i].t * query[i].speed;
				else val[query[i].cyc] -= (query[i].t * (query[i].speed - (int)g[query[i].cyc].back()));

				tree.update(query[i].speed, val[query[i].cyc]);

				g[query[i].cyc].push_back(query[i].speed);
			}
			else
			{
				ans = tree.ask(query[i].t);
				printf("%lld\n", ans);
			}
		}
    }


}


