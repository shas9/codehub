struct Line
{
    ll m, c;
};

struct nodes
{
	Line line;
	ll lft, rgt;
}


struct DynamicLichao
{
    vector < nodes > tree;

    ll n;
    ll nowroot;
    ll type;
    ll lft, rgt;
    ll idx;

    void init(ll _t, ll l, ll r)
    {
		idx = 0;
		nowroot = 0;

		lft = l;
		rgt = r;

		n = 1e6

        tree.clear();
        tree.resize(20 * (n + 5));

        type = _t; // 1 = maximum, 2 = minimum

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

        if(type & 1)
        {
			bool left = f(line, lo) > f(tree[node].line, lo);
			bool m = f(line, mid) > f(tree[node].line, mid);
        }
        else
        {
			bool left = f(line, lo) < f(tree[node].line, lo);
			bool m = f(line, mid) < f(tree[node].line, mid);
        }

        if(m) swap(line, tree[node].line);

        if(left != m)
        {
			if(tree[nodes].lft == -1) tree[nodes].lft = ++idx;

			ll left = tree[nodes].lft;
			add1(lo, mid, line, left);
        }
        else
        {
			if(tree[nodes].rgt == -1) tree[nodes].rgt = ++idx;

			ll right = tree[nodes].rgt;
			add(mid+1, hi, line, right);
        }
    }

    void update(ll m, ll c)
    {
        Line x;
        x.m = m;
        x.c = c;

        add(lft,rgt,x,nowroot);
    }

    ll query(ll lo, ll hi, ll pos, ll node)
    {
        if(lo == hi)
            return f(tree[node], pos);

        ll mid = (lo+hi) >> 1, ret = f(tree[node], pos);

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
				return max(ret, query(lo, mid, pos, right));
			}
			else
			{
				return min(ret, query(lo, mid, pos, right));
			}
        }
    }


    ll ask(ll x)
    {
		return query(lft,rgt,x,nowroot);
    }
};
