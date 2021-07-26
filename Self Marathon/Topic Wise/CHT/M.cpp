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

    ll n;
    ll type;
    ll lft, rgt;
    ll idx;

    void init(ll _t, ll l, ll r)
    {
		lft = l;
		rgt = r;

		n = 2e5;

        tree.clear();
        tree.resize(22 * (n + 5));

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

    void update(ll m, ll c, ll root)
    {
        Line x;
        x.m = m;
        x.c = c;

        add(lft,rgt,x,root);
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

    ll ask(ll x, ll root)
    {
		return query(lft,rgt,x,root);
    }
};

struct st
{
	ll id, s, node;
}a1[1000006];

struct en
{
	ll id, e, node;
}a2[1000006];

bool cmp1(st a, st b)
{
	return a.s < b.s;
}

bool cmp2(en a, en b)
{
	return  a.e < b.e;
}

ll ans[200006];
DynamicLichao tree;
bool skip[200006];

ll solve(ll n, ll m)
{
	ll idx = 1;

	tree.update(0,0,1);

	for(ll i = 1; i <= m; i++)
	{
		while(a2[idx].e <= a1[i].s)
		{
			if(ans[a2[idx].id] == mxlld)
			{
				idx++;
				continue;
			}

			tree.update(-2 * a2[idx].e, ans[a2[idx].id] + a2[idx].e * a2[idx].e, a2[idx].node);
			idx++;
		}

		ans[a1[i].id] = tree.ask(a1[i].s, a1[i].node);

		if(ans[a1[i].id] == mxlld) continue;

		ans[a1[i].id] += a1[i].s * a1[i].s;

		assert(ans[a1[i].id] >= 0);

	}

	ll ret = mxlld;

	for(ll i = 1; i <= m; i++)
	{
		if(a2[i].node == n) ret = min(ret, ans[a2[i].id]);
	}

	return ret;
}

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);


    tree.init(0,0,1000005);

    slld(n);
    slld(m);

    for(i = 1; i <= m; i++)
    {
		a1[i].id = a2[i].id = i;

		slld(a1[i].node);
		slld(a2[i].node);
		slld(a1[i].s);
		slld(a2[i].e);

//		assert(a1[i].s != a2[i].e);
    }

    sort(a1 + 1, a1 + 1 + m, cmp1);
    sort(a2 + 1, a2 + 1 + m, cmp2);

    tree.idx = n;

	ans = solve(n,m);

	printf("%lld\n", ans);

}



