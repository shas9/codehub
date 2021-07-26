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

struct shop
{
	ll c, p, id;
} a1[200005];

struct cust
{
	ll c, id;
	vector < ll > vec;
} a2[200005];

ll mp[200005];

bool comp(shop a, shop b)
{
	return a.c < b.c;
}

bool comp1(cust a, cust b)
{
	return a.c < b.c;
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
} tree[1000006];

// 1 = mi > mi+1, mn

void init(ll node, ll b, ll e)
{
    if(b == e)
    {
        tree[node].init(1);
        return;
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    init(left, b, mid);
    init(right, mid + 1, e);

    tree[node].init(1);
}

void update(ll node, ll b, ll e, ll i, line val)
{
    if(i > e || i < b)
    {
        return;
    }

    tree[node].add(val);

    if(b == i && e == i) return;

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    update(left, b, mid, i, val);
    update(right, mid + 1, e, i, val);
}

ll sum(ll node, ll b, ll e, ll i, ll j, ll x)
{
    if(i > e || j < b)
    {
        return mxlld;
    }

    if(b >= i && e <= j)
    {
        return tree[node].ask1(x);
    }

    ll left = node * 2;
    ll right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    ll p1 = sum(left, b, mid, i, j, x);
    ll p2 = sum(right, mid + 1, e,i, j, x);

    return min(p1,p2);
}

ll ans[200005];

int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(n);
    slld(m);

    init(1,1,n);

    for(ll i = 1; i <= n; i++)
    {
		slld(a1[i].c);
		slld(a1[i].p);
		a1[i].id = i;
    }

    sort(a1 + 1, a1 + 1 + n, comp);

    for(ll i = 1; i <= n; i++)
    {
		mp[a1[i].id] = i;
    }

    for(ll i = 1; i <= m; i++)
    {
		slld(a2[i].c);
		a2[i].id = i;

		slld(k);

		for(ll j = 1; j <= k; j++)
		{
			slld(input);

			input = mp[input];
			a2[i].vec.push_back(input);
		}

		a2[i].vec.push_back(n + 1);

		sort(a2[i].vec.begin(),a2[i].vec.end());
    }

    sort(a2 + 1, a2 + 1 + m, comp1);

    for(ll i = 1; i <= n; i++)
    {
		update(1,1,n,i,{-2*a1[i].c, a1[i].c * a1[i].c + a1[i].p});
    }

    for(ll i = 1; i <= m; i++)
    {
		ll prv = 1;

		ll mn = mxlld;

		for(auto it: a2[i].vec)
		{
			if(prv < it)
			{
				mn = min(mn, sum(1,1,n,prv, it - 1,a2[i].c));

//				cout << prv << " " << it - 1 << " " << mn << endl;
			}

			prv = it + 1;
		}

//		for(auto it: a2[i].ve)

//		cout << a2[i].c << " & " << a2[i].id << " = " << mn << " " << a2[i].vec.size() <<  endl;

		mn += a2[i].c * a2[i].c;

		ans[a2[i].id] = mn;
    }

    for(ll i = 1; i <= m; i++)
    {
		printf("%lld\n", ans[i]);
    }

}



