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

struct line
{
    ll m, c;

    line(ll x, ll y)
    {
        m = x;
        c = y;
    }
};

struct CHT
{
	vector < line > vec;
	ll t, ptr;

	void init(ll x)
	{
		t = x;
		ptr = 0;
		vec.clear();
	}

	inline ll func(ll idx, ll x)
	{
		ll ret = vec[idx].m * x + vec[idx].c;

		return ret;
	}

    bool bad(line f1, line f2, line f3)
    {
        __int128 a = (f3.c - f1.c);
        a = a * (f1.m - f2.m);

        __int128 b = (f2.c - f1.c);
        b = b * (f1.m - f3.m);

        if(t == 1) return a <= b;
        if(t == 2) return a >= b;
        if(t == 3) return a >= b;
        if(t == 4) return a <= b;

        assert(0);
    }

    void add(line x)
    {
        ll sz = vec.size();

        while(sz >= 2 && bad(vec[sz - 2], vec[sz - 1], x))
        {
            vec.pop_back();
            sz--;
        }

        vec.push_back(x);
    }

    ll ask(ll x) // ternary search
    {
		if(vec.empty())
		{
			return 0;
		}

        ll lo = 0;
        ll hi = vec.size() - 1;

        ll ret = (t & 1)? mxlld : mnlld;

        while(lo <= hi)
        {
            ll mid1 = (lo + (hi - lo) / 3);
            ll mid2 = (hi - (hi - lo) / 3);

            ll ans1 = func(mid1,x);
            ll ans2 = func(mid2,x);

            if(ans1 > ans2)
            {
                if(t & 1)
                {
					ret = min(ret, ans2);
					lo = mid1 + 1;
                }
                else
                {
					ret = max(ret, ans1);
					hi = mid2 - 1;
                }
            }
            else
            {
                if(t & 1)
                {
					ret =  min(ret,ans1);
					hi = mid2 - 1;
                }
                else
                {
					ret = max(ret,ans2);
					lo = mid1 + 1;
                }
            }
        }

        return ret;
    }

    ll ask1(ll x) // pointer search (linear)
    {
		if(vec.empty())
		{
			return 0;
		}

		if(ptr >= vec.size()) ptr = vec.size() - 1;

		while(ptr < (vec.size() - 1))
		{
			if(t & 1)
			{
				if(func(ptr,x) > func(ptr + 1,x))
				{
					ptr++;
				}
				else break;
			}
			else
			{
				if(func(ptr,x) < func(ptr + 1,x))
				{
					ptr++;
				}
				else break;
			}
		}

		return func(ptr,x);
    }
} cht[500005];

void init(ll node, ll b, ll e)
{
	cht[node].init(2);

    if(b == e)
    {
        return;
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    init(left, b, mid);
    init(right, mid + 1, e);
}

void update(ll node, ll b, ll e, ll i, line val)
{
    if(i > e || i < b)
    {
        return;
    }

	cht[node].add(line);

    if(b == i && e == i)
    {
        return;
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    update(left, b, mid, i, val);
    update(right, mid + 1, e, i, val);
}

ll chtmax(ll node, ll b, ll e, ll i, ll j, ll x)
{
    if(i > e || j < b)
    {
        return mnlld;
    }

    if(b >= i && e <= j)
    {
        return cht[node].ask(x);
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    ll p1 = chtmax(left, b, mid, i, j, x);
    ll p2 = chtmax(right, mid + 1, e,i, j, x);

    return max(p1,p2);
}

ll arr[100005];
ll tree[500005];

void _init(ll node, ll b, ll e)
{
    if(b == e)
    {
        tree[node] = arr[b];
        return;
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    _init(left, b, mid);
    _init(right, mid + 1, e);

    tree[node] = min(tree[left], tree[right]);
}

ll getmin(ll node, ll b, ll e, ll i, ll j)
{
    if(i > e || j < b)
    {
        return mxlld;
    }

    if(b >= i && e <= j)
    {
        return tree[node];
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    ll p1 = getmin(left, b, mid, i, j);
    ll p2 = getmin(right, mid + 1, e,i, j);

    return min(p1,p2);
}

ll dp[55][100005];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(testcase);

    for(ll cs = 1; cs <= testcase; cs++)
    {
		slld(n);
		slld(k);

		for(ll i = 1; i <= n; i++)
		{
			slld(arr[i]);
		}

		_init(1,1,n);

		k++;

		for(ll i = 1; i <= n; i++)
		{
			dp[1][i] = getmin(1,1,n,1,i) * i;
		}

		for(ll i = 2; i <= k; i++)
		{
			init(1,1,n);

			for(ll j = 1; j <= n; j++)
			{
				if(j == 1) dp[i][j] = arr[j];
				else
				{

				}
			}
		}
    }


}



